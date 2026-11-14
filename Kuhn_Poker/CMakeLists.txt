cmake_minimum_required(VERSION 3.20)

# Build with Rulebook (RLC) and disable CMake's default C and C++ build rules.
project(KuhnPoker LANGUAGES NONE)

# Enable CTest.
enable_testing()

# ==========================================================
# 1. Find build and test tools in the active Conda environment.
# Use RLC and LLVM 22 from the rulebook environment.
# ==========================================================
# Conda sets CONDA_PREFIX to the path of the active environment.
if(NOT DEFINED ENV{CONDA_PREFIX})
    message(FATAL_ERROR "Activate the rulebook environment first with conda activate rulebook")
endif()

set(CONDA_BIN "$ENV{CONDA_PREFIX}/bin")
set(CONDA_LIB "$ENV{CONDA_PREFIX}/lib")

# Require the RLC compiler.
find_program(RLC NAMES rlc
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# Require the RLC unit test tool.
find_program(RLC_TEST NAMES rlc-test
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# Locate the Rulebook trace replay tool in the active Conda environment.
find_program(RLC_ACTION NAMES rlc-action
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# clang-22 is the LLVM 22 compiler and linker driver.
find_program(CLANG NAMES clang-22
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# opt processes LLVM IR.
find_program(LLVM_OPT NAMES opt
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# llvm-symbolizer turns ASan error addresses into readable symbols.
find_program(SYMBOLIZER NAMES llvm-symbolizer
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# libfuzzer.a provides the fuzzing engine.
# libfuzzer.a
find_file(FUZZ_ADAPTER NAMES libfuzzer.a
    PATHS "${CONDA_LIB}" NO_DEFAULT_PATH REQUIRED)

# LLVM 22 needs the SDK path to link on macOS.
# Stop configuration if the command fails or returns an empty path.
# During configuration, run xcrun --sdk macosx --show-sdk-path.
# OUTPUT_VARIABLE stores the command's standard output.
# OUTPUT_STRIP_TRAILING_WHITESPACE removes trailing newlines and spaces.
# RESULT_VARIABLE stores the command's exit status.
execute_process(
    COMMAND xcrun --sdk macosx --show-sdk-path
    OUTPUT_VARIABLE MACOS_SDK
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE SDK_RESULT
)
if(NOT "${SDK_RESULT}" STREQUAL "0" OR MACOS_SDK STREQUAL "")
    message(FATAL_ERROR "macOS SDK not found. Check xcrun and Xcode Command Line Tools.")
endif()

# ==========================================================
# 2. Store executables in result/ and intermediate files in build_cmake/temp/.
# ==========================================================
# CMake provides the following directory variables.
# CMAKE_CURRENT_SOURCE_DIR points to the Kuhn_Poker/ source directory.
# CMAKE_CURRENT_BINARY_DIR points to the Kuhn_Poker/build_cmake/ build directory.
set(SRC "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD "${CMAKE_CURRENT_BINARY_DIR}")

set(RESULT_DIR "${SRC}/result")
set(TEMP_DIR "${BUILD}/temp")
set(FUZZ_TEMP "${TEMP_DIR}/fuzzer")
set(TEST_TEMP "${TEMP_DIR}/test")
set(ASAN_TEMP "${TEMP_DIR}/Sanitizer")

# Create these directories during configuration.
# libFuzzer stores test inputs in corpus and failure cases in artifacts.
file(MAKE_DIRECTORY
    "${RESULT_DIR}"
    "${FUZZ_TEMP}/corpus"
    "${FUZZ_TEMP}/artifacts"
    "${TEST_TEMP}"
    "${ASAN_TEMP}/corpus"
    "${ASAN_TEMP}/artifacts"
)

# Project source files.
set(GAME_SOURCE "${SRC}/kuhn_poker.rl")
set(GAME_MAIN_SOURCE "${SRC}/kuhn_poker_main.rl")
set(TEST_SOURCE "${SRC}/kuhn_poker_test.rl")
set(FUZZ_SOURCE "${SRC}/kuhn_poker_fuzz.rl")
set(HELPER "${SRC}/cmake/kuhn_poker_game.cmake")

# Final executables go in result/ next to the .rl source files.
set(GAME_BIN "${RESULT_DIR}/kuhn_poker")
set(FUZZ_BIN "${RESULT_DIR}/kuhn_poker_fuzzer")

# ==========================================================
# 3. Build the game executable from kuhn_poker_main.rl into result/kuhn_poker.
# ==========================================================
# Equivalent to running rlc kuhn_poker_main.rl -g -o result/kuhn_poker.
# Define how to generate a specific output file.
# OUTPUT is the file to generate, result/kuhn_poker.
# COMMAND is the command to execute.
# DEPENDS lists the inputs so Ninja rebuilds the executable when source files change.
# Ninja can usually reuse an existing output when its inputs are unchanged.
# This is an incremental build.
# WORKING_DIRECTORY is the directory in which the command runs.
# COMMENT is the description displayed during the build.
# VERBATIM is CMake's recommended way to handle escaping and quoting in custom commands.
add_custom_command(
    OUTPUT "${GAME_BIN}"
    COMMAND "${RLC}" "${GAME_MAIN_SOURCE}" -g -o "${GAME_BIN}"
    DEPENDS "${GAME_MAIN_SOURCE}" "${GAME_SOURCE}"
    WORKING_DIRECTORY "${SRC}"
    COMMENT "Building the Kuhn Poker game executable"
    VERBATIM
)

# Give the build task a target name so it can be run by name.
# 
add_custom_target(game_build ALL DEPENDS "${GAME_BIN}")

# ==========================================================
# 4. Build the fuzzer using RLC's built-in --fuzzer mode and Conda LLVM 22.
# ==========================================================
# Store the LLVM IR generated by RLC as temp/fuzzer/kuhn.raw.ll.
set(RAW_IR "${FUZZ_TEMP}/kuhn.raw.ll")
# Store the ASan-instrumented LLVM IR as temp/Sanitizer/kuhn.asan.ll.
set(ASAN_IR "${ASAN_TEMP}/kuhn.asan.ll")
# kuhn.asan.o is the object file containing compiled machine code.
set(ASAN_OBJ "${ASAN_TEMP}/kuhn.asan.o")

add_custom_command(
    OUTPUT "${FUZZ_BIN}"

    # Step 1. Generate LLVM IR using RLC's built-in --fuzzer flag.
    # The helper captures RLC's standard output with OUTPUT_FILE in place of shell redirection.
    COMMAND "${CMAKE_COMMAND}"
        "-DMODE=ir"
        "-DRLC=${RLC}"
        "-DSOURCE=${FUZZ_SOURCE}"
        "-DINCLUDE_DIR=${SRC}"
        "-DOUTPUT=${RAW_IR}"
        -P "${HELPER}"

    # Step 2. Add AddressSanitizer instrumentation.
    COMMAND "${LLVM_OPT}"
        -S -passes=forceattrs,asan
        -force-attribute=sanitize_address
        "${RAW_IR}" -o "${ASAN_IR}"

    # Step 3. Compile the LLVM IR into a .o object file.
    COMMAND "${CLANG}"
        -g -O0 -fno-omit-frame-pointer
        -c "${ASAN_IR}" -o "${ASAN_OBJ}"

    # Step 4. Link the LLVM libFuzzer runtime and RLC adapter library.
    COMMAND "${CLANG}"
        -g -isysroot "${MACOS_SDK}"
        -fsanitize=fuzzer,address
        "${ASAN_OBJ}" "${FUZZ_ADAPTER}"
        -o "${FUZZ_BIN}"

    # DEPENDS triggers a fuzzer rebuild when the game, fuzzer entry point, or helper changes.
    # BYPRODUCTS lists the three intermediate files generated alongside kuhn_poker_fuzzer.
    DEPENDS "${GAME_SOURCE}" "${FUZZ_SOURCE}" "${HELPER}"
    BYPRODUCTS "${RAW_IR}" "${ASAN_IR}" "${ASAN_OBJ}"
    WORKING_DIRECTORY "${SRC}"
    COMMENT "Building the RLC fuzzer with ASan instrumentation"
    VERBATIM
)
add_custom_target(fuzzer_build ALL DEPENDS "${FUZZ_BIN}")

# ==========================================================
# 5. Register the game, unit, short ASan, and fuzz tests with CTest.
# ==========================================================
# Test 1. The game's main() returns 0 on success.
add_test(NAME game_test COMMAND "${GAME_BIN}")

# Test 2. Run rlc-test and write the output to temp/test/unit_test.log.
add_test(NAME unit_test
    COMMAND "${CMAKE_COMMAND}"
        "-DMODE=unit"
        "-DRLC_TEST=${RLC_TEST}"
        "-DSOURCE=${TEST_SOURCE}"
        "-DSOURCE_DIR=${SRC}"
        "-DOUTPUT=${TEST_TEMP}/unit_test.log"
        -P "${HELPER}"
)

# Test 3. Run the ASan-instrumented fuzzer for 100 iterations.
add_test(NAME sanitizer_test
    COMMAND "${FUZZ_BIN}"
        -runs=100 -seed=418 -max_len=256 -timeout=5
        "-artifact_prefix=${ASAN_TEMP}/artifacts/"
        "${ASAN_TEMP}/corpus"
)

# Test 4. Run 10,000 coverage-guided fuzzing iterations with a separate corpus.
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

# Test 5: replay a fixed trace and check the expected final game state.
add_test(NAME trace_test
    COMMAND "${CMAKE_COMMAND}"
        "-DMODE=trace"
        "-DRLC_ACTION=${RLC_ACTION}"
        "-DRLC=${RLC}"
        "-DSOURCE=${GAME_SOURCE}"
        "-DSOURCE_DIR=${SRC}"
        "-DTRACE_FILE=${SRC}/traces/game1.txt"
        "-DEXPECTED_FILE=${SRC}/traces/game1.expected.txt"
        "-DOUTPUT=${TEST_TEMP}/trace_test.log"
        -P "${HELPER}"
)

set_tests_properties(trace_test PROPERTIES TIMEOUT 90)

# ==========================================================
# 6. Build and run all tests with one command.
# ==========================================================
# CMAKE_CTEST_COMMAND points to the CTest executable.
# --output-on-failure shows the output of failed tests.
# --output-log saves CTest output to a log file.
# WORKING_DIRECTORY specifies the directory in which CTest runs.
# USES_TERMINAL gives the build command access to the terminal to display test progress.
add_custom_target(verify_all
    COMMAND "${CMAKE_CTEST_COMMAND}"
        --output-on-failure
        --output-log "${TEST_TEMP}/ctest.log"
    WORKING_DIRECTORY "${BUILD}"
    COMMENT "Running all Kuhn Poker tests"
    USES_TERMINAL
    VERBATIM
)
# verify_all runs the tests after game_build and fuzzer_build finish.
add_dependencies(verify_all game_build fuzzer_build)

message(STATUS "Kuhn Poker configuration complete")
message(STATUS "Final executables: ${RESULT_DIR}")
message(STATUS "Intermediate build and test files: ${TEMP_DIR}")