import game

# Repeated collection models cards already revealed in the stated order.
fun collect_copies(Player player, Int card, Int count):
    let index = 0
    while index < count:
        collect(player, card)
        index = index + 1

fun test_empty_tableau_scores_zero() -> Bool:
    let player : Player
    return set_score(player) == 0

fun test_tempura_pairs_and_leftovers() -> Bool:
    let player : Player
    collect(player, Card::Tempura.value)
    if set_score(player) != 0:
        return false
    collect(player, Card::Tempura.value)
    if set_score(player) != 5:
        return false
    collect(player, Card::Tempura.value)
    if set_score(player) != 5:
        return false
    collect(player, Card::Tempura.value)
    return set_score(player) == 10

fun test_sashimi_triples_and_leftovers() -> Bool:
    let player : Player
    collect(player, Card::Sashimi.value)
    if set_score(player) != 0:
        return false
    collect(player, Card::Sashimi.value)
    if set_score(player) != 0:
        return false
    collect(player, Card::Sashimi.value)
    if set_score(player) != 10:
        return false
    collect_copies(player, Card::Sashimi.value, 2)
    if set_score(player) != 10:
        return false
    collect(player, Card::Sashimi.value)
    return set_score(player) == 20

fun test_dumpling_scoring_all_thresholds() -> Bool:
    let player : Player
    collect(player, Card::Dumpling.value)
    if set_score(player) != 1:
        return false
    collect(player, Card::Dumpling.value)
    if set_score(player) != 3:
        return false
    collect(player, Card::Dumpling.value)
    if set_score(player) != 6:
        return false
    collect(player, Card::Dumpling.value)
    if set_score(player) != 10:
        return false
    collect(player, Card::Dumpling.value)
    if set_score(player) != 15:
        return false
    collect_copies(player, Card::Dumpling.value, 9)
    return set_score(player) == 15

fun test_nigiri_base_values() -> Bool:
    let egg : Player
    let salmon : Player
    let squid : Player
    collect(egg, Card::EggNigiri.value)
    collect(salmon, Card::SalmonNigiri.value)
    collect(squid, Card::SquidNigiri.value)
    return set_score(egg) == 1 and set_score(salmon) == 2 and set_score(squid) == 3

fun test_each_nigiri_tripled_by_prior_wasabi() -> Bool:
    let egg : Player
    let salmon : Player
    let squid : Player
    collect(egg, Card::Wasabi.value)
    collect(salmon, Card::Wasabi.value)
    collect(squid, Card::Wasabi.value)
    collect(egg, Card::EggNigiri.value)
    collect(salmon, Card::SalmonNigiri.value)
    collect(squid, Card::SquidNigiri.value)
    return set_score(egg) == 3 and set_score(salmon) == 6 and set_score(squid) == 9

fun test_wasabi_does_not_change_earlier_nigiri() -> Bool:
    let player : Player
    collect(player, Card::SalmonNigiri.value)
    collect(player, Card::Wasabi.value)
    if set_score(player) != 2 or player.unused_wasabi != 1:
        return false
    collect(player, Card::SquidNigiri.value)
    return set_score(player) == 11 and player.unused_wasabi == 0

fun test_one_nigiri_per_wasabi_and_mandatory_next_use() -> Bool:
    let player : Player
    collect_copies(player, Card::Wasabi.value, 2)
    collect(player, Card::SalmonNigiri.value)
    if player.unused_wasabi != 1 or set_score(player) != 6:
        return false
    collect(player, Card::Tempura.value)
    collect(player, Card::EggNigiri.value)
    if player.unused_wasabi != 0 or set_score(player) != 9:
        return false
    collect(player, Card::SquidNigiri.value)
    return set_score(player) == 12

fun test_unused_wasabi_and_chopsticks_score_zero() -> Bool:
    let player : Player
    collect_copies(player, Card::Wasabi.value, 3)
    collect_copies(player, Card::Chopsticks.value, 2)
    return set_score(player) == 0 and player.unused_wasabi == 3

