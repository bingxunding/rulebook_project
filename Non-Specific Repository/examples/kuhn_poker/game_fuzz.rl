import game
import action

# FUZZ_TRACE = 0 suppresses output for each executed action.
# FUZZ_TRACE = 1 prints legal actions that were executed and a message when the game ends.
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
