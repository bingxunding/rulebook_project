import game

fun card_for_test(Int value) -> Card:
    let card : Card
    card.value = value
    return card

fun visible_cards(Player player) -> Int:
    let total = 0
    let card = 0
    while card < 12:
        total = total + player.table[card]
        card = card + 1
    return total

# Deal the lowest remaining card type, without inventing a new deck.
fun deal_round_for_test(Game game) -> Bool:
    let count = game.s.participants * game.s.hand_size
    let dealt = 0
    while dealt < count:
        let card = 0
        while card < 12 and game.s.remaining.value.counts[card] == 0:
            card = card + 1
        if card == 12:
            return false
        if !(can game.deal(card_for_test(card))):
            return false
        game.deal(card_for_test(card))
        dealt = dealt + 1
    return true

# This deterministic policy only executes legal actions from the initial state.
fun finish_round_for_test(Game game) -> Bool:
    let round = game.s.round
    let limit = 0
    while !game.is_done() and game.s.round == round and limit < 60:
        let player = 0
        while player < game.s.players and game.s.round == round:
            let dummy_index = -1
            if game.s.dummy_mode and player == game.s.controller:
                dummy_index = 1
            if !(can game.choose(player, 0, -1, dummy_index)):
                return false
            game.choose(player, 0, -1, dummy_index)
            player = player + 1
        limit = limit + 1
    return game.s.round != round

fun complete_game_for_test(Int players, Bool alternate, Bool dummy, Int controller) -> Bool:
    let game = play()
    game.configure(players, alternate, dummy, controller)
    let participants = players
    let size = 12 - players
    if dummy:
        participants = 3
        size = 9
    let round = 1
    while round <= 3:
        if game.s.round != round or game.is_done():
            return false
        if !deal_round_for_test(game):
            return false
        if !finish_round_for_test(game):
            return false
        round = round + 1
    if !game.is_done() or game.s.round != 4:
        return false
    if game.s.remaining.value.total != 108 - 3 * participants * size:
        return false
    let winners = 0
    let player = 0
    while player < participants:
        if game.s.seats[player].winner:
            winners = winners + 1
        if game.s.seats[player].hand.value.size != 0:
            return false
        if can game.choose(player, 0, -1, -1):
            return false
        player = player + 1
    return winners > 0 and !(can game.deal(Card::tempura)) and !(can game.configure(players, alternate, dummy, controller))

# Two balanced legal opening hands, each containing most card types.
fun deal_mechanics_hands(Game game):
    game.deal(Card::chopsticks)
    game.deal(Card::wasabi)
    game.deal(Card::salmon_nigiri)
    game.deal(Card::egg_nigiri)
    game.deal(Card::squid_nigiri)
    game.deal(Card::tempura)
    game.deal(Card::sashimi)
    game.deal(Card::dumpling)
    game.deal(Card::maki_one)
    game.deal(Card::pudding)
    game.deal(Card::wasabi)
    game.deal(Card::salmon_nigiri)
    game.deal(Card::egg_nigiri)
    game.deal(Card::squid_nigiri)
    game.deal(Card::tempura)
    game.deal(Card::sashimi)
    game.deal(Card::dumpling)
    game.deal(Card::maki_one)
    game.deal(Card::pudding)
    game.deal(Card::chopsticks)

fun test_initial_action_order() -> Bool:
    let game = play()
    if game.is_done() or !(can game.configure(2, false, false, 0)):
        return false
    return !(can game.deal(Card::tempura)) and !(can game.choose(0, 0, -1, -1))

fun test_player_count_and_configuration_bounds() -> Bool:
    let game = play()
    if can game.configure(1, false, false, 0):
        return false
    if can game.configure(6, false, false, 0):
        return false
    if can game.configure(3, false, true, 0):
        return false
    if can game.configure(2, false, true, -1):
        return false
    if can game.configure(2, false, true, 2):
        return false
    let players = 2
    while players <= 5:
        let configured = play()
        configured.configure(players, false, false, 0)
        if configured.s.players != players or configured.s.participants != players:
            return false
        if configured.s.hand_size != 12 - players or configured.s.round != 1:
            return false
        if can configured.configure(players, false, false, 0):
            return false
        if can configured.choose(0, 0, -1, -1):
            return false
        players = players + 1
    return true

