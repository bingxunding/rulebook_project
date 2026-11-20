import game
import action

# Signed Byte values become a nonnegative 0..255 choice stream.
fun next_choice(Vector<Byte> input, Int cursor) -> Int:
    let value = int(input.get(cursor % input.size())) + 128
    cursor = cursor + 1
    return value

fun check_fuzz_state(Game state):
    if state.table.humans >= 2:
        assert(state_is_valid(state.table), "Game state invariant failed")
    if state.is_done():
        assert(!(can state.deal(Card::Tempura)), "Terminal deal was legal")
        assert(!(can state.pick(0, 0, -1)), "Terminal pick was legal")
        let winners = 0
        let i = 0
        while i < state.table.seats:
            if state.table.winners[i]:
                winners = winners + 1
            i = i + 1
        assert(winners > 0, "Finished game has no winner")

fun fuzz(Vector<Byte> input):
    if input.size() == 0:
        return

    # Exercise the generated action parser and reject arbitrary illegal actions.
    let state = play()
    let action : AnyGameAction
    let trace = parse_actions(action, input)
    for action in trace:
        if can apply(action, state):
            apply(action, state)
            check_fuzz_state(state)

    # A second byte-guided legal playthrough reaches scoring and end states even
    # when randomly serialized Int arguments would reject every parsed action.
    let guided = play()
    let cursor = 0
    let humans = 2 + next_choice(input, cursor) % 4
    let alternate = next_choice(input, cursor) % 2 == 1
    let dummy = next_choice(input, cursor) % 5 == 0
    let controller = 0
    if dummy:
        humans = 2
        controller = next_choice(input, cursor) % 2
    assert(can guided.setup(humans, alternate, dummy, controller), "Invalid generated setup")
    guided.setup(humans, alternate, dummy, controller)
    check_fuzz_state(guided)
    let steps = 0
    while !guided.is_done() and steps < 256:
        let card = next_choice(input, cursor) % 12
        let tries = 0
        while tries < 12 and !(can guided.deal(card_from_int(card))):
            card = (card + 1) % 12
            tries = tries + 1
        if tries < 12:
            assert(can guided.deal(card_from_int(card)), "Illegal generated deal")
            guided.deal(card_from_int(card))
        else:
            let player = guided.table.actor
            let size = guided.table.players[player].hand.size
            let first = next_choice(input, cursor) % size
            let second = next_choice(input, cursor) % size
            let gift = -1
            if guided.table.dummy and player == guided.table.controller:
                gift = (first + 1) % size
            if can guided.chopsticks(player, first, second, gift):
                guided.chopsticks(player, first, second, gift)
            else:
                assert(can guided.pick(player, first, gift), "Illegal generated pick")
                guided.pick(player, first, gift)
        check_fuzz_state(guided)
        steps = steps + 1
    assert(guided.is_done(), "Legal guided game failed to terminate")
