import collections.vector

# Colors are white, red, blue, yellow, green, and optional multicolor (0..5).
# Masks describe what a player has learned, never the hidden card itself.
cls Card:
    Int color
    Int rank
    Int color_options
    Int rank_options

cls Hand:
    Vector<Card> cards

cls Table:
    Int players
    Int first_player
    Int variant
    Bool extended
    Int colors
    Int hand_limit
    Int current_player
    Int blue
    Int strikes
    Int deck_left
    Int turns_left
    Int turns_played
    Int score
    Int outcome
    Int deal_count
    Int phase
    Int[30] deck_counts
    Int[30] discard_counts
    Vector<Int> discards
    Int[6] fireworks
    Vector<Hand> hands
    Int last_target
    Int last_hint_type
    Int last_hint_value
    Int last_hint_mask

# A player-facing projection deliberately has no deck composition or own faces.
cls Observation:
    Bool valid
    Int players
    Int current_player
    Int blue
    Int strikes
    Int deck_left
    Int turns_left
    Int score
    Int outcome
    Int[6] fireworks
    Vector<Hand> hands
    Vector<Int> discards

fun bit_value(Int index) -> Int:
    let value = 1
    let i = 0
    while i < index:
        value = value * 2
        i = i + 1
    return value

fun has_bit(Int mask, Int index) -> Bool:
    return (mask / bit_value(index)) % 2 == 1

fun without_bit(Int mask, Int index) -> Int:
    if has_bit(mask, index):
        return mask - bit_value(index)
    return mask

fun copies(Int color, Int rank, Int variant) -> Int:
    if color == 5 and variant == 2:
        return 1
    if rank == 1:
        return 3
    if rank == 5:
        return 1
    return 2

fun setup_table(Table table, Int players, Int first_player, Int variant, Bool extended):
    table.players = players
    table.first_player = first_player
    table.variant = variant
    table.extended = extended
    table.colors = 5
    if variant != 0:
        table.colors = 6
    table.hand_limit = 5
    if players >= 4:
        table.hand_limit = 4
    table.current_player = first_player
    table.blue = 8
    table.strikes = 0
    table.deck_left = 0
    table.turns_left = -1
    table.turns_played = 0
    table.score = 0
    table.outcome = 0
    table.deal_count = 0
    table.phase = 1
    table.last_target = -1
    table.last_hint_type = -1
    table.last_hint_value = -1
    table.last_hint_mask = 0
    let color = 0
    while color < table.colors:
        let rank = 1
        while rank <= 5:
            let count = copies(color, rank, variant)
            table.deck_counts[color * 5 + rank - 1] = count
            table.deck_left = table.deck_left + count
            rank = rank + 1
        color = color + 1
    let p = 0
    while p < players:
        let hand : Hand
        table.hands.append(hand)
        p = p + 1

fun available_card(Table table, Int color, Int rank) -> Bool:
    if color < 0 or color >= table.colors or rank < 1 or rank > 5:
        return false
    return table.deck_counts[color * 5 + rank - 1] > 0

fun take_card(Table table, Int color, Int rank) -> Card:
    let card : Card
    card.color = color
    card.rank = rank
    card.color_options = bit_value(table.colors) - 1
    card.rank_options = 31
    let id = color * 5 + rank - 1
    table.deck_counts[id] = table.deck_counts[id] - 1
    table.deck_left = table.deck_left - 1
    return card

fun valid_actor(Table table, Int actor) -> Bool:
    return table.phase == 2 and actor == table.current_player and actor >= 0 and actor < table.players

fun valid_slot(Table table, Int player, Int slot) -> Bool:
    if player < 0 or player >= table.players:
        return false
    return slot >= 0 and slot < table.hands[player].cards.size()

fun matches_color(Card card, Int color, Int variant) -> Bool:
    return card.color == color or (variant == 3 and card.color == 5)

fun legal_color_hint(Table table, Int actor, Int target, Int color) -> Bool:
    if !valid_actor(table, actor) or table.blue == 0 or target < 0 or target >= table.players or target == actor:
        return false
    if color < 0 or color >= table.colors or (table.variant == 3 and color == 5):
        return false
    let slot = 0
    while slot < table.hands[target].cards.size():
        if matches_color(table.hands[target].cards[slot], color, table.variant):
            return true
        slot = slot + 1
    return false

