
# CMake runs this script with cmake -P. No separate invocation is needed.
# MODE=ir   : Generate LLVM IR with RLC's built-in Fuzzer mode.
# MODE=unit : Run RLC unit tests and save the output.

if(NOT DEFINED MODE)
    message(FATAL_ERROR "Missing MODE argument")
endif()

if(MODE STREQUAL "ir")
    # Write RLC's --ir output to the specified file without shell > redirection.
    # MODE=ir generates LLVM IR.
    # OUTPUT_FILE captures RLC standard output, which contains the LLVM IR.
    # ERROR_VARIABLE:	RLC error output
    # RESULT_VARIABLE   	RLC exit status
    execute_process(
        COMMAND "${RLC}" "${SOURCE}"
            -i "${INCLUDE_DIR}"
            -g --fuzzer --compile --ir
        OUTPUT_FILE "${OUTPUT}"
        ERROR_VARIABLE ERROR_MSG
        RESULT_VARIABLE RESULT
    )

    # Check for compilation failure.
    if(NOT "${RESULT}" STREQUAL "0")
        file(REMOVE "${OUTPUT}")
        message(FATAL_ERROR "RLC failed to generate LLVM IR.\n${ERROR_MSG}")
    endif()

    if(NOT EXISTS "${OUTPUT}")
        message(FATAL_ERROR "RLC did not generate the LLVM IR file at ${OUTPUT}")
    endif()

    # Also check for empty IR because an RLC link failure previously left an empty executable.
    file(SIZE "${OUTPUT}" IR_SIZE)
    if(IR_SIZE EQUAL 0)
        message(FATAL_ERROR "RLC generated an empty LLVM IR file at ${OUTPUT}")
    endif()

elseif(MODE STREQUAL "unit")
    # Run Rulebook unit tests and log stdout and stderr in temp/test.
    # Equivalent to running    rlc-test game_test.rl
    # TEST_STDOUT captures standard output.
    # TEST_STDERR captures standard error.
    # TEST_RESULT stores the exit status.
    execute_process(
        COMMAND "${RLC_TEST}" "${SOURCE}"
        WORKING_DIRECTORY "${SOURCE_DIR}"
        OUTPUT_VARIABLE TEST_STDOUT
        ERROR_VARIABLE TEST_STDERR
        RESULT_VARIABLE TEST_RESULT
    )
    # Write the results to build_cmake/temp/test/unit_test.log.
    file(WRITE "${OUTPUT}" "${TEST_STDOUT}${TEST_STDERR}")

    if(NOT "${TEST_RESULT}" STREQUAL "0")
        message(FATAL_ERROR
            "Rulebook unit tests failed.\n${TEST_STDOUT}\n${TEST_STDERR}")
    endif()

    message(STATUS "Unit tests passed. See the log at ${OUTPUT}")

else()
    message(FATAL_ERROR "Unsupported MODE ${MODE}")
endif()
