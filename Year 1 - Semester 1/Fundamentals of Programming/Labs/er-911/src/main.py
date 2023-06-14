import texttable
class Board:
    def __init__(self, rows, cols):
        self.rows, self.cols = rows, cols
        self.board = [["" for i in range(0, self.cols)] for i in range(0, self.rows)]


    def __str__(self):
        t = texttable.Texttable()
        for i in range(0, self.rows):
            line = []
            for j in range(0, self.cols):
                piece = self.board[i][j]
                line.append(piece)
            t.add_row(line)
        return t.draw()


class Controller:
    def __init__(self, table):
        self.table = table
        self.player_turn = 1 # player 1(order/computer), player 2(chaos/human)


    def cons_pieces_rows(self, piece):
       b = self.table.board
       lmax = 0
       for i in range(0, self.table.rows):
           l = 0
           for j in range(0, self.table.cols):
               if b[i][j] == piece:
                   l += 1
               else:
                   if lmax < l:
                      lmax = l
                   l = 0
           if lmax < l:
              lmax = l

       return lmax


    def cons_pieces_cols(self, piece):
        b = self.table.board
        lmax = 0
        for j in range(0, self.table.cols):
            l = 0
            for i in range(0, self.table.rows):
                if b[i][j] == piece:
                    l += 1
                else:
                    if lmax < l:
                        lmax = l
                    l = 0
            if lmax < l:
                lmax = l

        return lmax


    def cons_pieces_diag(self, piece):
        b = self.table.board
        #all the diagonals of 6x6 matrix which has at least 5 cells
        d1 = [(0, 0), (1,1), (2, 2), (3, 3), (4, 4), (5,5)]
        d2 = [(1, 0), (2, 1), (3, 2), (4, 3), (5, 4)]
        d3 = [(0, 1), (1, 2), (2, 3), (3, 4), (4, 5)]
        d4 = [(0, 5), (1, 4), (2, 3), (3,2), (4, 1), (5, 0)]
        d5 = [(1, 5), (2, 4), (3, 3), (4, 2), (5, 1)]
        d6 = [(0, 4), (1, 3), (2, 2), (3, 1), (4, 1)]
        l = [d1, d2, d3, d4, d5, d6]
        lmax = 0
        for curr_l in l:
            l = 0
            for i, j in curr_l:
                if b[i][j] == piece:
                    l += 1
                else:
                    if lmax < l:
                        lmax = l
                    l = 0
            if lmax < l:
                lmax = l

        return lmax


    def is_table_filled(self):
        """
        :return: True if the board is filled, false otherwise. A table is filled if it doesn't have any cell
                 containing ""
        """
        b = self.table.board
        for i in range(self.table.rows):
            for j in range(self.table.cols):
                if b[i][j] == "":
                    return False
        return True


    def move_piece(self, row, col, piece):
        b = self.table.board
        if b[row][col] == "X"  or b[row][col] == "O" or not(0 <= row < self.table.rows or 0 <= col < self.table.cols):
            raise Exception("Illegal move!")
        else:
            self.table.board[row][col] = piece


    def is_inside(self, i, j):
        return 0 <= i < self.table.rows and 0 <= j < self.table.cols


    def nr_same_neighbours(self, piece, i, j):
        b = self.table.board
        dx = [-1, -1, 0, 1, 1, 1, 0, -1]
        dy = [-1, 0, 1, 1, 1, 0, -1, -1]
        s = 0
        for k in range(0, 8):
            x = dx[k] + i
            y = dy[k] + j
            if self.is_inside(x, y) and piece == b[x][y]:
                s += 1
        return s


    def maxnr_same_symbols(self):
        b = self.table.board
        symX, symO = 0, 0
        for i in range(self.table.rows):
            for j in range(self.table.cols):
                if b[i][j] == "X":
                    symX += 1
                if b[i][j] == "O":
                    symO += 1

        if symX > symO:
            return "X"
        else:
            return "O"


    def computer_move(self):
        x,y =1, 1
        max = 0
        b = self.table.board
        comp_symbol = self.maxnr_same_symbols()
        for i in range(0, self.table.rows):
            for j in range(0, self.table.cols):
                if b[i][j] == "": # the cell is available
                    new_max = self.nr_same_neighbours(comp_symbol, i, j)
                    if max < new_max:
                        max = new_max
                        x = i
                        y = j

        self.move_piece(x, y, comp_symbol)


    def has_player_won(self):
        for piece in ["X", "O"]:
            return self.cons_pieces_rows(piece) >= 5 or self.cons_pieces_cols(piece) >= 5 \
                   or self.cons_pieces_diag(piece) >= 5




class UI:
    def __init__(self, controller):
        self.controller = controller
        self.turn = 0 # 0 computer, 1 human

    def ui_comp_move(self):
        self.controller.computer_move()


    def ui_human_turn(self):
        while True:
            try:
                i = int(input("row = "))
                j = int(input("col = "))
                symbol = input("symbol = ")
                symbol = symbol.upper().strip()
                # if symbol != "X" or symbol != "O":
                #     raise Exception("Invalid symbol!")
                self.controller.move_piece(i, j, symbol)
            except Exception as e:
                print(e)
            else:
                break


    def play_game(self):
        while True:
            print(str(self.controller.table))
            if self.controller.is_table_filled():
                print("Chaos won!")
                exit()
            if self.turn == 0: #order turn
               self.ui_comp_move()
               self.turn = 1
               if self.controller.has_player_won(): # the game has finished
                   print("Order won!")
                   exit()
            elif self.turn == 1: #chaos turn
                self.ui_human_turn()
                self.turn = 0
                if self.controller.has_player_won() or self.controller.is_table_filled(): # the game has finished
                    print("Chaos won!")
                    exit()


b = Board(6, 6)
c = Controller(b)
u = UI(c)
u.play_game()









