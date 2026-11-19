import machine_learning

enum Card:
    tempura
    sashimi
    dumpling
    maki_one
    maki_two
    maki_three
    salmon_nigiri
    squid_nigiri
    egg_nigiri
    pudding
    wasabi
    chopsticks

cls Hand:
    Int[10] cards
    Int size

    fun init():
        self.size = 0
        let i = 0
        while i < 10:
            self.cards[i] = -1
            i = i + 1

    fun append(Int card):
        assert(self.size < 10, "Hand capacity exceeded")
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

cls Selection:
    Int first
    Int second
    Int dummy_card

    fun init():
        self.first = -1
        self.second = -1
        self.dummy_card = -1

cls Supply:
    Int[12] counts
    Int total

    fun init():
        self.counts[0] = 14
        self.counts[1] = 14
        self.counts[2] = 14
        self.counts[3] = 6
        self.counts[4] = 12
        self.counts[5] = 8
        self.counts[6] = 10
        self.counts[7] = 5
        self.counts[8] = 5
        self.counts[9] = 10
        self.counts[10] = 6
        self.counts[11] = 4
        self.total = 108

cls Player:
    HiddenInformation<Hand> hand
    HiddenInformation<Selection> pending
    Int[12] table
    Int unused_wasabi
    Int nigiri_points
    Int puddings
    Int score
    Bool winner
    Bool committed

cls State:
    Int players
    Int participants
    Bool dummy_mode
    Bool alternate
    Int first_controller
    Int controller
    Int round
    Int turn
    Int hand_size
    Hidden<Supply> remaining
    Player[5] seats
    Hidden<Hand> dummy_pile
    Int[12] discarded
    Int deal_seat
    Int deal_count
    Int submitted

fun hand_size_for(Int players) -> Int:
    if players >= 2 and players <= 5:
        return 12 - players
    return 0

fun valid_deal(State state, Card card) -> Bool:
    if card.value < 0 or card.value >= 12:
        return false
    return state.remaining.value.counts[card.value] > 0

fun valid_selection(State state, Int player, Int first, Int second, Int dummy_index) -> Bool:
    if player < 0 or player >= state.players:
        return false
    if state.seats[player].committed:
        return false
    let size = state.seats[player].hand.value.size
    if first < 0 or first >= size:
        return false
    if second != -1:
        if second < 0 or second >= size or first == second:
            return false
        if state.seats[player].table[Card::chopsticks.value] == 0:
            return false
    if state.dummy_mode and player == state.controller:
        if dummy_index < 0 or dummy_index >= size:
            return false
        if dummy_index == first or dummy_index == second:
            return false
    else:
        if dummy_index != -1:
            return false
    return true

fun commit_selection(State state, Int player, Int first, Int second, Int dummy_index):
    ref seat = state.seats[player]
    seat.pending.value.first = seat.hand.value.cards[first]
    if second != -1:
        seat.pending.value.second = seat.hand.value.cards[second]
    if dummy_index != -1:
        seat.pending.value.dummy_card = seat.hand.value.cards[dummy_index]
    # Indices refer to the original hand, so remove in descending order.
    let i = seat.hand.value.size - 1
    while i >= 0:
        if i == first or i == second or i == dummy_index:
            seat.hand.value.erase(i)
        i = i - 1
    if second != -1:
        seat.hand.value.append(Card::chopsticks.value)
    seat.committed = true
    state.submitted = state.submitted + 1

fun pass_hands(State state):
    let old : Hand[5]
    let i = 0
    while i < state.players:
        old[i] = state.seats[i].hand.value
        i = i + 1
    i = 0
    while i < state.players:
        # Seat i's left neighbor is (i + 1) modulo the human player count.
        let receiver = (i + 1) % state.players
        if state.alternate and state.round == 2:
            receiver = (i + state.players - 1) % state.players
        state.seats[receiver].hand.value = old[i]
        i = i + 1

fun clear_round(State state):
    let i = 0
    while i < state.participants:
        let card = 0
        while card < 12:
            if card != Card::pudding.value:
                state.discarded[card] = state.discarded[card] + state.seats[i].table[card]
            state.seats[i].table[card] = 0
            card = card + 1
        state.seats[i].unused_wasabi = 0
        state.seats[i].nigiri_points = 0
        i = i + 1

# Each ordered reveal consumes the next available Wasabi for a Nigiri.
# A two-card selection is resolved in the chosen order.
fun add_card(Player player, Int card):
    player.table[card] = player.table[card] + 1
    if card == 9:
        player.puddings = player.puddings + 1
    if card == 10:
        player.unused_wasabi = player.unused_wasabi + 1
    let value = 0
    if card == 6:
        value = 2
    if card == 7:
        value = 3
    if card == 8:
        value = 1
    if value > 0:
        if player.unused_wasabi > 0:
            value = value * 3
            player.unused_wasabi = player.unused_wasabi - 1
        player.nigiri_points = player.nigiri_points + value

fun local_points(Player player) -> Int:
    let dumplings = player.table[2]
    if dumplings > 5:
        dumplings = 5
    return (player.table[0] / 2) * 5 + (player.table[1] / 3) * 10 + (dumplings * (dumplings + 1)) / 2 + player.nigiri_points

fun maki_icons(Player player) -> Int:
    return player.table[3] + 2 * player.table[4] + 3 * player.table[5]

