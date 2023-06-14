from src.domain.Exceptions import ValidatorException
from src.domain.Book import Book

class BookValidator:
    @staticmethod
    def validate(book):
        errors = []
        if not isinstance(book, Book):
            errors.append("Not a book!")
        if not book.book_id.isnumeric():
            errors.append("The id is not numerical!")
        if int(book.book_id) < 1:
            errors.append("The id is not a positive integer!")

        if len(errors) > 0:
            raise ValidatorException(errors)