fun legal_rank_hint(Table table, Int actor, Int target, Int rank) -> Bool:
    if !valid_actor(table, actor) or table.blue == 0 or target < 0 or target >= table.players or target == actor or rank < 1 or rank > 5:
        return false
    let slot = 0
    while slot < table.hands[target].cards.size():
        if table.hands[target].cards[slot].rank == rank:
            return true
        slot = slot + 1
    return false

fun give_color_hint(Table table, Int target, Int color):
    table.last_target = target
    table.last_hint_type = 0
    table.last_hint_value = color
    table.last_hint_mask = 0
    let slot = 0
    while slot < table.hands[target].cards.size():
        ref card = table.hands[target].cards[slot]
        let matching = matches_color(card, color, table.variant)
        if matching:
            table.last_hint_mask = table.last_hint_mask + bit_value(slot)
        let candidate = 0
        while candidate < table.colors:
            let candidate_matches = candidate == color or (table.variant == 3 and candidate == 5)
            if candidate_matches != matching:
                card.color_options = without_bit(card.color_options, candidate)
            candidate = candidate + 1
        slot = slot + 1
    table.blue = table.blue - 1
    table.phase = 5

fun give_rank_hint(Table table, Int target, Int rank):
    table.last_target = target
    table.last_hint_type = 1
    table.last_hint_value = rank
    table.last_hint_mask = 0
    let slot = 0
    while slot < table.hands[target].cards.size():
        ref card = table.hands[target].cards[slot]
        if card.rank == rank:
            table.last_hint_mask = table.last_hint_mask + bit_value(slot)
            card.rank_options = bit_value(rank - 1)
        else:
            card.rank_options = without_bit(card.rank_options, rank - 1)
        slot = slot + 1
    table.blue = table.blue - 1
    table.phase = 5

fun record_discard(Table table, Card card):
    let id = card.color * 5 + card.rank - 1
    table.discards.append(id)
    table.discard_counts[id] = table.discard_counts[id] + 1
    if table.extended and card.rank > table.fireworks[card.color] and table.discard_counts[id] == copies(card.color, card.rank, table.variant):
        table.outcome = 4

# Ends immediately on a winning play or fatal loss; otherwise draws if possible.
fun remove_card(Table table, Int slot, Bool playing):
    let card = table.hands[table.current_player].cards[slot]
    table.hands[table.current_player].cards.erase(slot)
    if playing:
        if card.rank == table.fireworks[card.color] + 1:
            table.fireworks[card.color] = card.rank
            table.score = table.score + 1
            if card.rank == 5 and table.blue < 8:
                table.blue = table.blue + 1
            if table.score == table.colors * 5:
                table.outcome = 1
        else:
            record_discard(table, card)
            table.strikes = table.strikes + 1
            if table.strikes == 3:
                table.outcome = 2
    else:
        record_discard(table, card)
        table.blue = table.blue + 1
    table.phase = 5
    if table.outcome == 0 and table.deck_left > 0:
        table.phase = 3

fun complete_turn(Table table):
    table.turns_played = table.turns_played + 1
    if table.outcome == 0 and table.turns_left >= 0:
        table.turns_left = table.turns_left - 1
        if table.turns_left == 0:
            table.outcome = 3
    if table.outcome == 0:
        table.current_player = (table.current_player + 1) % table.players
        table.phase = 2
    else:
        table.phase = 4

fun observe(Table table, Int viewer) -> Observation:
    let view : Observation
    view.valid = viewer >= 0 and viewer < table.players
    if !view.valid:
        return view
    view.players = table.players
    view.current_player = table.current_player
    view.blue = table.blue
    view.strikes = table.strikes
    view.deck_left = table.deck_left
    view.turns_left = table.turns_left
    view.score = table.score
    view.outcome = table.outcome
    view.fireworks = table.fireworks
    view.discards = table.discards
    view.hands = table.hands
    let slot = 0
    while slot < view.hands[viewer].cards.size():
        view.hands[viewer].cards[slot].color = -1
        view.hands[viewer].cards[slot].rank = 0
        slot = slot + 1
    return view

# The qualitative scale belongs to the five-color base game only.
fun artistic_rating(Table table) -> Int:
    if table.extended or table.colors != 5:
        return -1
    if table.score <= 5:
        return 0
    if table.score <= 10:
        return 1
    if table.score <= 15:
        return 2
    if table.score <= 20:
        return 3
    if table.score <= 24:
        return 4
    return 5