fun test_pudding_is_retained_but_not_round_scored() -> Bool:
    let player : Player
    collect_copies(player, Card::Pudding.value, 3)
    return player.puddings == 3 and set_score(player) == 0

fun test_independent_food_sets_add_together() -> Bool:
    let player : Player
    collect_copies(player, Card::Tempura.value, 2)
    collect_copies(player, Card::Sashimi.value, 3)
    collect_copies(player, Card::Dumpling.value, 4)
    collect(player, Card::Wasabi.value)
    collect(player, Card::SalmonNigiri.value)
    return set_score(player) == 31

# The rulebook's example has icon totals 5, 3, 3, 2.
fun test_maki_rulebook_example_and_weighted_icons() -> Bool:
    let table : Table
    table.seats = 4
    collect(table.players[0], Card::Maki2.value)
    collect(table.players[0], Card::Maki3.value)
    collect(table.players[1], Card::Maki3.value)
    collect_copies(table.players[2], Card::Maki1.value, 3)
    collect(table.players[3], Card::Maki2.value)
    score_maki(table)
    return table.players[0].score == 6 and table.players[1].score == 1 and table.players[2].score == 1 and table.players[3].score == 0

fun test_maki_tied_first_suppresses_second_award() -> Bool:
    let table : Table
    table.seats = 3
    collect(table.players[0], Card::Maki3.value)
    collect(table.players[1], Card::Maki3.value)
    collect(table.players[2], Card::Maki2.value)
    score_maki(table)
    return table.players[0].score == 3 and table.players[1].score == 3 and table.players[2].score == 0

fun test_maki_five_way_first_tie_drops_remainder() -> Bool:
    let table : Table
    table.seats = 5
    let seat = 0
    while seat < 5:
        collect(table.players[seat], Card::Maki1.value)
        seat = seat + 1
    score_maki(table)
    seat = 0
    while seat < 5:
        if table.players[seat].score != 1:
            return false
        seat = seat + 1
    return true

fun test_maki_four_way_second_tie_awards_zero() -> Bool:
    let table : Table
    table.seats = 5
    collect(table.players[0], Card::Maki2.value)
    let seat = 1
    while seat < 5:
        collect(table.players[seat], Card::Maki1.value)
        seat = seat + 1
    score_maki(table)
    if table.players[0].score != 6:
        return false
    seat = 1
    while seat < 5:
        if table.players[seat].score != 0:
            return false
        seat = seat + 1
    return true

fun test_maki_awards_add_to_existing_score() -> Bool:
    let table : Table
    table.seats = 3
    table.players[0].score = 17
    table.players[1].score = 11
    table.players[2].score = 8
    collect(table.players[0], Card::Maki3.value)
    collect(table.players[1], Card::Maki2.value)
    collect(table.players[2], Card::Maki1.value)
    score_maki(table)
    return table.players[0].score == 23 and table.players[1].score == 14 and table.players[2].score == 8

fun test_zero_maki_icons_never_score() -> Bool:
    let table : Table
    table.seats = 5
    score_maki(table)
    let seat = 0
    while seat < 5:
        if table.players[seat].score != 0:
            return false
        seat = seat + 1
    return true

fun test_single_maki_collector_gets_no_zero_icon_runner_up() -> Bool:
    let table : Table
    table.seats = 3
    collect(table.players[0], Card::Maki1.value)
    score_maki(table)
    return table.players[0].score == 6 and table.players[1].score == 0 and table.players[2].score == 0

fun test_maki_scoring_ignores_inactive_seats() -> Bool:
    let table : Table
    table.seats = 2
    collect(table.players[0], Card::Maki2.value)
    collect(table.players[1], Card::Maki1.value)
    collect_copies(table.players[4], Card::Maki3.value, 3)
    score_maki(table)
    return table.players[0].score == 6 and table.players[1].score == 3 and table.players[4].score == 0

