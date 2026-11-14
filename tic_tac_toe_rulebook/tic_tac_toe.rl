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

import collections.vector
import serialization.print
import string

# Use the OpenSpiel enum order (empty, O, X).
enum CellState:
    kEmpty
    kNought
    kCross

fun PlayerToState(Int player) -> CellState {player == 0 or player == 1}:
    if player == 0:
        return CellState::kCross
    return CellState::kNought

# Store the board in row-major order and index cells as row * 3 + column.
#   0 1 2
#   3 4 5
#   6 7 8
# Player 0 plays X and goes first. Player 1 plays O.
# Update the state through ApplyAction to keep these fields consistent.
cls TicTacToeState:
    CellState[9] board
    Int current_player
    Int outcome
    Int num_moves

    fun init():
        let cell = 0
        while cell < 9:
            self.board[cell] = CellState::kEmpty
            cell = cell + 1
        self.current_player = 0
        # OpenSpiel's kInvalidPlayer (-3) indicates that neither player has won.
        # A draw also keeps the value at -3. A full board distinguishes a draw from an ongoing game.
        self.outcome = -3
        self.num_moves = 0

    # Check the three rows, three columns, and two diagonals for the given player.

    # Check the three rows, three columns, and two diagonals for the given player
    fun HasLine(Int player) -> Bool {player == 0 or player == 1}:
        let c = PlayerToState(player).value
        # Three rows.
        let row0 = self.board[0].value == c and self.board[1].value == c and self.board[2].value == c
        let row1 = self.board[3].value == c and self.board[4].value == c and self.board[5].value == c
        let row2 = self.board[6].value == c and self.board[7].value == c and self.board[8].value == c
        # Three columns.
        let col0 = self.board[0].value == c and self.board[3].value == c and self.board[6].value == c
        let col1 = self.board[1].value == c and self.board[4].value == c and self.board[7].value == c
        let col2 = self.board[2].value == c and self.board[5].value == c and self.board[8].value == c
        # Two diagonals.
        let diag0 = self.board[0].value == c and self.board[4].value == c and self.board[8].value == c
        let diag1 = self.board[2].value == c and self.board[4].value == c and self.board[6].value == c
        return row0 or row1 or row2 or col0 or col1 or col2 or diag0 or diag1


    fun IsFull() -> Bool:
        return self.num_moves == 9

    fun IsTerminal() -> Bool:
        return self.outcome != -3 or self.IsFull()

    fun IsDraw() -> Bool:
        return self.outcome == -3 and self.IsFull()

    # Return OpenSpiel's kTerminalPlayerId (-4) when the game ends.
    fun CurrentPlayer() -> Int:
        if self.IsTerminal():
            return -4
        return self.current_player

    # The short-circuiting and operator checks bounds before indexing the array.
    fun IsLegalAction(Int move) -> Bool:
        return !self.IsTerminal() and move >= 0 and move < 9 and self.board[move].value == CellState::kEmpty.value

    # Return all legal positions in ascending order. Return an empty list when the game ends.
    # Use moves.size() and moves.get(i) to inspect the list.
    fun LegalActions() -> Vector<Int>:
        let moves: Vector<Int>
        if self.IsTerminal():
            return moves
        let cell = 0
        while cell < 9:
            if self.board[cell].value == CellState::kEmpty.value:
                moves.append(cell)
            cell = cell + 1
        return moves

    # The precondition rejects out-of-bounds moves, occupied cells, and moves after the game ends.
    # Use can state.DoApplyAction(move) to check whether the move is legal.
    fun DoApplyAction(Int move) {self.IsLegalAction(move)}:
        self.board[move] = PlayerToState(self.current_player)
        if self.HasLine(self.current_player):
            self.outcome = self.current_player
        # As in the original implementation, update the turn and move count even if this move ends the game.
        self.current_player = 1 - self.current_player
        self.num_moves = self.num_moves + 1

    # Public entry point for moves, corresponding to State::ApplyAction in the screenshot.
    # This method only forwards the move. OpenSpiel base-class features such as move history are outside its scope.
    fun ApplyAction(Int move) {self.IsLegalAction(move)}:
        self.DoApplyAction(move)

    # Match the C++ ToString format with three rows, a dot for each empty cell, and no trailing newline.
    fun ToString() -> String:
        let text: String
        let cell = 0
        while cell < 9:
            if self.board[cell].value == CellState::kCross.value:
                text.append("x")
            else:
                if self.board[cell].value == CellState::kNought.value:
                    text.append("o")
                else:
                    text.append(".")
            if cell == 2 or cell == 5:
                text.append("\n")
            cell = cell + 1
        return text

    # Return payoffs in the order [player 0 payoff, player 1 payoff].
    # An X win yields [1.0, -1.0]. An O win yields [-1.0, 1.0].
    # A draw or an ongoing game yields [0.0, 0.0].
    fun Returns() -> Float[2]:
        let rewards: Float[2]
        rewards[0] = 0.0
        rewards[1] = 0.0
        if self.HasLine(0):
            rewards[0] = 1.0
            rewards[1] = -1.0
        else:
            if self.HasLine(1):
                rewards[0] = -1.0
                rewards[1] = 1.0
        return rewards

# Corresponds to the parameterless TicTacToeGame::NewInitialState().
# Return an independent state on each call. Construction invokes init() automatically.
fun NewInitialState() -> TicTacToeState:
    let state: TicTacToeState
    return state

# Game definition. Each call to NewInitialState() creates an independent game.
cls TicTacToeGame:
    fun NewInitialState() -> TicTacToeState:
        return NewInitialState()

    fun NumPlayers() -> Int:
        return 2

    fun NumDistinctActions() -> Int:
        return 9

# This loader accepts only tic_tac_toe. OpenSpiel provides the general game registry.
fun LoadGame(StringLiteral name) -> TicTacToeGame {s(name) == "tic_tac_toe"}:
    let game: TicTacToeGame
    return game

# Choose the lowest-numbered legal position to make the example repeatable.
# Replace this function's selection logic to use human input, a random policy, or an AI player.
fun SelectAction(TicTacToeState state) -> Int {!state.IsTerminal()}:
    let legal_actions = state.LegalActions()
    return legal_actions.get(0)

# Build and run in the rulebook Conda environment.
# conda activate rulebook
# cd /Users/dingbingxun/Desktop/rulebook_project/tic_tac_toe_rulebook
# rlc tic_tac_toe.rl -o tic_tac_toe
# ./tic_tac_toe
# This entry point plays a complete game automatically without terminal input.
fun main() -> Int:
    # 1. Load the game definition.
    let game = LoadGame("tic_tac_toe")
    # 2 and 3. Create the state, which calls TicTacToeState.init() automatically.
    let state = game.NewInitialState()
    print("New game: player 0 = x, player 1 = o")
    print("Board positions: 0 1 2 / 3 4 5 / 6 7 8")
    print(state.ToString())

    # 4, 5, and 6. Get the current player and legal moves, apply a move, and check for the end of the game.
    while !state.IsTerminal():
        let player = state.CurrentPlayer()
        let legal_actions = state.LegalActions()
        print("Current player:")
        print(player)
        print("Legal actions:")
        print(legal_actions)
        let action = SelectAction(state)
        print("Selected action:")
        print(action)
        state.ApplyAction(action)
        print(state.ToString())

    # After the game ends, read both players' payoffs.
    print("Game over")
    if state.IsDraw():
        print("Draw")
    else:
        print("Winner:")
        print(state.outcome)
    print("Returns [player 0, player 1]:")
    print(state.Returns())
    return 0
