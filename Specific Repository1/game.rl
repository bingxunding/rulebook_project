# Sushi Go! (2014): card identifiers follow the rulebook's twelve card types.
enum Card:
    Tempura
    Sashimi
    Dumpling
    Maki1
    Maki2
    Maki3
    EggNigiri
    SalmonNigiri
    SquidNigiri
    Pudding
    Wasabi
    Chopsticks

fun card_from_int(Int value) -> Card:
    let card : Card
    card.value = value
    return card

fun card_supply(Int card) -> Int:
    if card >= 0 and card <= 2:
        return 14
    if card == 3 or card == 10:
        return 6
    if card == 4:
        return 12
    if card == 5:
        return 8
    if card == 6 or card == 8:
        return 5
    if card == 7 or card == 9:
        return 10
    if card == 11:
        return 4
    return 0

fun hand_size_for(Int seats) -> Int:
    if seats == 2:
        return 10
    return 12 - seats

cls Hand:
    Int[11] cards
    Int size

    fun init():
        self.size = 0
        let i = 0
        while i < 11:
            self.cards[i] = -1
            i = i + 1

    fun append(Int card):
        assert(self.size < 11, "Hand capacity exceeded")
        self.cards[self.size] = card
        self.size = self.size + 1

    fun erase(Int index):
        assert(index >= 0 and index < self.size, "Invalid hand index")
        let i = index
        while i + 1 < self.size:
            self.cards[i] = self.cards[i + 1]
            i = i + 1
        self.size = self.size - 1
        self.cards[self.size] = -1

cls Player:
    Hand hand
    Int[12] tableau
    Int puddings
    Int unused_wasabi
    Int nigiri_points
    Int score
    Int last_round_score

# Ordered collection makes the first nigiri use one previously unused wasabi.
fun collect(Player player, Int card):
    assert(card >= 0 and card < 12, "Invalid card")
    player.tableau[card] = player.tableau[card] + 1
    if card == Card::Pudding.value:
        player.puddings = player.puddings + 1
    if card == Card::Wasabi.value:
        player.unused_wasabi = player.unused_wasabi + 1
    if card >= Card::EggNigiri.value and card <= Card::SquidNigiri.value:
        let points = card - Card::EggNigiri.value + 1
        if player.unused_wasabi > 0:
            player.unused_wasabi = player.unused_wasabi - 1
            points = points * 3
        player.nigiri_points = player.nigiri_points + points

fun set_score(Player player) -> Int:
    let dumplings = player.tableau[Card::Dumpling.value]
    if dumplings > 5:
        dumplings = 5
    return (player.tableau[Card::Tempura.value] / 2) * 5 + (player.tableau[Card::Sashimi.value] / 3) * 10 + (dumplings * (dumplings + 1)) / 2 + player.nigiri_points

cls Table:
    Player[5] players
    Int[12] stock
    Int seats
    Int humans
    Int hand_size
    Int round
    Int dealt
    Int turn
    Int actor
    Int controller
    Bool alternate
    Bool dummy
    Int[5] first
    Int[5] second
    Int[5] gift
    Bool[5] used_chopsticks
    Bool[5] winners

fun maki_icons(Player player) -> Int:
    return player.tableau[Card::Maki1.value] + 2 * player.tableau[Card::Maki2.value] + 3 * player.tableau[Card::Maki3.value]

fun score_puddings(Table table):
    let most = table.players[0].puddings
    let least = most
    let i = 1
    while i < table.seats:
        if table.players[i].puddings > most:
            most = table.players[i].puddings
        if table.players[i].puddings < least:
            least = table.players[i].puddings
        i = i + 1
    if most == least:
        return
    let top_count = 0
    let bottom_count = 0
    i = 0
    while i < table.seats:
        if table.players[i].puddings == most:
            top_count = top_count + 1
        if table.players[i].puddings == least:
            bottom_count = bottom_count + 1
        i = i + 1
    i = 0
    while i < table.seats:
        if table.players[i].puddings == most:
            table.players[i].score = table.players[i].score + 6 / top_count
        if table.seats != 2 and table.players[i].puddings == least:
            table.players[i].score = table.players[i].score - 6 / bottom_count
        i = i + 1