fun test_pudding_rulebook_example() -> Bool:
    let table : Table
    table.seats = 4
    table.players[0].puddings = 4
    table.players[1].puddings = 3
    score_puddings(table)
    return table.players[0].score == 6 and table.players[1].score == 0 and table.players[2].score == -3 and table.players[3].score == -3

fun test_pudding_tied_most_split_award() -> Bool:
    let table : Table
    table.seats = 4
    table.players[0].puddings = 3
    table.players[1].puddings = 3
    table.players[2].puddings = 1
    score_puddings(table)
    return table.players[0].score == 3 and table.players[1].score == 3 and table.players[2].score == 0 and table.players[3].score == -6

fun test_pudding_four_way_most_tie_drops_remainder() -> Bool:
    let table : Table
    table.seats = 5
    let seat = 0
    while seat < 4:
        table.players[seat].puddings = 2
        seat = seat + 1
    score_puddings(table)
    seat = 0
    while seat < 4:
        if table.players[seat].score != 1:
            return false
        seat = seat + 1
    return table.players[4].score == -6

fun test_pudding_four_way_least_tie_loses_one_each() -> Bool:
    let table : Table
    table.seats = 5
    table.players[0].puddings = 3
    score_puddings(table)
    if table.players[0].score != 6:
        return false
    let seat = 1
    while seat < 5:
        if table.players[seat].score != -1:
            return false
        seat = seat + 1
    return true

fun test_pudding_all_zero_has_no_awards_or_penalties() -> Bool:
    let table : Table
    table.seats = 5
    score_puddings(table)
    let seat = 0
    while seat < 5:
        if table.players[seat].score != 0:
            return false
        seat = seat + 1
    return true

fun test_pudding_all_equal_positive_has_no_awards() -> Bool:
    let table : Table
    table.seats = 3
    let seat = 0
    while seat < 3:
        table.players[seat].puddings = 2
        table.players[seat].score = 7
        seat = seat + 1
    score_puddings(table)
    return table.players[0].score == 7 and table.players[1].score == 7 and table.players[2].score == 7

fun test_two_player_pudding_has_no_negative_points() -> Bool:
    let table : Table
    table.seats = 2
    table.players[0].puddings = 4
    table.players[0].score = 12
    table.players[1].score = 15
    score_puddings(table)
    return table.players[0].score == 18 and table.players[1].score == 15

fun test_two_player_tied_pudding_has_no_award() -> Bool:
    let table : Table
    table.seats = 2
    table.players[0].puddings = 2
    table.players[1].puddings = 2
    score_puddings(table)
    return table.players[0].score == 0 and table.players[1].score == 0

fun test_highest_score_wins_before_pudding_tiebreak() -> Bool:
    let table : Table
    table.seats = 3
    table.players[0].score = 20
    table.players[1].score = 19
    table.players[1].puddings = 8
    table.players[2].score = 18
    find_winners(table)
    return table.winners[0] and !table.winners[1] and !table.winners[2] and !table.winners[3] and !table.winners[4]

fun test_equal_score_uses_most_puddings() -> Bool:
    let table : Table
    table.seats = 3
    table.players[0].score = 20
    table.players[1].score = 20
    table.players[2].score = 20
    table.players[0].puddings = 2
    table.players[1].puddings = 4
    table.players[2].puddings = 3
    find_winners(table)
    return !table.winners[0] and table.winners[1] and !table.winners[2]

fun test_equal_score_and_puddings_produce_co_winners() -> Bool:
    let table : Table
    table.seats = 3
    table.players[0].score = 12
    table.players[1].score = 12
    table.players[2].score = 11
    table.players[0].puddings = 3
    table.players[1].puddings = 3
    table.players[2].puddings = 5
    find_winners(table)
    return table.winners[0] and table.winners[1] and !table.winners[2]

fun test_winner_can_have_negative_total_score() -> Bool:
    let table : Table
    table.seats = 3
    table.players[0].score = -4
    table.players[1].score = -1
    table.players[2].score = -3
    find_winners(table)
    return !table.winners[0] and table.winners[1] and !table.winners[2]


