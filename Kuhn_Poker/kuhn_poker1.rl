
enum CardNumber:
    J
    Q
    K

enum PlayerId:
    player0
    player1

# ========================================
# Player Class
# ========================================
cls Player:
    Int contribution
    Int card
    Int reward

    fun init():
        self.contribution = 1
        self.card = -1
        self.reward = 0


# ========================================
# Calculate Reward
# ========================================
fun calculate_reward(
    Int winner,
    Int player,
    Int now_pot,
    Int contribution
) -> Int:
    if winner == player:
        return now_pot - contribution
    return 0 - contribution


# ========================================
# Main Game
# ========================================

act play() -> Game:

    # Step 1: Initialize & Ante
    frm player0 : Player
    frm player1 : Player
    frm init_pot = player0.contribution + player1.contribution    # 底池初始赌注
    frm now_pot = init_pot                                       # 底池当前赌注
    frm is_p1_bet = false
    frm winner = -1                                              # 是否已经有玩家胜出


    # Step 2: Deal
    act deal(Int card1, Int card2){
        card1 >= CardNumber::J.value and
        card1 <= CardNumber::K.value and
        card2 >= CardNumber::J.value and
        card2 <= CardNumber::K.value and
        card1 != card2
    }
        player0.card = card1
        player1.card = card2


    # Step 4: Player 0 Decision
    actions:
        act p0_check()
        act p0_bet()
            player0.contribution = player0.contribution + 1
            now_pot = player0.contribution + player1.contribution


    # Step 5: Player 1 Decision
    # p0下注的情况下，if条件成立
    if now_pot > init_pot:
        actions:
            act p1_fold()
                winner = PlayerId::player0.value

            act p1_call()
                player1.contribution = player1.contribution + 1
                now_pot = player0.contribution + player1.contribution

    else:
        actions:
            act p1_check()

            act p1_bet()
                player1.contribution = player1.contribution + 1
                now_pot = player0.contribution + player1.contribution
                is_p1_bet = true


    # p1也下注的情况下，交互行为再次流转到p0
    if is_p1_bet == true:
        actions:
            act p0_fold()
                winner = PlayerId::player1.value

            act p0_call()
                player0.contribution = player0.contribution + 1
                now_pot = player0.contribution + player1.contribution


    # Step 6: Determine Winner
    if winner == -1:
        if player0.card > player1.card:
            winner = PlayerId::player0.value
        else:
            winner = PlayerId::player1.value


    # Step 7: Calculate Rewards
    player0.reward = calculate_reward(winner, PlayerId::player0.value, now_pot, player0.contribution)
    player1.reward = calculate_reward(winner, PlayerId::player1.value, now_pot, player1.contribution)

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
