import kuhn_poker
import action

# Enable only in the separate trace build used to audit executed actions.
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