# Transition helpers choose concrete legal actions and preserve chance semantics.
fun transition_deal_remaining(Game game) -> Bool:
    while game.table.dealt < game.table.seats * game.table.hand_size:
        let card = 0
        while card < 12 and game.table.stock[card] == 0:
            card = card + 1
        if card == 12:
            return false
        if !(can game.deal(card_from_int(card))):
            return false
        game.deal(card_from_int(card))
        if !state_is_valid(game.table):
            return false
    return true

fun transition_finish(Game game) -> Bool:
    let steps = 0
    while !game.is_done() and steps < 1000:
        if game.table.dealt < game.table.seats * game.table.hand_size:
            if !transition_deal_remaining(game):
                return false
        else:
            let player = game.table.actor
            let gift = -1
            if game.table.dummy and player == game.table.controller:
                gift = 1
            if !(can game.pick(player, 0, gift)):
                return false
            game.pick(player, 0, gift)
            if !state_is_valid(game.table):
                return false
        steps = steps + 1
    return game.is_done()

fun transition_stock_total(Table table) -> Int:
    let total = 0
    let i = 0
    while i < 12:
        total = total + table.stock[i]
        i = i + 1
    return total

fun transition_tableau_total(Player player) -> Int:
    let total = 0
    let i = 0
    while i < 12:
        total = total + player.tableau[i]
        i = i + 1
    return total

# A reproducible opening: player 0 has chopsticks then nine tempura;
# player 1 has nine sashimi then chopsticks.
fun transition_chopsticks_opening(Game game):
    game.setup(2, false, false, 0)
    game.deal(Card::Chopsticks)
    let i = 0
    while i < 9:
        game.deal(Card::Tempura)
        i = i + 1
    i = 0
    while i < 9:
        game.deal(Card::Sashimi)
        i = i + 1
    game.deal(Card::Chopsticks)

fun test_transition_initial_phase() -> Bool:
    let game = play()
    if game.is_done():
        return false
    if !(can game.setup(2, false, false, 0)):
        return false
    if can game.deal(Card::Tempura):
        return false
    if can game.pick(0, 0, -1):
        return false
    return !(can game.chopsticks(0, 0, 1, -1))

fun test_transition_setup_bounds() -> Bool:
    let game = play()
    if can game.setup(1, false, false, 0):
        return false
    if can game.setup(6, false, false, 0):
        return false
    if can game.setup(-9223372036854775807, false, false, 0):
        return false
    if can game.setup(9223372036854775807, false, false, 0):
        return false
    if can game.setup(3, false, true, 0):
        return false
    if can game.setup(2, false, true, -1):
        return false
    if can game.setup(2, false, true, 2):
        return false
    if can game.setup(2, false, false, 1):
        return false
    return (can game.setup(2, false, true, 0)) and (can game.setup(2, false, true, 1))

fun test_transition_player_counts_and_hand_sizes() -> Bool:
    let humans = 2
    while humans <= 5:
        let game = play()
        game.setup(humans, false, false, 0)
        let expected = 10
        if humans == 3:
            expected = 9
        if humans == 4:
            expected = 8
        if humans == 5:
            expected = 7
        if game.table.seats != humans or game.table.humans != humans or game.table.hand_size != expected:
            return false
        if !transition_deal_remaining(game):
            return false
        let player = 0
        while player < humans:
            if game.table.players[player].hand.size != expected:
                return false
            player = player + 1
        if transition_stock_total(game.table) != 108 - humans * expected:
            return false
        humans = humans + 1
    return true

fun test_transition_exact_deck_multiplicities() -> Bool:
    let game = play()
    game.setup(2, false, false, 0)
    let expected : Int[12]
    expected[0] = 14
    expected[1] = 14
    expected[2] = 14
    expected[3] = 6
    expected[4] = 12
    expected[5] = 8
    expected[6] = 5
    expected[7] = 10
    expected[8] = 5
    expected[9] = 10
    expected[10] = 6
    expected[11] = 4
    let i = 0
    while i < 12:
        if game.table.stock[i] != expected[i]:
            return false
        i = i + 1
    return transition_stock_total(game.table) == 108

