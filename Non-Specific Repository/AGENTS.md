
# AGENTS.md

## Goal and Scope

Use the natural-language rules provided by the user to implement a Rulebook game that can be compiled and verified. Follow those rules and clarify any ambiguity that could affect game outcomes before proceeding.

The four `.rl` files currently contain a Kuhn Poker example. For a new game, replace their implementations as needed and keep their filenames and entry points. Preserve `CMakeLists.txt`, `cmake/`, and `environment.yml` as shared build and verification infrastructure. These guidelines define what agents may edit. The runtime environment controls file permissions.

## File Conventions

- `game.rl` implements game state, initialization, action order, action legality, end conditions, and scoring rules where applicable.
- `game_main.rl` loads the game with `import game` and defines `fun main() -> Int`. Run one reproducible legal playthrough and check its expected outcome. Return `0` on success and a nonzero value on failure.
- `game_test.rl` imports `game` and defines unit tests as `fun test_...() -> Bool` so `rlc-test` can discover them. Derive expected results directly from the rules. Cover the initial state, action order, legal and illegal actions, edge cases, end conditions, and scoring where applicable.
- `game_fuzz.rl` imports `game` and provides `fun fuzz(Vector<Byte> input)`. Follow the example by using `parse_actions` to turn bytes into actions, then check each action with `can apply` before applying it to exercise the new game's state transitions.

## Rulebook Development

- Follow the Action Function example in `game.rl`, such as `act play() -> Game`. Use `act` to declare actions, `actions:` to express alternatives at the same stage, and `frm` to store state across actions.
- Write preconditions in `{ ... }` after the action declaration. Use `can state.action(...)` to check whether an action is legal in the current state and `is_done()` to check whether the game has ended.
- Use the current example and the compiler and standard library versions specified by `environment.yml` as your baseline. Verify that any new syntax or API is supported before using it. For language features, see the [Rulebook Language Reference](https://rl-language.github.io/language-reference.html).

## Build and Verification

Run these commands from the template repository root. The toolchain targets Apple Silicon macOS and uses the macOS SDK and LLVM 22 from a Conda environment. Before building, activate a Conda environment with the required tools and dependencies. Any environment name is acceptable. See `environment.yml`.

```sh
cmake -S . -B build_cmake -G Ninja
cmake --build build_cmake --target verify_all
```

`verify_all` builds `result/game` and `result/game_fuzzer`, then runs `game_test`, `unit_test`, `sanitizer_test`, and `fuzzer_test`. For a standalone build or to diagnose a failure, start with the build command below, then select the relevant CTest case as needed.

```sh
cmake --build build_cmake
ctest --test-dir build_cmake --output-on-failure -R '^game_test$'
ctest --test-dir build_cmake --output-on-failure -R '^unit_test$'
ctest --test-dir build_cmake --output-on-failure -R '^sanitizer_test$'
ctest --test-dir build_cmake --output-on-failure -R '^fuzzer_test$'
```

`sanitizer_test` and `fuzzer_test` use the same fuzzer with AddressSanitizer instrumentation for 100 and 10,000 runs, respectively. The unit test log and the `verify_all` summary log are at `build_cmake/temp/test/unit_test.log` and `build_cmake/temp/test/ctest.log`, respectively.

## Failure Handling and Completion Criteria

- If compilation or a test fails, read the diagnostics and logs, identify the cause, and fix the game files. Rerun the failed checks and then `verify_all`. Do not delete tests, weaken assertions, or bypass checks to get a passing result. Report any environment issues.
- Before declaring completion, confirm that the code compiles, `verify_all` passes, and the unit test log shows that the intended cases ran. Report the results of each check, rule assumptions, and unresolved issues. Passing tests confirms only the checks that ran. Review the game behavior against each rule to assess semantic correctness.
