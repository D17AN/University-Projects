import unittest
from src.repository.RentalRepository import RentalRepository
from src.repository.ClientRepository import ClientRepository
from src.repository.BookRepository import BookRepository
from src.domain.Rental import Rental
from src.domain.Client import Client
from src.domain.Book import Book


class Tests(unittest.TestCase):
    def setUp(self):
        self.__rental_repo = RentalRepository()
        self.__book_repo = BookRepository()
        self.__client_repo = ClientRepository()
        self.__client_repo.add_client(Client("1", "Popescu Gigel"))
        self.__client_repo.add_client(Client("2", "Cazacu Aurelian"))
        self.__book_repo.add_book(Book("1", "Mizerabilii", "Victor Hugo"))
        self.__book_repo.add_book(Book("2", "Coding the Matrix", "Philip N. Klein"))


    def test_rental(self):
        self.__rental_repo.rent_book(Rental("1", "1", "1", "11/08/2021", None), self.__client_repo, self.__book_repo)
        self.assertEqual(len(self.__rental_repo.rentals_list), 1)
        try:
            self.__rental_repo.rent_book(Rental("1", "1", "3", "12/08/2021", None), self.__client_repo, self.__book_repo)
            assert False
        except:
            assert True
        self.assertEqual(len(self.__rental_repo.rentals_list), 1)
        self.assertEqual(self.__rental_repo.rentals_list, [Rental("1", "1", "1", "11/08/2021", None)])


    def test_return(self):
        self.__rental_repo.rent_book(Rental("1", "1", "1", "11/08/2021", None), self.__client_repo, self.__book_repo)
        self.__rental_repo.return_book(Rental("1", "1", "1", "11/08/2021", None),Rental("1", "1", "1", "11/08/2021", "12/08/2021"), self.__client_repo, self.__book_repo)
        self.assertIn(Rental("1", "1", "1", "11/08/2021", "12/08/2021"), self.__rental_repo.rentals_list)
        try:
            self.__rental_repo.return_book(Rental("2", "2", "2", "8/ 13/2019", None), Rental("2", "2", "2", "9/13/2019", "17/12/2019"),self.__client_repo, self.__book_repo)
            assert False
        except:
            assert True
        self.assertEqual(len(self.__rental_repo.rentals_list), 1)



    def tearDown(self):
        self.__rental_repo = None
        self.__book_repo = None
        self.__client_repo = None