fun test_exact_deck_composition() -> Bool:
    let game = play()
    game.configure(2, false, false, 0)
    if game.s.remaining.value.total != 108:
        return false
    let card = 0
    let sum = 0
    while card < 12:
        let expected = 14
        if card == 3:
            expected = 6
        if card == 4:
            expected = 12
        if card == 5:
            expected = 8
        if card == 6 or card == 9:
            expected = 10
        if card == 7 or card == 8:
            expected = 5
        if card == 10:
            expected = 6
        if card == 11:
            expected = 4
        if game.s.remaining.value.counts[card] != expected:
            return false
        sum = sum + expected
        card = card + 1
    return sum == 108

fun test_deal_without_replacement_and_enum_bounds() -> Bool:
    let game = play()
    game.configure(2, false, false, 0)
    if can game.deal(card_for_test(-1)):
        return false
    if can game.deal(card_for_test(12)):
        return false
    let count = 0
    while count < 5:
        if !(can game.deal(Card::squid_nigiri)):
            return false
        game.deal(Card::squid_nigiri)
        count = count + 1
    if can game.deal(Card::squid_nigiri):
        return false
    return game.s.remaining.value.counts[7] == 0 and game.s.remaining.value.total == 103 and game.s.seats[0].hand.value.size == 5

fun test_choice_bounds_and_commit_barrier() -> Bool:
    let game = play()
    game.configure(2, false, false, 0)
    deal_mechanics_hands(game)
    if can game.deal(Card::tempura):
        return false
    if can game.choose(-1, 0, -1, -1):
        return false
    if can game.choose(2, 0, -1, -1):
        return false
    if can game.choose(0, -1, -1, -1):
        return false
    if can game.choose(0, 10, -1, -1):
        return false
    if can game.choose(0, 0, 1, -1):
        return false
    if can game.choose(0, 0, -1, 1):
        return false
    game.choose(0, 0, -1, -1)
    if !game.s.seats[0].committed or game.s.seats[1].committed:
        return false
    if visible_cards(game.s.seats[0]) != 0 or visible_cards(game.s.seats[1]) != 0:
        return false
    if game.s.seats[1].hand.value.cards[0] != 10:
        return false
    if can game.choose(0, 1, -1, -1):
        return false
    game.choose(1, 0, -1, -1)
    if game.s.seats[0].table[11] != 1 or game.s.seats[1].table[10] != 1:
        return false
    return game.s.seats[0].hand.value.size == 9 and game.s.seats[1].hand.value.size == 9 and game.s.seats[0].hand.value.cards[0] == 6 and game.s.seats[1].hand.value.cards[0] == 10

fun test_chopsticks_return_and_later_reuse() -> Bool:
    let game = play()
    game.configure(2, false, false, 0)
    deal_mechanics_hands(game)
    game.choose(0, 0, -1, -1)
    game.choose(1, 0, -1, -1)
    if !(can game.choose(0, 0, 1, -1)):
        return false
    if can game.choose(0, 0, 0, -1):
        return false
    if can game.choose(0, 0, 9, -1):
        return false
    if can game.choose(0, 0, -2, -1):
        return false
    game.choose(0, 0, 1, -1)
    game.choose(1, 0, -1, -1)
    if game.s.seats[0].table[11] != 0 or game.s.seats[0].table[6] != 1 or game.s.seats[0].table[8] != 1:
        return false
    if game.s.seats[0].nigiri_points != 3:
        return false
    if game.s.seats[1].hand.value.size != 8 or game.s.seats[1].hand.value.cards[7] != 11:
        return false
    if can game.choose(0, 0, 1, -1):
        return false
    game.choose(0, 0, -1, -1)
    game.choose(1, 7, -1, -1)
    return game.s.seats[1].table[11] == 1 and (can game.choose(1, 0, 1, -1))

fun test_final_card_is_automatic() -> Bool:
    let game = play()
    game.configure(2, false, false, 0)
    deal_mechanics_hands(game)
    let turn = 0
    while turn < 8:
        game.choose(0, 0, -1, -1)
        game.choose(1, 0, -1, -1)
        turn = turn + 1
    if game.s.round != 1 or game.s.seats[0].hand.value.size != 2:
        return false
    game.choose(0, 0, -1, -1)
    game.choose(1, 0, -1, -1)
    return game.s.round == 2 and game.s.seats[0].hand.value.size == 0 and game.s.seats[1].hand.value.size == 0 and (can game.deal(Card::tempura))

fun test_tempura_sets_and_leftovers() -> Bool:
    let player : Player
    let count = 0
    while count <= 14:
        if local_points(player) != (count / 2) * 5:
            return false
        if count < 14:
            add_card(player, 0)
        count = count + 1
    return true

