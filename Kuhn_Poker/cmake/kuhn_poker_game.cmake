
# 此文件通过 cmake -P 执行，不需要单独运行。
# MODE=ir   : 使用 RLC 官方 Fuzzer 模式生成 LLVM IR。
# MODE=unit : 执行 RLC 单元测试并保存输出。

if(NOT DEFINED MODE)
    message(FATAL_ERROR "缺少 MODE 参数")
endif()

if(MODE STREQUAL "ir")
    # RLC 的 --ir 输出写入指定文件，代替 Shell 的 > 重定向。
    # MODE=ir：生成 LLVM IR
    # OUTPUT_FILE：RLC 的标准输出，即 LLVM IR
    # ERROR_VARIABLE：	RLC 输出的错误信息
    # RESULT_VARIABLE   	RLC 的退出状态
    execute_process(
        COMMAND "${RLC}" "${SOURCE}"
            -i "${INCLUDE_DIR}"
            -g --fuzzer --compile --ir
        OUTPUT_FILE "${OUTPUT}"
        ERROR_VARIABLE ERROR_MSG
        RESULT_VARIABLE RESULT
    )

    # 用于检测编译失败
    if(NOT "${RESULT}" STREQUAL "0")
        file(REMOVE "${OUTPUT}")
        message(FATAL_ERROR "RLC 生成 LLVM IR 失败：\n${ERROR_MSG}")
    endif()

    if(NOT EXISTS "${OUTPUT}")
        message(FATAL_ERROR "RLC 未生成 LLVM IR：${OUTPUT}")
    endif()

    # 用于进一步检查生成的 IR 文件是否为空，因为之前遇到过RLC 链接失败，却留下空可执行文件的问题
    file(SIZE "${OUTPUT}" IR_SIZE)
    if(IR_SIZE EQUAL 0)
        message(FATAL_ERROR "RLC 生成的 LLVM IR 为空：${OUTPUT}")
    endif()

elseif(MODE STREQUAL "unit")
    # 运行 Rulebook 单元测试；把 stdout 和 stderr 记录到 temp/test。
    # 相当于执行    rlc-test kuhn_poker_test.rl
    # TEST_STDOUT：正常输出
    # TEST_STDERR：错误输出
    # TEST_RESULT：退出状态
    execute_process(
        COMMAND "${RLC_TEST}" "${SOURCE}"
        WORKING_DIRECTORY "${SOURCE_DIR}"
        OUTPUT_VARIABLE TEST_STDOUT
        ERROR_VARIABLE TEST_STDERR
        RESULT_VARIABLE TEST_RESULT
    )
    # 把结果写入：build_cmake/temp/test/unit_test.log
    file(WRITE "${OUTPUT}" "${TEST_STDOUT}${TEST_STDERR}")

    if(NOT "${TEST_RESULT}" STREQUAL "0")
        message(FATAL_ERROR
            "Rulebook 单元测试失败：\n${TEST_STDOUT}\n${TEST_STDERR}")
    endif()

    message(STATUS "单元测试通过，日志：${OUTPUT}")

else()
    message(FATAL_ERROR "不支持的 MODE：${MODE}")
endif()
