import game

# ========================================
# Test
# ========================================
fun main() -> Int:
    let game = play()

    game.deal(2, 0)
    game.p0_bet()
    game.p1_fold()

    if !game.is_done():
        return 1

    if game.player0.reward != 1:
        return 2

    if game.player1.reward != -1:
        return 3

    return 0
