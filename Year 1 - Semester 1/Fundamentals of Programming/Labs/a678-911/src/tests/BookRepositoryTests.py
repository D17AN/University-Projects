import unittest
from src.repository.BookRepository import BookRepository
from src.domain.Book import Book
class Tests(unittest.TestCase):
    def setUp(self):
        self.__repo = BookRepository()


    def test_add(self):
        self.__repo.add_book(Book("1", "Mizerabilii", "Victor Hugo"))
        self.__repo.add_book(Book("2", "Coding the Matrix", "Philip N. Klein"))
        self.assertEqual(self.__repo.books_list, [Book("1", "Mizerabilii", "Victor Hugo"),
                                           Book("2", "Coding the Matrix", "Philip N. Klein")])
        self.assertNotEqual(self.__repo.books_list, [Book("1", "Mizerabilii", "Victor Hugo")])
        self.assertNotIn(Book("3", "Mizerabilii", "Victor Hugo"), self.__repo.books_list)
        self.assertIn(Book("1", "Mizerabilii", "Victor Hugo"), self.__repo.books_list)


    def test_remove(self):
        self.__repo.add_book(Book("1", "Mizerabilii", "Victor Hugo"))
        self.__repo.add_book(Book("2", "Coding the Matrix", "Philip N. Klein"))
        self.__repo.remove_book(Book("2", "Coding the Matrix", "Philip N. Klein"))
        self.assertEqual(self.__repo.books_list, [Book("1", "Mizerabilii", "Victor Hugo")])
        self.assertNotEqual(self.__repo.books_list, [Book("1", "Mizerabilii", "Victor Hugo"), Book("2", "Coding the Matrix", "Philip N. Klein")])
        self.assertNotIn(Book("3", "Mizerabilii", "Victor Hugo"), self.__repo.books_list)
        self.assertIn(Book("1", "Mizerabilii", "Victor Hugo"), self.__repo.books_list)


    def test_update(self):
        self.__repo.add_book(Book("1", "Mizerabilii", "Victor Hugo"))
        self.__repo.add_book(Book("2", "Coding the Matrix", "Philip N. Klein"))
        self.__repo.update_book(Book("1", "Mizerabilii", "Victor Hugo"), Book("1", "Harap Alb", "Ion Creanga"))
        self.assertEqual(self.__repo.books_list, [Book("1", "Harap Alb", "Ion Creanga"), Book("2", "Coding the Matrix", "Philip N. Klein")])
        self.assertNotEqual(self.__repo.books_list, [Book("1", "Mizerabilii", "Victor Hugo"), Book("2", "Coding the Matrix", "Philip N. Klein")])
        self.assertNotIn(Book("1", "Mizerabilii", "Victor Hugo"), self.__repo.books_list)
        self.assertIn(Book("1", "Harap Alb", "Ion Creanga"), self.__repo.books_list)


    def tearDown(self):
        self.__repo = None
