import game

# These fixtures choose actual remaining cards; they never create extra copies.
fun ready_game(Int players, Int first, Int variant, Bool extended) -> Game:
    let state = play()
    state.configure(players, first, variant, extended)
    let dealt = 0
    while dealt < players * state.table.hand_limit:
        let color = dealt % state.table.colors
        let rank = 1
        while state.table.deck_counts[color * 5 + rank - 1] == 0:
            rank = rank + 1
        state.deal_card(color, rank)
        dealt = dealt + 1
    return state

fun draw_remaining(Game state):
    if state.table.phase != 3:
        return
    let id = 0
    while state.table.deck_counts[id] == 0:
        id = id + 1
    state.draw_card(id / 5, id % 5 + 1)

fun replace_card(Table table, Int player, Int slot, Int color, Int rank):
    let old = table.hands[player].cards[slot]
    table.deck_counts[old.color * 5 + old.rank - 1] = table.deck_counts[old.color * 5 + old.rank - 1] + 1
    table.deck_left = table.deck_left + 1
    table.hands[player].cards[slot] = take_card(table, color, rank)

# Move unneeded deck cards into the public discard pile, preserving conservation.
fun leave_one_draw(Table table, Int color, Int rank):
    let keep = color * 5 + rank - 1
    let id = 0
    while id < 30:
        let retain = 0
        if id == keep:
            retain = 1
        while table.deck_counts[id] > retain:
            table.deck_counts[id] = table.deck_counts[id] - 1
            table.deck_left = table.deck_left - 1
            table.discard_counts[id] = table.discard_counts[id] + 1
            table.discards.append(id)
        id = id + 1

# Construct a physically consistent late-game position with one missing five.
# It tests immediate victory independently of any particular strategy.
fun near_victory(Int variant, Bool extended) -> Game:
    let state = ready_game(2, 0, variant, extended)
    let player = 0
    while player < 2:
        for card in state.table.hands[player].cards:
            let id = card.color * 5 + card.rank - 1
            state.table.deck_counts[id] = state.table.deck_counts[id] + 1
            state.table.deck_left = state.table.deck_left + 1
        state.table.hands[player].cards.clear()
        player = player + 1
    let color = 0
    while color < state.table.colors:
        let height = 5
        if color + 1 == state.table.colors:
            height = 4
        let rank = 1
        while rank <= height:
            take_card(state.table, color, rank)
            rank = rank + 1
        state.table.fireworks[color] = height
        state.table.score = state.table.score + height
        color = color + 1
    state.table.hands[0].cards.append(take_card(state.table, state.table.colors - 1, 5))
    player = 0
    while player < 2:
        while state.table.hands[player].cards.size() < 5:
            let id = 0
            while state.table.deck_counts[id] == 0:
                id = id + 1
            state.table.hands[player].cards.append(take_card(state.table, id / 5, id % 5 + 1))
        player = player + 1
    return state

fun no_turn_actions(Game state) -> Bool:
    return !(can state.hint_color(0, 1, 0)) and !(can state.hint_rank(0, 1, 1)) and !(can state.discard(0, 0)) and !(can state.play_card(0, 0)) and !(can state.reorder(0, 0, 1))

fun test_initial_state_and_configuration() -> Bool:
    let state = play()
    if state.is_done() or state.table.phase != 0:
        return false
    if can state.configure(1, 0, 0, false):
        return false
    if can state.configure(6, 0, 0, false):
        return false
    if can state.configure(2, -1, 0, false):
        return false
    if can state.configure(2, 2, 0, false):
        return false
    if can state.configure(2, 0, -1, false):
        return false
    if can state.configure(2, 0, 4, false):
        return false
    if !no_turn_actions(state):
        return false
    state.configure(2, 1, 0, false)
    return state.table.players == 2 and state.table.first_player == 1 and state.table.current_player == 1 and state.table.hand_limit == 5 and state.table.blue == 8 and state.table.strikes == 0 and state.table.deck_left == 50 and state.table.score == 0 and state.table.turns_left == -1 and state.table.phase == 1

fun test_all_player_counts_and_starting_seats() -> Bool:
    let players = 2
    while players <= 5:
        let first = 0
        while first < players:
            let state = ready_game(players, first, 0, false)
            let hand_size = 5
            if players >= 4:
                hand_size = 4
            if state.table.hand_limit != hand_size or state.table.deck_left != 50 - players * hand_size:
                return false
            if state.table.current_player != first or state.table.phase != 2:
                return false
            let p = 0
            while p < players:
                if state.table.hands[p].cards.size() != hand_size:
                    return false
                p = p + 1
            first = first + 1
        players = players + 1
    return true

