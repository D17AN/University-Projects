import pygame
from src.domain.Board import Board
from src.repository.GameRepository import GameRepo
from src.services.GameServices import GameServices
from src.gui.Constants import WIDTH_MAIN_MENU, HEIGHT_MAIN_MENU, WHITE, BLACK, RED, BLUE


class Game:
    def __init__(self):
        # GUI Related
        pygame.init()
        pygame.display.set_caption('Obstruction')
        self.running, self.playing = True, False
        self.UP_KEY, self.DOWN_KEY, self.START_KEY, self.BACK_KEY, self.CLICK = False, False, False, False, False
        self.mouseX, self.mouseY = -1, -1
        self.DISPLAY_W, self.DISPLAY_H = WIDTH_MAIN_MENU, HEIGHT_MAIN_MENU
        self.display = pygame.Surface((self.DISPLAY_W, self.DISPLAY_H))
        self.window = pygame.display.set_mode(((self.DISPLAY_W, self.DISPLAY_H)))
        self.font_name = '8bit_wonder/8-BIT WONDER.TTF'
        self.BLACK, self.WHITE, self.RED, self.BLUE = BLACK, WHITE, RED, BLUE
        self.main_menu = MainMenu(self)
        self.start_game = StartMenu(self)
        self.options = OptionsMenu(self)
        self.play_game = Play_Game(self)
        self.credits = CreditsMenu(self)
        self.winner_status = WinnerStatus(self)
        self.curr_menu = self.main_menu
        # Obstruction settings
        self.rows, self.columns = 6, 6
        self.human, self.computer = 1, 2
        self.winner = None
        self.depth = 3


    def game_loop(self):
        pygame.time.Clock().tick(60)
        self.curr_menu.display_menu()


    def check_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running, self.playing = False, False
                self.curr_menu.run_display = False
                exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    self.START_KEY = True
                if event.key == pygame.K_BACKSPACE:
                    self.BACK_KEY = True
                if event.key == pygame.K_DOWN:
                    self.DOWN_KEY = True
                if event.key == pygame.K_UP:
                    self.UP_KEY = True
            if event.type == pygame.MOUSEBUTTONDOWN:
                self.CLICK = True
                self.mouseX = event.pos[0]
                self.mouseY = event.pos[1]


    def draw_table(self):
        rect_w = self.DISPLAY_W//self.columns
        rect_h = self.DISPLAY_H//self.rows
        self.window.fill(WHITE)
        for row in range(0, self.rows):
            for col in range(0, self.columns):
                pygame.draw.rect(self.window, self.BLACK, pygame.Rect(col*rect_w, row*rect_h, rect_w, rect_h), 5)


    def reset_keys(self):
        self.UP_KEY, self.DOWN_KEY, self.START_KEY, self.BACK_KEY, self.CLICK = False, False, False, False, False
        self.mouseX, self.mouseY = -1, -1


    def draw_text(self, text, size, x, y):
        font = pygame.font.Font(self.font_name, size)
        text_surface = font.render(text, True, self.WHITE)
        text_rect = text_surface.get_rect()
        text_rect.center = (x, y)
        self.display.blit(text_surface, text_rect)




class Menu:
    def __init__(self, game):
        self.game = game
        self.mid_w, self.mid_h = self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2
        self.run_display = True
        self.cursor_rect = pygame.Rect(-10, -10, 70, 70)
        self.offset = -100


    def draw_cursor(self):
        self.game.draw_text('*', 15, self.cursor_rect.x, self.cursor_rect.y)


    def blit_screen(self):
        self.game.window.blit(self.game.display, (0, 0))
        pygame.display.update()
        self.game.reset_keys()


