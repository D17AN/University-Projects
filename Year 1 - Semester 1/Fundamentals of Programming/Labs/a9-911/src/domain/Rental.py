from src.domain.Client import Client
from src.domain.Book import Book
from datetime import datetime, date

class Rental(Client, Book):
    def __init__(self, rental_id, book_id, client_id, rented_date, returned_date):
        self.__rental_id = rental_id
        self.__rented_date = rented_date
        self.__returned_date = returned_date
        Client.__init__(self, client_id, None)
        Book.__init__(self, book_id, None, None)


    def __str__(self):
        return "Rental : rental_id = " + str(self.__rental_id) + ", book id = " + str(self.book_id) + ", client id = " \
               + str(self.client_id) + ", rented date = " + str(self.__rented_date) + ", returned date = " + str(self.__returned_date)

    def __eq__(self, other_rental):
        if not isinstance(other_rental, Rental):
            raise ValueError("Error, not allowed comparing objects from different classes!")

        return self.__rental_id == other_rental.__rental_id and self.__rented_date == other_rental.__rented_date \
               and self.__returned_date == other_rental.__returned_date and self.book_id == other_rental.book_id \
               and self.client_id == other_rental.client_id

    def __len__(self):
        if self.__returned_date != None:
            t1 = datetime.strptime(self.__returned_date, "%d/%m/%Y")
            t0 = datetime.strptime(self.__rented_date, "%d/%m/%Y")
        else:
            t1 = datetime.today()
            t0 = datetime.strptime(self.__rented_date, "%d/%m/%Y")

        return (t1 - t0).days + 1


    @property
    def rental_id(self):
        """
        Getter for the rental id
        :return: the rental id
        """
        return self.__rental_id


    @rental_id.setter
    def rental_id(self, new_rental_id):
        """
        Setter for the rental id
        :param new_rental_id: the new rental id
        """
        self.__rental_id == new_rental_id


    @property
    def rented_date(self):
        """
        Getter for rented date
        :return: the rented date
        """
        return self.__rented_date


    @rented_date.setter
    def rented_date(self, new_rented_date):
        """
        Setter for the rented date
        :param new_rented_date: the new rented date
        """
        self.__rented_date = new_rented_date


    @property
    def returned_date(self):
        """
        Getter for the returned date
        :return: the returned date
        """
        return self.__returned_date


    @returned_date.setter
    def returned_date(self, new_returned_date):
        """
        Setter for the returned date
        :param new_returned_date: the new returned date
        """
        self.__returned_date = new_returned_date