fun test_deck_multiplicities_and_variants() -> Bool:
    let variant = 0
    while variant < 4:
        let state = play()
        state.configure(2, 0, variant, false)
        let expected = 60
        let colors = 6
        if variant == 0:
            expected = 50
            colors = 5
        if variant == 2:
            expected = 55
        if state.table.deck_left != expected or state.table.colors != colors:
            return false
        let color = 0
        while color < 6:
            let rank = 1
            while rank <= 5:
                let copies = 2
                if rank == 1:
                    copies = 3
                if rank == 5:
                    copies = 1
                if color == 5 and variant == 2:
                    copies = 1
                if color == 5 and variant == 0:
                    copies = 0
                if state.table.deck_counts[color * 5 + rank - 1] != copies:
                    return false
                rank = rank + 1
            color = color + 1
        variant = variant + 1
    return true

fun test_dealing_legality_and_copy_limits() -> Bool:
    let state = play()
    state.configure(2, 0, 0, false)
    if can state.deal_card(-1, 1):
        return false
    if can state.deal_card(5, 1):
        return false
    if can state.deal_card(0, 0):
        return false
    if can state.deal_card(0, 6):
        return false
    state.deal_card(0, 1)
    state.deal_card(0, 1)
    state.deal_card(0, 1)
    if can state.deal_card(0, 1):
        return false
    if state.table.hands[0].cards.size() != 2 or state.table.hands[1].cards.size() != 1:
        return false
    if state.table.deck_left != 47 or state.table.deck_counts[0] != 0:
        return false
    return no_turn_actions(state) and !(can state.draw_card(0, 2)) and !(can state.configure(2, 0, 0, false))

fun test_turn_order_and_mandatory_replacement() -> Bool:
    let state = ready_game(3, 2, 0, false)
    if can state.play_card(0, 0):
        return false
    if can state.play_card(1, 0):
        return false
    state.play_card(2, 0)
    if state.table.phase != 3 or state.table.current_player != 2 or state.table.turns_played != 0:
        return false
    if !no_turn_actions(state) or (can state.deal_card(0, 1)):
        return false
    let before = state.table.deck_left
    draw_remaining(state)
    if state.table.current_player != 0 or state.table.turns_played != 1 or state.table.deck_left != before - 1:
        return false
    state.hint_rank(0, 1, 1)
    return state.table.current_player == 1 and state.table.turns_played == 2 and state.table.blue == 7 and !(can state.draw_card(0, 2))

fun test_hint_legality_and_no_zero_clues() -> Bool:
    let state = ready_game(2, 0, 0, false)
    if can state.hint_color(0, 0, 0):
        return false
    if can state.hint_rank(0, 0, 1):
        return false
    if can state.hint_color(1, 0, 0):
        return false
    if can state.hint_color(0, -1, 0):
        return false
    if can state.hint_color(0, 2, 0):
        return false
    if can state.hint_color(0, 1, -1):
        return false
    if can state.hint_color(0, 1, 5):
        return false
    if can state.hint_rank(0, 1, 0):
        return false
    if can state.hint_rank(0, 1, 6):
        return false
    if can state.hint_rank(0, 1, 5):
        return false
    return (can state.hint_rank(0, 1, 1)) and state.table.blue == 8 and state.table.turns_played == 0

fun test_color_clue_marks_every_match_and_every_nonmatch() -> Bool:
    let state = ready_game(2, 0, 0, false)
    replace_card(state.table, 1, 0, 1, 2)
    replace_card(state.table, 1, 1, 1, 3)
    state.hint_color(0, 1, 1)
    if state.table.last_target != 1 or state.table.last_hint_type != 0 or state.table.last_hint_value != 1 or state.table.last_hint_mask != 3:
        return false
    let i = 0
    while i < 5:
        let expected = 29
        if i < 2:
            expected = 2
        if state.table.hands[1].cards[i].color_options != expected:
            return false
        if state.table.hands[1].cards[i].rank_options != 31:
            return false
        i = i + 1
    return state.table.blue == 7 and state.table.current_player == 1 and state.table.deck_left == 40