fun test_sashimi_sets_and_leftovers() -> Bool:
    let player : Player
    let count = 0
    while count <= 14:
        if local_points(player) != (count / 3) * 10:
            return false
        if count < 14:
            add_card(player, 1)
        count = count + 1
    return true

fun test_dumpling_progression_and_cap() -> Bool:
    let player : Player
    if local_points(player) != 0:
        return false
    add_card(player, 2)
    if local_points(player) != 1:
        return false
    add_card(player, 2)
    if local_points(player) != 3:
        return false
    add_card(player, 2)
    if local_points(player) != 6:
        return false
    add_card(player, 2)
    if local_points(player) != 10:
        return false
    let count = 4
    while count < 14:
        add_card(player, 2)
        if local_points(player) != 15:
            return false
        count = count + 1
    return true

fun test_all_nigiri_values_and_forced_wasabi() -> Bool:
    let card = 6
    while card <= 8:
        let value = 2
        if card == 7:
            value = 3
        if card == 8:
            value = 1
        let player : Player
        add_card(player, card)
        if local_points(player) != value:
            return false
        add_card(player, 10)
        if local_points(player) != value or player.unused_wasabi != 1:
            return false
        add_card(player, card)
        if local_points(player) != 4 * value or player.unused_wasabi != 0:
            return false
        add_card(player, card)
        if local_points(player) != 5 * value:
            return false
        card = card + 1
    return true

fun test_multiple_wasabi_and_pick_order() -> Bool:
    let player : Player
    add_card(player, 10)
    add_card(player, 10)
    add_card(player, 7)
    add_card(player, 8)
    add_card(player, 6)
    if local_points(player) != 14 or player.unused_wasabi != 0:
        return false
    let forward : Player
    add_card(forward, 10)
    add_card(forward, 6)
    let reverse : Player
    add_card(reverse, 6)
    add_card(reverse, 10)
    return local_points(forward) == 6 and local_points(reverse) == 2 and reverse.unused_wasabi == 1

fun test_zero_value_cards_and_maki_icons() -> Bool:
    let player : Player
    add_card(player, 3)
    add_card(player, 4)
    add_card(player, 5)
    add_card(player, 9)
    add_card(player, 10)
    add_card(player, 11)
    return local_points(player) == 0 and maki_icons(player) == 6 and player.puddings == 1

fun test_maki_rulebook_example() -> Bool:
    let state : State
    state.participants = 4
    state.seats[0].table[3] = 5
    state.seats[1].table[3] = 3
    state.seats[2].table[3] = 3
    state.seats[3].table[3] = 2
    score_round(state)
    return state.seats[0].score == 6 and state.seats[1].score == 1 and state.seats[2].score == 1 and state.seats[3].score == 0

fun test_maki_first_tie_suppresses_second() -> Bool:
    let state : State
    state.participants = 4
    state.seats[0].table[5] = 2
    state.seats[1].table[4] = 3
    state.seats[2].table[3] = 5
    score_round(state)
    return state.seats[0].score == 3 and state.seats[1].score == 3 and state.seats[2].score == 0 and state.seats[3].score == 0

fun test_maki_all_zero_and_rounding() -> Bool:
    let players = 2
    while players <= 5:
        let state : State
        state.participants = players
        score_round(state)
        let player = 0
        while player < players:
            if state.seats[player].score != 6 / players:
                return false
            player = player + 1
        players = players + 1
    let state : State
    state.participants = 5
    state.seats[0].table[3] = 1
    score_round(state)
    return state.seats[0].score == 6 and state.seats[1].score == 0 and state.seats[2].score == 0 and state.seats[3].score == 0 and state.seats[4].score == 0

fun test_round_score_accumulates_local_points() -> Bool:
    let state : State
    state.participants = 2
    state.seats[0].score = 11
    state.seats[1].score = 7
    add_card(state.seats[0], 0)
    add_card(state.seats[0], 0)
    add_card(state.seats[0], 4)
    add_card(state.seats[1], 2)
    score_round(state)
    return state.seats[0].score == 22 and state.seats[1].score == 11

fun test_pudding_rulebook_example() -> Bool:
    let state : State
    state.participants = 4
    state.seats[0].puddings = 4
    state.seats[1].puddings = 3
    score_puddings(state)
    return state.seats[0].score == 6 and state.seats[1].score == 0 and state.seats[2].score == -3 and state.seats[3].score == -3

