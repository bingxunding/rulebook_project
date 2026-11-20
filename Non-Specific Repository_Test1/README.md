# Sushi Go! - Rulebook Game Repository

This repository implements the supplied 2014 Sushi Go! rules for two to five
players, including three rounds, the complete 108-card supply, simultaneous
selection, passing, chopsticks, wasabi, all scoring, pudding retention, and the
pudding tiebreaker. Both printed variants are available: Pass Both Ways and the
two-human game with a third dummy scoring player.

## Requirements

Use native Apple Silicon macOS, the Xcode Command Line Tools/macOS SDK, and a
Conda environment matching `environment.yml`: Python 3.11, CMake 4.4.3,
Ninja 1.13.2, LLVM/Clang 22.1.8, compiler-rt 22.1.8, zstd 1.5.7, and
`rl-language-core==0.4.18`. The Rulebook executable reports its embedded LLVM
version separately from the Conda LLVM tools.

```sh
conda env create -f environment.yml
conda activate rulebook
cmake -S . -B build_cmake -G Ninja
cmake --build build_cmake
cmake --build build_cmake --target verify_all
```

If an appropriate environment already exists, activate it and skip creation.
The build and environment files are unchanged copies of the source template.

To rerun the configured tests or one individual check:

```sh
ctest --test-dir build_cmake --output-on-failure
ctest --test-dir build_cmake --output-on-failure -R '^game_test$'
ctest --test-dir build_cmake --output-on-failure -R '^unit_test$'
ctest --test-dir build_cmake --output-on-failure -R '^sanitizer_test$'
ctest --test-dir build_cmake --output-on-failure -R '^fuzzer_test$'
ctest --test-dir build_cmake --output-on-failure -R '^trace_test$'
./result/game
```

`verify_all` builds both executables and runs all five checks. The ASan checks
use 100 and 10,000 fuzzer runs. `game_fuzz.rl` first parses arbitrary bytes using
`parse_actions` and checks `can apply` before applying actions. It also drives
a complete legal game from normalized byte choices so that fuzzing reaches
round scoring, every player count, both variants, and terminal states. It
asserts finite supply, live-round card conservation, hand bounds, wasabi
constraints, termination, and the existence of a winner.

## Actions and state

Start with `let state = play()` and call:

- `setup(humans, alternate, dummy, first_controller)`: two to five humans;
  `dummy=true` requires exactly two humans and creates scoring seat 2.
  `alternate=true` passes right in round 2 and left in rounds 1 and 3.
  `first_controller` is 0 for standard games, and 0 or 1 for dummy games.
- `deal(Card::Tempura)` and corresponding card types: deal the configured hand
  size to seat 0, then seat 1, and so on. A chance action can choose only a card
  remaining in the original supply. Stock persists across all three rounds.
- `pick(player, index, gift)`: commit one card using its zero-based hand index.
- `chopsticks(player, first, second, gift)`: commit two distinct indices in the
  declared order, spending one chopsticks card already face-up before the turn.

Every action must be checked using `can state.action(...)` before invocation.
Humans commit in numeric seat order, but no selected card reaches a tableau
until all humans have committed. Hands then pass. The last singleton is passed
and automatically revealed in standard games. In dummy games, the controller
draws the top dummy-pile card before each selection; `gift` must be a separate
index in that augmented hand. All other choices require `gift=-1`. The dummy
pile stays in place while only the two human hands switch. Its final turn still
requires a choice between the controller's two cards.

`state.table` is the full internal state for verification, including private
hands and committed cards. It is an omniscient rules-engine representation;
a client implementing hidden information must expose only its permitted view.
Chance actions enumerate possible shuffled deals without assigning probability
weights. A caller supplying random deals should sample remaining cards in
proportion to their stock counts. Every legal deal sequence is realizable by a
shuffle of the physical deck; discarded cards are never recycled.

Rounds are numbered 0 through 2 internally; terminal state has `round=3` and
`state.is_done() == true`. Each player's `score` is cumulative,
`last_round_score` excludes end-game pudding points, and `puddings` persists
across rounds. The final round tableau remains available for inspection.
`table.winners` identifies every winner after score and pudding comparison.

## Confirmed rule interpretations

The following outcome-relevant interpretations were confirmed for this project:

- Only positive maki totals can receive first- or second-place points.
- A paired selection resolves in declared order. Wasabi selected first can
  triple the nigiri selected second on that same turn. Reversing the order
  leaves that nigiri untripled unless an earlier unused wasabi exists.
- The dummy participates in maki and pudding scoring, including three-player
  pudding penalties, and can win. Each human can activate one previously
  collected chopsticks card per turn when enough distinct cards remain;
  the dummy itself does not activate chopsticks.
- Dummy control alternates continuously across all three rounds.

Point splits discard remainders, including negative pudding shares, whose
magnitudes are rounded down. All-equal puddings award nothing. A tie that
remains after the printed pudding tiebreaker is recorded as shared victory.

## Tests and traces

Unit tests cover independent scoring examples and thresholds, action legality,
choice/reveal timing, deck bounds, chopsticks, passing, round transitions,
all player counts, and dummy behavior. The executable replays the complete
legal game in `traces/game1.trace.txt` and checks scores 46 and 43, pudding
counts 2 and 3, the winner, and 48 remaining cards.

Each trace completes all three rounds. Expected files contain complete final
states calculated independently from card counts and the printed scoring
rules, rather than copied from executable output.

| Trace | Mode | Human players | Special coverage |
| --- | --- | --- | --- |
| game1 | Standard | 2 | No negative pudding points; chopsticks |
| game2 | Standard | 3 | Maki ties and pudding splits |
| game3 | Pass Both Ways | 4 | Right passing in round 2 |
| game4 | Pass Both Ways | 5 | Four-way maki tie; nearly exhausted deck |
| game5 | Dummy | 2 | Initial controller 0; dummy scoring and victory |
| game6 | Dummy | 2 | Initial controller 1; continuous alternating control |

```sh
rlc-action game.rl traces/game1.trace.txt --rlc "${CONDA_PREFIX}/bin/rlc"
```

Verification evidence is saved to:

- `build_cmake/temp/test/ctest.log`
- `build_cmake/temp/test/unit_test.log`
- `build_cmake/temp/test/traces/gameN.log`
- `build_cmake/Testing/Temporary/LastTest.log`

## Source structure and provenance

```text
.
|-- CMakeLists.txt
|-- README.md
|-- environment.yml
|-- game.rl
|-- game_main.rl
|-- game_test.rl
|-- game_fuzz.rl
|-- cmake/
|   `-- rulebook_game.cmake
`-- traces/
    |-- game1.trace.txt
    |-- game1.expected.txt
    `-- ... game6.trace.txt and game6.expected.txt
```

Build-generated `build_cmake/` and `result/` directories contain only derived
artifacts. Template instructions, input PDFs, and examples are read from the
source template and are not copied into this repository.

Template: https://github.com/bingxunding/rulebook_project/tree/main/Non-Specific%20Repository

Fetched source commit: `abbb8b067a14b80e503ed73401037a81dc4e0f1e`.