fun test_rank_clue_marks_every_match_and_every_nonmatch() -> Bool:
    let state = ready_game(2, 0, 0, false)
    replace_card(state.table, 1, 2, 0, 2)
    state.hint_rank(0, 1, 1)
    if state.table.last_hint_type != 1 or state.table.last_hint_value != 1 or state.table.last_hint_mask != 27:
        return false
    let i = 0
    while i < 5:
        let expected = 1
        if i == 2:
            expected = 30
        if state.table.hands[1].cards[i].rank_options != expected or state.table.hands[1].cards[i].color_options != 31:
            return false
        i = i + 1
    return state.table.blue == 7

fun test_blue_tokens_exhaustion_and_discard_recovery() -> Bool:
    let state = ready_game(2, 0, 0, false)
    if can state.discard(0, 0):
        return false
    let i = 0
    while i < 8:
        let actor = state.table.current_player
        state.hint_rank(actor, 1 - actor, 1)
        i = i + 1
    if state.table.blue != 0 or (can state.hint_rank(0, 1, 1)) or (can state.hint_color(0, 1, 1)):
        return false
    state.discard(0, 0)
    if state.table.blue != 1 or state.table.strikes != 0 or state.table.discards.size() != 1 or state.table.discard_counts[0] != 1:
        return false
    if state.table.hands[0].cards.size() != 4:
        return false
    draw_remaining(state)
    return state.table.hands[0].cards.size() == 5 and state.table.current_player == 1 and state.table.deck_left == 39

fun test_play_builds_only_the_next_number() -> Bool:
    let state = ready_game(2, 0, 0, false)
    state.play_card(0, 0)
    if state.table.score != 1 or state.table.fireworks[0] != 1 or state.table.strikes != 0 or state.table.blue != 8:
        return false
    draw_remaining(state)
    replace_card(state.table, 1, 0, 0, 2)
    state.play_card(1, 0)
    if state.table.score != 2 or state.table.fireworks[0] != 2 or state.table.strikes != 0:
        return false
    draw_remaining(state)
    replace_card(state.table, 0, 0, 0, 4)
    state.play_card(0, 0)
    return state.table.score == 2 and state.table.fireworks[0] == 2 and state.table.strikes == 1 and state.table.discard_counts[3] == 1 and state.table.blue == 8

fun test_duplicate_play_loses_a_fuse_without_recovering_blue() -> Bool:
    let state = ready_game(2, 0, 0, false)
    state.hint_rank(0, 1, 1)
    replace_card(state.table, 1, 0, 0, 1)
    state.play_card(1, 0)
    draw_remaining(state)
    state.play_card(0, 0)
    return state.table.strikes == 1 and state.table.blue == 7 and state.table.score == 1 and state.table.fireworks[0] == 1 and state.table.discard_counts[0] == 1

fun test_third_fuse_ends_immediately_without_replacement() -> Bool:
    let state = ready_game(2, 0, 0, false)
    state.table.strikes = 2
    replace_card(state.table, 0, 0, 0, 3)
    let before = state.table.deck_left
    state.play_card(0, 0)
    return state.is_done() and state.table.phase == 4 and state.table.outcome == 2 and state.table.strikes == 3 and state.table.deck_left == before and state.table.hands[0].cards.size() == 4 and !(can state.draw_card(0, 2)) and no_turn_actions(state)

fun test_illegal_slots_and_actors_leave_state_unchanged() -> Bool:
    let state = ready_game(2, 0, 0, false)
    let actor = -1
    while actor <= 2:
        let slot = -1
        while slot <= 5:
            let expected = actor == 0 and slot >= 0 and slot < 5
            if (can state.play_card(actor, slot)) != expected:
                return false
            if can state.discard(actor, slot):
                return false
            slot = slot + 1
        actor = actor + 1
    return state.table.score == 0 and state.table.strikes == 0 and state.table.blue == 8 and state.table.deck_left == 40 and state.table.hands[0].cards.size() == 5 and state.table.current_player == 0

fun test_draw_bounds_and_exhausted_copies() -> Bool:
    let state = ready_game(2, 0, 0, false)
    if can state.draw_card(0, 2):
        return false
    state.play_card(0, 0)
    if can state.draw_card(-1, 1):
        return false
    if can state.draw_card(5, 1):
        return false
    if can state.draw_card(0, 0):
        return false
    if can state.draw_card(0, 6):
        return false
    state.draw_card(0, 5)
    state.play_card(1, 0)
    return !(can state.draw_card(0, 5)) and (can state.draw_card(0, 2))

