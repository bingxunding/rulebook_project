cmake_minimum_required(VERSION 3.20)

# Compile with Rulebook (RLC) without enabling CMake's default C/C++ build rules.
project(RulebookGame LANGUAGES NONE)

if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux" OR
   NOT CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|amd64|AMD64)$")
    message(FATAL_ERROR
        "This project requires native Linux x86_64. "
        "Detected ${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}. "
        "Configure and build it on the Linux server with environment.yml.")
endif()

# Enable CTest.
enable_testing()

# ==========================================================
# 1. Find build and test tools in the active Conda environment
# Use RLC and LLVM 22 from the active Linux Conda environment.
# ==========================================================
# Conda sets CONDA_PREFIX to the path of the active environment.
if(NOT DEFINED ENV{CONDA_PREFIX})
    message(FATAL_ERROR "Activate a Conda environment with the required tools first.")
endif()

set(CONDA_BIN "$ENV{CONDA_PREFIX}/bin")
set(CONDA_LIB "$ENV{CONDA_PREFIX}/lib")

# Ensure rlc is installed. The optional RULEBOOK_RLC environment variable selects
# the real compiler for a new build directory. A cached RLC is never replaced,
# because RLC_STDLIB below is derived from it and cached as well.
if(NOT "$ENV{RULEBOOK_RLC}" STREQUAL "")
    if(NOT IS_ABSOLUTE "$ENV{RULEBOOK_RLC}")
        message(FATAL_ERROR "RULEBOOK_RLC must be an absolute path: $ENV{RULEBOOK_RLC}")
    endif()
    if(NOT RLC)
        find_program(RLC NAMES "$ENV{RULEBOOK_RLC}" NO_DEFAULT_PATH)
        if(NOT RLC)
            message(FATAL_ERROR "RULEBOOK_RLC is not an executable file: $ENV{RULEBOOK_RLC}")
        endif()
    endif()
    get_filename_component(RULEBOOK_RLC_REAL "$ENV{RULEBOOK_RLC}" REALPATH)
    get_filename_component(RLC_CACHED_REAL "${RLC}" REALPATH)
    if(NOT RULEBOOK_RLC_REAL STREQUAL RLC_CACHED_REAL)
        message(FATAL_ERROR
            "RULEBOOK_RLC (${RULEBOOK_RLC_REAL}) is not the compiler cached in this build "
            "directory (${RLC_CACHED_REAL}). The compiler has changed: configure a new build "
            "directory, so that RLC_STDLIB and the other cached settings match the compiler.")
    endif()