fun test_transition_deal_card_bounds_and_exhaustion() -> Bool:
    let game = play()
    game.setup(2, false, false, 0)
    if can game.deal(card_from_int(-1)):
        return false
    if can game.deal(card_from_int(12)):
        return false
    if can game.deal(card_from_int(-9223372036854775807)):
        return false
    if can game.deal(card_from_int(9223372036854775807)):
        return false
    let i = 0
    while i < 14:
        if !(can game.deal(Card::Tempura)):
            return false
        game.deal(Card::Tempura)
        i = i + 1
    if game.table.stock[0] != 0 or can game.deal(Card::Tempura):
        return false
    return can game.deal(Card::Sashimi)

fun test_transition_deal_and_pick_phase_order() -> Bool:
    let game = play()
    game.setup(2, false, false, 0)
    if can game.setup(2, false, false, 0):
        return false
    if can game.pick(0, 0, -1):
        return false
    if !transition_deal_remaining(game):
        return false
    if can game.deal(Card::Sashimi):
        return false
    if can game.pick(1, 0, -1):
        return false
    game.pick(0, 0, -1)
    if can game.pick(0, 0, -1):
        return false
    return can game.pick(1, 0, -1)

fun test_transition_choice_bounds() -> Bool:
    let game = play()
    transition_chopsticks_opening(game)
    if can game.pick(-1, 0, -1):
        return false
    if can game.pick(2, 0, -1):
        return false
    if can game.pick(9223372036854775807, 0, -1):
        return false
    if can game.pick(0, -1, -1):
        return false
    if can game.pick(0, 10, -1):
        return false
    if can game.pick(0, 9223372036854775807, -1):
        return false
    if can game.pick(0, 0, 1):
        return false
    if can game.chopsticks(0, 0, 1, -1):
        return false
    return (can game.pick(0, 0, -1)) and (can game.pick(0, 9, -1))

fun test_transition_simultaneous_reveal() -> Bool:
    let game = play()
    transition_chopsticks_opening(game)
    game.pick(0, 0, -1)
    if transition_tableau_total(game.table.players[0]) != 0:
        return false
    if transition_tableau_total(game.table.players[1]) != 0:
        return false
    if game.table.players[0].score != 0 or game.table.players[1].score != 0:
        return false
    game.pick(1, 0, -1)
    return game.table.players[0].tableau[11] == 1 and game.table.players[1].tableau[1] == 1 and game.table.turn == 1

fun test_transition_chopsticks_delayed_use_and_return() -> Bool:
    let game = play()
    transition_chopsticks_opening(game)
    if can game.chopsticks(0, 0, 1, -1):
        return false
    game.pick(0, 0, -1)
    game.pick(1, 0, -1)
    if !(can game.chopsticks(0, 0, 1, -1)):
        return false
    if can game.chopsticks(0, 0, 0, -1):
        return false
    if can game.chopsticks(0, -1, 0, -1):
        return false
    if can game.chopsticks(0, 0, 9, -1):
        return false
    game.chopsticks(0, 0, 1, -1)
    game.pick(1, 0, -1)
    if game.table.players[0].tableau[11] != 0 or game.table.players[0].tableau[1] != 2:
        return false
    if game.table.players[0].hand.size != 8 or game.table.players[1].hand.size != 8:
        return false
    if game.table.players[1].hand.cards[7] != Card::Chopsticks.value:
        return false
    return !(can game.chopsticks(0, 0, 1, -1))

