import kuhn_poker

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