# Kuhn Poker has 6 ordered deals × 5 terminal action sequences, for a total of 30 combinations.
# The five sequences are bet → fold, bet → call, check → check, check → bet → fold, and check → bet → call.
import game

# Test 1: Initial State
fun test_initial_state() -> Bool:
    let game = play()
    if game.now_pot != 2:
        return false
    if game.player0.contribution != 1:
        return false
    if game.player1.contribution != 1:
        return false
    return !game.is_done()

# Test 2: Bet -> Fold
fun test_bet_fold() -> Bool:
    let game = play()
    game.deal(2, 0)
    game.p0_bet()
    game.p1_fold()
    if !game.is_done():
        return false
    if game.now_pot != 3:
        return false
    if game.player0.reward != 1:
        return false
    if game.player1.reward != -1:
        return false
    return true

# Test 3: Bet -> Call
fun test_bet_call() -> Bool:
    let game = play()
    game.deal(2, 0)
    game.p0_bet()
    game.p1_call()
    if !game.is_done():
        return false
    if game.now_pot != 4:
        return false
    if game.player0.reward != 2:
        return false
    if game.player1.reward != -2:
        return false
    return true


# Helpers for the additional rule tests. Querying can does not execute an action.
fun count_available_actions(Game game) -> Int:
    let count = 0
    if can game.deal(2, 0):
        count = count + 1
    if can game.p0_check():
        count = count + 1
    if can game.p0_bet():
        count = count + 1
    if can game.p0_fold():
        count = count + 1
    if can game.p0_call():
        count = count + 1
    if can game.p1_check():
        count = count + 1
    if can game.p1_bet():
        count = count + 1
    if can game.p1_fold():
        count = count + 1
    if can game.p1_call():
        count = count + 1
    return count

fun check_finished_game(Game game, Int card0, Int card1, Int pot, Int contribution0, Int contribution1, Int winner, Int reward0) -> Bool:
    if !game.is_done():
        return false
    if game.player0.card != card0 or game.player1.card != card1:
        return false
    if game.now_pot != pot:
        return false
    if game.player0.contribution != contribution0:
        return false
    if game.player1.contribution != contribution1:
        return false
    if game.now_pot != game.player0.contribution + game.player1.contribution:
        return false
    if game.winner != winner:
        return false
    if game.player0.reward != reward0 or game.player1.reward != 0 - reward0:
        return false
    return count_available_actions(game) == 0

# Tests 4-8: six ordered deals per route, covering all 30 terminal combinations.
fun test_all_deals_bet_fold() -> Bool:
    let card0 = 0
    while card0 < 3:
        let card1 = 0
        while card1 < 3:
            if card0 != card1:
                let game = play()
                game.deal(card0, card1)
                game.p0_bet()
                game.p1_fold()
                if !check_finished_game(game, card0, card1, 3, 2, 1, 0, 1):
                    return false
            card1 = card1 + 1
        card0 = card0 + 1
    return true

fun test_all_deals_bet_call() -> Bool:
    let card0 = 0
    while card0 < 3:
        let card1 = 0
        while card1 < 3:
            if card0 != card1:
                let game = play()
                game.deal(card0, card1)
                game.p0_bet()
                game.p1_call()
                let winner = 1
                let reward0 = -2
                if card0 > card1:
                    winner = 0
                    reward0 = 2
                if !check_finished_game(game, card0, card1, 4, 2, 2, winner, reward0):
                    return false
            card1 = card1 + 1
        card0 = card0 + 1
    return true

fun test_all_deals_check_check() -> Bool:
    let card0 = 0
    while card0 < 3:
        let card1 = 0
        while card1 < 3:
            if card0 != card1:
                let game = play()
                game.deal(card0, card1)
                game.p0_check()
                game.p1_check()
                let winner = 1
                let reward0 = -1
                if card0 > card1:
                    winner = 0
                    reward0 = 1
                if !check_finished_game(game, card0, card1, 2, 1, 1, winner, reward0):
                    return false
            card1 = card1 + 1
        card0 = card0 + 1
    return true

fun test_all_deals_check_bet_fold() -> Bool:
    let card0 = 0
    while card0 < 3:
        let card1 = 0
        while card1 < 3:
            if card0 != card1:
                let game = play()
                game.deal(card0, card1)
                game.p0_check()
                game.p1_bet()
                game.p0_fold()
                if !check_finished_game(game, card0, card1, 3, 1, 2, 1, -1):
                    return false
            card1 = card1 + 1
        card0 = card0 + 1
    return true

fun test_all_deals_check_bet_call() -> Bool:
    let card0 = 0
    while card0 < 3:
        let card1 = 0
        while card1 < 3:
            if card0 != card1:
                let game = play()
                game.deal(card0, card1)
                game.p0_check()
                game.p1_bet()
                game.p0_call()
                let winner = 1
                let reward0 = -2
                if card0 > card1:
                    winner = 0
                    reward0 = 2
                if !check_finished_game(game, card0, card1, 4, 2, 2, winner, reward0):
                    return false
            card1 = card1 + 1
        card0 = card0 + 1
    return true

# Test 9: both card bounds, duplicate cards, and all six valid deals.
fun test_deal_preconditions() -> Bool:
    let game = play()
    let card0 = -1
    while card0 < 4:
        let card1 = -1
        while card1 < 4:
            let expected = card0 >= 0 and card0 < 3 and card1 >= 0 and card1 < 3 and card0 != card1
            if (can game.deal(card0, card1)) != expected:
                return false
            card1 = card1 + 1
        card0 = card0 + 1
    # Legality queries must leave the game ready for the first deal.
    if game.is_done() or game.now_pot != 2:
        return false
    game.deal(2, 0)
    return game.player0.card == 2 and game.player1.card == 0

# Test 10: only the correct player's actions are available at each decision.
fun test_action_order() -> Bool:
    let game = play()
    if count_available_actions(game) != 1 or !(can game.deal(2, 0)):
        return false
    game.deal(2, 0)
    if game.is_done() or count_available_actions(game) != 2:
        return false
    if !(can game.p0_check()) or !(can game.p0_bet()):
        return false

    game.p0_check()
    if game.is_done() or count_available_actions(game) != 2:
        return false
    if !(can game.p1_check()) or !(can game.p1_bet()):
        return false
    if game.now_pot != 2 or game.player0.contribution != 1 or game.player1.contribution != 1:
        return false

    game.p1_bet()
    if game.is_done() or count_available_actions(game) != 2:
        return false
    if !(can game.p0_fold()) or !(can game.p0_call()):
        return false
    if game.now_pot != 3 or game.player0.contribution != 1 or game.player1.contribution != 2:
        return false
    game.p0_call()
    if !check_finished_game(game, 2, 0, 4, 2, 2, 0, 2):
        return false

    let bet_game = play()
    bet_game.deal(0, 2)
    bet_game.p0_bet()
    if bet_game.is_done() or count_available_actions(bet_game) != 2:
        return false
    if !(can bet_game.p1_fold()) or !(can bet_game.p1_call()):
        return false
    if bet_game.now_pot != 3 or bet_game.player0.contribution != 2 or bet_game.player1.contribution != 1:
        return false
    bet_game.p1_call()
    return check_finished_game(bet_game, 0, 2, 4, 2, 2, 1, -2)
