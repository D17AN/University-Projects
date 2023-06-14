from src.repository.BookRepository import BookRepository
from src.domain.BookValidator import BookValidator
from src.domain.Book import Book

class BookFileRepository(BookRepository):
    def __init__(self, file_name):
        super().__init__()
        self.__file_name = file_name
        self.__entity_validator = BookValidator()


    def read_file(self):
        try:
            with open(self.__file_name, "rt") as read:
                for index, line in enumerate(read.readlines()):
                    if line != "\n":
                        tokens = line.strip().upper().split("|")
                        if len(tokens) != 3:
                            raise Exception(f"Line {index} of the file {str(self.__file_name)} has"
                                            f" {len(tokens)} parameters, but only 3 are requiered!")
                        book_id = tokens[0].strip()
                        book_title = tokens[1].strip()
                        book_author = tokens[2].strip()
                        book = Book(book_id, book_title, book_author)
                        self.__entity_validator.validate(book)
                        self.add_book(book)
        except IOError:
            raise IOError("File not found!")
        except EOFError:
            pass



    def save_file(self):
        try:
            with open(self.__file_name, "wt") as write:
                for book in self.books_list:
                    line = str(book.book_id) + " | " + str(book.book_title) + " | " + str(book.book_author) + "\n"
                    write.write(line)
        except IOError:
            raise IOError("File not found!")


