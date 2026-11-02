# Kuhn Poker（Rulebook）
使用 Rulebook 实现 Kuhn Poker，以 CMake 构建游戏示例和带 AddressSanitizer（ASan）的 libFuzzer 程序，通过 CTest 自动运行测试。

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
成功时显示 `100% tests passed`。CTest 不会自动构建程序，修改源码后应先 Build 再 Test；`verify_all` 会依次完成两者。

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
CTest 共注册 4 项测试，其中 `unit_test` 内部运行 10 个单元测试函数。

| 测试 | 内容 |
| --- | --- |
| `game_test` | 运行固定的下注、弃牌示例，检查退出码 |
| `unit_test` | 6 种发牌 × 5 条终局路线，共 30 局，并检查发牌边界和动作顺序 |
| `sanitizer_test` | 带 ASan 的 fuzzer，运行 100 次 |
| `fuzzer_test` | 同一个带 ASan 的 fuzzer，运行 10,000 次 |

两项 fuzz 测试共用一个程序，分别保存 corpus 和错误输入。当前单测通过 `rlc-test` 执行，该工具会在内部临时编译 `.rl`。
单独运行单测，或显示 fuzz 测试的详细输出：
```sh
ctest --test-dir build_cmake -R '^unit_test$' --output-on-failure
ctest --test-dir build_cmake -R '^fuzzer_test$' -V
```

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
| `cmake/kuhn_poker_game.cmake` | 生成 IR、执行单测并保存日志 |

## 输出与日志
| 路径 | 内容 |
| --- | --- |
| `result/kuhn_poker` | 普通游戏示例 |
| `result/kuhn_poker_fuzzer` | 带 ASan 的 fuzzer |
| `build_cmake/temp/test/unit_test.log` | 单元测试结果 |
| `build_cmake/Testing/Temporary/LastTest.log` | 最近一次 CTest 的详细输出 |
| `build_cmake/temp/test/ctest.log` | `verify_all` 生成的整体日志 |

两项 fuzz 测试的数据分别位于 `build_cmake/temp/Sanitizer/` 和 `build_cmake/temp/fuzzer/`：`corpus/` 保存输入集合，`artifacts/` 保存触发错误的输入。