fun test_replacement_is_unknown_and_old_knowledge_follows_survivors() -> Bool:
    let state = ready_game(2, 0, 0, false)
    state.hint_rank(0, 1, 1)
    state.discard(1, 0)
    draw_remaining(state)
    if state.table.hands[1].cards[0].rank_options != 1:
        return false
    return state.table.hands[1].cards[4].rank_options == 31 and state.table.hands[1].cards[4].color_options == 31

fun test_reordering_is_free_and_moves_knowledge() -> Bool:
    let state = ready_game(2, 0, 0, false)
    state.hint_color(0, 1, 1)
    if can state.reorder(2, 0, 1):
        return false
    if can state.reorder(1, -1, 1):
        return false
    if can state.reorder(1, 0, 5):
        return false
    if can state.reorder(1, 0, 0):
        return false
    let before = state.table.hands[1].cards[0]
    state.reorder(1, 0, 4)
    if state.table.hands[1].cards[4].color != before.color or state.table.hands[1].cards[4].color_options != before.color_options:
        return false
    state.reorder(0, 0, 1)
    return state.table.current_player == 1 and state.table.turns_played == 1 and state.table.blue == 7 and state.table.deck_left == 40

fun test_observation_hides_own_cards_and_retains_public_knowledge() -> Bool:
    let state = ready_game(2, 0, 0, false)
    state.hint_color(0, 1, 1)
    let view = observe(state.table, 1)
    if !view.valid or view.players != 2 or view.blue != 7 or view.current_player != 1 or view.deck_left != 40:
        return false
    let i = 0
    while i < 5:
        if view.hands[1].cards[i].color != -1 or view.hands[1].cards[i].rank != 0:
            return false
        if view.hands[1].cards[i].color_options != state.table.hands[1].cards[i].color_options:
            return false
        if view.hands[0].cards[i].color != state.table.hands[0].cards[i].color or view.hands[0].cards[i].rank != state.table.hands[0].cards[i].rank:
            return false
        i = i + 1
    view.hands[0].cards[0].color = -1
    return state.table.hands[0].cards[0].color == 0

fun test_invalid_observers_are_rejected() -> Bool:
    let state = ready_game(2, 0, 0, false)
    let a = observe(state.table, -1)
    let b = observe(state.table, 2)
    return !a.valid and !b.valid

fun test_last_draw_gives_each_player_one_further_turn() -> Bool:
    let state = ready_game(2, 0, 0, false)
    leave_one_draw(state.table, 0, 2)
    state.play_card(0, 0)
    if state.table.turns_left != -1:
        return false
    state.draw_card(0, 2)
    if state.table.deck_left != 0 or state.table.turns_left != 2 or state.table.current_player != 1 or state.is_done():
        return false
    state.hint_rank(1, 0, 1)
    if state.table.turns_left != 1 or state.table.current_player != 0 or state.is_done():
        return false
    state.play_card(0, 4)
    return state.is_done() and state.table.outcome == 3 and state.table.turns_left == 0 and state.table.hands[0].cards.size() == 4 and state.table.deck_left == 0 and no_turn_actions(state)

fun test_five_player_final_round_is_exactly_five_turns() -> Bool:
    let state = ready_game(5, 3, 0, false)
    leave_one_draw(state.table, 0, 2)
    state.play_card(3, 0)
    state.draw_card(0, 2)
    if state.table.turns_left != 5 or state.table.current_player != 4:
        return false
    let remaining = 5
    while remaining > 0:
        let actor = state.table.current_player
        state.hint_rank(actor, (actor + 1) % 5, 1)
        remaining = remaining - 1
        if state.table.turns_left != remaining:
            return false
        if remaining > 0 and state.is_done():
            return false
    return state.is_done() and state.table.outcome == 3 and state.table.current_player == 3 and state.table.turns_played == 6

fun test_completing_five_returns_one_token() -> Bool:
    let state = near_victory(0, false)
    state.table.blue = 6
    let before = state.table.deck_left
    state.play_card(0, 0)
    return state.is_done() and state.table.outcome == 1 and state.table.score == 25 and state.table.blue == 7 and state.table.deck_left == before and state.table.fireworks[4] == 5 and no_turn_actions(state)

fun test_five_bonus_is_capped_at_eight() -> Bool:
    let state = near_victory(0, false)
    state.play_card(0, 0)
    return state.is_done() and state.table.score == 25 and state.table.blue == 8 and state.table.strikes == 0