fun find_winners(Table table):
    let best = 0
    let i = 1
    while i < table.seats:
        if table.players[i].score > table.players[best].score:
            best = i
        else if table.players[i].score == table.players[best].score and table.players[i].puddings > table.players[best].puddings:
            best = i
        i = i + 1
    i = 0
    while i < 5:
        table.winners[i] = i < table.seats and table.players[i].score == table.players[best].score and table.players[i].puddings == table.players[best].puddings
        i = i + 1

fun begin_round(Table table):
    table.dealt = 0
    table.turn = 0
    let i = 0
    while i < table.seats:
        table.players[i].hand.init()
        let card = 0
        while card < 12:
            table.players[i].tableau[card] = 0
            card = card + 1
        table.players[i].unused_wasabi = 0
        table.players[i].nigiri_points = 0
        table.players[i].last_round_score = 0
        i = i + 1

# Chance actions consume the finite shuffled supply; every accepted deal prefix
# is realizable by a shuffle of the original 108-card deck. Discards never return.
fun deal_card(Table table, Int card):
    let seat = table.dealt / table.hand_size
    table.players[seat].hand.append(card)
    table.stock[card] = table.stock[card] - 1
    table.dealt = table.dealt + 1

fun pass_hands(Table table):
    let hands : Hand[5]
    let i = 0
    while i < table.humans:
        hands[i] = table.players[i].hand
        i = i + 1
    i = 0
    while i < table.humans:
        let target = (i + 1) % table.humans
        if table.alternate and table.round == 1:
            target = (i + table.humans - 1) % table.humans
        table.players[target].hand = hands[i]
        i = i + 1

fun begin_turn(Table table):
    table.actor = 0
    let i = 0
    while i < 5:
        table.first[i] = -1
        table.second[i] = -1
        table.gift[i] = -1
        table.used_chopsticks[i] = false
        i = i + 1
    if table.dummy:
        let card = table.players[2].hand.cards[0]
        table.players[2].hand.erase(0)
        table.players[table.controller].hand.append(card)

fun valid_choice(Table table, Int player, Int first, Int second, Int gift) -> Bool:
    if player != table.actor or player < 0 or player >= table.humans:
        return false
    let size = table.players[player].hand.size
    if first < 0 or first >= size:
        return false
    if second != -1:
        if second < 0 or second >= size or second == first:
            return false
        if table.players[player].tableau[Card::Chopsticks.value] == 0:
            return false
    if table.dummy and player == table.controller:
        return gift >= 0 and gift < size and gift != first and gift != second
    return gift == -1

# Store card identities before erasing indices. Tableau and scores stay unchanged
# until all humans have committed their choices for this simultaneous turn.
fun commit_choice(Table table, Int player, Int first, Int second, Int gift):
    table.first[player] = table.players[player].hand.cards[first]
    if second != -1:
        table.second[player] = table.players[player].hand.cards[second]
        table.used_chopsticks[player] = true
    if gift != -1:
        table.gift[player] = table.players[player].hand.cards[gift]
    let index = table.players[player].hand.size - 1
    while index >= 0:
        if index == first or index == second or index == gift:
            table.players[player].hand.erase(index)
        index = index - 1
    if second != -1:
        table.players[player].hand.append(Card::Chopsticks.value)
    table.actor = table.actor + 1

# Only positive icon totals participate. A tied first place suppresses second.
fun score_maki(Table table):
    let most = 0
    let i = 0
    while i < table.seats:
        let icons = maki_icons(table.players[i])
        if icons > most:
            most = icons
        i = i + 1
    if most == 0:
        return
    let top_count = 0
    let runner_up = 0
    i = 0
    while i < table.seats:
        let icons = maki_icons(table.players[i])
        if icons == most:
            top_count = top_count + 1
        else if icons > runner_up:
            runner_up = icons
        i = i + 1
    let second_count = 0
    i = 0
    while i < table.seats:
        if maki_icons(table.players[i]) == runner_up:
            second_count = second_count + 1
        i = i + 1
    i = 0
    while i < table.seats:
        let points = 0
        if maki_icons(table.players[i]) == most:
            points = 6 / top_count
        else if top_count == 1 and runner_up > 0 and maki_icons(table.players[i]) == runner_up:
            points = 3 / second_count
        table.players[i].score = table.players[i].score + points
        table.players[i].last_round_score = table.players[i].last_round_score + points
        i = i + 1

