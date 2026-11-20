import game

# A legal shuffle prefix, followed by one success and three failed plays.
fun main() -> Int:
    let game = play()
    game.configure(2, 0, 0, false)
    let rank = 1
    while rank <= 5:
        game.deal_card(0, rank)
        game.deal_card(1, rank)
        rank = rank + 1
    game.play_card(0, 0)
    game.draw_card(2, 2)
    game.play_card(1, 1)
    game.draw_card(2, 3)
    game.play_card(0, 1)
    game.draw_card(2, 4)
    game.play_card(1, 1)
    if !game.is_done() or game.table.outcome != 2:
        return 1
    if game.table.score != 1 or game.table.strikes != 3:
        return 2
    if game.table.deck_left != 37 or game.table.turns_played != 4:
        return 3
    if can game.draw_card(2, 1):
        return 4
    if !invariant(game.table):
        return 5
    return 0
