import game

# A complete deterministic two-player game, independently scored from the PDF.
# Round totals are (11, 7), (15, 12), and (22, 12).
# Puddings add (0, 6), producing final scores (48, 37).
fun main() -> Int:
    let game = play()
    if !(can game.configure(2, false, false, 0)):
        return 1
    game.configure(2, false, false, 0)
    let deck : Int[60]
    deck[0] = 4
    deck[1] = 6
    deck[2] = 6
    deck[3] = 3
    deck[4] = 4
    deck[5] = 5
    deck[6] = 9
    deck[7] = 4
    deck[8] = 6
    deck[9] = 8
    deck[10] = 2
    deck[11] = 4
    deck[12] = 9
    deck[13] = 8
    deck[14] = 1
    deck[15] = 5
    deck[16] = 5
    deck[17] = 5
    deck[18] = 4
    deck[19] = 1
    deck[20] = 7
    deck[21] = 7
    deck[22] = 1
    deck[23] = 3
    deck[24] = 1
    deck[25] = 3
    deck[26] = 0
    deck[27] = 2
    deck[28] = 0
    deck[29] = 10
    deck[30] = 9
    deck[31] = 8
    deck[32] = 1
    deck[33] = 7
    deck[34] = 2
    deck[35] = 9
    deck[36] = 4
    deck[37] = 10
    deck[38] = 9
    deck[39] = 0
    deck[40] = 6
    deck[41] = 0
    deck[42] = 6
    deck[43] = 5
    deck[44] = 9
    deck[45] = 6
    deck[46] = 1
    deck[47] = 10
    deck[48] = 0
    deck[49] = 9
    deck[50] = 3
    deck[51] = 10
    deck[52] = 2
    deck[53] = 4
    deck[54] = 1
    deck[55] = 7
    deck[56] = 1
    deck[57] = 5
    deck[58] = 6
    deck[59] = 0
    let position = 0
    let round = 0
    while round < 3:
        let dealt = 0
        while dealt < 20:
            let card : Card
            card.value = deck[position]
            if !(can game.deal(card)):
                return 2
            game.deal(card)
            position = position + 1
            dealt = dealt + 1
        let turn = 0
        while turn < 9:
            if !(can game.choose(0, 0, -1, -1)):
                return 3
            game.choose(0, 0, -1, -1)
            if !(can game.choose(1, 0, -1, -1)):
                return 4
            game.choose(1, 0, -1, -1)
            turn = turn + 1
        round = round + 1
    if !game.is_done() or game.s.round != 4:
        return 5
    if game.s.seats[0].score != 48 or game.s.seats[1].score != 37:
        return 6
    if game.s.seats[0].puddings != 3 or game.s.seats[1].puddings != 4:
        return 7
    if !game.s.seats[0].winner or game.s.seats[1].winner:
        return 8
    if game.s.remaining.value.total != 48:
        return 9
    let expected_supply : Int[12]
    expected_supply[0] = 8
    expected_supply[1] = 6
    expected_supply[2] = 10
    expected_supply[3] = 2
    expected_supply[4] = 5
    expected_supply[5] = 2
    expected_supply[6] = 3
    expected_supply[7] = 1
    expected_supply[8] = 2
    expected_supply[9] = 3
    expected_supply[10] = 2
    expected_supply[11] = 4
    let index = 0
    while index < 12:
        if game.s.remaining.value.counts[index] != expected_supply[index]:
            return 10
        index = index + 1
    if can game.choose(0, 0, -1, -1):
        return 11
    return 0
