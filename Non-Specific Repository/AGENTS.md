
# AGENTS.md

## Goal and Scope

Use the natural-language rules provided by the user to implement a Rulebook game that can be compiled and verified. Follow those rules and clarify any ambiguity that could affect game outcomes before proceeding.
The game rules are provided as PDF files under `input/`, for example `input/rules.pdf`.

The Kuhn Poker example lives in `examples/kuhn_poker/`. Use it as a reference for new games. Generate the four `.rl` files listed below at the generated project root, using the specified filenames and entry points, and the trace and expected-state files under the generated project's root `traces/` directory. Also generate `README.md` at the generated project root. For game-generation tasks, edit only these generated files.

Copy the following files without modification from the `Non-Specific Repository/` template directory on the source repository's `main` branch:

- `Non-Specific Repository/CMakeLists.txt` to `<project-root>/CMakeLists.txt`.
- `Non-Specific Repository/cmake/rulebook_game.cmake` to `<project-root>/cmake/rulebook_game.cmake`.
- `Non-Specific Repository/environment.yml` to `<project-root>/environment.yml`.

Do not copy these files from `examples/kuhn_poker/` or any other example directory. The Kuhn Poker example is reference material for generating the game implementation, tests, and traces; it is not the source of the generated project's build or environment files.

Preserve the original template, including the example and `AGENTS.md`, without modification. These guidelines define what agents may edit. The runtime environment controls file permissions.

Read `AGENTS.md`, `input/`, and `examples/` from the source template; do not copy them into the generated project. All references to `input/` and `examples/` in these instructions refer to the source template.

The final source tree must contain exactly the following seven root files and two root source directories:

```text
<project-root>/
├── CMakeLists.txt
├── README.md
├── environment.yml
├── game.rl
├── game_main.rl
├── game_test.rl
├── game_fuzz.rl
├── cmake/
│   └── rulebook_game.cmake
└── traces/
    ├── game1.trace.txt
    ├── game1.expected.txt
    └── ...
```

The `traces/` directory must contain only complete `gameN.trace.txt` and `gameN.expected.txt` pairs. Determine the number of pairs according to the game and the testing coverage needed. Do not include other source files or directories. Files and directories automatically produced by configuration, building, and verification, including `build_cmake/`, `result/`, executables, logs, and fuzzing corpora, are permitted and excluded from these source-structure counts.

## File Conventions

- `game.rl` implements game state, initialization, action order, action legality, end conditions, and scoring rules where applicable.
- `game_main.rl` loads the game with `import game` and defines `fun main() -> Int`. Run one reproducible legal playthrough and check its expected outcome. Return `0` on success and a nonzero value on failure.
- `game_test.rl` imports `game` and defines unit tests as `fun test_...() -> Bool` so `rlc-test` can discover them. Derive expected results directly from the rules. Cover the initial state, action order, legal and illegal actions, edge cases, end conditions, and scoring where applicable.
- `game_fuzz.rl` imports `game` and provides `fun fuzz(Vector<Byte> input)`. Follow the example by using `parse_actions` to turn bytes into actions, then check each action with `can apply` before applying it to exercise the new game's state transitions.
- `README.md` describes the game, required environment, build and verification commands, and project structure in English.

## Rulebook Development

- Follow the Action Function example in `examples/kuhn_poker/kuhn_poker.rl`, such as `act play() -> Game`. Use `act` to declare actions, `actions:` to express alternatives at the same stage, and `frm` to store state across actions.
- Write preconditions in `{ ... }` after the action declaration. Use `can state.action(...)` to check whether an action is legal in the current state and `is_done()` to check whether the game has ended.
- Use the current example and the compiler and standard library versions specified by `environment.yml` as your baseline. Verify that any new syntax or API is supported before using it. For language features, see the [Rulebook Language Reference](https://rl-language.github.io/language-reference.html).

## Trace-Based Testing

- Refer to `examples/kuhn_poker/traces/game1.txt` and `examples/kuhn_poker/traces/game1.expected.txt` for the trace and expected-state formats. Do not copy the example's game-specific actions or states into another game.
- Generate at least one pair of files for the current game under the root `traces/` directory: `game1.trace.txt` and `game1.expected.txt`. Use `game2`, `game3`, and so on for additional pairs. Each trace must contain a legal sequence of actions from the initial state to a terminal state. Write traces by hand or use `rlc-random` to generate candidates and check them against the rules.
- Derive the complete expected final state from the game rules and save it as a single serialized line in the matching expected-state file. Do not use unverified program output as the expected state.
- Replay each trace with `rlc-action` and check the actual final state against the expected state. For example:

```sh
rlc-action game.rl traces/game1.trace.txt --rlc "${CONDA_PREFIX}/bin/rlc"
```

## Build and Verification

Once all four generated `.rl` files and the trace pairs are in place, run these commands from the repository root. The toolchain targets Apple Silicon macOS and uses the macOS SDK and LLVM 22 from a Conda environment. Before building, activate a Conda environment with the required tools and dependencies. Any environment name is acceptable. See `environment.yml`.

```sh
cmake -S . -B build_cmake -G Ninja
cmake --build build_cmake --target verify_all
```

`verify_all` builds `result/game` and `result/game_fuzzer`, then runs `game_test`, `unit_test`, `sanitizer_test`, `fuzzer_test`, and `trace_test`. For a standalone build or to diagnose a failure, start with the build command below, then select the relevant CTest case as needed.

```sh
cmake --build build_cmake
ctest --test-dir build_cmake --output-on-failure -R '^game_test$'
ctest --test-dir build_cmake --output-on-failure -R '^unit_test$'
ctest --test-dir build_cmake --output-on-failure -R '^sanitizer_test$'
ctest --test-dir build_cmake --output-on-failure -R '^fuzzer_test$'
ctest --test-dir build_cmake --output-on-failure -R '^trace_test$'
```

`sanitizer_test` and `fuzzer_test` use the same fuzzer with AddressSanitizer instrumentation for 100 and 10,000 runs, respectively. The unit test log and the `verify_all` summary log are at `build_cmake/temp/test/unit_test.log` and `build_cmake/temp/test/ctest.log`, respectively. `trace_test` discovers the trace pairs in the root `traces/` directory and saves each trace log to `build_cmake/temp/test/traces/<name>.log`.

## Failure Handling and Completion Criteria

- If compilation or a test fails, read the diagnostics and logs, identify the cause, and fix the game files or trace data as appropriate. Rerun the failed checks and then `verify_all`. Do not delete tests, change correct expected states, weaken assertions, or bypass checks to get a passing result. Report any environment issues.
- Before declaring completion, confirm that the code compiles, `verify_all` passes all five tests, and the unit test log and trace logs show that the intended cases ran. Report the results of each check, rule assumptions, and unresolved issues. Passing tests confirms only the checks that ran. Review the game behavior against each rule to assess semantic correctness.