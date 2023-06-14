import math
from copy import copy
from src.domain.Board import Board
from random import shuffle, randint

class GameServices:
    def __init__(self, game_repo):
        """
        :param GameRepo: entity of type GameRepo
        """
        self.__game = game_repo


    @property
    def board(self):
        return self.__game.board


    def game_state(self):
        """
        :return: True if the game is not over, false otherwise
        """
        return self.__game.board_state()


    def is_inside(self, row, column):
        """
        Check if the given coordinates are inside the board
        :param row: the row of a cell
        :param column: the column of a cell
        :return: true if the cell is inside, false otherwise
        """
        return self.__game.is_inside(row, column)


    def is_available(self, row, column):
        """
        Check if the content of the board from [row][column] is available for a move
        :param row: the row of cell
        :param column: the column of a cell
        :return: true if the content from [row][column] is available, false otherwise.
        """
        return self.__game.is_available(row, column)


    def move(self, row, column, player):
        """
        Placing a player at the cell with coordinates row x column
        :param row: the row of the cell
        :param column: the column of the cell
        :param player: the player which must be placed on that cell
        :return: True if the placing has ended successfully, false otherwise
        """
        self.__game.move_player(row, column, player)


    def reset_move(self, row, column):
        """
       Reset a certain move from a cell
       :param row: the row of the cell
       :param column: the column of the cell
       """
        self.__game.reset_move(row, column)


    def random_move(self, player):
        """
         Placing a player on a random generated position
        :param player: a player
        """
        self.__game.random_move_player(player)

    # AI
    def calculate_neighbours(self, row, column):
        """
        Calculates the neighbours of selected cell
        :param row: the row of the cell
        :param column: the column of the cell
        :return: the number of neighbours of a cell
        """
        board = self.board
        coord = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
        neighbours = 0
        for x, y in coord:
            x1 = x + row
            y1 = y + column
            if self.is_inside(x1, y1) == True and board[x1, y1] == 0:
                neighbours += 1

        return neighbours


    def calculate_current_score(self, player):
        """
        For a player calculates the sum of the neighbours of all the cells on which the player
        has moved
        :param player: an integer, the player
        :return: the sum of the neighbours of all the cells on which the player
        has moved
        """
        board = self.board
        rows = [i for i in range(self.board.rows)]
        columns = [i for i in range(self.board.columns)]
        sum_neighbours = 0
        for row in rows:
            for col in columns:
                if board[row, col] == player:
                    sum_neighbours += self.calculate_neighbours(row, col)

        return sum_neighbours


    def make_best_move(self, depth, player_turn, human, computer):
        """
        An optimal move depending of the current state of the board
        :param depth: the max depth until where we'll let to explore all the possibilities
        :param player_turn: an integer, which player must move at a given time
        :param human: an integer, the human player
        :param computer: an integer, the computer player
        :return:
        """
        rows = [i for i in range(self.board.rows)]
        columns = [i for i in range(self.board.columns)]
        shuffle(rows)
        shuffle(columns)
        best_score = -math.inf
        best_row = None
        best_col = None
        for row in rows:
            for col in columns:
                if self.is_available(row, col) ==  True:
                    self.move(row, col, player_turn)
                    if player_turn == computer:
                        player_turn = human
                    elif player_turn == human:
                        player_turn = computer
                    score = self.minimax(False, depth, player_turn, human, computer)
                    self.reset_move(row, col)
                    if score > best_score:
                        best_score = score
                        best_row = row
                        best_col = col

        if best_score != -math.inf:
            self.move(best_row, best_col, computer)


    def minimax(self, is_maximazing, depth, player_turn, human, computer):
        """
        Minimax algorithm for exploring the best move for a giving depth
        :param is_maximazing: a boolen, True if the maximazing player must move, False if the non maximazing player must move
        :param depth: the max depth until where we'll let to explore
        :param player_turn: an integer, which player must move at a given time
        :param human: an integer, the human player
        :param computer: an integer, the computer player
        :return: a score for certain moves
        """
        if self.game_state() == False or depth == 0: # if the game is over or we reached a certain level
            if player_turn == human: # if the computer has won
                return self.calculate_current_score(computer)
            elif player_turn == computer: # if the human has won
                return self.calculate_current_score(human)

        rows = [i for i in range(self.board.rows)]
        columns = [i for i in range(self.board.columns)]
        shuffle(rows)
        shuffle(columns)
        if is_maximazing:
            value = -math.inf
            for row in rows:
                for col in columns:
                    if self.is_available(row, col) == True:
                        self.move(row, col, player_turn)
                        if player_turn == computer:
                            player_turn = human
                        elif player_turn == human:
                            player_turn = computer
                        value = max(value, self.minimax(False, depth - 1, player_turn, human, computer))
                        self.reset_move(row, col)
            return value
        else:
            value = math.inf
            for row in rows:
                for col in columns:
                    if self.is_available(row, col) == True:
                        self.move(row, col, player_turn)
                        if player_turn == computer:
                            player_turn = human
                        elif player_turn == human:
                            player_turn = computer
                        value = min(value, self.minimax(True, depth - 1, player_turn, human, computer))
                        self.reset_move(row, col)
            return value