fun test_six_color_victory_requires_thirty_points() -> Bool:
    let variant = 1
    while variant <= 3:
        let state = near_victory(variant, false)
        if state.table.score != 29 or state.is_done():
            return false
        state.play_card(0, 0)
        if !state.is_done() or state.table.outcome != 1 or state.table.score != 30 or state.table.fireworks[5] != 5:
            return false
        variant = variant + 1
    return true

fun test_ordinary_multicolor_clue_names_the_sixth_suit() -> Bool:
    let state = ready_game(2, 0, 1, false)
    replace_card(state.table, 1, 0, 5, 2)
    if !(can state.hint_color(0, 1, 5)):
        return false
    state.hint_color(0, 1, 5)
    if state.table.hands[1].cards[0].color_options != 32:
        return false
    return state.table.last_hint_mask == 5 and state.table.hands[1].cards[1].color_options == 31

fun test_singleton_multicolor_deck_rejects_second_copy() -> Bool:
    let state = play()
    state.configure(2, 0, 2, false)
    let rank = 1
    while rank <= 5:
        state.deal_card(5, rank)
        if can state.deal_card(5, rank):
            return false
        rank = rank + 1
    return state.table.deck_left == 50

fun test_wild_multicolor_matches_every_ordinary_color_clue() -> Bool:
    let color = 0
    while color < 5:
        let state = ready_game(2, 0, 3, false)
        replace_card(state.table, 1, 0, 5, 2)
        if can state.hint_color(0, 1, 5):
            return false
        if !(can state.hint_color(0, 1, color)):
            return false
        state.hint_color(0, 1, color)
        let options = (1 << color) | 32
        if state.table.hands[1].cards[0].color_options != options or state.table.hands[1].cards[2].color_options != options:
            return false
        color = color + 1
    return true

fun test_wild_multicolor_still_builds_its_own_firework() -> Bool:
    let state = ready_game(2, 0, 3, false)
    replace_card(state.table, 0, 0, 5, 1)
    state.play_card(0, 0)
    return state.table.fireworks[5] == 1 and state.table.fireworks[0] == 0 and state.table.score == 1 and state.table.strikes == 0

fun test_extended_mode_does_not_stop_after_last_draw() -> Bool:
    let state = near_victory(0, true)
    # The only still-needed card is safely retained in player zero's hand.
    let id = 0
    while state.table.deck_counts[id] == 0:
        id = id + 1
    leave_one_draw(state.table, id / 5, id % 5 + 1)
    state.hint_rank(0, 1, 1)
    state.discard(1, 0)
    state.draw_card(id / 5, id % 5 + 1)
    if state.is_done() or state.table.deck_left != 0 or state.table.turns_left != -1:
        return false
    state.hint_rank(0, 1, 1)
    state.hint_rank(1, 0, 5)
    if state.is_done() or state.table.turns_left != -1:
        return false
    state.play_card(0, 0)
    return state.is_done() and state.table.outcome == 1 and state.table.score == 25

fun test_extended_mode_loses_when_last_needed_copy_is_discarded() -> Bool:
    let state = ready_game(2, 0, 0, true)
    replace_card(state.table, 0, 0, 0, 5)
    state.hint_rank(0, 1, 1)
    state.hint_rank(1, 0, 5)
    let before = state.table.deck_left
    state.discard(0, 0)
    return state.is_done() and state.table.outcome == 4 and state.table.strikes == 0 and state.table.deck_left == before and state.table.discard_counts[4] == 1

fun test_normal_mode_does_not_lose_when_a_needed_five_is_discarded() -> Bool:
    let state = ready_game(2, 0, 0, false)
    replace_card(state.table, 0, 0, 0, 5)
    state.hint_rank(0, 1, 1)
    state.hint_rank(1, 0, 5)
    state.discard(0, 0)
    if state.is_done() or state.table.phase != 3:
        return false
    draw_remaining(state)
    return !state.is_done() and state.table.current_player == 1 and state.table.outcome == 0

fun test_extended_singleton_multicolor_is_indispensable() -> Bool:
    let state = ready_game(2, 0, 2, true)
    replace_card(state.table, 0, 0, 5, 5)
    state.hint_rank(0, 1, 1)
    state.hint_rank(1, 0, 5)
    state.discard(0, 0)
    return state.is_done() and state.table.outcome == 4 and state.table.discard_counts[29] == 1

fun test_color_clue_without_any_matching_card_is_illegal() -> Bool:
    let state = ready_game(2, 0, 0, false)
    replace_card(state.table, 1, 2, 1, 2)
    return !(can state.hint_color(0, 1, 0)) and state.table.blue == 8 and state.table.turns_played == 0