class MainMenu(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)
        self.state = "Start"
        self.startx, self.starty = self.mid_w, self.mid_h + 30
        self.optionsx, self.optionsy = self.mid_w, self.mid_h + 50
        self.creditsx, self.creditsy = self.mid_w, self.mid_h + 70
        self.quitx, self.quity = self.mid_w, self.mid_h + 90
        self.cursor_rect.midtop = (self.startx + self.offset, self.starty)


    def display_menu(self):
        self.run_display = True
        while self.run_display:
            self.game.check_events()
            self.check_input()
            self.game.display.fill(self.game.BLACK)
            self.game.draw_text('Main Menu', 20, self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 - 20)
            self.game.draw_text('Start Game', 20, self.startx, self.starty)
            self.game.draw_text('Options', 20, self.optionsx, self.optionsy)
            self.game.draw_text('Credits', 20, self.creditsx, self.creditsy)
            self.game.draw_text('Quit', 20, self.quitx, self.quity)
            self.draw_cursor()
            self.blit_screen()


    def move_cursor(self):
        if self.game.DOWN_KEY:
            if self.state == 'Start':
                self.cursor_rect.midtop = (self.optionsx + self.offset, self.optionsy)
                self.state = 'Options'
            elif self.state == 'Options':
                self.cursor_rect.midtop = (self.creditsx + self.offset, self.creditsy)
                self.state = 'Credits'
            elif self.state == 'Credits':
                self.cursor_rect.midtop = (self.quitx + self.offset, self.quity)
                self.state = 'Quit'
            elif self.state == 'Quit':
                self.cursor_rect.midtop = (self.startx + self.offset, self.starty)
                self.state = 'Start'
        elif self.game.UP_KEY:
            if self.state == 'Start':
                self.cursor_rect.midtop = (self.quitx + self.offset, self.quity)
                self.state = 'Quit'
            elif self.state == 'Options':
                self.cursor_rect.midtop = (self.startx + self.offset, self.starty)
                self.state = 'Start'
            elif self.state == 'Credits':
                self.cursor_rect.midtop = (self.optionsx + self.offset, self.optionsy)
                self.state = 'Options'
            elif self.state == 'Quit':
                self.cursor_rect.midtop = (self.creditsx + self.offset, self.creditsy)
                self.state = 'Credits'


    def check_input(self):
        self.move_cursor()
        if self.game.START_KEY:
            if self.state == 'Start':
                self.game.curr_menu = self.game.start_game
            elif self.state == 'Options':
                self.game.curr_menu = self.game.options
            elif self.state == 'Credits':
                self.game.curr_menu = self.game.credits
            elif self.state == 'Quit':
                self.game.playing, self.game.running = False, False
            self.run_display = False


class StartMenu(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)
        self.state = 'Player 1'
        self.player1_x, self.player1_y = self.mid_w - 50, self.mid_h + 20
        self.player2_x, self.player2_y = self.mid_w - 50, self.mid_h + 40


    def display_menu(self):
        self.run_display = True
        while self.run_display:
            self.game.check_events()
            self.check_input()
            self.game.display.fill((0, 0, 0))
            self.game.draw_text('Player 1  ( X )', 20, self.player1_x, self.player1_y)
            self.game.draw_text('Player 2  ( O )', 20, self.player2_x, self.player2_y)
            self.draw_cursor()
            self.blit_screen()



    def check_input(self):
        if self.game.BACK_KEY:
            self.game.curr_menu = self.game.main_menu
            self.run_display = False
        elif self.game.UP_KEY or self.game.DOWN_KEY:
            if self.state == 'Player 1':
                self.state = 'Player 2'
                self.cursor_rect.midtop = (self.player2_x + self.offset, self.player2_y)
            elif self.state == 'Player 2':
                self.state = 'Player 1'
                self.cursor_rect.midtop = (self.player1_x + self.offset, self.player1_y)
        elif self.game.START_KEY:
            if self.state == 'Player 1':
                self.game.human, self.game.computer = 1, 2
            elif self.state == 'Player 2':
                self.game.computer, self.game.human = 1, 2
            self.game.playing = True
            self.run_display = False
            self.game.curr_menu = self.game.play_game


