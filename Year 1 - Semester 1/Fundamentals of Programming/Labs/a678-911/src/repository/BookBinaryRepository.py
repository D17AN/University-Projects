import pickle
from copy import deepcopy
from src.repository.BookRepository import BookRepository
from src.domain.BookValidator import BookValidator
from src.domain.Book import Book

class BookBinaryRepository(BookRepository):
    def __init__(self, file_name):
        super().__init__()
        self.__file_name = file_name
        self.__entity_validator = BookValidator()


    def read_file(self):
        try:
            data = []
            with open(self.__file_name, "rb") as f:
                data = pickle.load(f)
            for el in data: # validate each entity from data
                self.__entity_validator.validate(el)
            for el in data: # if the previous stage was completed we're ready to save the books in the repository
                aux_el = deepcopy(el)
                self.add_book(aux_el)
            return True # if the file was succesfully read then we return True
        except EOFError:
            "if the input of the file is empty we return None"
            return None
        except IOError as ioe:
            raise ioe


    def save_file(self):
        try:
            with open(self.__file_name, "wb") as f:
                pickle.dump(self.books_list, f)
        except IOError:
            raise IOError("File not found!")