fun test_transition_multiple_chopsticks_use_exactly_one() -> Bool:
    let game = play()
    transition_chopsticks_opening(game)
    game.pick(0, 0, -1)
    game.pick(1, 0, -1)
    # The second chopsticks is now the last card of player 0's received hand.
    game.pick(0, 8, -1)
    game.pick(1, 0, -1)
    if game.table.players[0].tableau[11] != 2:
        return false
    if !(can game.chopsticks(0, 0, 1, -1)):
        return false
    game.chopsticks(0, 0, 1, -1)
    game.pick(1, 0, -1)
    # One activation returns exactly one of the two chopsticks.
    if game.table.players[0].tableau[11] != 1 or game.table.players[0].tableau[0] != 2:
        return false
    return game.table.players[1].hand.size == 7 and game.table.players[1].hand.cards[6] == 11

fun test_transition_final_singletons_pass_before_reveal() -> Bool:
    let game = play()
    game.setup(2, false, false, 0)
    let i = 0
    while i < 9:
        game.deal(Card::Tempura)
        i = i + 1
    game.deal(Card::EggNigiri)
    i = 0
    while i < 9:
        game.deal(Card::Sashimi)
        i = i + 1
    game.deal(Card::SquidNigiri)
    i = 0
    while i < 8:
        game.pick(0, 0, -1)
        game.pick(1, 0, -1)
        i = i + 1
    if game.table.players[0].hand.size != 2 or game.table.players[1].hand.size != 2:
        return false
    game.pick(0, 0, -1)
    if game.table.round != 0:
        return false
    game.pick(1, 0, -1)
    # Nine left passes swap two hands an odd number of times.
    # The singletons are automatically awarded, so player 0 gets squid (3),
    # player 1 gets egg (1). Both have 20 set points, so scores differ by 2.
    if game.table.round != 1:
        return false
    return game.table.players[0].score - game.table.players[1].score == 2

fun test_transition_left_and_reverse_passing() -> Bool:
    let table : Table
    table.seats = 3
    table.humans = 3
    table.alternate = true
    table.players[0].hand.append(0)
    table.players[1].hand.append(1)
    table.players[2].hand.append(2)
    pass_hands(table)
    if table.players[0].hand.cards[0] != 2 or table.players[1].hand.cards[0] != 0 or table.players[2].hand.cards[0] != 1:
        return false
    table.round = 1
    pass_hands(table)
    if table.players[0].hand.cards[0] != 0 or table.players[1].hand.cards[0] != 1 or table.players[2].hand.cards[0] != 2:
        return false
    table.round = 2
    pass_hands(table)
    return table.players[0].hand.cards[0] == 2 and table.players[1].hand.cards[0] == 0 and table.players[2].hand.cards[0] == 1

fun test_transition_normal_round_two_still_passes_left() -> Bool:
    let table : Table
    table.seats = 3
    table.humans = 3
    table.round = 1
    table.players[0].hand.append(0)
    table.players[1].hand.append(1)
    table.players[2].hand.append(2)
    pass_hands(table)
    return table.players[0].hand.cards[0] == 2 and table.players[1].hand.cards[0] == 0 and table.players[2].hand.cards[0] == 1

fun test_transition_round_reset_preserves_pudding_and_stock() -> Bool:
    let table : Table
    table.seats = 3
    table.players[0].puddings = 4
    table.players[0].score = 17
    table.players[0].tableau[9] = 2
    table.players[0].tableau[11] = 1
    table.players[0].unused_wasabi = 2
    table.players[0].nigiri_points = 9
    table.players[0].last_round_score = 13
    table.stock[0] = 7
    table.dealt = 27
    table.turn = 8
    begin_round(table)
    if table.players[0].puddings != 4 or table.players[0].score != 17 or table.stock[0] != 7:
        return false
    return transition_tableau_total(table.players[0]) == 0 and table.players[0].unused_wasabi == 0 and table.players[0].nigiri_points == 0 and table.players[0].last_round_score == 0 and table.dealt == 0 and table.turn == 0

