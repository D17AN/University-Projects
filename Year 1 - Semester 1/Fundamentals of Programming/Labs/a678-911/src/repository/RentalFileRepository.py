from src.repository.RentalRepository import RentalRepository
from src.domain.Rental import Rental
from src.domain.RentalValidator import RentalValidator

class RentalFileRepository(RentalRepository):
    def __init__(self, file_name):
        super().__init__()
        self.__file_name = file_name
        self.__entity_validator = RentalValidator()


    def read_file(self):
        try:
            with open(self.__file_name, "rt") as read:
                for index, line in enumerate(read.readlines()):
                    if line != "\n":
                        tokens = line.upper().split("|")
                        if len(tokens) != 5:
                            raise Exception(f"Line {index} of the file {str(self.__file_name)} has"
                                            f" {len(tokens)} parameters, but only 5 are requiered!")
                        rental_id = tokens[0].strip()
                        book_id = tokens[1].strip()
                        client_id = tokens[2].strip()
                        rented_date = tokens[3].strip()
                        returned_date = tokens[4].strip()
                        if returned_date == "NONE":
                            returned_date = None
                        rental = Rental(rental_id, book_id, client_id, rented_date, returned_date)
                        self.__entity_validator.validate(rental)
                        self.add_rental(rental)
        except IOError:
            raise IOError("File not found!")
        except EOFError:
            pass


    def save_file(self):
        try:
            with open(self.__file_name, "wt") as write:
                for rental in self.rentals_list:
                    line = str(rental.rental_id) + " | " + str(rental.book_id) + " | " + str(rental.client_id) + " | " \
                           + str(rental.rented_date) + " | " + str(rental.returned_date) + "\n"
                    write.write(line)
        except IOError:
            raise IOError("File not found!")


