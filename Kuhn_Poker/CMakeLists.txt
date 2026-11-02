cmake_minimum_required(VERSION 3.20)

# 使用 Rulebook (RLC) 编译，不启用 CMake 默认的 C/C++ 编译规则
project(KuhnPoker LANGUAGES NONE)

# 启用 CTest
# dingbingxun_temp_code
# 这个就是为了开启CTest的吗？那不开启会怎么样
enable_testing()

# ==========================================================
# 1. 从当前 Conda 环境中查找编译、测试工具
# 确保Cmake使用的是rulebook环境中的RLC和LLVM 22
# ==========================================================
# CONDA_PREFIX 是conda提供的当前激活的 Conda 环境路径
if(NOT DEFINED ENV{CONDA_PREFIX})
    message(FATAL_ERROR "请先执行 conda activate rulebook")
endif()

set(CONDA_BIN "$ENV{CONDA_PREFIX}/bin")
set(CONDA_LIB "$ENV{CONDA_PREFIX}/lib")

# 确保rlc程序已经安装了
find_program(RLC NAMES rlc
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# 确保rlc的单元测试工具已经安装
find_program(RLC_TEST NAMES rlc-test
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# clang-22是LLVM 22 编译和链接工具
find_program(CLANG NAMES clang-22
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# opt是LLVM IR 处理工具
find_program(LLVM_OPT NAMES opt
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# llvm-symbolizer：将 ASan 错误地址转换成可读信息
find_program(SYMBOLIZER NAMES llvm-symbolizer
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# libfuzzer.a 提供模糊测试引擎（Fuzzing Engine）
# libfuzzer.a
find_file(FUZZ_ADAPTER NAMES libfuzzer.a
    PATHS "${CONDA_LIB}" NO_DEFAULT_PATH REQUIRED)

# LLVM 22 在 macOS 上链接时需要 SDK 路径
# 作用是：如果命令失败或者没有得到路径，就直接停止配置。
# 在Configure 阶段 执行：xcrun --sdk macosx --show-sdk-path
# OUTPUT_VARIABLE：保存命令标准输出
# OUTPUT_STRIP_TRAILING_WHITESPACE：去掉末尾换行和空白
# RESULT_VARIABLE：保存命令退出状态
execute_process(
    COMMAND xcrun --sdk macosx --show-sdk-path
    OUTPUT_VARIABLE MACOS_SDK
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE SDK_RESULT
)
if(NOT "${SDK_RESULT}" STREQUAL "0" OR MACOS_SDK STREQUAL "")
    message(FATAL_ERROR "找不到 macOS SDK，请检查 xcrun / Xcode Command Line Tools")
endif()

# ==========================================================
# 2. 目录：result/ 放最终程序，build_cmake/temp/ 放中间文件
# ==========================================================
# 对应变量是CMake 自带的路径变量
# CMAKE_CURRENT_SOURCE_DIR：当前 CMake 源码目录，对应 Kuhn_Poker/
# CMAKE_CURRENT_BINARY_DIR：当前 CMake 构建目录，对应 Kuhn_Poker/build_cmake/
set(SRC "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD "${CMAKE_CURRENT_BINARY_DIR}")

set(RESULT_DIR "${SRC}/result")
set(TEMP_DIR "${BUILD}/temp")
set(FUZZ_TEMP "${TEMP_DIR}/fuzzer")
set(TEST_TEMP "${TEMP_DIR}/test")
set(ASAN_TEMP "${TEMP_DIR}/Sanitizer")

# 在 Configure 阶段执行
# corpus 和 artifacts 是 libFuzzer 使用的测试数据目录
file(MAKE_DIRECTORY
    "${RESULT_DIR}"
    "${FUZZ_TEMP}/corpus"
    "${FUZZ_TEMP}/artifacts"
    "${TEST_TEMP}"
    "${ASAN_TEMP}/corpus"
    "${ASAN_TEMP}/artifacts"
)

# 项目源码
set(GAME_SOURCE "${SRC}/kuhn_poker.rl")
set(TEST_SOURCE "${SRC}/kuhn_poker_test.rl")
set(FUZZ_SOURCE "${SRC}/kuhn_poker_fuzz.rl")
set(HELPER "${SRC}/cmake/kuhn_poker_game.cmake")

# 最终可执行程序：与 .rl 同级的 result/ 目录
set(GAME_BIN "${RESULT_DIR}/kuhn_poker")
set(FUZZ_BIN "${RESULT_DIR}/kuhn_poker_fuzzer")

# ==========================================================
# 3. 正常编译游戏：kuhn_poker.rl -> result/kuhn_poker
# ==========================================================
# 等价于手动执行 rlc kuhn_poker.rl -g -o result/kuhn_poker
# 定义怎么编译，定义的是：如何生成一个具体文件。
# OUTPUT：最终需要生成的文件：result/kuhn_poker
# COMMAND：实际执行的命令
# DEPENDS：构建依赖的输入文件，Ninja 就知道：输出程序依赖于源文件，源文件发生变化后应重新编译。
# 如果没有修改文件，而且输出文件还存在，通常就不需要重新编译。
# 所谓的 Incremental Build 增量构建
# WORKING_DIRECTORY：执行命令时的当前目录
# COMMENT 构建时显示的说明
# VERBATIM 正确处理命令参数的转义和引用，是 CMake 官方推荐的自定义构建写法，通常应该保留
add_custom_command(
    OUTPUT "${GAME_BIN}"
    COMMAND "${RLC}" "${GAME_SOURCE}" -g -o "${GAME_BIN}"
    DEPENDS "${GAME_SOURCE}"
    WORKING_DIRECTORY "${SRC}"
    COMMENT "编译正常 Kuhn Poker 游戏"
    VERBATIM
)

# 给构建任务命名，定义的是：一个用户可以通过名字选择执行的构建目标。
# 
add_custom_target(game_build ALL DEPENDS "${GAME_BIN}")

# ==========================================================
# 4. Fuzzer 构建：RLC 官方 --fuzzer 模式 + Conda LLVM 22
# ==========================================================
# RLC 原始 IR：归类到 temp/fuzzer。kuhn.raw.ll，LLVM IR类型，RLC 编译产生的中间表示
set(RAW_IR "${FUZZ_TEMP}/kuhn.raw.ll")
# ASan 插桩 IR / Object：归类到 temp/Sanitizer，kuhn.asan.ll，LLVM IR类型，加入 ASan 插桩后的中间表示
set(ASAN_IR "${ASAN_TEMP}/kuhn.asan.ll")
# kuhn.asan.o Object File 类型 编译成机器代码后的目标文件
set(ASAN_OBJ "${ASAN_TEMP}/kuhn.asan.o")

add_custom_command(
    OUTPUT "${FUZZ_BIN}"

    # 步骤 1：通过 RLC 官方 --fuzzer 参数生成 LLVM IR
    # 辅助脚本使用 OUTPUT_FILE 接收 RLC 标准输出，不依赖 Shell 的 > 符号
    COMMAND "${CMAKE_COMMAND}"
        "-DMODE=ir"
        "-DRLC=${RLC}"
        "-DSOURCE=${FUZZ_SOURCE}"
        "-DINCLUDE_DIR=${SRC}"
        "-DOUTPUT=${RAW_IR}"
        -P "${HELPER}"

    # 步骤 2：添加 AddressSanitizer 插桩
    COMMAND "${LLVM_OPT}"
        -S -passes=forceattrs,asan
        -force-attribute=sanitize_address
        "${RAW_IR}" -o "${ASAN_IR}"

    # 步骤 3：LLVM IR 编译为 .o 目标文件
    COMMAND "${CLANG}"
        -g -O0 -fno-omit-frame-pointer
        -c "${ASAN_IR}" -o "${ASAN_OBJ}"

    # 步骤 4：链接 LLVM libFuzzer Runtime 和 RLC 适配库
    COMMAND "${CLANG}"
        -g -isysroot "${MACOS_SDK}"
        -fsanitize=fuzzer,address
        "${ASAN_OBJ}" "${FUZZ_ADAPTER}"
        -o "${FUZZ_BIN}"

    # DEPENDS 表示：修改游戏代码、Fuzzer 入口或辅助脚本后，需要重新执行 Fuzzer 构建。
    # BYPRODUCTS 表示：除了主要输出 kuhn_poker_fuzzer，这个命令还会产生三个中间文件。
    DEPENDS "${GAME_SOURCE}" "${FUZZ_SOURCE}" "${HELPER}"
    BYPRODUCTS "${RAW_IR}" "${ASAN_IR}" "${ASAN_OBJ}"
    WORKING_DIRECTORY "${SRC}"
    COMMENT "构建 RLC Fuzzer（含 ASan 插桩）"
    VERBATIM
)
add_custom_target(fuzzer_build ALL DEPENDS "${FUZZ_BIN}")

# ==========================================================
# 5. CTest：游戏、单元测试、ASan 短测、Fuzzer 测试
# ==========================================================
# 测试 1：游戏 main() 返回 0 表示成功
add_test(NAME game_test COMMAND "${GAME_BIN}")

# 测试 2：运行 rlc-test，把输出写到 temp/test/unit_test.log
add_test(NAME unit_test
    COMMAND "${CMAKE_COMMAND}"
        "-DMODE=unit"
        "-DRLC_TEST=${RLC_TEST}"
        "-DSOURCE=${TEST_SOURCE}"
        "-DSOURCE_DIR=${SRC}"
        "-DOUTPUT=${TEST_TEMP}/unit_test.log"
        -P "${HELPER}"
)

# 测试 3：同一个带 ASan 插桩的 Fuzzer 做 100 次短测试
add_test(NAME sanitizer_test
    COMMAND "${FUZZ_BIN}"
        -runs=100 -seed=418 -max_len=256 -timeout=5
        "-artifact_prefix=${ASAN_TEMP}/artifacts/"
        "${ASAN_TEMP}/corpus"
)

# 测试 4：使用独立 corpus 执行 10,000 次覆盖率引导的 Fuzzing
add_test(NAME fuzzer_test
    COMMAND "${FUZZ_BIN}"
        -runs=10000 -seed=418 -max_len=256 -timeout=5
        -print_final_stats=1
        "-artifact_prefix=${FUZZ_TEMP}/artifacts/"
        "${FUZZ_TEMP}/corpus"
)

set_tests_properties(sanitizer_test fuzzer_test PROPERTIES
    ENVIRONMENT "ASAN_SYMBOLIZER_PATH=${SYMBOLIZER}"
    TIMEOUT 180
    RUN_SERIAL TRUE
)

# ==========================================================
# 6. 一键构建和执行全部测试
# ==========================================================
# CMAKE_CTEST_COMMAND：指向 CTest 可执行程序
# --output-on-failure：测试失败时显示对应的测试输出
# --output-log：将 CTest 输出保存到日志文件
# WORKING_DIRECTORY：指定执行 CTest 的工作目录
# USES_TERMINAL：让构建命令使用终端，方便显示测试过程
add_custom_target(verify_all
    COMMAND "${CMAKE_CTEST_COMMAND}"
        --output-on-failure
        --output-log "${TEST_TEMP}/ctest.log"
    WORKING_DIRECTORY "${BUILD}"
    COMMENT "运行全部 Kuhn Poker 测试"
    USES_TERMINAL
    VERBATIM
)
# verify_all 必须先完成 game_build 和 fuzzer_build，才能执行测试
add_dependencies(verify_all game_build fuzzer_build)

message(STATUS "Kuhn Poker 配置完成")
message(STATUS "最终可执行文件：${RESULT_DIR}")
message(STATUS "编译及测试中间文件：${TEMP_DIR}")