fun test_transition_full_games_all_player_counts() -> Bool:
    let humans = 2
    while humans <= 5:
        let game = play()
        game.setup(humans, false, false, 0)
        if !transition_finish(game):
            return false
        if game.table.round != 3:
            return false
        let expected_left = 48
        if humans == 3:
            expected_left = 27
        if humans == 4:
            expected_left = 12
        if humans == 5:
            expected_left = 3
        if transition_stock_total(game.table) != expected_left:
            return false
        let player = 0
        while player < humans:
            if game.table.players[player].hand.size != 0:
                return false
            player = player + 1
        humans = humans + 1
    return true

fun test_transition_full_alternate_direction_game() -> Bool:
    let game = play()
    game.setup(4, true, false, 0)
    return transition_finish(game) and transition_stock_total(game.table) == 12

fun test_transition_terminal_rejects_all_actions() -> Bool:
    let game = play()
    game.setup(2, false, false, 0)
    if !transition_finish(game):
        return false
    if can game.setup(2, false, false, 0):
        return false
    if can game.deal(Card::Tempura):
        return false
    if can game.pick(0, 0, -1):
        return false
    return !(can game.chopsticks(0, 0, 1, -1))

fun test_transition_dummy_setup_and_top_draw() -> Bool:
    let game = play()
    game.setup(2, false, true, 1)
    let i = 0
    while i < 9:
        game.deal(Card::Tempura)
        i = i + 1
    i = 0
    while i < 9:
        game.deal(Card::Sashimi)
        i = i + 1
    game.deal(Card::EggNigiri)
    i = 0
    while i < 8:
        game.deal(Card::Dumpling)
        i = i + 1
    if game.table.seats != 3 or game.table.hand_size != 9 or game.table.controller != 1:
        return false
    if game.table.players[0].hand.size != 9 or game.table.players[1].hand.size != 10 or game.table.players[2].hand.size != 8:
        return false
    return game.table.players[1].hand.cards[9] == Card::EggNigiri.value and game.table.players[2].hand.cards[0] == Card::Dumpling.value

fun test_transition_dummy_gift_bounds_and_control() -> Bool:
    let game = play()
    game.setup(2, false, true, 0)
    if !transition_deal_remaining(game):
        return false
    if can game.pick(0, 0, -1):
        return false
    if can game.pick(0, 0, 0):
        return false
    if can game.pick(0, 0, 10):
        return false
    if !(can game.pick(0, 0, 1)):
        return false
    game.pick(0, 0, 1)
    if can game.pick(1, 0, 1):
        return false
    game.pick(1, 0, -1)
    return game.table.controller == 1 and game.table.players[2].hand.size == 7 and transition_tableau_total(game.table.players[2]) == 1

fun test_transition_dummy_final_turn_stays_a_choice() -> Bool:
    let game = play()
    game.setup(2, false, true, 0)
    if !transition_deal_remaining(game):
        return false
    let i = 0
    while i < 8:
        let gift0 = -1
        let gift1 = -1
        if game.table.controller == 0:
            gift0 = 1
        else:
            gift1 = 1
        game.pick(0, 0, gift0)
        game.pick(1, 0, gift1)
        i = i + 1
    if game.table.round != 0 or game.table.controller != 0:
        return false
    if game.table.players[0].hand.size != 2 or game.table.players[1].hand.size != 1 or game.table.players[2].hand.size != 0:
        return false
    return (can game.pick(0, 0, 1)) and (can game.pick(0, 1, 0))

fun test_transition_full_dummy_games_both_initial_controllers() -> Bool:
    let controller = 0
    while controller < 2:
        let game = play()
        game.setup(2, false, true, controller)
        if !transition_finish(game):
            return false
        if transition_stock_total(game.table) != 27 or game.table.round != 3:
            return false
        let player = 0
        while player < 3:
            if game.table.players[player].hand.size != 0:
                return false
            player = player + 1
        controller = controller + 1
    return true

# Two legal commitments test the user-approved within-turn card order.
fun transition_paired_wasabi_opening(Game game):
    game.setup(2, false, false, 0)
    game.deal(Card::Chopsticks)
    let i = 0
    while i < 9:
        game.deal(Card::Tempura)
        i = i + 1
    game.deal(Card::Sashimi)
    game.deal(Card::Wasabi)
    game.deal(Card::SquidNigiri)
    i = 0
    while i < 7:
        game.deal(Card::Dumpling)
        i = i + 1
    game.pick(0, 0, -1)
    game.pick(1, 0, -1)