fun score_round(State state):
    let first = -1
    let first_count = 0
    let i = 0
    while i < state.participants:
        state.seats[i].score = state.seats[i].score + local_points(state.seats[i])
        let icons = maki_icons(state.seats[i])
        if icons > first:
            first = icons
            first_count = 1
        else:
            if icons == first:
                first_count = first_count + 1
        i = i + 1

    # The PDF ranks all icon totals, including zero.
    i = 0
    while i < state.participants:
        if maki_icons(state.seats[i]) == first:
            state.seats[i].score = state.seats[i].score + 6 / first_count
        i = i + 1
    if first_count != 1:
        return

    let second = -1
    let second_count = 0
    i = 0
    while i < state.participants:
        let icons = maki_icons(state.seats[i])
        if icons < first:
            if icons > second:
                second = icons
                second_count = 1
            else:
                if icons == second:
                    second_count = second_count + 1
        i = i + 1
    if second_count == 0:
        return
    i = 0
    while i < state.participants:
        if maki_icons(state.seats[i]) == second:
            state.seats[i].score = state.seats[i].score + 3 / second_count
        i = i + 1

fun score_puddings(State state):
    let most = -1
    let least = 109
    let most_count = 0
    let least_count = 0
    let i = 0
    while i < state.participants:
        let count = state.seats[i].puddings
        if count > most:
            most = count
            most_count = 1
        else:
            if count == most:
                most_count = most_count + 1
        if count < least:
            least = count
            least_count = 1
        else:
            if count == least:
                least_count = least_count + 1
        i = i + 1
    if most == least:
        return
    i = 0
    while i < state.participants:
        if state.seats[i].puddings == most:
            state.seats[i].score = state.seats[i].score + 6 / most_count
        # The dummy variant scores three participants under normal scoring.
        if state.participants > 2 and state.seats[i].puddings == least:
            state.seats[i].score = state.seats[i].score - 6 / least_count
        i = i + 1

fun choose_winners(State state):
    let best_score = state.seats[0].score
    let best_puddings = state.seats[0].puddings
    let i = 1
    while i < state.participants:
        if state.seats[i].score > best_score:
            best_score = state.seats[i].score
            best_puddings = state.seats[i].puddings
        else:
            if state.seats[i].score == best_score and state.seats[i].puddings > best_puddings:
                best_puddings = state.seats[i].puddings
        i = i + 1
    # The PDF gives no further tiebreak: equally ranked participants share victory.
    i = 0
    while i < 5:
        state.seats[i].winner = false
        if i < state.participants:
            state.seats[i].winner = state.seats[i].score == best_score and state.seats[i].puddings == best_puddings
        i = i + 1
fun reveal_selections(State state):
    let i = 0
    while i < state.players:
        ref seat = state.seats[i]
        if seat.pending.value.second != -1:
            seat.table[Card::chopsticks.value] = seat.table[Card::chopsticks.value] - 1
        # Selected order resolves Wasabi before a second selected Nigiri.
        add_card(seat, seat.pending.value.first)
        if seat.pending.value.second != -1:
            add_card(seat, seat.pending.value.second)
        if seat.pending.value.dummy_card != -1:
            add_card(state.seats[2], seat.pending.value.dummy_card)
        seat.pending.value.first = -1
        seat.pending.value.second = -1
        seat.pending.value.dummy_card = -1
        seat.committed = false
        i = i + 1

# Each deal action chooses a card from the hidden remaining supply. This
# represents every possible shuffled deck prefix without replacement. Chance
# callers should sample card types proportionally to their remaining counts.
# Choices may arrive in any player order and remain private until all commit.
# The approved conventions include zero-icon Maki rankings, shared final ties,
# and a fully scored dummy that can win. Only humans can use Chopsticks.
@classes
act play() -> Game:
    frm s : State
    act configure(Int players, Bool alternate, Bool dummy, Int controller) {
        players >= 2 and players <= 5 and
        (!dummy or players == 2) and controller >= 0 and controller < 2
    }
        s.players = players
        s.participants = players
        s.dummy_mode = dummy
        s.alternate = alternate
        s.first_controller = controller
        s.controller = controller
        s.hand_size = hand_size_for(players)
        if dummy:
            s.participants = 3
            s.hand_size = 9
        let i = 0
        while i < 5:
            s.seats[i].hand.owner = i
            s.seats[i].pending.owner = i
            i = i + 1
        s.round = 1

    while s.round <= 3:
        s.deal_seat = 0
        s.deal_count = 0
        while s.deal_seat < s.participants:
            act deal(Card card) {valid_deal(s, card)}
                s.remaining.value.counts[card.value] = s.remaining.value.counts[card.value] - 1
                s.remaining.value.total = s.remaining.value.total - 1
                if s.dummy_mode and s.deal_seat == 2:
                    s.dummy_pile.value.append(card.value)
                else:
                    s.seats[s.deal_seat].hand.value.append(card.value)
                s.deal_count = s.deal_count + 1
                if s.deal_count == s.hand_size:
                    s.deal_count = 0
                    s.deal_seat = s.deal_seat + 1

        s.turn = 0
        # Dummy control alternates continuously, including across round breaks.
        while s.seats[0].hand.value.size > 0:
            if s.dummy_mode:
                s.seats[s.controller].hand.value.append(s.dummy_pile.value.cards[0])
                s.dummy_pile.value.erase(0)
            s.submitted = 0
            while s.submitted < s.players:
                act choose(Int player, Int first, Int second, Int dummy_index) {
                    valid_selection(s, player, first, second, dummy_index)
                }
                    commit_selection(s, player, first, second, dummy_index)
            reveal_selections(s)
            pass_hands(s)
            s.turn = s.turn + 1
            if !s.dummy_mode and s.seats[0].hand.value.size == 1:
                let i = 0
                while i < s.players:
                    add_card(s.seats[i], s.seats[i].hand.value.cards[0])
                    s.seats[i].hand.value.erase(0)
                    i = i + 1
            if s.dummy_mode:
                s.controller = 1 - s.controller
        score_round(s)
        if s.round < 3:
            clear_round(s)
        s.round = s.round + 1
    score_puddings(s)
    choose_winners(s)
