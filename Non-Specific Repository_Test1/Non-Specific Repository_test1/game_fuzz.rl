import game
import action

fun check_invariants(State state):
    let expected : Supply
    let counts : Int[12]
    let total = 0
    let card = 0
    while card < 12:
        assert(state.remaining.value.counts[card] >= 0, "Negative supply")
        counts[card] = state.remaining.value.counts[card] + state.discarded[card]
        total = total + state.remaining.value.counts[card]
        card = card + 1
    assert(total == state.remaining.value.total, "Supply total mismatch")
    let i = 0
    while i < state.participants:
        ref player = state.seats[i]
        assert(player.hand.value.size >= 0 and player.hand.value.size <= 10, "Invalid hand size")
        card = 0
        while card < 12:
            assert(player.table[card] >= 0, "Negative table count")
            counts[card] = counts[card] + player.table[card]
            card = card + 1
        # Earlier-round Puddings remain in front of the player, outside table.
        counts[9] = counts[9] + player.puddings - player.table[9]
        assert(player.unused_wasabi >= 0 and player.unused_wasabi <= player.table[10], "Invalid Wasabi count")
        let j = 0
        while j < player.hand.value.size:
            let held = player.hand.value.cards[j]
            assert(held >= 0 and held < 12, "Invalid hand card")
            counts[held] = counts[held] + 1
            j = j + 1
        if player.committed:
            counts[player.pending.value.first] = counts[player.pending.value.first] + 1
            if player.pending.value.second != -1:
                counts[player.pending.value.second] = counts[player.pending.value.second] + 1
                # Returned Chopsticks are already in the outgoing hidden hand.
                counts[11] = counts[11] - 1
            if player.pending.value.dummy_card != -1:
                counts[player.pending.value.dummy_card] = counts[player.pending.value.dummy_card] + 1
        i = i + 1
    i = 0
    while i < state.dummy_pile.value.size:
        card = state.dummy_pile.value.cards[i]
        assert(card >= 0 and card < 12, "Invalid dummy card")
        counts[card] = counts[card] + 1
        i = i + 1
    card = 0
    while card < 12:
        assert(counts[card] == expected.counts[card], "Physical card conservation failed")
        card = card + 1

# A compact second interpretation reaches legal drafting decisions even when
# arbitrary serialized Int arguments do not satisfy the action preconditions.
fun fuzz_legal_play(Vector<Byte> input):
    let state = play()
    let config = int(input.get(0)) + 128
    let players = 2 + config % 4
    let dummy = config % 8 == 0
    if dummy:
        players = 2
    if can state.configure(players, config % 2 == 0, dummy, (config / 2) % 2):
        state.configure(players, config % 2 == 0, dummy, (config / 2) % 2)
    check_invariants(state.s)
    let i = 1
    # At most 195 steps deal and draft a full five-player game. Reuse short
    # inputs so even the sanitizer's small corpus exercises all three rounds.
    while i < 200 and !state.is_done():
        let value = int(input.get(i % input.size())) + 128
        if state.s.deal_seat < state.s.participants:
            let card : Card
            card.value = value % 12
            while state.s.remaining.value.counts[card.value] == 0:
                card.value = (card.value + 1) % 12
            if can state.deal(card):
                state.deal(card)
        else:
            let player = value % state.s.players
            while state.s.seats[player].committed:
                player = (player + 1) % state.s.players
            let size = state.s.seats[player].hand.value.size
            let first = value % size
            let second = -1
            let dummy_index = -1
            let required = 2
            if state.s.dummy_mode and player == state.s.controller:
                dummy_index = (first + 1) % size
                required = 3
            if state.s.seats[player].table[11] > 0 and size >= required and value % 2 == 0:
                second = (first + 1) % size
                if second == dummy_index:
                    second = (second + 1) % size
            if can state.choose(player, first, second, dummy_index):
                state.choose(player, first, second, dummy_index)
        check_invariants(state.s)
        i = i + 1
    assert(state.is_done(), "Legal playthrough failed to terminate")

fun fuzz(Vector<Byte> input):
    if input.size() == 0:
        return
    let state = play()
    let action : AnyGameAction
    let trace = parse_actions(action, input)
    for action in trace:
        if can apply(action, state):
            apply(action, state)
            check_invariants(state.s)
    fuzz_legal_play(input)
