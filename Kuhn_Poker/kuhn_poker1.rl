enum CardNumber:
    J
    Q
    K

enum Player:
    player0
    player1

fun calculate_reward(
    Int winner,
    Int player,
    Int now_pot,
    Int contribution
) -> Int:
    if winner == player:
        return now_pot - contribution
    return 0 - contribution

act play() -> Game:
    frm play0 = 1   # 玩家0当前下的赌注
    frm play1 = 1   # 玩家1当前下的赌注
    frm init_pot = play0 + play1    #底池初始赌注
    frm now_pot = init_pot          #底池当前赌注
    frm card_play0 = 0              #玩家0拿到的牌
    frm card_play1 = 1              #玩家1拿到的牌
    frm is_p1_bet = false
    frm winner = -1                  #是否已经有玩家胜出

    act deal(Int card1, Int card2){
        card1 >= CardNumber::J.value and
        card1 <= CardNumber::K.value and
        card2 >= CardNumber::J.value and
        card2 <= CardNumber::K.value and
        card1 != card2
    }
        card_play0 = card1
        card_play1 = card2

    actions:
        act p0_check()
        act p0_bet()
            play0 = play0 + 1
            now_pot = play0 + play1
    
    # p0下注的情况下，if条件成立
    if now_pot > init_pot:
        actions:
            act p1_fold()
                winner = Player::player0.value
            act p1_call()
                play1 = play1 + 1
                now_pot = play0 + play1
    else:
        actions:
            act p1_check()
            act p1_bet()
                play1 = play1 + 1
                now_pot = play0 + play1
                is_p1_bet = true

    # p1也下注的情况下,交互行为再次流转到p0
    if is_p1_bet == true:
        actions:
            act p0_fold()
                winner = Player::player1.value
            act p0_call()
                play0 = play0 + 1
                now_pot = play0 + play1

    if winner == -1:
        if card_play0 > card_play1:
            winner = Player::player0.value
        else:
            winner = Player::player1.value

    frm reward0 = calculate_reward(winner, Player::player0.value, now_pot, play0)
    frm reward1 = calculate_reward(winner, Player::player1.value, now_pot, play1)

fun main() -> Int:
    let game = play()

    game.deal(2, 0)
    game.p0_bet()
    game.p1_fold()

    if !game.is_done():
        return 1

    if game.reward0 != 1:
        return 2

    if game.reward1 != -1:
        return 3

    return 0