fun test_pudding_ties_truncate() -> Bool:
    let state : State
    state.participants = 5
    state.seats[0].puddings = 1
    state.seats[1].puddings = 1
    state.seats[2].puddings = 1
    state.seats[3].puddings = 1
    score_puddings(state)
    if state.seats[0].score != 1 or state.seats[1].score != 1 or state.seats[2].score != 1 or state.seats[3].score != 1 or state.seats[4].score != -6:
        return false
    let low_tie : State
    low_tie.participants = 5
    low_tie.seats[0].puddings = 1
    score_puddings(low_tie)
    return low_tie.seats[0].score == 6 and low_tie.seats[1].score == -1 and low_tie.seats[2].score == -1 and low_tie.seats[3].score == -1 and low_tie.seats[4].score == -1

fun test_pudding_all_equal_is_zero() -> Bool:
    let players = 2
    while players <= 5:
        let state : State
        state.participants = players
        let player = 0
        while player < players:
            state.seats[player].puddings = 2
            state.seats[player].score = 10
            player = player + 1
        score_puddings(state)
        player = 0
        while player < players:
            if state.seats[player].score != 10:
                return false
            player = player + 1
        players = players + 1
    return true

fun test_two_player_pudding_has_no_penalty() -> Bool:
    let state : State
    state.players = 2
    state.participants = 2
    state.seats[0].puddings = 1
    score_puddings(state)
    return state.seats[0].score == 6 and state.seats[1].score == 0

fun test_winner_points_then_pudding_then_shared_tie() -> Bool:
    let state : State
    state.participants = 4
    state.seats[0].score = 20
    state.seats[0].puddings = 1
    state.seats[1].score = 20
    state.seats[1].puddings = 2
    state.seats[2].score = 19
    state.seats[2].puddings = 5
    state.seats[3].score = 20
    state.seats[3].puddings = 2
    state.seats[4].winner = true
    choose_winners(state)
    return !state.seats[0].winner and state.seats[1].winner and !state.seats[2].winner and state.seats[3].winner and !state.seats[4].winner

fun test_complete_two_player_game() -> Bool:
    return complete_game_for_test(2, false, false, 0)

fun test_complete_three_player_game() -> Bool:
    return complete_game_for_test(3, false, false, 0)

fun test_complete_four_player_game() -> Bool:
    return complete_game_for_test(4, false, false, 0)

fun test_complete_five_player_game() -> Bool:
    return complete_game_for_test(5, false, false, 0)

fun test_complete_pass_both_ways_game() -> Bool:
    return complete_game_for_test(3, true, false, 0)

fun test_complete_dummy_game_controller_zero() -> Bool:
    return complete_game_for_test(2, false, true, 0)

fun test_complete_dummy_game_controller_one() -> Bool:
    return complete_game_for_test(2, false, true, 1)

fun deal_three_hands_for_test(Game game, Card first, Card second, Card third):
    let count = 0
    while count < 9:
        game.deal(first)
        count = count + 1
    count = 0
    while count < 9:
        game.deal(second)
        count = count + 1
    count = 0
    while count < 9:
        game.deal(third)
        count = count + 1

fun test_left_pass_and_alternate_round_two_right_pass() -> Bool:
    let game = play()
    game.configure(3, true, false, 0)
    deal_three_hands_for_test(game, Card::tempura, Card::sashimi, Card::dumpling)
    game.choose(0, 0, -1, -1)
    game.choose(1, 0, -1, -1)
    game.choose(2, 0, -1, -1)
    if game.s.seats[0].hand.value.cards[0] != 2 or game.s.seats[1].hand.value.cards[0] != 0 or game.s.seats[2].hand.value.cards[0] != 1:
        return false
    if !finish_round_for_test(game) or game.s.round != 2:
        return false
    deal_three_hands_for_test(game, Card::salmon_nigiri, Card::maki_two, Card::pudding)
    game.choose(0, 0, -1, -1)
    game.choose(1, 0, -1, -1)
    game.choose(2, 0, -1, -1)
    return game.s.seats[0].hand.value.cards[0] == 4 and game.s.seats[1].hand.value.cards[0] == 9 and game.s.seats[2].hand.value.cards[0] == 6

fun test_round_reset_preserves_pudding_and_discards_other_cards() -> Bool:
    let game = play()
    game.configure(2, false, false, 0)
    deal_mechanics_hands(game)
    if !finish_round_for_test(game):
        return false
    if game.s.seats[0].puddings + game.s.seats[1].puddings != 2:
        return false
    if visible_cards(game.s.seats[0]) != 0 or visible_cards(game.s.seats[1]) != 0:
        return false
    if game.s.seats[0].unused_wasabi != 0 or game.s.seats[1].unused_wasabi != 0:
        return false
    if game.s.seats[0].nigiri_points != 0 or game.s.seats[1].nigiri_points != 0:
        return false
    let discarded = 0
    let card = 0
    while card < 12:
        let expected = 2
        if card == 4 or card == 5 or card == 9:
            expected = 0
        if game.s.discarded[card] != expected:
            return false
        discarded = discarded + game.s.discarded[card]
        card = card + 1
    return discarded == 18 and game.s.remaining.value.total == 88

