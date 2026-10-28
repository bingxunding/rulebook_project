from rlc import compile
import random

# load the rl file
program = compile(["black_jack.rl"])
# starts a rlc program invoking the user defined play
# function and wraps it in object for with some useful methods
state = program.start()

# invokes directly the user defined function on the real state object
while program.module.get_current_player(state.state) == -1:
    # enumerate legal actions using the methods defined on the
    # wrapper
    action = random.choice(state.legal_actions)
    state.step(action)

# prints the state
state.pretty_print()

# checks for termination by using the helper functions
while not state.is_done():
    print("hit? (y/n)")
    decision = input()
    # invokes user defined actions directly
    if decision == "y":
        state.state.hit()
    else:
        state.state.stand()

    state.pretty_print()

print(f"Your final score is: {program.module.score(state.state, 0)}")