# Check card conservation, bounds, and consistency after every fuzzed transition.
fun invariant(Table table) -> Bool:
    if table.phase == 0:
        return table.players == 0
    if table.players < 2 or table.players > 5 or table.colors < 5 or table.colors > 6:
        return false
    if table.blue < 0 or table.blue > 8 or table.strikes < 0 or table.strikes > 3:
        return false
    if table.current_player < 0 or table.current_player >= table.players or table.hands.size() != table.players:
        return false
    let in_hands : Int[30]
    let p = 0
    while p < table.players:
        if table.hands[p].cards.size() > table.hand_limit:
            return false
        let slot = 0
        while slot < table.hands[p].cards.size():
            let card = table.hands[p].cards[slot]
            if card.color < 0 or card.color >= table.colors or card.rank < 1 or card.rank > 5:
                return false
            if !has_bit(card.color_options, card.color) or !has_bit(card.rank_options, card.rank - 1):
                return false
            in_hands[card.color * 5 + card.rank - 1] = in_hands[card.color * 5 + card.rank - 1] + 1
            slot = slot + 1
        p = p + 1
    let discard_tally : Int[30]
    let i = 0
    while i < table.discards.size():
        let id = table.discards[i]
        if id < 0 or id >= table.colors * 5:
            return false
        discard_tally[id] = discard_tally[id] + 1
        i = i + 1
    let total = 0
    let score = 0
    let color = 0
    while color < 6:
        if table.fireworks[color] < 0 or table.fireworks[color] > 5:
            return false
        if color >= table.colors and table.fireworks[color] != 0:
            return false
        score = score + table.fireworks[color]
        let rank = 1
        while rank <= 5:
            let id = color * 5 + rank - 1
            if table.deck_counts[id] < 0 or table.discard_counts[id] != discard_tally[id]:
                return false
            total = total + table.deck_counts[id]
            let played = 0
            if rank <= table.fireworks[color]:
                played = 1
            let expected = 0
            if color < table.colors:
                expected = copies(color, rank, table.variant)
            if table.deck_counts[id] + table.discard_counts[id] + in_hands[id] + played != expected:
                return false
            rank = rank + 1
        color = color + 1
    if total != table.deck_left or score != table.score:
        return false
    if table.extended and table.turns_left != -1:
        return false
    if table.outcome == 1 and table.score != table.colors * 5:
        return false
    if table.outcome == 2 and table.strikes != 3:
        return false
    if table.outcome == 3 and (table.deck_left != 0 or table.turns_left != 0 or table.extended):
        return false
    return true

@classes
act play() -> Game:
    frm table : Table
    act configure(Int players, Int first_player, Int variant, Bool extended){
        players >= 2 and players <= 5 and first_player >= 0 and first_player < players and variant >= 0 and variant <= 3
    }
    setup_table(table, players, first_player, variant, extended)
    while table.deal_count < table.players * table.hand_limit:
        act deal_card(Int color, Int rank){available_card(table, color, rank)}
        let card = take_card(table, color, rank)
        table.hands[table.deal_count % table.players].cards.append(card)
        table.deal_count = table.deal_count + 1
    table.phase = 2

    while table.outcome == 0:
        actions:
            act hint_color(Int actor, Int target, Int color){legal_color_hint(table, actor, target, color)}
                give_color_hint(table, target, color)
            act hint_rank(Int actor, Int target, Int rank){legal_rank_hint(table, actor, target, rank)}
                give_rank_hint(table, target, rank)
            act discard(Int actor, Int slot){valid_actor(table, actor) and valid_slot(table, actor, slot) and table.blue < 8}
                remove_card(table, slot, false)
            act play_card(Int actor, Int slot){valid_actor(table, actor) and valid_slot(table, actor, slot)}
                remove_card(table, slot, true)
            act reorder(Int player, Int first, Int second){table.phase == 2 and valid_slot(table, player, first) and valid_slot(table, player, second) and first != second}
                let card = table.hands[player].cards[first]
                table.hands[player].cards[first] = table.hands[player].cards[second]
                table.hands[player].cards[second] = card
        if table.phase == 3:
            act draw_card(Int color, Int rank){available_card(table, color, rank)}
            table.hands[table.current_player].cards.append(take_card(table, color, rank))
            if table.deck_left == 0 and !table.extended:
                table.turns_left = table.players + 1
            table.phase = 5
        if table.phase == 5:
            complete_turn(table)
