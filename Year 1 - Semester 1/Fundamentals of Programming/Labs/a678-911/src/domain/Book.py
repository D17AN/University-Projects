class Book:
    """
    Object book has the attributes: id
                                    title
                                    author
    """
    def __init__(self, id, title, author):
        """
        Construct the entities of the object
        :param id: id of a book
        :param title: title of a book
        :param author: author of a book
        """
        self.__book_id = id
        self.__book_title = title
        self.__book_author = author


    def __str__(self):
        """
        :return: how should be displayed an object of type Book
        """
        return str(self.__book_title) + " by " + str(self.__book_author) + " with id " + str(self.__book_id)


    def __eq__(self, other_book):
        """
        Overwriting '==' allowing to compare objects of class Book
        :param other_book: An other object of type Book
        :return: True with 2 objects are equal, false otherwise
        """
        if not isinstance(other_book, Book):
            raise ValueError("Error, not allowed comparing objects from different classes!")
        return self.__book_id == other_book.__book_id and self.__book_title == other_book.__book_title and self.__book_author == other_book.__book_author


    @property
    def book_id(self):
        """
        getter for the id of a book
        :return: the id of book
        """
        return self.__book_id


    @book_id.setter
    def book_id(self, new_book_id):
        """
        setter for the id of a book
        :param new_book_id: the id of the book which must be attributed to the object of type Book
        """
        self.__book_id = new_book_id


    @property
    def book_title(self):
        """
        Getter for the title of a book
        :return: the title of a book
        """
        return self.__book_title


    @book_title.setter
    def book_title(self, new_book_title):
        """
        Setter for the title of a book
        :param new_book_title: the title of the book which must be attributed to the object of type Book
        """
        self.__book_title = new_book_title


    @property
    def book_author(self):
        """
        Getter for the book author
        :return: The author of a book
        """
        return self.__book_author


    @book_author.setter
    def book_author(self, new_book_author):
        """
        Setter for the author of a book
        :param new_book_author: the author of the book which must be attributed to the object of type Book
        """
        self.__book_author = new_book_author
