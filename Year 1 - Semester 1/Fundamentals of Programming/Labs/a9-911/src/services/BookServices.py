from src.domain.Book import Book
from src.repository.HistoryOperationsRepository import Call, Operations
from src.services.PyFilter.PyFilter import Algorithms, Collection

class BookServices:
    def __init__(self, book_repo, book_validator, rental_services, history_service):
        self.__book_repo = book_repo
        self.__book_validator = book_validator
        self.__rental_services = rental_services
        self.__history_service = history_service


    def initialiaze_repo_service(self, n):
        self.__book_repo.generate_books(n)


    def add_book_service(self, book_id, book_title, book_author):
        book = Book(book_id, book_title, book_author)
        self.__book_validator.validate(book)
        self.__book_repo.add_book(book)

        tuple_operation = (Call(self._remove_book_service, book_id, book_title, book_author),
                           Call(self._add_book_service, book_id, book_title, book_author))

        operations = Operations()
        operations.add_operation(tuple_operation)
        self.__history_service.register_operation(operations)


    def _add_book_service(self, book_id, book_title, book_author):  # for undo/redo
        book = Book(book_id, book_title, book_author)
        self.__book_validator.validate(book)
        self.__book_repo.add_book(book)


    def remove_book_service(self, book_id, book_title, book_author):
        book = Book(book_id, book_title, book_author)
        self.__book_validator.validate(book)
        self.__book_repo.remove_book(book)
        tuple_operation = (Call(self._add_book_service, book_id, book_title, book_author),
                           Call(self._remove_book_service, book_id, book_title, book_author))

        operations = Operations()
        operations.add_operation(tuple_operation)

        mark = []
        for index, rental in enumerate(self.__rental_services.list_rentals_service()):
            if rental.book_id == book_id:
                mark.append(index)
                tuple_operation = (Call(self.__rental_services.add_rental_service, rental), None)
                operations.add_operation(tuple_operation)

        self.__history_service.register_operation(operations)
        for index in sorted(mark, reverse=True):
            self.__rental_services.delete_rental_by_index_service(index)



    def _remove_book_service(self, book_id, book_title, book_author):   # for undo/redo
        book = Book(book_id, book_title, book_author)
        self.__book_validator.validate(book)
        self.__book_repo.remove_book(book)
        mark = []
        for index, rental in enumerate(self.__rental_services.list_rentals_service()):
            if rental.book_id == book_id:
                mark.append(index)

        for index in sorted(mark, reverse=True):
            self.__rental_services.delete_rental_by_index_service(index)


    def update_book_service(self, old_book_id, old_book_title, old_book_author, new_book_title, new_book_author):
        old_book = Book(old_book_id, old_book_title, old_book_author)
        new_book = Book(old_book_id, new_book_title, new_book_author)
        self.__book_validator.validate(old_book)
        self.__book_validator.validate(new_book)
        self.__book_repo.update_book(old_book, new_book)
        tuple_operation = (Call(self._update_book_service, old_book_id, new_book_title, new_book_author, old_book_title, old_book_author),
                           Call(self._update_book_service, old_book_id, old_book_title, old_book_author, new_book_title, new_book_author))
        operations = Operations()
        operations.add_operation(tuple_operation)
        self.__history_service.register_operation(operations)


    def _update_book_service(self, old_book_id, old_book_title, old_book_author, new_book_title, new_book_author):  # for undo/redo
        old_book = Book(old_book_id, old_book_title, old_book_author)
        new_book = Book(old_book_id, new_book_title, new_book_author)
        self.__book_validator.validate(old_book)
        self.__book_validator.validate(new_book)
        self.__book_repo.update_book(old_book, new_book)


    def filter_books_service(self, book_id, book_title, book_author):
        result = []
        for book in self.__book_repo.books_list:
            if book_id != None and book.book_id != book_id:
                continue
            if book_title != None and book_title not in book.book_title:
                continue
            if book_author != None and  book_author not in book.book_author:
                continue
            result.append(book)
        return result


    def list_books_service(self):
        return self.__book_repo.books_list


    # @staticmethod
    # def alphabetical_order_by_title(book1, book2):
    #     if book1.book_title > book2.book_title:
    #         return True
    #
    #
    # def sorted_books(self, function):
    #     r = Algorithms(self.list_books_service())
    #     return r.shell_sort(function)
    #
    #
    # @staticmethod
    # def even_id(book):
    #     if int(book.book_id) % 2 == 0:
    #         return True
    #     return False
    #
    #
    # def filter_with_function(self, function):
    #     r = Algorithms(self.list_books_service())
    #     return r.filter(function)