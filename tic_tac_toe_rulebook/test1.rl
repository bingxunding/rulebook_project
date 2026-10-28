import serialization.print

act play() -> Game:
    frm score = 0

    act move(Int value)
    score = score + value

    act finish()
    print("Game Finished")


fun main() -> Int:
    print("1. Before creating game")

    let game = play()

    print("2. Game created")

    game.finish()  # 故意跳过 move()，直接调用 finish()

    print("3. After finish")

    return 0