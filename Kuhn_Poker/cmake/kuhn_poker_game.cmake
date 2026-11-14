
# The build invokes this helper with cmake -P.
# MODE=ir   : Generate LLVM IR using RLC's built-in fuzzer mode.
# MODE=unit : Run the RLC unit tests and save their output.

if(NOT DEFINED MODE)
    message(FATAL_ERROR "Missing MODE argument")
endif()

if(MODE STREQUAL "ir")
    # Write RLC's --ir output directly to the specified file in place of shell redirection.
    # MODE=ir generates LLVM IR.
    # OUTPUT_FILE captures RLC's LLVM IR from standard output.
    # ERROR_VARIABLE captures RLC's error output.
    # RESULT_VARIABLE captures RLC's exit status.
    execute_process(
        COMMAND "${RLC}" "${SOURCE}"
            -i "${INCLUDE_DIR}"
            -g --fuzzer --compile --ir
        OUTPUT_FILE "${OUTPUT}"
        ERROR_VARIABLE ERROR_MSG
        RESULT_VARIABLE RESULT
    )

    # Check for a compilation failure.
    if(NOT "${RESULT}" STREQUAL "0")
        file(REMOVE "${OUTPUT}")
        message(FATAL_ERROR "RLC failed to generate LLVM IR:\n${ERROR_MSG}")
    endif()

    if(NOT EXISTS "${OUTPUT}")
        message(FATAL_ERROR "RLC did not generate LLVM IR: ${OUTPUT}")
    endif()

    # Check that the IR file is nonempty. An earlier RLC link failure left an empty executable.
    file(SIZE "${OUTPUT}" IR_SIZE)
    if(IR_SIZE EQUAL 0)
        message(FATAL_ERROR "RLC generated an empty LLVM IR file: ${OUTPUT}")
    endif()

elseif(MODE STREQUAL "unit")
    # Run the Rulebook unit tests and log stdout and stderr in temp/test.
    # Equivalent to running rlc-test kuhn_poker_test.rl.
    # TEST_STDOUT captures standard output.
    # TEST_STDERR captures standard error.
    # TEST_RESULT captures the exit status.
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
            "Rulebook unit tests failed:\n${TEST_STDOUT}\n${TEST_STDERR}")
    endif()

    message(STATUS "Unit tests passed. Log: ${OUTPUT}")

elseif(MODE STREQUAL "trace")
    # Replay a fixed action trace and compare its final state.
    if(NOT EXISTS "${TRACE_FILE}" OR NOT EXISTS "${EXPECTED_FILE}")
        message(FATAL_ERROR "Missing trace or expected state file")
    endif()

    execute_process(
        COMMAND "${RLC_ACTION}" "${SOURCE}" "${TRACE_FILE}"
            --rlc "${RLC}"
        WORKING_DIRECTORY "${SOURCE_DIR}"
        OUTPUT_VARIABLE TRACE_STDOUT
        ERROR_VARIABLE TRACE_STDERR
        RESULT_VARIABLE TRACE_RESULT
        TIMEOUT 60
    )

    file(WRITE "${OUTPUT}" "${TRACE_STDOUT}\n${TRACE_STDERR}")

    if(NOT "${TRACE_RESULT}" STREQUAL "0")
        message(FATAL_ERROR
            "Trace execution failed:\n${TRACE_STDOUT}\n${TRACE_STDERR}")
    endif()

    # Some tool versions may report invalid actions without a nonzero exit code.
    if("${TRACE_STDOUT}\n${TRACE_STDERR}" MATCHES
       "Cannot parse the following action|Cannot apply|Invalid action")
        message(FATAL_ERROR
            "Invalid action in trace:\n${TRACE_STDOUT}\n${TRACE_STDERR}")
    endif()

    file(READ "${EXPECTED_FILE}" EXPECTED_STATE)
    string(STRIP "${EXPECTED_STATE}" EXPECTED_STATE)
    string(STRIP "${TRACE_STDOUT}" TRACE_STDOUT)

    # The observed rlc-action output ends with a single-line serialized state.
    string(REGEX MATCH "[^\r\n]+$" ACTUAL_STATE "${TRACE_STDOUT}")
    string(STRIP "${ACTUAL_STATE}" ACTUAL_STATE)

    if("${EXPECTED_STATE}" STREQUAL "" OR
       NOT "${ACTUAL_STATE}" STREQUAL "${EXPECTED_STATE}")
        message(FATAL_ERROR
            "Unexpected final state:\nExpected: ${EXPECTED_STATE}\nActual: ${ACTUAL_STATE}\nLog: ${OUTPUT}")
    endif()

    message(STATUS "Trace test passed. Log: ${OUTPUT}")

else()
    message(FATAL_ERROR "Unsupported MODE: ${MODE}")
endif()
