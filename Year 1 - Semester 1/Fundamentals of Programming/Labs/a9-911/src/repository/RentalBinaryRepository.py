from src.repository.RentalRepository import RentalRepository
from src.domain.Rental import Rental
from src.domain.RentalValidator import RentalValidator
import pickle
from copy import deepcopy

class RentalBinaryRepository(RentalRepository):
    def __init__(self, file_name):
        super().__init__()
        self.__file_name = file_name
        self.__entity_validator = RentalValidator()


    def read_file(self):
        try:
            data = []
            with open(self.__file_name, "rb") as f:
                data = pickle.load(f)

            for el in data: # check if each object it's a valide one
                self.__entity_validator.validate(el)

            for el in data:
                aux_el = deepcopy(el)
                self.add_rental(aux_el)

        except IOError:
            raise IOError("File not found!")
        except EOFError:
            pass


    def save_file(self):
        try:
            with open(self.__file_name, "wb") as f:
                pickle.dump(self.rentals_list, f)
        except IOError:
            raise IOError("File not found!")