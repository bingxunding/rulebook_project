import game

# Reproducible complete legal game corresponding to traces/game1.trace.txt.
# Expected scores were calculated independently from the printed rules.
fun main() -> Int:
    let state = play()
    if !(can state.setup(2, false, false, 0)):
        return 1
    state.setup(2, false, false, 0)
    if !(can state.deal(Card::Maki1)):
        return 1
    state.deal(Card::Maki1)
    if !(can state.deal(Card::Tempura)):
        return 1
    state.deal(Card::Tempura)
    if !(can state.deal(Card::Maki1)):
        return 1
    state.deal(Card::Maki1)
    if !(can state.deal(Card::Sashimi)):
        return 1
    state.deal(Card::Sashimi)
    if !(can state.deal(Card::Dumpling)):
        return 1
    state.deal(Card::Dumpling)
    if !(can state.deal(Card::Maki2)):
        return 1
    state.deal(Card::Maki2)
    if !(can state.deal(Card::Dumpling)):
        return 1
    state.deal(Card::Dumpling)
    if !(can state.deal(Card::Tempura)):
        return 1
    state.deal(Card::Tempura)
    if !(can state.deal(Card::Dumpling)):
        return 1
    state.deal(Card::Dumpling)
    if !(can state.deal(Card::SalmonNigiri)):
        return 1
    state.deal(Card::SalmonNigiri)
    if !(can state.deal(Card::Maki2)):
        return 1
    state.deal(Card::Maki2)
    if !(can state.deal(Card::Sashimi)):
        return 1
    state.deal(Card::Sashimi)
    if !(can state.deal(Card::SalmonNigiri)):
        return 1
    state.deal(Card::SalmonNigiri)
    if !(can state.deal(Card::Maki3)):
        return 1
    state.deal(Card::Maki3)
    if !(can state.deal(Card::Pudding)):
        return 1
    state.deal(Card::Pudding)
    if !(can state.deal(Card::Tempura)):
        return 1
    state.deal(Card::Tempura)
    if !(can state.deal(Card::SquidNigiri)):
        return 1
    state.deal(Card::SquidNigiri)
    if !(can state.deal(Card::Tempura)):
        return 1
    state.deal(Card::Tempura)
    if !(can state.deal(Card::SalmonNigiri)):
        return 1
    state.deal(Card::SalmonNigiri)
    if !(can state.deal(Card::Pudding)):
        return 1
    state.deal(Card::Pudding)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.deal(Card::Maki2)):
        return 1
    state.deal(Card::Maki2)
    if !(can state.deal(Card::Maki2)):
        return 1
    state.deal(Card::Maki2)
    if !(can state.deal(Card::Tempura)):
        return 1
    state.deal(Card::Tempura)
    if !(can state.deal(Card::Wasabi)):
        return 1
    state.deal(Card::Wasabi)
    if !(can state.deal(Card::Tempura)):
        return 1
    state.deal(Card::Tempura)
    if !(can state.deal(Card::Wasabi)):
        return 1
    state.deal(Card::Wasabi)
    if !(can state.deal(Card::SquidNigiri)):
        return 1
    state.deal(Card::SquidNigiri)
    if !(can state.deal(Card::Maki1)):
        return 1
    state.deal(Card::Maki1)
    if !(can state.deal(Card::Maki2)):
        return 1
    state.deal(Card::Maki2)
    if !(can state.deal(Card::Dumpling)):
        return 1
    state.deal(Card::Dumpling)
    if !(can state.deal(Card::Maki3)):
        return 1
    state.deal(Card::Maki3)
    if !(can state.deal(Card::Dumpling)):
        return 1
    state.deal(Card::Dumpling)
    if !(can state.deal(Card::Tempura)):
        return 1
    state.deal(Card::Tempura)
    if !(can state.deal(Card::SalmonNigiri)):
        return 1
    state.deal(Card::SalmonNigiri)
    if !(can state.deal(Card::EggNigiri)):
        return 1
    state.deal(Card::EggNigiri)
    if !(can state.deal(Card::Chopsticks)):
        return 1
    state.deal(Card::Chopsticks)
    if !(can state.deal(Card::Sashimi)):
        return 1
    state.deal(Card::Sashimi)
    if !(can state.deal(Card::Pudding)):
        return 1
    state.deal(Card::Pudding)
    if !(can state.deal(Card::Tempura)):
        return 1
    state.deal(Card::Tempura)
    if !(can state.deal(Card::Sashimi)):
        return 1
    state.deal(Card::Sashimi)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.chopsticks(0, 0, 1, -1)):
        return 1
    state.chopsticks(0, 0, 1, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.deal(Card::Maki3)):
        return 1
    state.deal(Card::Maki3)
    if !(can state.deal(Card::Pudding)):
        return 1
    state.deal(Card::Pudding)
    if !(can state.deal(Card::Maki1)):
        return 1
    state.deal(Card::Maki1)
    if !(can state.deal(Card::Pudding)):
        return 1
    state.deal(Card::Pudding)
    if !(can state.deal(Card::Maki2)):
        return 1
    state.deal(Card::Maki2)
    if !(can state.deal(Card::Wasabi)):
        return 1
    state.deal(Card::Wasabi)
    if !(can state.deal(Card::SalmonNigiri)):
        return 1
    state.deal(Card::SalmonNigiri)
    if !(can state.deal(Card::Sashimi)):
        return 1
    state.deal(Card::Sashimi)
    if !(can state.deal(Card::EggNigiri)):
        return 1
    state.deal(Card::EggNigiri)
    if !(can state.deal(Card::Maki2)):
        return 1
    state.deal(Card::Maki2)
    if !(can state.deal(Card::Maki1)):
        return 1
    state.deal(Card::Maki1)
    if !(can state.deal(Card::SalmonNigiri)):
        return 1
    state.deal(Card::SalmonNigiri)
    if !(can state.deal(Card::Maki1)):
        return 1
    state.deal(Card::Maki1)
    if !(can state.deal(Card::SalmonNigiri)):
        return 1
    state.deal(Card::SalmonNigiri)
    if !(can state.deal(Card::Maki2)):
        return 1
    state.deal(Card::Maki2)
    if !(can state.deal(Card::Tempura)):
        return 1
    state.deal(Card::Tempura)
    if !(can state.deal(Card::EggNigiri)):
        return 1
    state.deal(Card::EggNigiri)
    if !(can state.deal(Card::Chopsticks)):
        return 1
    state.deal(Card::Chopsticks)
    if !(can state.deal(Card::Sashimi)):
        return 1
    state.deal(Card::Sashimi)
    if !(can state.deal(Card::Maki2)):
        return 1
    state.deal(Card::Maki2)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.pick(0, 0, -1)):
        return 1
    state.pick(0, 0, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !(can state.chopsticks(0, 0, 1, -1)):
        return 1
    state.chopsticks(0, 0, 1, -1)
    if !(can state.pick(1, 0, -1)):
        return 1
    state.pick(1, 0, -1)
    if !state.is_done():
        return 2
    if state.table.players[0].score != 46 or state.table.players[1].score != 43:
        return 3
    if state.table.players[0].puddings != 2 or state.table.players[1].puddings != 3:
        return 4
    if !state.table.winners[0] or state.table.winners[1]:
        return 5
    let remaining = 0
    let card = 0
    while card < 12:
        remaining = remaining + state.table.stock[card]
        card = card + 1
    if remaining != 48:
        return 6
    return 0