class Play_Game(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)
        self.selected_row, self.selected_column = -1, -1
        self.player_turn = 1
        self.move_index = 0


    def reset_keys(self):
        self.player_turn, self.selected_column, self.selected_row = 1, -1, -1
        self.move_index = 0

    def display_menu(self): # TO-DO Solve the problem when selecting a bad cell for the current move
        if self.game.playing:
            self.run_display = True
            self.board = Board(self.game.rows, self.game.columns)
            self.game_repo = GameRepo(self.board)
            self.game_services = GameServices(self.game_repo)
            human, computer = self.game.human, self.game.computer

            while self.run_display:
                self.end_game()
                self.game.check_events()
                self.check_input()
                self.game.draw_table()
                self.draw_pieces()
                pygame.display.update()
                self.game.reset_keys()


    def check_input(self):
        if self.game.BACK_KEY:
            self.game.curr_menu = self.game.main_menu
            self.run_display = False
            self.game.playing = False
            self.reset_keys()

        if self.game.playing == True and self.player_turn == self.game.computer:
            self.computer_random_turn()

        if self.game.CLICK:
            if self.game.playing == True:
                if self.player_turn == self.game.human:
                    rect_w = self.game.DISPLAY_W // self.game.columns
                    rect_h = self.game.DISPLAY_H // self.game.rows
                    self.selected_column = self.game.mouseX//rect_w
                    self.selected_row = self.game.mouseY//rect_h
                    self.human_turn(self.selected_row, self.selected_column)


    def end_game(self):
        if self.game_services.game_state() == False:
            self.game.curr_menu = self.game.winner_status
            self.run_display = False
            self.game.playing = False
            if self.player_turn == self.game.human:
                self.game.winner = self.game.computer
            elif self.player_turn == self.game.computer:
                self.game.winner = self.game.human
            self.reset_keys()



    def human_turn(self, x, y):
        if self.game_services.is_available(x, y) == True:
            self.game_services.move(x, y, self.game.human)
            self.player_turn = self.game.computer
            self.move_index += 1


    def computer_random_turn(self):
        if self.move_index >= 3:
            self.game_services.make_best_move(self.game.depth, self.player_turn, self.game.human, self.game.computer)
        else:
            self.game_services.random_move(self.game.computer)
        # self.game_services.random_move(self.game.computer)
        self.player_turn = self.game.human
        self.move_index += 1

    def draw_pieces(self):
        rect_w = self.game.DISPLAY_W // self.game.columns
        rect_h = self.game.DISPLAY_H // self.game.rows
        min_side = min(rect_w, rect_h) // 4
        for row in range(0, self.game.rows):
            for col in range(0, self.game.columns):
                if self.game_services.board[row, col] == 2:
                    pygame.draw.circle(self.game.window, self.game.BLUE, (col * rect_w + rect_w / 2, row * rect_h + rect_h / 2), min_side, 7)
                elif self.game_services.board[row, col] == 1:
                    x1, y1 = col * rect_w + rect_w / 4, row * rect_h + rect_h / 4
                    x2, y2 = col * rect_w + (3 * rect_w) / 4, row * rect_h + (3 * rect_h) / 4
                    pygame.draw.line(self.game.window, self.game.RED, (x1, y1), (x2, y2), 10)
                    pygame.draw.line(self.game.window, self.game.RED, (x2, y1), (x1, y2), 10)
                elif self.game_services.is_available(row, col) == False and self.game_services.board[row, col] == 0:
                    # if the cell is not available but it has not a move placed on it
                    gray = (128,128,128)
                    pygame.draw.rect(self.game.window, self.game.BLACK, pygame.Rect(col * rect_w, row * rect_h, rect_w, rect_h), 5)
                    pygame.draw.rect(self.game.window, gray, pygame.Rect(col * rect_w + 5, row * rect_h + 5, rect_w-10, rect_h-10))


class WinnerStatus(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)


    def display_menu(self):
        self.run_display = True
        while self.run_display:
            self.game.check_events()
            self.check_input()
            self.game.display.fill(self.game.BLACK)
            if self.game.winner == self.game.human:
                self.game.draw_text('YOU WON', 20, self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 - 20)
            elif self.game.winner == self.game.computer:
                self.game.draw_text('YOU LOST', 20, self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 - 20)
            self.blit_screen()


    def check_input(self):
        if self.game.BACK_KEY:
            self.game.curr_menu = self.game.main_menu
            self.run_display = False


