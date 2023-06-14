from src.domain.Board import Board
from src.repository.GameRepository import GameRepo
from src.services.GameServices import GameServices
import unittest

class Tests(unittest.TestCase):
    def setUp(self) -> None:
        self.__board = Board(6, 6)
        self.__game_repo = GameRepo(self.__board)
        self.__game_services = GameServices(self.__game_repo)


    def test_is_inside(self):
        self.assertFalse(self.__game_services.is_inside(-1, -1))
        self.assertTrue(self.__game_services.is_inside(1, 1))


    def test_is_available(self):
        self.__game_services.move(3, 3, 1)
        self.assertFalse(self.__game_services.is_available(3, 3))
        self.assertTrue(self.__game_services.is_available(1, 1))
        self.__game_services.reset_move(3, 3)


    def test_move(self):
        try:
            self.__game_services.move(3, 3, 1)
            assert True
        except:
            assert False

        try:
            self.__game_services.move(3, 3, 1)
            assert False
        except:
            assert True

        try:
            self.__game_services.move(1, 1, 10)
            assert False
        except:
            assert True

        try:
            self.__game_services.move(1, 1, 1)
            assert True
        except:
            assert False

        try:
            self.__game_services.reset_move(3, 3)
            assert True
        except:
            assert False


    def test_random_move(self):
        try:
            self.__game_services.random_move(1)
            assert True
        except:
            assert False

        try:
            self.__game_services.random_move(3)
            assert False
        except:
            assert True

        for row in range(self.__game_services.board.rows):
            for col in range(self.__game_services.board.columns):
                self.__game_services.reset_move(row, col)


    def test_ai(self):
        self.__game_services.move(2, 2, 1)
        self.assertEqual(8, self.__game_services.calculate_neighbours(2,2))
        self.assertEqual(8, self.__game_services.calculate_current_score(1))
        self.__game_services.reset_move(2, 2)

        try:
            self.__game_services.make_best_move(1, 1, 1, 2)
            assert True
        except:
            assert False

        for row in range(self.__game_services.board.rows):
            for col in range(self.__game_services.board.columns):
                self.__game_services.reset_move(row, col)



    def tearDown(self) -> None:
        self.__board = None
        self.__game_repo = None
        self.__game_services = None