fun test_repeated_wild_clues_intersect_to_multicolor_only() -> Bool:
    let state = ready_game(2, 0, 3, false)
    replace_card(state.table, 1, 0, 5, 2)
    state.hint_color(0, 1, 0)
    state.hint_rank(1, 0, 1)
    state.hint_color(0, 1, 1)
    return state.table.hands[1].cards[0].color_options == 32 and state.table.hands[1].cards[2].color_options == 32 and state.table.hands[1].cards[3].color_options == 2

fun test_five_bonus_also_applies_before_terminal_victory() -> Bool:
    let state = near_victory(0, false)
    state.table.fireworks[0] = 4
    state.table.deck_counts[4] = state.table.deck_counts[4] + 1
    state.table.deck_left = state.table.deck_left + 1
    state.table.score = 23
    state.table.blue = 7
    state.play_card(0, 0)
    return !state.is_done() and state.table.phase == 3 and state.table.score == 24 and state.table.blue == 8 and state.table.fireworks[4] == 5

fun test_artistic_rating_boundaries_and_variant_exclusions() -> Bool:
    let state = ready_game(2, 0, 0, false)
    let score = 0
    while score <= 25:
        state.table.score = score
        let expected = 0
        if score >= 6:
            expected = 1
        if score >= 11:
            expected = 2
        if score >= 16:
            expected = 3
        if score >= 21:
            expected = 4
        if score == 25:
            expected = 5
        if artistic_rating(state.table) != expected:
            return false
        score = score + 1
    state.table.extended = true
    if artistic_rating(state.table) != -1:
        return false
    state.table.extended = false
    state.table.colors = 6
    return artistic_rating(state.table) == -1

fun test_extended_loss_occurs_only_on_last_of_multiple_needed_copies() -> Bool:
    let state = ready_game(2, 0, 0, true)
    replace_card(state.table, 0, 0, 0, 2)
    if !invariant(state.table):
        return false
    state.hint_rank(0, 1, 1)
    state.hint_rank(1, 0, 2)
    state.discard(0, 0)
    if state.is_done() or state.table.discard_counts[1] != 1 or state.table.phase != 3 or !invariant(state.table):
        return false
    state.draw_card(0, 2)
    state.hint_rank(1, 0, 2)
    let before = state.table.deck_left
    state.discard(0, 4)
    return state.is_done() and state.table.outcome == 4 and state.table.discard_counts[1] == 2 and state.table.deck_left == before and state.table.strikes == 0 and invariant(state.table)

fun test_extended_failed_play_can_destroy_an_indispensable_card() -> Bool:
    let state = ready_game(2, 0, 0, true)
    replace_card(state.table, 0, 0, 0, 5)
    if !invariant(state.table):
        return false
    let before = state.table.deck_left
    state.play_card(0, 0)
    return state.is_done() and state.table.outcome == 4 and state.table.strikes == 1 and state.table.discard_counts[4] == 1 and state.table.score == 0 and state.table.deck_left == before and invariant(state.table)

fun test_extended_discarding_an_already_built_duplicate_stays_legal() -> Bool:
    let state = ready_game(2, 0, 0, true)
    state.play_card(0, 0)
    state.draw_card(0, 1)
    state.hint_rank(1, 0, 1)
    if !invariant(state.table) or !(can state.discard(0, 4)):
        return false
    state.discard(0, 4)
    if state.is_done() or state.table.outcome != 0 or state.table.fireworks[0] != 1 or state.table.discard_counts[0] != 1 or !invariant(state.table):
        return false
    draw_remaining(state)
    return !state.is_done() and state.table.score == 1 and state.table.blue == 8 and invariant(state.table)

fun test_fuse_defeat_retains_the_display_total() -> Bool:
    let state = ready_game(2, 0, 0, false)
    state.play_card(0, 0)
    draw_remaining(state)
    replace_card(state.table, 1, 0, 0, 3)
    state.play_card(1, 0)
    draw_remaining(state)
    replace_card(state.table, 0, 0, 0, 4)
    state.play_card(0, 0)
    draw_remaining(state)
    replace_card(state.table, 1, 0, 0, 3)
    if !invariant(state.table):
        return false
    state.play_card(1, 0)
    return state.is_done() and state.table.outcome == 2 and state.table.strikes == 3 and state.table.score == 1 and state.table.fireworks[0] == 1 and invariant(state.table)
