
# CMake runs this script with cmake -P. No separate invocation is needed.
# MODE=ir   : Generate LLVM IR with RLC's built-in Fuzzer mode.
# MODE=unit : Run RLC unit tests and save the output.
# MODE=trace: Replay action traces and compare their final states.

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

elseif(MODE STREQUAL "trace")
    cmake_policy(SET CMP0054 NEW)
    file(GLOB trace_files LIST_DIRECTORIES false RELATIVE "${TRACE_DIR}"
        "${TRACE_DIR}/*.trace.txt")
    # CMake globs case-insensitively on macOS.
    list(FILTER trace_files INCLUDE REGEX "\\.trace\\.txt$")
    if(NOT trace_files)
        message(FATAL_ERROR "No *.trace.txt files found in ${TRACE_DIR}")
    endif()

    find_program(RLC_ACTION NAMES rlc-action PATHS "${CONDA_BIN}" NO_DEFAULT_PATH)
    file(MAKE_DIRECTORY "${LOG_DIR}")
    foreach(trace_file IN LISTS trace_files)
        string(REGEX REPLACE "\\.trace\\.txt$" "" trace_name "${trace_file}")
        set(expected_file "${TRACE_DIR}/${trace_name}.expected.txt")
        set(log_file "${LOG_DIR}/${trace_name}.log")
        set(log "Trace: ${TRACE_DIR}/${trace_file}\nExpected state file: ${expected_file}\n")
        set(failure "")

        execute_process(
            COMMAND "${CMAKE_COMMAND}" -E cat "${expected_file}"
            OUTPUT_VARIABLE expected_state ERROR_VARIABLE read_error
            RESULT_VARIABLE read_result TIMEOUT 5
        )
        if(NOT "${read_result}" STREQUAL "0")
            set(failure "Could not read expected state file (${read_result}): ${expected_file}\n${read_error}")
        elseif(NOT RLC_ACTION)
            set(failure "rlc-action was not found in ${CONDA_BIN}")
        else()
            execute_process(
                COMMAND "${RLC_ACTION}" "${SOURCE}" "${TRACE_DIR}/${trace_file}" --rlc "${RLC}"
                WORKING_DIRECTORY "${SOURCE_DIR}"
                OUTPUT_VARIABLE trace_stdout ERROR_VARIABLE trace_stderr
                RESULT_VARIABLE trace_result TIMEOUT 60
            )
            string(APPEND log "rlc-action result: ${trace_result}\n"
                "\nstdout:\n${trace_stdout}\n\nstderr:\n${trace_stderr}\n")

            string(STRIP "${expected_state}" expected_state)
            string(STRIP "${trace_stdout}" actual_state)
            # The final nonblank stdout line is the serialized state.
            string(REGEX MATCH "[^\r\n]+$" actual_state "${actual_state}")
            string(STRIP "${actual_state}" actual_state)

            if(NOT "${trace_result}" STREQUAL "0")
                set(failure "Trace replay failed (${trace_result})")
            # An action parse error can still produce a zero exit status.
            elseif("${trace_stdout}\n${trace_stderr}" MATCHES
                   "(^|[\r\n])(Cannot parse the following action:|Cannot apply the following action:|Invalid action)")
                set(failure "rlc-action reported an invalid action")
            elseif("${expected_state}" STREQUAL "" OR NOT "${actual_state}" STREQUAL "${expected_state}")
                set(failure "Unexpected final state.\nExpected: ${expected_state}\nActual: ${actual_state}")
            endif()
        endif()

        if(failure)
            file(WRITE "${log_file}" "${log}\nFAIL: ${failure}\n")
            message(SEND_ERROR "${trace_file}: ${failure}\nLog: ${log_file}")
        else()
            file(WRITE "${log_file}" "${log}\nPASS\n")
            message(STATUS "${trace_file} passed. Log: ${log_file}")
        endif()
    endforeach()

else()
    message(FATAL_ERROR "Unsupported MODE ${MODE}")
endif()
