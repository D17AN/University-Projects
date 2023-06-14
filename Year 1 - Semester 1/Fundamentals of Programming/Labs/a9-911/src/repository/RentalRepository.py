import random
from src.domain.Rental import Rental
from src.domain.Exceptions import RepoException
from copy import deepcopy
from src.services.PyFilter.PyFilter import Collection

class RentalRepository:
    def __init__(self):
        """
        Constructs a object of type rental repository
        """
        self.__rentals_list = Collection([])


    @property
    def rentals_list(self):
        return self.__rentals_list


    def generate_rentals(self, l1, l2, n = 20):
        """
        Generates n rentals for the rental list
        :param l1: a list of clients
        :param l2: a list of books
        """

        rental_id = "1"
        dates = [
                 ("11/10/2021", None),
                 ("17/05/2021", None),
                 ("01/10/2020", "14/10/2020"),
                 ("05/12/2019", "03/01/2020"),
                 ("21/04/2018", "12/06/2018"),
                 ("15/08/2021", "07/09/2021"),
                 ]
        for i in range(n):
            while True:
                client_index = random.randint(0, n - 1)
                book_index = random.randint(0, n - 1)
                date_index = random.randint(0, len(dates) - 1)
                client = deepcopy(l1.clients_list[client_index])
                book = deepcopy(l2.books_list[book_index])
                rented_date, returned_date = dates[date_index]
                rental = Rental(rental_id, book.book_id, client.client_id, rented_date, returned_date)
                if self.__is_book_rented(book.book_id) == False:
                    self.__rentals_list.append(rental)
                    rental_id = str(int(rental_id) + 1)
                    break


    """
    1) Rent/Return functionality
    """
    def __is_rental_id_unique(self, rental_id):
        """
        Checks if rental id is unique
        :param rental_id: a given rental id
        :return: True if the rental id is unique, False otherwise
        """
        for rental in self.__rentals_list:
            if rental.rental_id == rental_id:
                return False
        return True


    def __is_book_rented(self, book_id):
        """
        Checks if a book is rented
        :param book_id: the id of a given book
        :return: True if the book is rented, False otherwise
        """
        for i in range(len(self.__rentals_list) - 1, -1, -1):
            rented_book = self.__rentals_list[i]
            if rented_book.book_id == book_id:  # if we found the book we're looking for
                if rented_book.returned_date == None:   # if the book has not been returned, then the book is rented
                    return True

        return False


    def rent_book(self, rental, client_repo, book_repo):
        """
        Rent a book
        :param rental: an object of type rental
        :param client_repo: a class of Clients
        :param book_repo: a class of Books
        """
        errors = []
        if self.__is_rental_id_unique(rental.rental_id) == False:
            errors.append("The id of the rental it's already used by another rental!")

        if client_repo.check_id_unique(rental.client_id) == True:
            errors.append("The client which wants to rent the book doesn't exist!")

        if book_repo.check_id_unique(rental.book_id) == True:
            errors.append("The book which the client wants to rent it doesn't exists!")
        elif self.__is_book_rented(rental.book_id) == True:
            errors.append("The book is already rented!")

        try:
            if len(errors) > 0:
                raise RepoException(errors)
        except RepoException as re:
            print(re)

        self.__rentals_list.append(rental)


    def __rental_index(self, rental1):
        """
        Get the index of a rental
        :param rental1: the given rental
        :return: the index of rental1
        """
        for i in range(0, len(self.__rentals_list)):
            rental2 = self.__rentals_list[i]
            if rental1 == rental2:
                return i


    def return_book(self, rental, returned, client_repo, book_repo):
        """
        Return a book
        :param rental: an object of type rental
        :param returned: an object of type rental with the returned day set
        :param client_repo: a class of Clients
        :param book_repo: a class of Books
        """
        errors = []

        if self.__is_rental_id_unique(rental.rental_id) == True:
            errors.append("The given rental id has no correspondent in the rentals repository!")

        if client_repo.check_id_unique(rental.client_id) == True:
            errors.append("The client which wants to return the book doesn't exist!")

        if book_repo.check_id_unique(rental.book_id) == True:
            errors.append("The book which the client wants to return doesn't exist!")
        elif self.__is_book_rented(rental.book_id) == False:
            errors.append("The book is not rented to be returned!")

        try:
            if len(errors) > 0:
                raise RepoException(errors)
        except RepoException as re:
            print(re)

        index = self.__rental_index(rental)
        self.__rentals_list[index] = returned


    def delete_rental_by_index(self, index):
        """
        Deletes a rental from a certain index
        :param index: an index of the list
        """
        try:
            if index < 0 or index > len(self.__rentals_list):
                raise RepoException(["Index out of range!"])
            self.__rentals_list.pop(index)
        except RepoException as re:
            print(re)


    def delete_rental(self, rental):
        """
        Deletes a rental from the rental repository which already exists
        :param rental: a rental
        """
        try:
            index = self.__rental_index(rental)
            self.__rentals_list.pop(index)
        except Exception as e:
            print(e)


    def add_rental(self, rental):
        """
        Add a rental - used for undo/redo, forbideen to use for something else
        :param rental: a rental
        """
        self.__rentals_list.append(rental)