fun test_chopsticks_wasabi_then_nigiri_reveal() -> Bool:
    let game = play()
    game.configure(2, false, false, 0)
    deal_mechanics_hands(game)
    game.choose(0, 0, -1, -1)
    game.choose(1, 1, -1, -1)
    game.choose(0, 0, 2, -1)
    game.choose(1, 0, -1, -1)
    return game.s.seats[0].table[11] == 0 and game.s.seats[0].table[10] == 1 and game.s.seats[0].table[7] == 1 and game.s.seats[0].unused_wasabi == 0 and game.s.seats[0].nigiri_points == 9

fun test_chopsticks_nigiri_then_wasabi_reveal() -> Bool:
    let game = play()
    game.configure(2, false, false, 0)
    deal_mechanics_hands(game)
    game.choose(0, 0, -1, -1)
    game.choose(1, 1, -1, -1)
    game.choose(0, 2, 0, -1)
    game.choose(1, 0, -1, -1)
    return game.s.seats[0].table[11] == 0 and game.s.seats[0].table[10] == 1 and game.s.seats[0].table[7] == 1 and game.s.seats[0].unused_wasabi == 1 and game.s.seats[0].nigiri_points == 3

fun test_dummy_selection_and_controller_alternation() -> Bool:
    let game = play()
    game.configure(2, false, true, 0)
    if !deal_round_for_test(game):
        return false
    if game.s.participants != 3 or game.s.hand_size != 9 or game.s.controller != 0:
        return false
    if game.s.dummy_pile.value.size != 8 or game.s.seats[0].hand.value.size != 10 or game.s.seats[1].hand.value.size != 9:
        return false
    if can game.choose(0, 0, -1, -1):
        return false
    if can game.choose(0, 0, -1, 0):
        return false
    if can game.choose(0, 0, -1, 10):
        return false
    if can game.choose(1, 0, -1, 1):
        return false
    if can game.choose(2, 0, -1, -1):
        return false
    game.choose(0, 0, -1, 1)
    if visible_cards(game.s.seats[2]) != 0:
        return false
    game.choose(1, 0, -1, -1)
    if game.s.controller != 1 or game.s.dummy_pile.value.size != 7:
        return false
    if game.s.seats[0].hand.value.size != 8 or game.s.seats[1].hand.value.size != 9:
        return false
    if game.s.seats[2].table[0] != 1:
        return false
    return !(can game.choose(1, 0, -1, -1)) and (can game.choose(1, 0, -1, 1)) and (can game.choose(0, 0, -1, -1))

fun test_dummy_is_scored_and_can_win() -> Bool:
    let state : State
    state.players = 2
    state.participants = 3
    state.dummy_mode = true
    state.seats[2].puddings = 2
    score_puddings(state)
    if state.seats[0].score != -3 or state.seats[1].score != -3 or state.seats[2].score != 6:
        return false
    choose_winners(state)
    return !state.seats[0].winner and !state.seats[1].winner and state.seats[2].winner

# Nine turns reverse the controller each round; dealing must preserve that order.
fun test_dummy_control_continues_across_all_round_boundaries() -> Bool:
    let initial_controller = 0
    while initial_controller <= 1:
        let game = play()
        game.configure(2, false, true, initial_controller)
        let round = 1
        while round <= 3:
            let expected_controller = initial_controller
            if round == 2:
                expected_controller = 1 - initial_controller
            if game.s.round != round or game.s.controller != expected_controller:
                return false
            if !deal_round_for_test(game):
                return false
            if game.s.controller != expected_controller or game.s.turn != 0:
                return false
            if game.s.seats[expected_controller].hand.value.size != 10:
                return false
            if game.s.seats[1 - expected_controller].hand.value.size != 9 or game.s.dummy_pile.value.size != 8:
                return false
            if can game.choose(expected_controller, 0, -1, -1):
                return false
            if !(can game.choose(expected_controller, 0, -1, 1)):
                return false
            if !finish_round_for_test(game):
                return false
            if game.s.round != round + 1 or game.s.turn != 9 or game.s.controller != 1 - expected_controller:
                return false
            round = round + 1
        if !game.is_done():
            return false
        initial_controller = initial_controller + 1
    return true