endif()
find_program(RLC NAMES rlc
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# Ensure the RLC unit test tool is installed.
find_program(RLC_TEST NAMES rlc-test
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# Locate the Rulebook trace replay tool in the active Conda environment.
find_program(RLC_ACTION NAMES rlc-action
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# Python tools otherwise infer this from --rlc, which points to our build-local
# launcher rather than the installed compiler. Trace replay needs learn.rl.
get_filename_component(RLC_REAL "${RLC}" REALPATH)
get_filename_component(RLC_BIN_DIR "${RLC_REAL}" DIRECTORY)
get_filename_component(RLC_PREFIX "${RLC_BIN_DIR}" DIRECTORY)
find_path(RLC_STDLIB NAMES learn.rl
    PATHS "${RLC_PREFIX}/lib/rlc/stdlib" "${CONDA_LIB}/rlc/stdlib"
    NO_DEFAULT_PATH REQUIRED)


# Prefer the Conda target driver, which selects the Linux sysroot and linker.
find_program(CLANG NAMES x86_64-conda-linux-gnu-clang clang-22 clang
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# opt processes LLVM IR.
find_program(LLVM_OPT NAMES opt-22 opt
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# llvm-symbolizer turns ASan error addresses into readable information.
find_program(SYMBOLIZER NAMES llvm-symbolizer-22 llvm-symbolizer
    PATHS "${CONDA_BIN}" NO_DEFAULT_PATH REQUIRED)

# libfuzzer.a provides the fuzzing engine.
# libfuzzer.a
find_file(FUZZ_ADAPTER NAMES libfuzzer.a
    PATHS "${CONDA_LIB}" NO_DEFAULT_PATH REQUIRED)

# Check the external LLVM tools, not RLC's separately bundled LLVM backend.
function(check_llvm_version tool)
    execute_process(COMMAND "${${tool}}" --version
        OUTPUT_VARIABLE version_output ERROR_VARIABLE version_error
        RESULT_VARIABLE version_result)
    if(NOT "${version_result}" STREQUAL "0")
        message(FATAL_ERROR "Cannot run ${tool}: ${${tool}}\n${version_error}")
    endif()
    string(REGEX MATCH "[Vv]ersion[ \t]+([0-9]+\\.[0-9]+\\.[0-9]+)"
        version_match "${version_output}")
    if(NOT CMAKE_MATCH_1 STREQUAL "22.1.8")
        message(FATAL_ERROR
            "${tool} must be LLVM 22.1.8, as pinned in environment.yml.\n${version_output}")
    endif()
    message(STATUS "${tool}: ${${tool}} (LLVM ${CMAKE_MATCH_1})")
endfunction()
check_llvm_version(CLANG)
check_llvm_version(LLVM_OPT)
check_llvm_version(SYMBOLIZER)

execute_process(COMMAND "${CLANG}" -dumpmachine
    OUTPUT_VARIABLE CLANG_TARGET OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_VARIABLE target_error RESULT_VARIABLE target_result)
if(NOT "${target_result}" STREQUAL "0" OR
   NOT CLANG_TARGET MATCHES "^x86_64-.*linux")
    message(FATAL_ERROR "Expected a Linux x86_64 Clang target; got '${CLANG_TARGET}'.\n${target_error}")
endif()
message(STATUS "Clang target: ${CLANG_TARGET}")
message(STATUS "RLC: ${RLC}")
message(STATUS "RLC test runner: ${RLC_TEST}")
message(STATUS "RLC trace runner: ${RLC_ACTION}")
message(STATUS "RLC standard library: ${RLC_STDLIB}")
message(STATUS "RLC fuzzer adapter: ${FUZZ_ADAPTER}")

# ==========================================================
# 2. Keep all generated files inside the selected build directory.
# ==========================================================
# Use CMake's built-in path variables.
# CMAKE_CURRENT_SOURCE_DIR is the current CMake source directory.
# CMAKE_CURRENT_BINARY_DIR is the current CMake build directory.
set(SRC "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD "${CMAKE_CURRENT_BINARY_DIR}")

set(RESULT_DIR "${BUILD}/result")
set(TEMP_DIR "${BUILD}/temp")
set(FUZZ_TEMP "${TEMP_DIR}/fuzzer")
set(TEST_TEMP "${TEMP_DIR}/test")
set(ASAN_TEMP "${TEMP_DIR}/Sanitizer")

# Create these directories during configuration.
# libFuzzer uses corpus and artifacts as test data directories.
file(MAKE_DIRECTORY
    "${RESULT_DIR}"
    "${FUZZ_TEMP}/corpus"
    "${FUZZ_TEMP}/artifacts"
    "${TEST_TEMP}"
    "${ASAN_TEMP}/corpus"
    "${ASAN_TEMP}/artifacts"
)

# Project source files
set(GAME_SOURCE "${SRC}/game.rl")
set(GAME_MAIN_SOURCE "${SRC}/game_main.rl")
set(TEST_SOURCE "${SRC}/game_test.rl")
set(FUZZ_SOURCE "${SRC}/game_fuzz.rl")
set(HELPER "${SRC}/cmake/rulebook_game.cmake")

# Store executables in this build directory, avoiding copied platform binaries.
set(GAME_BIN "${RESULT_DIR}/game")
set(FUZZ_BIN "${RESULT_DIR}/game_fuzzer")

# ==========================================================
# Optional RLC invocation monitor
# ==========================================================
# An experiment launcher can route every RLC invocation through a logging
# wrapper. RLC_MONITOR_WRAPPER and RLC_MONITOR_LOG_DIR, given as environment or
# cache variables, enable it. Once enabled, it stays enabled for this build
# directory; -DRLC_MONITOR_ENABLED=OFF disables it. RLC_ENTRY is the command
# that invokes RLC: the real compiler, or the rlc-monitored launcher.
set(RLC_MONITORED "${BUILD}/rlc-monitored")
set(RLC_ENTRY "${RLC}")

# Return a monitor setting: the cache value first, else the environment value.
function(rlc_monitor_setting name result)
    set(value "$CACHE{${name}}")
    set(from_env "$ENV{${name}}")
    if(NOT value STREQUAL "" AND NOT from_env STREQUAL "")
        get_filename_component(value_real "${value}" REALPATH)
        get_filename_component(from_env_real "${from_env}" REALPATH)
        if(NOT value_real STREQUAL from_env_real)
            message(FATAL_ERROR
                "${name} is '${value}' in the CMake cache but '${from_env}' in the "
                "environment. Configure a new build directory to change it.")
        endif()
    elseif(value STREQUAL "")
        set(value "${from_env}")
    endif()
    if(NOT value STREQUAL "" AND NOT IS_ABSOLUTE "${value}")
        message(FATAL_ERROR "${name} must be an absolute path: ${value}")
    endif()
    set(${result} "${value}" PARENT_SCOPE)
endfunction()

if(DEFINED CACHE{RLC_MONITOR_ENABLED} AND NOT RLC_MONITOR_ENABLED)
    set(RLC_MONITOR OFF)
    message(STATUS "RLC monitor: disabled (RLC_MONITOR_ENABLED=OFF in the cache; "
        "RLC_MONITOR_* environment variables are ignored)")
else()
    rlc_monitor_setting(RLC_MONITOR_WRAPPER RLC_MONITOR_WRAPPER_VALUE)
    rlc_monitor_setting(RLC_MONITOR_LOG_DIR RLC_MONITOR_LOG_DIR_VALUE)
    if(RLC_MONITOR_ENABLED)
        # Enabled by an earlier configuration of this build directory.
        if(RLC_MONITOR_WRAPPER_VALUE STREQUAL "" OR RLC_MONITOR_LOG_DIR_VALUE STREQUAL "")
            message(FATAL_ERROR
                "RLC_MONITOR_ENABLED is ON in this build directory, but RLC_MONITOR_WRAPPER "
                "and RLC_MONITOR_LOG_DIR are not both set in the cache or the environment.")
        endif()
        set(RLC_MONITOR ON)
    elseif(RLC_MONITOR_WRAPPER_VALUE STREQUAL "" AND RLC_MONITOR_LOG_DIR_VALUE STREQUAL "")
        set(RLC_MONITOR OFF)
        message(STATUS "RLC monitor: disabled")
    elseif(RLC_MONITOR_WRAPPER_VALUE STREQUAL "" OR RLC_MONITOR_LOG_DIR_VALUE STREQUAL "")
        message(FATAL_ERROR
            "Set both RLC_MONITOR_WRAPPER and RLC_MONITOR_LOG_DIR to enable the RLC monitor, "
            "or neither of them.")
    else()
        set(RLC_MONITOR ON)
    endif()
endif()

if(RLC_MONITOR)
    if(NOT EXISTS "${RLC_MONITOR_WRAPPER_VALUE}" OR IS_DIRECTORY "${RLC_MONITOR_WRAPPER_VALUE}")
        message(FATAL_ERROR "RLC monitor wrapper not found: ${RLC_MONITOR_WRAPPER_VALUE}")
    endif()
    find_program(RLC_MONITOR_PYTHON NAMES python3 PATHS "${CONDA_BIN}" NO_DEFAULT_PATH)
    if(NOT RLC_MONITOR_PYTHON)
        message(FATAL_ERROR "The RLC monitor needs python3 in ${CONDA_BIN}.")
    endif()
    execute_process(
        COMMAND "${RLC_MONITOR_PYTHON}" -c "import sys; sys.exit(sys.version_info < (3, 9))"
        RESULT_VARIABLE python_result OUTPUT_QUIET ERROR_QUIET)
    if(NOT python_result EQUAL 0)
        message(FATAL_ERROR "The RLC monitor needs Python 3.9 or newer: ${RLC_MONITOR_PYTHON}")
    endif()
    if(NOT IS_DIRECTORY "${RLC_MONITOR_LOG_DIR_VALUE}")
        message(FATAL_ERROR "RLC monitor log directory not found: ${RLC_MONITOR_LOG_DIR_VALUE}")
    endif()
    string(RANDOM LENGTH 16 probe_suffix)
    set(probe "${RLC_MONITOR_LOG_DIR_VALUE}/.rlc_monitor_configure_probe_${probe_suffix}")
    execute_process(COMMAND "${CMAKE_COMMAND}" -E touch "${probe}"
        RESULT_VARIABLE probe_result OUTPUT_QUIET ERROR_QUIET)
    file(REMOVE "${probe}")
    if(NOT probe_result EQUAL 0)
        message(FATAL_ERROR "RLC monitor log directory is not writable: ${RLC_MONITOR_LOG_DIR_VALUE}")
    endif()

    set(RLC_MONITOR_ENABLED ON CACHE BOOL "Route RLC invocations through the monitor." FORCE)
    set(RLC_MONITOR_WRAPPER "${RLC_MONITOR_WRAPPER_VALUE}" CACHE FILEPATH
        "RLC monitor wrapper script." FORCE)
    set(RLC_MONITOR_LOG_DIR "${RLC_MONITOR_LOG_DIR_VALUE}" CACHE PATH
        "RLC monitor log directory." FORCE)

    # -I keeps the caller's PYTHON* variables from affecting the wrapper; the
    # compiler still receives the unchanged environment.
    string(REPLACE "'" "'\\''" python_shell "${RLC_MONITOR_PYTHON}")
    string(REPLACE "'" "'\\''" wrapper_shell "${RLC_MONITOR_WRAPPER_VALUE}")
    string(REPLACE "'" "'\\''" real_rlc_shell "${RLC}")
    string(REPLACE "'" "'\\''" log_dir_shell "${RLC_MONITOR_LOG_DIR_VALUE}")
    string(REPLACE "'" "'\\''" source_shell "${CMAKE_CURRENT_SOURCE_DIR}")
    file(WRITE "${RLC_MONITORED}"
        "#!/bin/sh\nexec '${python_shell}' -I '${wrapper_shell}' --real-rlc '${real_rlc_shell}' "
        "--log-dir '${log_dir_shell}' --project-root '${source_shell}' -- \"$@\"\n")
    file(CHMOD "${RLC_MONITORED}" PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
    set(RLC_ENTRY "${RLC_MONITORED}")
    message(STATUS "RLC monitor: enabled (wrapper=${RLC_MONITOR_WRAPPER_VALUE}, "
        "log dir=${RLC_MONITOR_LOG_DIR_VALUE})")
else()
    file(REMOVE "${RLC_MONITORED}")
endif()

# Python CLI tools also compile/link through RLC. A launcher selects the same
# Clang for them without the CLI's space-splitting --extra-rlc-args option.
# It runs RLC_ENTRY, so these calls are monitored too when the monitor is on.
string(REPLACE "'" "'\\''" RLC_SHELL "${RLC_ENTRY}")
string(REPLACE "'" "'\\''" CLANG_SHELL "${CLANG}")
set(RLC_DRIVER "${BUILD}/rlc-with-clang")
file(WRITE "${RLC_DRIVER}"
    "#!/bin/sh\nexec '${RLC_SHELL}' '--clang=${CLANG_SHELL}' \"$@\"\n")
file(CHMOD "${RLC_DRIVER}" PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

# ==========================================================
# 3. Build the regular game executable (game_main.rl -> build_cmake/result/game)
# ==========================================================
# Select the same Conda Clang for the executable and Python CLI builds.
# Define how to build a specific output file.
# OUTPUT specifies the executable under this build directory.
# COMMAND is the command to run.
# DEPENDS lists build inputs so Ninja knows to rebuild the executable when the source files change.
# If the files are unchanged and the output still exists, a rebuild is usually unnecessary.
# This is an incremental build.
# WORKING_DIRECTORY is the current directory when the command runs.
# COMMENT is the description shown during the build.
# VERBATIM handles command argument escaping and quoting. CMake recommends keeping it for custom builds.
add_custom_command(
    OUTPUT "${GAME_BIN}"
    COMMAND "${RLC_ENTRY}" "${GAME_MAIN_SOURCE}" "--clang=${CLANG}" -g -o "${GAME_BIN}"
    DEPENDS "${GAME_MAIN_SOURCE}" "${GAME_SOURCE}" "${RLC}" "${CLANG}"
    WORKING_DIRECTORY "${SRC}"
    COMMENT "Build the game executable"
    VERBATIM
)

# Name the build target so users can select it by name.
# 
add_custom_target(game_build ALL DEPENDS "${GAME_BIN}")

# ==========================================================
# 4. Build the Fuzzer with RLC's built-in --fuzzer mode and Conda LLVM 22
# ==========================================================
# game.raw.ll is the raw LLVM IR generated by RLC and stored in temp/fuzzer.
set(RAW_IR "${FUZZ_TEMP}/game.raw.ll")
# ASan-instrumented IR and object files go in temp/Sanitizer. game.asan.ll contains the instrumented LLVM IR.
set(ASAN_IR "${ASAN_TEMP}/game.asan.ll")
# game.asan.o is the object file containing the compiled machine code.
set(ASAN_OBJ "${ASAN_TEMP}/game.asan.o")

add_custom_command(
    OUTPUT "${FUZZ_BIN}"

    # Step 1. Generate LLVM IR using RLC's built-in --fuzzer option.
    # The helper captures RLC standard output with OUTPUT_FILE, without shell > redirection.
    COMMAND "${CMAKE_COMMAND}"
        "-DMODE=ir"
        "-DRLC=${RLC_ENTRY}"
        "-DSOURCE=${FUZZ_SOURCE}"
        "-DINCLUDE_DIR=${SRC}"
        "-DOUTPUT=${RAW_IR}"
        -P "${HELPER}"

    # Step 2. Add AddressSanitizer instrumentation.
    COMMAND "${LLVM_OPT}"
        -S -passes=forceattrs,asan
        -force-attribute=sanitize_address
        "${RAW_IR}" -o "${ASAN_IR}"

    # Step 3. Compile the LLVM IR to a .o object file.
    COMMAND "${CLANG}"
        -g -O0 -fno-omit-frame-pointer
        -c "${ASAN_IR}" -o "${ASAN_OBJ}"

    # Step 4. Link the LLVM libFuzzer runtime and the RLC adapter library.
    COMMAND "${CLANG}"
        -g
        -fsanitize=fuzzer,address
        "${ASAN_OBJ}" "${FUZZ_ADAPTER}"
        -o "${FUZZ_BIN}"

    # DEPENDS rebuilds the Fuzzer when the game source, Fuzzer entry point, or helper script changes.
    # BYPRODUCTS lists the three intermediate files this command produces alongside the main output game_fuzzer.
    DEPENDS "${GAME_SOURCE}" "${FUZZ_SOURCE}" "${HELPER}"
        "${RLC}" "${LLVM_OPT}" "${CLANG}" "${FUZZ_ADAPTER}"
    BYPRODUCTS "${RAW_IR}" "${ASAN_IR}" "${ASAN_OBJ}"
    WORKING_DIRECTORY "${SRC}"
    COMMENT "Build the RLC Fuzzer with ASan instrumentation"
    VERBATIM
)
add_custom_target(fuzzer_build ALL DEPENDS "${FUZZ_BIN}")

# ==========================================================
# 5. CTest suite: game, unit, short ASan, and fuzzer tests
# ==========================================================
# Test 1 passes when the game's main() returns 0.
add_test(NAME game_test COMMAND "${GAME_BIN}")

# Test 2 runs rlc-test and writes its output to temp/test/unit_test.log.
add_test(NAME unit_test
    COMMAND "${CMAKE_COMMAND}"
        "-DMODE=unit"
        "-DRLC_TEST=${RLC_TEST}"
        "-DRLC=${RLC_DRIVER}"
        "-DRLC_STDLIB=${RLC_STDLIB}"
        "-DSOURCE=${TEST_SOURCE}"
        "-DSOURCE_DIR=${SRC}"
        "-DOUTPUT=${TEST_TEMP}/unit_test.log"
        -P "${HELPER}"
)

# Test 3 uses the same ASan-instrumented fuzzer for a short 100-run test.
add_test(NAME sanitizer_test
    COMMAND "${FUZZ_BIN}"
        -runs=100 -seed=418 -max_len=256 -timeout=5
        "-artifact_prefix=${ASAN_TEMP}/artifacts/"
        "${ASAN_TEMP}/corpus"
)

# Test 4 performs 10,000 runs of coverage-guided fuzzing with a separate corpus.
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

# Test 5 discovers and replays the action traces at test time.
add_test(NAME trace_test
    COMMAND "${CMAKE_COMMAND}"
        "-DMODE=trace"
        "-DRLC_ACTION=${RLC_ACTION}"
        "-DRLC=${RLC_DRIVER}"
        "-DRLC_STDLIB=${RLC_STDLIB}"
        "-DSOURCE=${GAME_SOURCE}"
        "-DSOURCE_DIR=${SRC}"
        "-DTRACE_DIR=${SRC}/traces"
        "-DLOG_DIR=${TEST_TEMP}/traces"
        -P "${HELPER}"
)
# The runner times out each replay independently of the number of traces.
set_tests_properties(trace_test PROPERTIES TIMEOUT 0)

# ==========================================================
# 6. Build and run all tests with one command
# ==========================================================
# CMAKE_CTEST_COMMAND points to the CTest executable.
# --output-on-failure shows output from failed tests.
# --output-log saves CTest output to a log file.
# WORKING_DIRECTORY sets the directory from which CTest runs.
# USES_TERMINAL gives the build command access to the terminal so test progress is visible.
add_custom_target(verify_all
    COMMAND "${CMAKE_CTEST_COMMAND}"
        --output-on-failure
        --output-log "${TEST_TEMP}/ctest.log"
    WORKING_DIRECTORY "${BUILD}"
    COMMENT "Run all game tests"
    USES_TERMINAL
    VERBATIM
)
# verify_all must complete game_build and fuzzer_build before running the tests.
add_dependencies(verify_all game_build fuzzer_build)

message(STATUS "RulebookGame configuration complete")
message(STATUS "Final executables are in ${RESULT_DIR}")
message(STATUS "Build and test intermediate files are in ${TEMP_DIR}")
