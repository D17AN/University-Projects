from src.repository.repo import Repository
from src.controller.controller import Controller
import unittest

class Tests(unittest.TestCase):
    def setUp(self) -> None:
        self.controller = Controller(Repository("file.txt"))


    def test_calculate_score(self):
        self.assertEqual(self.controller.score, 15)
        self.assertFalse(self.controller.score == 14)


    def test_move(self):
        try:
            self.controller.move(0, 1, 1, 1)
            assert True
        except:
            assert False

        try:
            self.controller.move(0, 0, 0, 1, 0)
            assert False
        except:
            assert True


    def decrement_score(self):
        try:
            self.controller.decrement_score()
            assert True
        except:
            assert False


    def tearDown(self) -> None:
        self.controller = None