fun reveal_choices(Table table):
    let i = 0
    while i < table.humans:
        if table.used_chopsticks[i]:
            table.players[i].tableau[Card::Chopsticks.value] = table.players[i].tableau[Card::Chopsticks.value] - 1
        collect(table.players[i], table.first[i])
        if table.second[i] != -1:
            collect(table.players[i], table.second[i])
        if table.gift[i] != -1:
            collect(table.players[2], table.gift[i])
        i = i + 1
    pass_hands(table)
    table.turn = table.turn + 1
    if table.dummy:
        table.controller = 1 - table.controller
    else if table.players[0].hand.size == 1:
        # The final card belongs to the receiving player after the final pass.
        i = 0
        while i < table.seats:
            collect(table.players[i], table.players[i].hand.cards[0])
            table.players[i].hand.erase(0)
            i = i + 1

fun score_round(Table table):
    let i = 0
    while i < table.seats:
        let points = set_score(table.players[i])
        table.players[i].last_round_score = points
        table.players[i].score = table.players[i].score + points
        i = i + 1
    score_maki(table)

# Check supply conservation and the live round, including committed cards and
# chopsticks returned to hands before the simultaneous reveal.
fun state_is_valid(Table table) -> Bool:
    if table.humans < 2 or table.humans > 5 or table.seats < 2 or table.seats > 5:
        return false
    if table.round < 0 or table.round > 3 or table.actor < 0 or table.actor > table.humans:
        return false
    let stock_total = 0
    let card = 0
    while card < 12:
        stock_total = stock_total + table.stock[card]
        if table.stock[card] < 0 or table.stock[card] > card_supply(card):
            return false
        card = card + 1
    let consumed = table.round * table.seats * table.hand_size + table.dealt
    if table.round == 3:
        consumed = 3 * table.seats * table.hand_size
    if stock_total + consumed != 108:
        return false
    let live_total = 0
    let i = 0
    while i < table.seats:
        live_total = live_total + table.players[i].hand.size
        if table.players[i].hand.size < 0 or table.players[i].hand.size > 11:
            return false
        if table.players[i].puddings < 0 or table.players[i].unused_wasabi < 0:
            return false
        if table.players[i].unused_wasabi > table.players[i].tableau[Card::Wasabi.value]:
            return false
        card = 0
        while card < table.players[i].hand.size:
            if table.players[i].hand.cards[card] < 0 or table.players[i].hand.cards[card] >= 12:
                return false
            card = card + 1
        card = 0
        while card < 12:
            if table.players[i].tableau[card] < 0:
                return false
            live_total = live_total + table.players[i].tableau[card]
            card = card + 1
        if table.dealt == table.seats * table.hand_size and table.actor < table.humans and i < table.actor:
            live_total = live_total + 1
            # A double pick adds one extra pending card and one returned
            # chopsticks, which cancel in this physical-card count.
            if table.gift[i] != -1:
                live_total = live_total + 1
        i = i + 1
    return live_total == table.dealt

@classes
act play() -> Game:
    frm table : Table
    act setup(Int humans, Bool alternate, Bool dummy, Int first_controller){
        humans >= 2 and humans <= 5 and
        ((!dummy and first_controller == 0) or
         (dummy and humans == 2 and first_controller >= 0 and first_controller <= 1))
    }
        table.humans = humans
        table.seats = humans
        table.hand_size = hand_size_for(humans)
        table.alternate = alternate
        table.dummy = dummy
        table.controller = first_controller
        if dummy:
            table.seats = 3
            table.hand_size = 9
        let card = 0
        while card < 12:
            table.stock[card] = card_supply(card)
            card = card + 1

    while table.round < 3:
        begin_round(table)
        while table.dealt < table.seats * table.hand_size:
            act deal(Card card){card.value >= 0 and card.value < 12 and table.stock[card.value] > 0}
                deal_card(table, card.value)
        while ((!table.dummy and table.turn < table.hand_size - 1) or
               (table.dummy and table.turn < table.hand_size)):
            begin_turn(table)
            while table.actor < table.humans:
                actions:
                    act pick(Int player, Int index, Int gift){valid_choice(table, player, index, -1, gift)}
                        commit_choice(table, player, index, -1, gift)
                    act chopsticks(Int player, Int first, Int second, Int gift){
                        second != -1 and valid_choice(table, player, first, second, gift)
                    }
                        commit_choice(table, player, first, second, gift)
            reveal_choices(table)
        score_round(table)
        table.round = table.round + 1
    score_puddings(table)
    find_winners(table)