class OptionsMenu(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)
        self.state = '6 x 5'
        self.grid1_x, self.grid1_y = self.mid_w, self.mid_h + 20
        self.grid2_x, self.grid2_y = self.mid_w, self.mid_h + 40
        self.grid3_x, self.grid3_y = self.mid_w, self.mid_h + 60
        self.grid4_x, self.grid4_y = self.mid_w, self.mid_h + 80
        self.grid5_x, self.grid5_y = self.mid_w, self.mid_h + 100
        self.cursor_rect.midtop = (self.grid1_x + self.offset, self.grid1_y)


    def display_menu(self):
        self.run_display = True
        while self.run_display:
            self.game.check_events()
            self.check_input()
            self.game.display.fill((0, 0, 0)) # fill with black
            self.game.draw_text('Grid size', 20, self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 - 30)
            self.game.draw_text('6 x 5', 15, self.grid1_x, self.grid1_y)
            self.game.draw_text('6 x 6', 15, self.grid2_x, self.grid2_y)
            self.game.draw_text('7 x 6', 15, self.grid3_x, self.grid3_y)
            self.game.draw_text('8 x 7', 15, self.grid4_x, self.grid4_y)
            self.game.draw_text('8 x 8', 15, self.grid5_x, self.grid5_y)
            self.draw_cursor()
            self.blit_screen()


    def check_input(self):
        if self.game.BACK_KEY:
            self.game.curr_menu = self.game.main_menu
            self.run_display = False
        elif self.game.DOWN_KEY:
            if self.state == '6 x 5':
                self.state = '6 x 6'
                self.cursor_rect.midtop = (self.grid2_x + self.offset, self.grid2_y)
            elif self.state == '6 x 6':
                self.state = '7 x 6'
                self.cursor_rect.midtop = (self.grid3_x + self.offset, self.grid3_y)
            elif self.state == '7 x 6':
                self.state = '8 x 7'
                self.cursor_rect.midtop = (self.grid4_x + self.offset, self.grid4_y)
            elif self.state == '8 x 7':
                self.state = '8 x 8'
                self.cursor_rect.midtop = (self.grid5_x + self.offset, self.grid5_y)
            elif self.state == '8 x 8':
                self.state = '6 x 5'
                self.cursor_rect.midtop = (self.grid1_x + self.offset, self.grid1_y)
        elif self.game.UP_KEY:
            if self.state == '6 x 5':
                self.state = '8 x 8'
                self.cursor_rect.midtop = (self.grid5_x + self.offset, self.grid5_y)
            elif self.state == '6 x 6':
                self.state = '6 x 5'
                self.cursor_rect.midtop = (self.grid1_x + self.offset, self.grid1_y)
            elif self.state == '7 x 6':
                self.state = '6 x 6'
                self.cursor_rect.midtop = (self.grid2_x + self.offset, self.grid2_y)
            elif self.state == '8 x 7':
                self.state = '7 x 6'
                self.cursor_rect.midtop = (self.grid3_x + self.offset, self.grid3_y)
            elif self.state == '8 x 8':
                self.state = '8 x 7'
                self.cursor_rect.midtop = (self.grid4_x + self.offset, self.grid4_y)
        elif self.game.START_KEY:
           # IMPLEMENT A GETTER FOR THE SETTINGS
            if self.state == '6 x 5':
                self.game.rows, self.game.columns = 6, 5
                self.game.depth = 3
            elif self.state == '6 x 6':
                self.game.rows, self.game.columns = 6, 6
                self.game.depth = 3
            elif self.state == '7 x 6':
                self.game.rows, self.game.columns = 7, 6
                self.game.depth = 2
            elif self.state == '8 x 7':
                self.game.rows, self.game.columns = 8, 7
                self.game.depth = 2
            elif self.state == '8 x 8':
                self.game.rows, self.game.columns = 8, 8
                self.game.depth = 2
            self.run_display = False


class CreditsMenu(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)


    def display_menu(self):
        self.run_display = True
        while self.run_display:
            self.game.check_events()
            if self.game.BACK_KEY:
                self.game.curr_menu = self.game.main_menu
                self.run_display = False
            self.game.display.fill(self.game.BLACK)
            self.game.draw_text('Credits', 20, self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 - 20)
            self.game.draw_text('Made by Dan Bejenaru', 15, self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 + 10)
            self.blit_screen()


g = Game()
while g.running:
    g.game_loop()

