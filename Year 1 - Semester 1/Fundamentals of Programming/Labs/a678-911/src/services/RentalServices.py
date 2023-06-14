from src.domain.Rental import Rental
from src.repository.HistoryOperationsRepository import Call, Operations


class RentalServices:
    def __init__(self, book_repo, client_repo, rental_repo, rental_validator, history_service):
        self.__history_service = history_service
        self.__book_repo = book_repo
        self.__client_repo = client_repo
        self.__rental_repo = rental_repo
        self.__rental_validator = rental_validator


    def initialiaze_repo_service(self, n):
        self.__rental_repo.generate_rentals(self.__client_repo, self.__book_repo, n)


    def rent_book_service(self, rental_id, book_id, client_id, rented_date):
        rental = Rental(rental_id, book_id, client_id, rented_date, None)
        self.__rental_validator.validate(rental)
        self.__rental_repo.rent_book(rental, self.__client_repo, self.__book_repo)
        tuple_operation = (Call(self.delete_rental_service, rental),
                           Call(self._rent_book_service, rental_id, book_id, client_id, rented_date))
        operations = Operations()
        operations.add_operation(tuple_operation)
        self.__history_service.register_operation(operations)


    def _rent_book_service(self, rental_id, book_id, client_id, rented_date):
        rental = Rental(rental_id, book_id, client_id, rented_date, None)
        self.__rental_validator.validate(rental)
        self.__rental_repo.rent_book(rental, self.__client_repo, self.__book_repo)


    def return_book_service(self, rental_id, book_id, client_id, rented_date, returned_date):
        rental = Rental(rental_id, book_id, client_id, rented_date, None)
        return_rental = Rental(rental_id, book_id, client_id, rented_date, returned_date)
        self.__rental_validator.validate(rental)
        self.__rental_validator.validate(return_rental)
        self.__rental_repo.return_book(rental, return_rental, self.__client_repo, self.__book_repo)
        operations = Operations()
        tuple_operation = (Call(self.delete_rental_service, return_rental),
                           Call(self._return_book_service, rental_id, book_id, client_id, rented_date, returned_date))
        operations.add_operation(tuple_operation)
        tuple_operation = (Call(self.add_rental_service, rental), None)
        operations.add_operation(tuple_operation)
        self.__history_service.register_operation(operations)


    def _return_book_service(self, rental_id, book_id, client_id, rented_date, returned_date):
        rental = Rental(rental_id, book_id, client_id, rented_date, None)
        return_rental = Rental(rental_id, book_id, client_id, rented_date, returned_date)
        self.__rental_validator.validate(rental)
        self.__rental_validator.validate(return_rental)
        self.__rental_repo.return_book(rental, return_rental, self.__client_repo, self.__book_repo)


    def most_rented_books(self):
        rental_books_dict = {}
        for rental in self.__rental_repo.rentals_list:
            id = rental.book_id
            book_title = self.__book_repo.get_book_title(id)    # get the book name based by its id
            book_author = self.__book_repo.get_book_author(id)  # get the book author base by its id
            book = book_title + " by " + book_author # the book will be stored in this format in the dictionary
            if book not in rental_books_dict:
                rental_books_dict[book] = 1
            else:
                rental_books_dict[book] += 1

        # Add the books which were never rented
        for book in self.__book_repo.books_list:
            book = book.book_title + " by " + book.book_author
            if book not in rental_books_dict:
                rental_books_dict[book] = 0

        result = []
        for book in rental_books_dict:
            result.append(BookRentalDTO(book, rental_books_dict[book]))

        result.sort(key=lambda obj: obj.rentals, reverse=True)
        return result


    def most_active_clients(self):
        clients_dict = {}
        for rental in self.__rental_repo.rentals_list:
            client_id = rental.client_id # the id of a client
            client_name = self.__client_repo.get_client_name(client_id) # gets the name of the client with that id
            client = client_name + " with id " + client_id
            if client not in clients_dict:
                clients_dict[client] = len(rental)
            else:
                clients_dict[client] += len(rental)

        for client in self.__client_repo.clients_list:
            client = client.client_name + " with id " + client.client_id
            if client not in clients_dict:
                clients_dict[client] = 0

        result = []
        for client in clients_dict:
            result.append(ClientRentalDTO(client, clients_dict[client]))

        result.sort(key = lambda obj: obj.activity, reverse = True)
        return result


    def most_rented_authors(self):
        rental_authors_dict = {}
        for rental in self.__rental_repo.rentals_list:
            id = rental.book_id
            book_author = self.__book_repo.get_book_author(id)  # get the book author base by its id
            if book_author not in rental_authors_dict:
                rental_authors_dict[book_author] = 1
            else:
                rental_authors_dict[book_author] += 1

        # Add the books which were never rented
        for book in self.__book_repo.books_list:
            book_author = book.book_author
            if book_author not in rental_authors_dict:
                rental_authors_dict[book_author] = 0

        result = []
        for book_author in rental_authors_dict:
            result.append(BookRentalDTO(book_author, rental_authors_dict[book_author]))

        result.sort(key=lambda obj: obj.rentals, reverse=True)
        return result


    def add_rental_service(self, rental):
        self.__rental_repo.add_rental(rental)


    def delete_rental_service(self, rental):
        self.__rental_repo.delete_rental(rental)


    def delete_rental_by_index_service(self, index):
        self.__rental_repo.delete_rental_by_index(index)


    def list_rentals_service(self):
        return self.__rental_repo.rentals_list



class BookRentalDTO:
    """
    DTO for a book and number of times it was rented
    """
    def __init__(self, book, rentals):
        self.__book = book
        self.__rentals = rentals


    @property
    def book(self):
        return self.__book


    @property
    def rentals(self):
        return self.__rentals


    def __str__(self):
        return str(self.__book) + " - " + str(self.__rentals) + " times"



class ClientRentalDTO:
    def __init__(self, client, activity):
        self.__client = client
        self.__activity = activity


    def __str__(self):
        return str(self.__client) + " - activity of " + str(self.__activity) + " days"


    @property
    def client(self):
        return self.__client


    @property
    def activity(self):
        return self.__activity