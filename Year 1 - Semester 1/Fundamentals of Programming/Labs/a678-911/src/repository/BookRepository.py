import copy, random
from src.domain.Book import Book
from src.domain.Exceptions import RepoException

class BookRepository:
    def __init__(self):
        """
        constructor for a list of books
        """
        self.__books_list = []


    def generate_books(self, n=20):
        """
        Generate books
        :param n: how many books to be generated
        """

        books = [
                {'author': "Ion Creanga", 'books': ["Amintiri din Copilarie", "Ursul Pacalit de Vulpe", "Harap Alb",
                                                      "Danila Prepeleac"]},
                {'author': "Stephen King", 'books': ["Misery", "The Stand", "The Shining", "Pet Sematary", "Cujo",
                                                       "Doctor Sleep", "Under the Dome", "The Night Shift", "Joyland",
                                                       "The Long Walk"] },
                {'author': "J.R.R. Tolkien", 'books': ["The Fall of Gondolin", "The Hobbit",
                                                         "The Fellowship of the Ring", "The Two Towers",
                                                         "The Return of the King"]},
                {'author': "Friedrich Nietzsche", 'books': ["Thus Spoke Zarathustra",
                                                              "Beyond Good and Evil",
                                                              "God is dead", "Ecce Homo"]}
                ]

        id = "1"
        for i in range(n):
            index1 = random.randint(0, len(books) - 1)
            book_author = books[index1]['author'].upper()
            index2 = random.randint(0, len(books[index1]['books']) - 1)
            book_name = books[index1]['books'][index2].upper()
            book = Book(id, book_name, book_author)
            self.__books_list.append(book)
            id = str(int(id) + 1)


    @property
    def books_list(self):
        """
        Getter for the books list
        :return: the list of books
        """
        return self.__books_list


    """
    1) Add functionality
    """
    def check_id_unique(self, book_id):
        """
        Checks if a given id is unique
        :param book_id: the given id of a book
        :return: True if the given id is unique, False otherwise
        """
        for book in self.__books_list:
            if book.book_id == book_id:
                return False

        return True


    def add_book(self, book):
        """
        Add to the books list a book
        :param book_id: a given book
        """
        if self.check_id_unique(book.book_id) == False:
            raise RepoException(["The book id has already a corepsondent in the books repository!"])
        self.__books_list.append(book)


    """
    2) Remove functionality
    """
    def remove_book(self, book):
        """
        Removes a book from the books_list
        :param book_id: a given book
        """
        if self.check_id_unique(book.book_id) == True: # if the book id is not in the repository, that means the book is not in repository
            raise RepoException(["The book is not in the repository!"])
        self.__books_list.remove(book)


    """
    3) Update functionality
    """
    def __book_index(self, book1):
        """
        Finds the index of a book
        :param book1: a given book
        :return: the index of the book1
        """
        for i in range(len(self.__books_list)):
            book2 = self.__books_list[i]
            if book1 == book2:
                return i


    def update_book(self, old_book, new_book):
        """
        Updates a given book from the books list
        :param old_book_id: the old book given id
        :param old_book_title: the old book given title
        :param old_book_author: the old book given author
        :param new_book_id: the new book given id
        :param new_book_title: the new book given title
        :param new_book_author: the new book give author
        """
        if self.check_id_unique(old_book.book_id) == True: # the id wasn't found in repository, means the old book isn't in repository
            raise RepoException(["The book that must be updated it's not in repository!"])

        index = self.__book_index(old_book) # finding the position of the book that must be updated
        self.__books_list[index] = new_book


    """
    3) Search functionality
    """
    def get_book_title(self, book_id):
        """
        Returns the book title that has a certain id
        :param book_id: the id of a book
        :return: the name of the book
        """
        for book in self.__books_list:
            if book.book_id == book_id:
                return book.book_title


    def get_book_author(self, book_id):
        """
        Returns the book author that has a certain id
        :param book_id: the id of a book
        :return: the author of the book
        """
        for book in self.__books_list:
            if book.book_id == book_id:
                return book.book_author

