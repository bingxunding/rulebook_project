
# AGENTS.md

## 目标与修改范围

根据用户提供的自然语言规则，实现可编译、可验证的 Rulebook 游戏。以规则为准，遇到会影响游戏结果的歧义时先澄清。

当前四个 `.rl` 文件是 Kuhn Poker 示例。开发新游戏时按需替换这四个文件的实现，保留文件名和入口约定。`CMakeLists.txt`、`cmake/` 和 `environment.yml` 是通用构建与验证基础设施，应保留。这里约定的是 Agent 的修改范围，文件权限由运行环境管理。

## 文件约定

- `game.rl` 实现游戏状态、初始化、行动顺序、动作合法性、终局和适用的计分规则。
- `game_main.rl` 通过 `import game` 加载游戏，实现 `fun main() -> Int`，运行一条可复现的合法对局并检查预期结果。成功返回 `0`，失败返回非零值。
- `game_test.rl` 导入 `game`，用 `fun test_...() -> Bool` 编写由 `rlc-test` 发现的单元用例。直接从规则推导期望值，覆盖初始状态、动作顺序、合法与非法动作、边界、终局和适用的计分。
- `game_fuzz.rl` 导入 `game`，提供 `fun fuzz(Vector<Byte> input)`。参考示例用 `parse_actions` 从字节生成动作，通过 `can apply` 检查后执行，以实际驱动新游戏的状态转换。

## Rulebook 开发

- 参考 `game.rl` 中的 Action Function，例如 `act play() -> Game`。用 `act` 声明动作，用 `actions:` 表达同一阶段的备选动作，用 `frm` 保存跨动作的状态。
- 用动作声明后的 `{ ... }` 写前置条件。用 `can state.action(...)` 查询当前状态下的动作是否合法，用 `is_done()` 检查终局。
- 以当前示例和 `environment.yml` 指定版本的编译器及标准库为准。使用新语法或 API 前先核实其支持情况。语言机制可参考 [Rulebook 语言参考](https://rl-language.github.io/language-reference.html)。

## 构建与验证

在模板仓库根目录执行。现有工具链面向 Apple Silicon macOS，使用 macOS SDK 和 Conda 环境中的 LLVM 22。构建前确保已激活具备所需工具和依赖的 Conda 环境（环境名称不限），可参考 `environment.yml`。

```sh
cmake -S . -B build_cmake -G Ninja
cmake --build build_cmake --target verify_all
```

`verify_all` 先构建 `result/game` 和 `result/game_fuzzer`，再运行 `game_test`、`unit_test`、`sanitizer_test` 和 `fuzzer_test`。如需单独构建或定位失败，先构建，再选择对应的 CTest 项。

```sh
cmake --build build_cmake
ctest --test-dir build_cmake --output-on-failure -R '^game_test$'
ctest --test-dir build_cmake --output-on-failure -R '^unit_test$'
ctest --test-dir build_cmake --output-on-failure -R '^sanitizer_test$'
ctest --test-dir build_cmake --output-on-failure -R '^fuzzer_test$'
```

`sanitizer_test` 和 `fuzzer_test` 使用同一个带 AddressSanitizer 插桩的 Fuzzer，分别运行 100 次和 10,000 次。单元测试日志和 `verify_all` 汇总日志分别位于 `build_cmake/temp/test/unit_test.log` 和 `build_cmake/temp/test/ctest.log`。

## 失败处理与完成标准

- 编译或测试失败时，读取诊断和日志，定位原因并修复游戏文件，再重跑失败项及 `verify_all`。禁止通过删除测试、削弱断言或绕过检查取得通过结果。环境问题应如实报告。
- 完成时须成功编译、通过 `verify_all`，并检查单元测试日志，确认预期用例实际执行。报告各项验证结果、规则假设和未解决的问题。测试通过仅说明已执行的检查通过，游戏语义仍需逐条对照规则审查。
