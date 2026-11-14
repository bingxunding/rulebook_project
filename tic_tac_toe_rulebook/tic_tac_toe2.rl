# Copyright 2019 DeepMind Technologies Limited (original OpenSpiel code).
# Adapted to Rulebook from the supplied tic_tac_toe.h and tic_tac_toe.cc.
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#     https://www.apache.org/licenses/LICENSE-2.0
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Architecture references
# https://rl-language.github.io/language_tour.html#example-ui-for-tic-tac-toe
# https://www.llvm.org/devmtg/2025-04/slides/poster/fioravanti_coroutines.pdf
#
# Board holds the game data, play runs the rules as a coroutine, and main drives the demo.
# The new interface provides play(), game.mark(row, col), can apply(action, game), and game.is_done().
# This interface replaces the C++-style LoadGame, TicTacToeGame, TicTacToeState, and ApplyAction layers.

import action
import bounded_arg
import collections.vector
import serialization.print
import string

using Coordinate = BInt<0, 3>

enum CellState:
    kEmpty
    kNought
    kCross

fun PlayerToState(Int player) -> CellState {player == 0 or player == 1}:
    if player == 0:
        return CellState::kCross
    return CellState::kNought

# Player 0 plays X and goes first. Player 1 plays O. Index cells as row * 3 + col.
#   0 1 2
#   3 4 5
#   6 7 8
# Callers can read the board and should use mark or apply to place a mark and preserve the board state.
cls Board:
    CellState[9] slots
    Int current_player
    Int num_moves

    fun init():
        let cell = 0
        while cell < 9:
            self.slots[cell] = CellState::kEmpty
            cell = cell + 1
        self.current_player = 0
        self.num_moves = 0

    fun full() -> Bool:
        return self.num_moves == 9

    # Check bounds before indexing the array, even if a caller writes directly to BInt.value.
    fun empty(Int row, Int col) -> Bool:
        return row >= 0 and row < 3 and col >= 0 and col < 3 and self.slots[row * 3 + col].value == CellState::kEmpty.value

    fun has_line(Int player) -> Bool {player == 0 or player == 1}:
        let c = PlayerToState(player).value
        # Three rows.
        let row0 = self.slots[0].value == c and self.slots[1].value == c and self.slots[2].value == c
        let row1 = self.slots[3].value == c and self.slots[4].value == c and self.slots[5].value == c
        let row2 = self.slots[6].value == c and self.slots[7].value == c and self.slots[8].value == c
        # Three columns.
        let col0 = self.slots[0].value == c and self.slots[3].value == c and self.slots[6].value == c
        let col1 = self.slots[1].value == c and self.slots[4].value == c and self.slots[7].value == c
        let col2 = self.slots[2].value == c and self.slots[5].value == c and self.slots[8].value == c
        # Two diagonals.
        let diag0 = self.slots[0].value == c and self.slots[4].value == c and self.slots[8].value == c
        let diag1 = self.slots[2].value == c and self.slots[4].value == c and self.slots[6].value == c
        return row0 or row1 or row2 or col0 or col1 or col2 or diag0 or diag1


    fun to_string() -> String:
        let text: String
        let cell = 0
        while cell < 9:
            if self.slots[cell].value == CellState::kCross.value:
                text.append("x")
            else:
                if self.slots[cell].value == CellState::kNought.value:
                    text.append("o")
                else:
                    text.append(".")
            if cell == 2 or cell == 5:
                text.append("\n")
            cell = cell + 1
        return text

# The compiler generates Game, GameMark, and AnyGameAction.
# frm fields persist across suspension points. Calling play() pauses at the first mark until a caller supplies a move.
# This coroutine handles every game transition independently of the UI, output, and move selection policy.
@classes
act play() -> Game:
    frm board: Board
    frm winner = -3
    while !board.full():
        act mark(Coordinate row, Coordinate col) {board.empty(row.value, col.value)}
        board.slots[row.value * 3 + col.value] = PlayerToState(board.current_player)
        board.num_moves = board.num_moves + 1
        if board.has_line(board.current_player):
            winner = board.current_player
            return
        board.current_player = 1 - board.current_player
    # If the board fills with no winner, end the game and leave winner at -3.
    # Returning from play makes the generated is_done() return true.
    return

# Queries use the coroutine to determine when the game is over, replacing manual tracking through IsTerminal or resume_index.
fun get_current_player(Game game) -> Int:
    if game.is_done():
        return -4
    return game.board.current_player

fun get_num_players() -> Int:
    return 2

fun is_draw(Game game) -> Bool:
    return game.is_done() and game.winner == -3

fun score(Game game, Int player_id) -> Float {player_id == 0 or player_id == 1}:
    if !game.is_done() or game.winner == -3:
        return 0.0
    if game.winner == player_id:
        return 1.0
    return -1.0

# Like the earlier Returns(), this returns payoffs in the order [player 0, player 1].
fun returns(Game game) -> Float[2]:
    let rewards: Float[2]
    rewards[0] = score(game, 0)
    rewards[1] = score(game, 1)
    return rewards

# Enumerate all nine possible moves on the 3-by-3 board.
# can apply checks both the action precondition and the coroutine stage. All moves become unavailable when the game ends.
# The UI and the move selection policy share the same checks for empty cells and game completion.
# Use a template parameter for the generated action type to accommodate the local compiler's type generation order.
# Declare let prototype: AnyGameAction, then call legal_actions(game, prototype).
fun<T> legal_actions(Game game, T prototype) -> Vector<T>:
    let candidates = enumerate(prototype)
    let legal: Vector<T>
    let i = 0
    while i < candidates.size():
        let candidate = candidates.get(i)
        if candidate is ApplicableTo<Game>:
            if can apply(candidate, game):
                legal.append(candidate)
        i = i + 1
    return legal

# A UI click handler should validate integer coordinates before constructing bounded coordinates to avoid truncation during conversion.
# Invalid input returns false without changing state. Legal moves use the generated action.
fun try_mark(Game game, Int row, Int col) -> Bool:
    if row < 0 or row >= 3 or col < 0 or col >= 3:
        return false
    let action: GameMark
    action.row = row
    action.col = col
    if can apply(action, game):
        apply(action, game)
        return true
    return false

# Terminals and external tools can call this display helper independently of the game rules.
fun pretty_print(Game game):
    print(game.board.to_string())

# The demo picks the first legal move in enumeration order.
# For human or AI players, replace the caller's move selection policy and reuse play().
fun<T> select_action(Game game, T prototype) -> T {!game.is_done()}:
    let choices = legal_actions(game, prototype)
    return choices.get(0)

# conda activate rulebook
# cd /Users/dingbingxun/Desktop/rulebook_project/tic_tac_toe_rulebook
# rlc tic_tac_toe.rl -o tic_tac_toe
# ./tic_tac_toe
# This demo plays a game automatically without a graphical interface or interactive terminal input.
fun main() -> Int:
    let game = play()
    let prototype: AnyGameAction
    print("New game: player 0 = x, player 1 = o")
    pretty_print(game)
    while !game.is_done():
        print("Current player:")
        print(get_current_player(game))
        print("Legal actions:")
        print(legal_actions(game, prototype))
        let action = select_action(game, prototype)
        print("Selected action:")
        print(action)
        apply(action, game)
        pretty_print(game)
    print("Game over")
    if is_draw(game):
        print("Draw")
    else:
        print("Winner:")
        print(game.winner)
    print("Returns [player 0, player 1]:")
    print(returns(game))
    return 0
