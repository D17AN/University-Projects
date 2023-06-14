from texttable import Texttable
from src.domain.BoardExceptions import BoardException


class Board:
    def __init__(self, rows, columns):
        """
        Initializing an entity of type board which will have as attributes:
         - a matrix of rows x columns
        :param rows: the number of rows of the matrix
        :param columns: the number of columns of the matrix
        """
        self.__rows = rows
        self.__columns = columns
        self.__board = [[0 for i in range(self.__columns)] for i in range(self.__rows)]


    def __str__(self):
        """
        :return: how it's interpreted the board as a string(how it should be displayed)
        """
        t = Texttable()
        for row in range(self.__rows):
            l = []
            for column in range(self.__columns):
                if self.__board[row][column] == 0:
                    l.append("")
                elif self.__board[row][column] == 1:
                    l.append("X")
                elif self.__board[row][column] == 2:
                    l.append("O")
            t.add_row(l)

        return t.draw()


    def __getitem__(self, coordinates):
        """
        Get an item from the board
        :param row: the row on which is placed the item
        :param column: the column on which is place the item
        :return: the item from the board[row][column], an Exception is raise if the input it's not valid
        """
        errors = []
        if isinstance(coordinates, tuple):
            if len(coordinates) != 2:
                errors.append(f"Invalid coordinates, 2 objects are requiered, but only {len(coordinates)} were given!")
        else:
            errors.append("The key must be a tuple which contains 2 integers, a row and a column")

        try:
            row = coordinates[0]
            column = coordinates[1]
        except:
            pass

        if 0 <= row < self.__rows and 0 <= column < self.__columns:
            return self.__board[row][column]
        else:
            errors.append("Invalid position!")

        if len(errors) > 0:
            raise BoardException(errors)


    def __setitem__(self, coordinates, value):
        """
        Change the value of an item from the board
        :param row: the row on which is placed the item
        :param column:the column on which is place the item
        :param value: the new value of the item( 0 - free space, 1 - X player, 2 - O player)
        """
        errors = []
        if isinstance(coordinates, tuple):
            if len(coordinates) != 2:
                errors.append(f"Invalid coordinates, 2 objects are requiered, but only {len(coordinates)} were given!")
        else:
            errors.append("The key must be a tuple which contains 2 integers, a row and a column")

        try:
            row = coordinates[0]
            column = coordinates[1]
        except:
            pass

        if value not in (0, 1, 2):
            errors.append("Invalid value! Only 0, 1 and 2 are accepted.")

        if 0 <= row < self.__rows and 0 <= column < self.__columns:
            self.__board[row][column] = value
        else:
            errors.append("Invalid position!")

        if len(errors) > 0:
            raise BoardException(errors)


    @property
    def board(self):
        """
        getter for the attribute board
        :return: the board
        """
        return self.__board


    @property
    def rows(self):
        """
        :return: the attribute rows
        """
        return self.__rows


    @property
    def columns(self):
        """
        :return: the attribute columns
        """
        return self.__columns