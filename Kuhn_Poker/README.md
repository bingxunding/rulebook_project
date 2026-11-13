-------------------------------------------------------------------------------------
ENGLISH VERSION
-------------------------------------------------------------------------------------
# Kuhn Poker (Rulebook)
Kuhn Poker implemented in Rulebook, using CMake to build the game example and a libFuzzer program with AddressSanitizer (ASan), and CTest to run tests automatically, including trace-based testing with `rlc-action`.

## Build and Test
Run the following commands in the `Kuhn_Poker` directory. For first-time setup, complete [Environment Setup](#environment-setup) below first.

```sh
conda activate rulebook
cmake -S . -B build_cmake -G Ninja
cmake --build build_cmake
ctest --test-dir build_cmake --output-on-failure
```

After Configure completes, you can also build and run all tests with one command:
```sh
cmake --build build_cmake --target verify_all
```
Successful execution displays `100% tests passed` out of 5 tests. CTest does not build programs automatically, so run Build before Test after changing the source; `verify_all` performs both in sequence.

## Environment Setup
The current setup supports **Apple Silicon macOS (native arm64)** and requires Git, Conda, and the macOS SDK. Install Conda by following the [official Miniforge instructions](https://github.com/conda-forge/miniforge). If neither Xcode nor Command Line Tools is installed, run the following command and wait for the system installation to finish:
```sh
xcode-select --install
```

Clone the repository, enter the project subdirectory, and create the environment:
```sh
git clone https://github.com/bingxunding/rulebook_project.git
cd rulebook_project/Kuhn_Poker
conda env create --file environment.yml
conda activate rulebook
```

If you already have a `rulebook` environment that meets the requirements, activate it without creating it again. Then run the build and test commands above.
[environment.yml](environment.yml) pins the key dependencies: Python 3.11, `rl-language-core` 0.4.18, external Clang/LLVM 22.1.8, CMake 4.4.3, Ninja 1.13.2, and zstd 1.5.7. RLC's bundled backend uses LLVM 21.1.3; CMake locates external tools in the active Conda environment.
Building and testing have been verified in an existing environment with these versions. The environment file is not a complete lock file, and a fresh Conda environment was not recreated for this verification.

## Test Coverage
CTest registers 5 tests, with `unit_test` running 10 unit test functions internally.

| Test | Description |
| --- | --- |
| `game_test` | Runs the fixed bet-and-fold example and checks the exit code |
| `unit_test` | Covers 6 deals × 5 terminal action sequences, totaling 30 games, and checks card input bounds and action order |
| `sanitizer_test` | Runs the fuzzer with ASan for 100 runs |
| `fuzzer_test` | Runs the same fuzzer with ASan for 10,000 runs |
| `trace_test` | Replays a fixed game trace with `rlc-action` and compares the final state with the expected state |

Both fuzz tests use the same program, with separate storage for their corpora and inputs that trigger errors. Unit tests currently run through `rlc-test`, which temporarily compiles `.rl` files internally.
Run unit tests separately, or display detailed fuzz test output:
```sh
ctest --test-dir build_cmake -R '^unit_test$' --output-on-failure
ctest --test-dir build_cmake -R '^fuzzer_test$' -V
```

## Trace-Based Testing
`trace_test` uses `rlc-action` to replay a fixed sequence of game actions and compare the resulting final state with an independently checked expected state. It is registered in CTest and runs automatically as part of `verify_all`.

### Trace and Expected State
The fixed action sequence is stored in `traces/game1.txt`:

```text
# game 0
deal {card1: J, card2: Q}
p0_bet {}
p1_fold {}
```

Player 0 receives J and Player 1 receives Q. Player 0 bets one chip, and Player 1 folds. Player 0 wins despite holding the lower card.

The expected final state is stored in `traces/game1.expected.txt` as a single line:

```text
{resume_index: -1, player0: {contribution: 2, card: 0, reward: 1}, player1: {contribution: 1, card: 1, reward: -1}, init_pot: 2, now_pot: 3, is_p1_bet: false, winner: 0}
```

This expected state is checked against the game rules: the initial pot is 2, the final recorded pot is 3, Player 0 wins with a net reward of +1, Player 1 loses 1, and the game terminates (`resume_index: -1`).

### Run the Trace Test
Run the trace test separately, or replay the trace manually:

```sh
ctest --test-dir build_cmake -R '^trace_test$' -V
rlc-action kuhn_poker.rl traces/game1.txt
```

The CMake helper runs `rlc-action` with the selected RLC compiler, captures the output and exit status, checks for execution and known action errors, and compares the final serialized state with the expected state file. It writes the output to `build_cmake/temp/test/trace_test.log`.

A successful replay alone is not sufficient: the final state must also match the expected result. The comparison uses exact text after trimming leading and trailing whitespace, so the expected state must remain on one line with matching field order and formatting.

### Generate Additional Traces (Optional)
`rlc-random` can generate a candidate game trace for inspection:

```sh
rlc-random kuhn_poker.rl -o traces/candidate.txt
rlc-action kuhn_poker.rl traces/candidate.txt
```

The `deal` action uses the enumerable `CardNumber` enum (J, Q, K), allowing `rlc-random` to enumerate its arguments. The unit tests use the same action parameter type. Warnings about non-tensorable `Int` state fields concern machine-learning tensor conversion and do not prevent the trace replay tested here.

Random traces are candidates, not independent correctness oracles: check their legality and expected results against the game rules before using them as regression tests. The registered `trace_test` replays the saved `game1.txt` rather than generating a new random trace each time.

### Verification Results
All five CTest tests passed through `verify_all` in the existing local environment. The trace test also passed independently. A negative check was performed by temporarily changing the expected winner from `0` to `1`; the trace test correctly failed with an `Unexpected final state` error. Restore the expected winner to `0` after such a check.

The current trace test covers one fixed bet-and-fold scenario and compares the final state. It complements the unit tests, sanitizer, and fuzzer but does not prove that every game rule or intermediate state is correct.

## Run the Game Example
```sh
./result/kuhn_poker
echo "退出码：$?"
```

The example has no interactive interface or printed output; exit code `0` indicates that the checks passed.
## Project Files
| File | Purpose |
| --- | --- |
| `kuhn_poker.rl` | Game rules, state, and reward calculation |
| `kuhn_poker_main.rl` | Entry point for the normal program; imports the game rules and runs a fixed example |
| `kuhn_poker_test.rl` | Rule unit tests and action legality checks |
| `kuhn_poker_fuzz.rl` | Parses fuzz inputs and executes legal actions |
| `CMakeLists.txt` | Tool discovery, build rules, and test registration |
| `cmake/kuhn_poker_game.cmake` | Generates IR, runs unit and trace tests, compares trace results, and saves logs |
| `traces/game1.txt` | Fixed game action sequence for trace replay |
| `traces/game1.expected.txt` | Independently checked expected final state (single line) |

## Outputs and Logs
| Path | Description |
| --- | --- |
| `result/kuhn_poker` | Normal game example |
| `result/kuhn_poker_fuzzer` | Fuzzer with ASan |
| `build_cmake/temp/test/unit_test.log` | Unit test results |
| `build_cmake/temp/test/trace_test.log` | Trace replay output and diagnostics |
| `build_cmake/Testing/Temporary/LastTest.log` | Detailed output from the most recent CTest run |
| `build_cmake/temp/test/ctest.log` | Overall log generated by `verify_all` |

Data for the two fuzz tests is stored in `build_cmake/temp/Sanitizer/` and `build_cmake/temp/fuzzer/`, respectively: `corpus/` holds the input collection, and `artifacts/` holds inputs that trigger errors.

-------------------------------------------------------------------------------------
CHINESE VERSION
-------------------------------------------------------------------------------------
# Kuhn Poker（Rulebook）
使用 Rulebook 实现 Kuhn Poker，以 CMake 构建游戏示例和带 AddressSanitizer（ASan）的 libFuzzer 程序，通过 CTest 自动运行测试，包括使用 `rlc-action` 的基于轨迹的测试。

## 构建与测试
在 `Kuhn_Poker` 目录执行以下命令。首次使用请先完成下方的[环境安装](#环境安装)。

```sh
conda activate rulebook
cmake -S . -B build_cmake -G Ninja
cmake --build build_cmake
ctest --test-dir build_cmake --output-on-failure
```

完成 Configure 后，也可以一条命令构建并运行全部测试：
```sh
cmake --build build_cmake --target verify_all
```
成功时显示 5 项测试全部通过（`100% tests passed`）。CTest 不会自动构建程序，修改源码后应先 Build 再 Test；`verify_all` 会依次完成两者。

## 环境安装
当前方案适用于 **Apple Silicon macOS（原生 arm64）**，需要 Git、Conda 和 macOS SDK。Conda 可按 [Miniforge 官方说明](https://github.com/conda-forge/miniforge)安装；尚未安装 Xcode 或 Command Line Tools 时，执行以下命令并等待系统安装完成：
```sh
xcode-select --install
```

克隆仓库，进入项目子目录并创建环境：
```sh
git clone https://github.com/bingxunding/rulebook_project.git
cd rulebook_project/Kuhn_Poker
conda env create --file environment.yml
conda activate rulebook
```

已有符合要求的 `rulebook` 环境时，直接激活即可，无需重复创建。随后执行上方的构建与测试命令。
[environment.yml](environment.yml)固定关键依赖：Python 3.11、`rl-language-core` 0.4.18、外部 Clang/LLVM 22.1.8、CMake 4.4.3、Ninja 1.13.2 和 zstd 1.5.7。RLC 自带后端为 LLVM 21.1.3；CMake 从当前 Conda 环境查找外部工具。
构建与测试已在上述版本的现有环境中验证；环境文件不是完整锁文件，本次未重新创建全新 Conda 环境。

## 测试内容
CTest 共注册 5 项测试，其中 `unit_test` 内部运行 10 个单元测试函数。

| 测试 | 内容 |
| --- | --- |
| `game_test` | 运行固定的下注、弃牌示例，检查退出码 |
| `unit_test` | 6 种发牌 × 5 条终局路线，共 30 局，并检查发牌边界和动作顺序 |
| `sanitizer_test` | 带 ASan 的 fuzzer，运行 100 次 |
| `fuzzer_test` | 同一个带 ASan 的 fuzzer，运行 10,000 次 |
| `trace_test` | 使用 `rlc-action` 重放固定游戏轨迹，并比较实际最终状态与预期状态 |

两项 fuzz 测试共用一个程序，分别保存 corpus 和错误输入。当前单测通过 `rlc-test` 执行，该工具会在内部临时编译 `.rl`。
单独运行单测，或显示 fuzz 测试的详细输出：
```sh
ctest --test-dir build_cmake -R '^unit_test$' --output-on-failure
ctest --test-dir build_cmake -R '^fuzzer_test$' -V
```

## 基于轨迹的测试（Trace-Based Testing）
`trace_test` 使用 `rlc-action` 重放固定的游戏动作序列，将实际最终状态与独立核对过的预期状态进行比较。该测试已注册到 CTest，并自动纳入 `verify_all`。

### 轨迹与预期状态
固定动作序列保存在 `traces/game1.txt`：

```text
# game 0
deal {card1: J, card2: Q}
p0_bet {}
p1_fold {}
```

Player 0 获得 J，Player 1 获得 Q。Player 0 下注 1 筹码，Player 1 弃牌，因此即使 Player 0 的牌更小，也由 Player 0 获胜。

预期最终状态保存在 `traces/game1.expected.txt`，内容为一行：

```text
{resume_index: -1, player0: {contribution: 2, card: 0, reward: 1}, player1: {contribution: 1, card: 1, reward: -1}, init_pot: 2, now_pot: 3, is_p1_bet: false, winner: 0}
```

该预期状态已根据游戏规则核对：初始底池为 2，最终记录的底池为 3，Player 0 获胜，净收益为 +1，Player 1 损失 1，游戏结束（`resume_index: -1`）。

### 运行轨迹测试
单独运行轨迹测试，或手动重放轨迹：

```sh
ctest --test-dir build_cmake -R '^trace_test$' -V
rlc-action kuhn_poker.rl traces/game1.txt
```

CMake 辅助脚本使用指定的 RLC 编译器运行 `rlc-action`，捕获输出和退出状态，检查执行错误及已知的动作错误，并将最终序列化状态与预期状态文件进行比较。执行输出保存到 `build_cmake/temp/test/trace_test.log`。

仅成功重放动作并不足以通过测试，最终状态还必须与预期结果一致。当前采用去除首尾空白后的精确文本比较，因此预期状态必须保存在一行，且字段顺序与格式需要一致。

### 生成其他轨迹（可选）
`rlc-random` 可以生成候选游戏轨迹供检查：

```sh
rlc-random kuhn_poker.rl -o traces/candidate.txt
rlc-action kuhn_poker.rl traces/candidate.txt
```

`deal` 动作使用可枚举的 `CardNumber` 枚举类型（J、Q、K），使 `rlc-random` 可以枚举发牌参数。单元测试也使用相同的动作参数类型。普通 `Int` 状态字段不可张量化的警告涉及机器学习的张量转换，不影响本次已验证的轨迹重放。

随机生成的轨迹只是候选测试数据，并非独立的正确性判断依据。应根据游戏规则核对其合法性和预期结果，再将其用于回归测试。已注册的 `trace_test` 每次重放保存好的 `game1.txt`，而不是重新随机生成轨迹。

### 验证结果
现有本地环境中，`verify_all` 的 5 项 CTest 测试均已通过，`trace_test` 单独运行也已通过。反向验证时，暂时将预期胜者从 `0` 改为 `1`，轨迹测试正确失败并报告 `Unexpected final state`。完成此类检查后，应将预期胜者恢复为 `0`。

当前轨迹测试覆盖一条固定的下注、弃牌流程，并比较最终状态。它与单元测试、Sanitizer 和 Fuzzer 互相补充，但不能证明所有游戏规则和中间状态都正确。

## 运行游戏示例
```sh
./result/kuhn_poker
echo "退出码：$?"
```

示例没有交互界面和打印输出，退出码 `0` 表示检查通过。
## 项目文件
| 文件 | 职责 |
| --- | --- |
| `kuhn_poker.rl` | 游戏规则、状态和收益结算 |
| `kuhn_poker_main.rl` | 普通程序入口，导入游戏规则并运行固定案例 |
| `kuhn_poker_test.rl` | 规则单测及动作合法性检查 |
| `kuhn_poker_fuzz.rl` | 解析 fuzz 输入并执行合法动作 |
| `CMakeLists.txt` | 工具查找、构建规则和测试注册 |
| `cmake/kuhn_poker_game.cmake` | 生成 IR、执行单测和轨迹测试、比较轨迹结果并保存日志 |
| `traces/game1.txt` | 用于重放的固定游戏动作序列 |
| `traces/game1.expected.txt` | 独立核对的预期最终状态（单行） |

## 输出与日志
| 路径 | 内容 |
| --- | --- |
| `result/kuhn_poker` | 普通游戏示例 |
| `result/kuhn_poker_fuzzer` | 带 ASan 的 fuzzer |
| `build_cmake/temp/test/unit_test.log` | 单元测试结果 |
| `build_cmake/temp/test/trace_test.log` | 轨迹重放输出及诊断信息 |
| `build_cmake/Testing/Temporary/LastTest.log` | 最近一次 CTest 的详细输出 |
| `build_cmake/temp/test/ctest.log` | `verify_all` 生成的整体日志 |

两项 fuzz 测试的数据分别位于 `build_cmake/temp/Sanitizer/` 和 `build_cmake/temp/fuzzer/`：`corpus/` 保存输入集合，`artifacts/` 保存触发错误的输入。
