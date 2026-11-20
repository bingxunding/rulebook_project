import game
import action

fun check_state(Game state):
    assert(invariant(state.table), "Hanabi state invariant")
    if state.table.phase != 0:
        let viewer = 0
        while viewer < state.table.players:
            let view = observe(state.table, viewer)
            assert(view.valid, "Valid player observation")
            let slot = 0
            while slot < view.hands[viewer].cards.size():
                assert(view.hands[viewer].cards[slot].color == -1, "Own color hidden")
                assert(view.hands[viewer].cards[slot].rank == 0, "Own rank hidden")
                slot = slot + 1
            viewer = viewer + 1

# A weighted choice of an undealt card is equivalent to sampling a shuffled deck.
fun choose_card(Table table, Int value) -> Int:
    let ticket = value % table.deck_left
    let id = 0
    while id < table.colors * 5:
        if ticket < table.deck_counts[id]:
            return id
        ticket = ticket - table.deck_counts[id]
        id = id + 1
    return 0

fun fuzz(Vector<Byte> input):
    if input.size() == 0:
        return

    # Exercise arbitrary serialized actions and their legality checks from setup.
    let state = play()
    let action : AnyGameAction
    let trace = parse_actions(action, input)
    for action in trace:
        if can apply(action, state):
            apply(action, state)
            check_state(state)

    # Guided legal play reaches deep transitions within the configured 256 bytes.
    let guided = play()
    let first = int(input[0]) + 128
    let players = 2 + first % 4
    let variant = (first / 4) % 4
    let extended = (first / 16) % 2 == 1
    if can guided.configure(players, first % players, variant, extended):
        guided.configure(players, first % players, variant, extended)
    let position = 0
    while guided.table.phase == 1:
        let value = int(input[position % input.size()]) + 128
        let id = choose_card(guided.table, value)
        if can guided.deal_card(id / 5, 1 + id % 5):
            guided.deal_card(id / 5, 1 + id % 5)
        check_state(guided)
        position = position + 1

    position = 0
    while position < input.size() and !guided.is_done():
        let value = int(input[position]) + 128
        let actor = guided.table.current_player
        let target = (actor + 1) % players
        let slot = 0
        if guided.table.hands[actor].cards.size() > 0:
            slot = value % guided.table.hands[actor].cards.size()
        let choice = value % 5
        if choice == 0:
            if guided.table.hands[target].cards.size() > 0:
                let color = guided.table.hands[target].cards[0].color
                if variant == 3 and color == 5:
                    color = 0
                if can guided.hint_color(actor, target, color):
                    guided.hint_color(actor, target, color)
        if choice == 1:
            if guided.table.hands[target].cards.size() > 0:
                let rank = guided.table.hands[target].cards[0].rank
                if can guided.hint_rank(actor, target, rank):
                    guided.hint_rank(actor, target, rank)
        if choice == 2:
            if can guided.discard(actor, slot):
                guided.discard(actor, slot)
        if choice == 3:
            if can guided.play_card(actor, slot):
                guided.play_card(actor, slot)
        if choice == 4:
            if can guided.reorder(actor, 0, slot):
                guided.reorder(actor, 0, slot)
        check_state(guided)
        if guided.table.phase == 3:
            let id = choose_card(guided.table, value)
            if can guided.draw_card(id / 5, 1 + id % 5):
                guided.draw_card(id / 5, 1 + id % 5)
            check_state(guided)
        position = position + 1
