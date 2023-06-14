from PyFilter import *
import unittest

class Tests(unittest.TestCase):
    def setUp(self) -> None:
        self.__alg1 = Algorithms([1, 2, 3, 4, 5])
        self.__alg2 = Algorithms([10, 15, 5, 2, 13])
        self.__alg3 = Algorithms([123, 234234, 1233, 1356, 946, 2345])


    @staticmethod
    def ascending_order(x, y):
        if x > y:
            return True
        return False


    @staticmethod
    def even_ascending_odd_descending(x, y):
        if x % 2 == 1 and y % 2 == 0:
            return True
        if x % 2 == 0 and y % 2 == 0 and x > y:
            return True
        if x % 2 == 1 and y % 2 == 1 and x < y:
            return True
        return False


    @staticmethod
    def descending_order(x, y):
        if x < y:
            return True
        return False


    def test_shell_sort(self):
        r1 = self.__alg1.shell_sort(lambda x, y: self.descending_order(x, y))
        r2 = self.__alg2.shell_sort(lambda x, y: self.ascending_order(x, y))
        r3 = self.__alg3.shell_sort(lambda x, y: self.even_ascending_odd_descending(x, y))
        # first part of r3 contains even numbers in ascending order,
        # the second part odd numbers in descending order
        self.assertEqual(r1, [5, 4, 3, 2, 1])
        self.assertEqual(r2, [2, 5, 10, 13, 15])
        self.assertEqual(r3, [946, 1356, 234234, 2345, 1233, 123])



    @staticmethod
    def even(x):
        if x % 2 == 0:
            return True
        return False


    def test_filter(self):
        r1 = self.__alg1.filter(lambda x: self.even(x))
        self.assertIn(4, r1)
        self.assertIn(2, r1)
        self.assertNotIn(5, r1)
        self.assertNotIn(3, r1)
        self.assertNotIn(1, r1)


    def test_setter(self):
        self.__col = Collection([1, 2])
        self.__col.data[0] = 3
        self.assertEqual(self.__col.data, [3, 2])


    def tearDown(self) -> None:
        self.__data1 = None
        self.__data2 = None
        self.__data3 = None