fun test_transition_paired_wasabi_then_nigiri() -> Bool:
    let game = play()
    transition_paired_wasabi_opening(game)
    if !(can game.chopsticks(0, 0, 1, -1)):
        return false
    game.chopsticks(0, 0, 1, -1)
    if !state_is_valid(game.table):
        return false
    game.pick(1, 0, -1)
    return game.table.players[0].nigiri_points == 9 and game.table.players[0].unused_wasabi == 0 and game.table.players[0].tableau[10] == 1 and game.table.players[0].tableau[8] == 1 and state_is_valid(game.table)

fun test_transition_paired_nigiri_then_wasabi() -> Bool:
    let game = play()
    transition_paired_wasabi_opening(game)
    if !(can game.chopsticks(0, 1, 0, -1)):
        return false
    game.chopsticks(0, 1, 0, -1)
    if !state_is_valid(game.table):
        return false
    game.pick(1, 0, -1)
    return game.table.players[0].nigiri_points == 3 and game.table.players[0].unused_wasabi == 1 and game.table.players[0].tableau[10] == 1 and game.table.players[0].tableau[8] == 1 and state_is_valid(game.table)

fun test_transition_dummy_controller_chopsticks_and_gift() -> Bool:
    let game = play()
    game.setup(2, false, true, 1)
    game.deal(Card::Chopsticks)
    let i = 0
    while i < 8:
        game.deal(Card::Tempura)
        i = i + 1
    i = 0
    while i < 9:
        game.deal(Card::Sashimi)
        i = i + 1
    i = 0
    while i < 9:
        game.deal(Card::Dumpling)
        i = i + 1
    game.pick(0, 0, -1)
    game.pick(1, 0, 1)
    # Controller 0 now owns chopsticks and has an augmented nine-card hand.
    if game.table.controller != 0 or game.table.players[0].hand.size != 9:
        return false
    if can game.chopsticks(0, 0, 1, 0):
        return false
    if can game.chopsticks(0, 0, 1, 1):
        return false
    if can game.chopsticks(0, 0, 1, -1):
        return false
    if !(can game.chopsticks(0, 0, 1, 2)):
        return false
    game.chopsticks(0, 0, 1, 2)
    if !state_is_valid(game.table):
        return false
    game.pick(1, 0, -1)
    if game.table.players[0].tableau[11] != 0 or game.table.players[0].tableau[1] != 2:
        return false
    if game.table.players[2].tableau[1] != 2:
        return false
    # One turn removes one card from each passed human hand. The next controller
    # immediately draws from the dummy pile; the returned chopsticks is just
    # before that new top card in controller 1's augmented received hand.
    if game.table.players[0].hand.size != 7 or game.table.players[1].hand.size != 8:
        return false
    return game.table.players[1].hand.cards[6] == Card::Chopsticks.value and state_is_valid(game.table)

fun test_transition_dummy_controller_continues_across_rounds() -> Bool:
    let game = play()
    game.setup(2, false, true, 0)
    if !transition_deal_remaining(game):
        return false
    let turn = 0
    while turn < 9:
        let gift0 = -1
        let gift1 = -1
        if game.table.controller == 0:
            gift0 = 1
        else:
            gift1 = 1
        game.pick(0, 0, gift0)
        if !state_is_valid(game.table):
            return false
        game.pick(1, 0, gift1)
        if !state_is_valid(game.table):
            return false
        turn = turn + 1
    if game.table.round != 1 or game.table.controller != 1:
        return false
    if !transition_deal_remaining(game):
        return false
    return game.table.controller == 1 and game.table.players[0].hand.size == 9 and game.table.players[1].hand.size == 10 and game.table.players[2].hand.size == 8
