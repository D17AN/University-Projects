from src.domain.Rental import Rental
from src.domain.Exceptions import ValidatorException
from datetime import datetime
import sys

class RentalValidator:
    @staticmethod
    def validate(rental):
        errors = []
        if not isinstance(rental, Rental):
            errors.append("Not a rental!")
        if not rental.rental_id.isnumeric():
            errors.append("The rental id is not numerical!")
        elif int(rental.rental_id) < 1:
            errors.append("The rental id is not a positive integer!")

        if not rental.book_id.isnumeric():
            errors.append("The book id is not numerical!")
        elif int(rental.book_id) < 1:
            errors.append("The book id is not a positive integer!")

        if not rental.client_id.isnumeric():
            errors.append("The client id is not numerical!")
        elif int(rental.client_id) < 1:
            errors.append("The client id is not a positive integer!")

        try:
            datetime.strptime(rental.rented_date, "%d/%m/%Y")
        except ValueError as ve:
            exc_type, exc_value, exc_traceback = sys.exc_info()
            errors.append("Rental date: " + str(exc_value))

        if rental.returned_date != None:
            try:
                datetime.strptime(rental.returned_date, "%d/%m/%Y")
            except ValueError as ve:
                exc_type, exc_value, exc_traceback = sys.exc_info()
                errors.append("Returned date: " + str(exc_value))
            else:
                t1 = datetime.strptime(rental.returned_date, "%d/%m/%Y")
                t0 = datetime.strptime(rental.rented_date, "%d/%m/%Y")
                if t1 < t0: # if the returned date is before rent date
                    errors.append("Returned date < Rent date(You can't return a book before renting it!")

        if len(errors) > 0:
            raise ValidatorException(errors)


