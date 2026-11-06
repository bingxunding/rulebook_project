import game
import action

# FUZZ_TRACE = 0 不打印每个执行的 Action
# FUZZ_TRACE = 1 打印合法且已执行的 Action；游戏结束时打印提示
const FUZZ_TRACE = 0

fun fuzz(Vector<Byte> input):
    if input.size() == 0:
        return
    let state = play()
    let action : AnyGameAction
    let trace = parse_actions(action, input)
    for action in trace:
        if can apply(action, state):
            apply(action, state)
            if FUZZ_TRACE == 1:
                print(action)
                if state.is_done():
                    print("FUZZ_GAME_DONE")
