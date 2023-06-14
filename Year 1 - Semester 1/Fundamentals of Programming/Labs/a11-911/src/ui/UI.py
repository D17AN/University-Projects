from src.domain.Board import Board
from src.repository.GameRepository import GameRepo
from src.services.GameServices import GameServices

class GameUI:
    def __init__(self, game_repo):
        """
        :param game_repo: an object of type GameServices
        """
        self.__game_repo = game_repo
        self.__game_services = GameServices(game_repo)


    @staticmethod
    def set_Up_game():
        """
        :return: an object of type GameUI
        """
        while True:
            try:
                rows = int(input("Grid rows = "))
                columns = int(input("Grid columns = "))
                if rows <= 0 or columns <= 0:
                    raise Exception("Rows and columns should be positive integers!")
            except Exception as e:
                print(e)
            else:
                break
        board = Board(rows, columns)
        game_repo = GameRepo(board)
        return GameUI(game_repo)



    def print_board_ui(self):
        print(self.__game_services.board)


    def human_turn_ui(self, player):
        while True:
            try:
                x = int(input("row = ")) - 1
                y = int(input("column = ")) - 1
                self.__game_services.move(x, y, player)
            except Exception as e:
                print(e)
            else:
                break


    def computer_ai_turn_ui(self, player_turn, human, computer):
        # self.__game_services.random_move(player)
        self.__game_services.make_best_move(2, player_turn, human, computer)



    def computer_random_turn_ui(self, player):
        try:
            self.__game_services.random_move(player)
        except Exception as e:
            print(e)


    def play_game_with_computer(self):
        while True:
            try:
                human = int(input("Player 1 or 2?\n"))
                if human not in (1, 2):
                    raise Exception("Not a valid player! Only 1 and 2 are accepted!")
            except Exception as e:
                print(e)
            else:
                break

        computer = 2 if human == 1 else 1
        player_turn = 1
        if player_turn == computer:
            self.computer_random_turn_ui(computer)
            player_turn = 2
        while True:
            print(self.__game_services.board, "\n")
            if self.__game_services.game_state() == False: # if the game is over
                if human == player_turn:
                    print("You lost!")
                else:
                    print("You won!")
                break
            else:
                if player_turn == human:
                    self.human_turn_ui(human)
                else:
                    self.computer_ai_turn_ui(player_turn, human, computer)

                if player_turn == 1:
                    player_turn = 2
                elif player_turn == 2:
                    player_turn = 1




game = GameUI.set_Up_game()
game.play_game_with_computer()