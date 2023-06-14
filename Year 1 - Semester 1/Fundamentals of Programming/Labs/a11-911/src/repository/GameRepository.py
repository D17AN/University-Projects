from random import randint

class GameRepo:
    def __init__(self, board):
        """
        :param board: an object of type Board
        """
        self.__board = board


    @property
    def board(self):
        return self.__board


    def is_inside(self, row, column):
        """
        Check if the given coordinates are inside the board
        :param row: the row of a cell
        :param column: the column of a cell
        :return: true if the cell is inside, false otherwise
        """
        if 0 <= row < self.__board.rows and 0 <= column < self.__board.columns:
            return True
        return False


    def is_available(self, row, column):
        """
        Check if the content of the board from [row][column] is available for a move
        :param row: the row of cell
        :param column: the column of a cell
        :return: true if the content from [row][column] is available, false otherwise.
        """

        """
         coord is a list of tuples, where which tuple represent the coordinates difference between a neighbour cell 
         and the cell placed at [row][column]
         first index of the tuple represents the row and the second the column
        """
        coord = [(0, 0), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

        if self.is_inside(row, column) == True:
            for x, y in coord:
                x1 = x + row
                y1 = y + column
                if self.is_inside(x1, y1) == True and self.__board[x1, y1] != 0: # if the cell is not available
                    return False
        else:
            return False
        return True


    def move_player(self, row, column, player):
        """
        Placing a player at the cell with coordinates row x column
        :param row: the row of the cell
        :param column: the column of the cell
        :param player: the player which must be placed on that cell
        :return: True if the placing has ended successfully, false otherwise
        """
        if self.is_available(row, column) == True and player in(0, 1, 2):
            self.__board[row, column] = player
        else:
            raise Exception("Illegal move!")


    def reset_move(self, row, column):
        """
        Reset a certain move from a cell
        :param row: the row of the cell
        :param column: the column of the cell
        """
        if self.is_inside(row, column) == True and self.is_available(row, column) == False:
            self.__board[row, column] = 0


    def random_move_player(self, player):
        """
         Placing a player on a random generated position
        :param player: a player
        """
        if self.board_state() == True:
            while True:
                i = randint(0, self.__board.rows - 1)
                j = randint(0, self.__board.columns - 1)
                if self.is_available(i, j) == True:
                    self.move_player(i, j, player)
                    break


    def board_state(self):
        """
        :return: True if the board is not full, false otherwise
        """
        for row in range(self.__board.rows):
            for column in range(self.__board.columns):
                if self.is_available(row, column) == True: # if a cell is available the game is not over
                    return True

        return False
