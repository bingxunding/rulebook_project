# Hanabi - Specific Repository2

This Rulebook implementation models the cooperative card game Hanabi for two to five players, including all four optional variants in the supplied rulebook. Players give complete clues, discard to recover clue tokens, or play cards to build ascending fireworks. Three failed plays cause immediate defeat.

The source template was fetched from [`bingxunding/rulebook_project`](https://github.com/bingxunding/rulebook_project/tree/124dc38d7321c80a4f69067741e30ee1ecf18bbb/Non-Specific%20Repository), commit `124dc38d7321c80a4f69067741e30ee1ecf18bbb`. Its `AGENTS.md`, rulebook PDF, and Kuhn Poker example informed this implementation. The template's CMake files and `environment.yml` are copied unchanged; the template instructions, input PDF, and example are not included in this generated project.

## Environment and verification

Use native Apple Silicon macOS with the Xcode Command Line Tools and an available macOS SDK. The supplied environment pins Python 3.11, CMake 4.4.3, Ninja 1.13.2, zstd 1.5.7, LLVM/Clang/compiler-rt 22.1.8, and `rl-language-core` 0.4.18.

```sh
conda env create -f environment.yml
conda activate rulebook
cmake -S . -B build_cmake -G Ninja
cmake --build build_cmake
cmake --build build_cmake --target verify_all
```

If the environment already exists with the required versions, activate it directly. An environment name other than `rulebook` is supported. Keep it active for configuration, builds, tests, and trace replay.

`verify_all` builds both executables and runs all five configured CTest cases:

| Test | Purpose |
| --- | --- |
| `game_test` | Run the reproducible legal playthrough in `game_main.rl`. |
| `unit_test` | Discover and execute the `test_...` functions in `game_test.rl`. |
| `sanitizer_test` | Run the AddressSanitizer-instrumented fuzzer for 100 iterations. |
| `fuzzer_test` | Run the same fuzzer for 10,000 iterations with a separate corpus. |
| `trace_test` | Replay every complete trace pair and compare the entire serialized terminal state. |

To diagnose an individual case:

```sh
ctest --test-dir build_cmake --output-on-failure -R '^unit_test$'
```

Replace the expression with another test name to select that case. The complete suite can also be run with `ctest --test-dir build_cmake --output-on-failure` after building. Logs are written to `build_cmake/temp/test/unit_test.log`, `build_cmake/temp/test/ctest.log` by `verify_all`, and `build_cmake/temp/test/traces/gameN.log`. Generated executables are `result/game` and `result/game_fuzzer`; fuzzing corpora and intermediate files remain under `build_cmake/`.

## Game interface

Create a game with `play()`, then call `configure(players, first_player, variant, extended)`. Player identifiers are zero-based seats in clockwise order. The caller selects `first_player` using the rulebook's clothing convention. Two or three players receive five cards each; four or five receive four.

| `variant` | Deck and color-clue behavior |
| --- | --- |
| `0` | Base game: five suits, 50 cards. |
| `1` | Variant 1: ordinary, separately clueable sixth suit, 60 cards. |
| `2` | Variant 2: sixth suit has one copy of each rank, 55 cards. |
| `3` | Variant 3: full sixth suit matches every ordinary color clue; its own color cannot be named, 60 cards. |

Each ordinary full suit contains three ones, two twos, two threes, two fours, and one five. `extended = true` selects Variant 4 and can accompany any of the four modes. Color identifiers `0..5` mean white, red, blue, yellow, green, and multicolor. Ranks are `1` through `5`; hand slots are zero-based.

Complete setup with `deal_card(color, rank)` chance actions. These deal one card at a time, round-robin from seat zero, within the deck's remaining multiplicities. The model does not store a predetermined shuffled order: legal dealing and drawing choices represent every possible shuffled deck. Chance actions are engine operations, not additional player turns.

At a player decision, use one of the following:

```text
hint_color(actor, target, color)
hint_rank(actor, target, rank)
discard(actor, slot)
play_card(actor, slot)
```

The actor must be the current player. A clue targets another seated player, identifies one color or rank, and automatically marks every matching card. A clue with no matches, or without an available blue token, is illegal. Discarding is illegal when all eight blue tokens are available. A successful five recovers one token, capped at eight. Unsuccessful plays enter the discard pile and consume one fuse.

After a nonterminal discard or play, a replacement `draw_card(color, rank)` chance action is required when cards remain. No new player turn begins before that draw. `reorder(player, first, second)` swaps two of a seated player's cards, including their clue knowledge, freely during a decision stage; it does not consume a turn.

Query legality with `can`, and completion with `is_done()`, as in the supplied example. The engine's `table` state is privileged and contains hidden card identities. A player-facing integration must use `observe(table, viewer)`, which hides that viewer's own faces and the remaining deck multiplicities while showing teammates' hands and public information. Card knowledge uses color and rank candidate masks; complete clues update both matching and nonmatching cards. For Variant 3, a positive ordinary-color clue includes the sixth suit as a possibility.

## Endings and rule interpretations

A perfect display and the third failed play terminate immediately, before any replacement draw. Drawing the last card in modes without Variant 4 starts exactly one further turn for each player, including the player who drew it. Clues also count as turns in this final round. Hands shrink because no replacement cards remain.

The table's outcome codes are:

| Code | Meaning |
| --- | --- |
| `0` | Game active. |
| `1` | Every required firework completed. |
| `2` | Third fuse consumed. |
| `3` | Final round after deck exhaustion completed. |
| `4` | Variant 4 indispensable-card defeat. |

The score is the sum of the active fireworks' top ranks, with a maximum of 25 in the base game and 30 with the sixth suit. The PDF's scoring paragraph says "six" while its base setup and example use five; the implementation sums only the suits enabled by the selected mode. As confirmed for this project, the pile total is retained on defeat and the outcome records the loss separately. The printed artistic-impression scale applies to the base game; sixth-suit modes retain their raw total without inventing additional scale categories.

Variant 4 disables the deck-exhaustion ending and the artistic-impression rating. Play continues until perfect completion or defeat, with potentially smaller hands. An indispensable card is the last remaining copy of a rank still needed above its suit's current top. Losing that copy by discarding or a failed play causes immediate defeat. Copies of ranks already built are dispensable.

These conventions model mechanical legality and explicit clues. Clothing selection and the rulebook's restrictions on informal conversation remain responsibilities of the caller and players.

## Project structure

```text
Specific Repository2/
  CMakeLists.txt
  README.md
  environment.yml
  game.rl
  game_main.rl
  game_test.rl
  game_fuzz.rl
  cmake/
    rulebook_game.cmake
  traces/
    game1.trace.txt
    game1.expected.txt
    ...
```

`game.rl` defines the state, actions, observations, endings, and scoring. `game_main.rl` runs a deterministic legal game and checks its result. `game_test.rl` contains 39 rule-derived unit tests. `game_fuzz.rl` parses input bytes with `parse_actions`, checks each candidate with `can apply`, and applies only legal actions. It also guides legal play from the input bytes to reach decisions within the configured input-size limit, checking card conservation, clue knowledge, score consistency, token bounds, and player observations after transitions.

The `traces/` directory contains ten numbered trace/expected-state pairs. Each trace is a complete legal game; each expected file contains its full terminal state as a single serialized line. Expected states were calculated with an independent rules model and conservation checks before replay comparison.

| Trace | Scenario |
| --- | --- |
| `game1` | Base fuse defeat with score one retained; matches the main playthrough. |
| `game2` | Five players, starting at seat three: deck exhaustion and exactly five further turns. |
| `game3` | Perfect base game, score 25. |
| `game4` | Perfect Variant 1 game, score 30. |
| `game5` | Variant 1 sixth-suit clue, rank clue, reordering, and fuse defeat. |
| `game6` | Variants 2 and 4: indispensable singleton-card discard. |
| `game7` | Variant 3 wild-color clue intersections, rank clue, reordering, and fuse defeat. |
| `game8` | Variant 4 continues beyond an empty deck and a full further round, then loses an indispensable card. |
| `game9` | Two players, starting at seat one: deck exhaustion and exactly two further turns. |
| `game10` | Perfect Variant 2 game, score 30. |

To replay an individual trace directly:

```sh
rlc-action game.rl traces/game1.trace.txt --rlc "${CONDA_PREFIX}/bin/rlc"
```

Configuration, build, test logs, executables, and fuzzing corpora are generated artifacts, excluded from the prescribed source-tree counts.
