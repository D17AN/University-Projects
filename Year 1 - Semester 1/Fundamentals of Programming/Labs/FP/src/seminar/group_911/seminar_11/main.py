from datetime import date, datetime


from seminar.group_911.seminar_09.domain.Car import Car
from seminar.group_911.seminar_09.domain.Client import Client
from seminar.group_911.seminar_09.domain.Rental import Rental
from seminar.group_911.seminar_11.repository.Repository import Repository

alice = Client(101, "2801010266699", "Alice")
bob = Client(102, "1800101248899", "Bob")
carol = Client(103, "2670511035588", "Carol")
sophia = Client(104, "2990511035588", "Sophia")

hyundai_tucson = Car(201, "CJ 02 TWD", "Hyundai", "Tucson")
toyota_corolla = Car(202, "CJ 02 FWD", "Toyota", "Corolla")
dacia_sandero = Car(203, "IS 99 RTY", "Dacia", "Sandero")

# 301, 104, 201, 2016-11-1, 2016-11-30
# when loading, first load client 104 and car 201 -> then load rental repo data
rental_sophia_tucson = Rental(301, sophia, hyundai_tucson, date(2016, 11, 1), date(2016, 11, 30))
rental_sophia_toyota = Rental(302, sophia, hyundai_tucson, date(2016, 12, 1), date(2016, 12, 31))
rental_bob_dacia = Rental(303, bob, dacia_sandero, date(2021, 12, 1), date(2021, 12, 31))

"""
    1. Start up an in-memory repository
"""
car_repo = Repository()
car_repo.store(hyundai_tucson)
car_repo.store(toyota_corolla)
car_repo.store(dacia_sandero)

client_repo = Repository()
client_repo.store(alice)
client_repo.store(bob)
client_repo.store(carol)
client_repo.store(sophia)

rental_repo = Repository()
rental_repo.store(rental_sophia_toyota)
rental_repo.store(rental_sophia_tucson)
rental_repo.store(rental_bob_dacia)

# TODO Implement 2. and test it in a PyUnit test case
"""
    2. Switch to a text-file based repository
"""

class CarTextFileRepo(Repository):
    def __init__(self):
        super.__init__(Repository)


    def read_text_file(self, file_name):
        try:
            f = open(filen_name, "r")
            while len(line) > 0:
                line = f.readline().strip()
                line = line.split(";")
                car = Car(int(line[0]), line[1], line[2], line[3])
                self._objects.store(car)
            f.close()
        except Exception as e:
            print(e)


    def write_text_file(self, file_name):
        try:
            f = open(file_name, "w")
            for car in self._objects:
                car_str = str(car.id) + ";" + car.license + ";" + car.make + ";" + car.model + "\n"
                f.write(car_str)
            f.close()
        except Exception as e:
            print(e)


class ClientTextFileRepo(Repository):
    def __init__(self):
        super.__init__(Repository)


    def read_text_file(self, file_name):
        try:
            f = open(file_name, "r")
            while len(line) > 0:
                line = f.readline().strip()
                line = line.split(";")
                client = Client(int(line[0]), line[1], line[2])
                self._objects.store(client)
            f.close()
        except Exception as e:
            print(e)


    def write_text_file(self, file_name):
        try:
            f = open(file_name, "w")
            for client in self._objects:
                client_str = str(client.id) + ";" + client.cnp + ";" + car.name + "\n"
                f.write(client_str)
            f.close()
        except Exception as e:
            print(e)


rental_bob_dacia = Rental(303, bob, dacia_sandero, date(2021, 12, 1), date(2021, 12, 31))
class RentalTextFileRepo(Repository):
    def __init__(self):
        super.__init__(Repository)


    def read_text_file(self, file_name):
        try:
            f = open(file_name, "r")
            while len(line) > 0:
                line = f.readline().strip()
                line = line.split(";")
                client = Client(int(line[1]), line[2], line[3])
                car = Car(int(line[4]), line[5], line[6], line[7])
                rental = Rental(int(line[0]), client, car, datetime.strptime(line[8], "%d/%m/%Y"), datetime.strptime(line[9], "%d/%m/%Y"))
                self._objects.store(client)
            f.close()
        except Exception as e:
            print(e)


    def write_text_file(self, file_name):
        try:
            f = open(file_name, "w")
            for rental in self._objects:
                rental_str = str(rental.id) + ";" + rental.client + ";" + rental.car + ";" + str(rental.start) + ";" + str(rental.end) + ";" + car.name + "\n"
                f.write(rental_str)
            f.close()
        except Exception as e:
            print(e)



# TODO Implement 3. and test it in a PyUnit test case
#   use pickle or another Python serialization library
"""
    3. Implement a binary file repository
"""


class BinaryFileRepo(Repository):
    pass


"""
4. Implement a single text file Repository
"""


# TODO
#   pass a function reference (callable type) to __init__ to convert between <entity> and <str>
#   <entity>_to_<str> (e.g. car_to_str)
#   <str>_to_<entity> (e.g. str_to_car)
class TextFileRepo(Repository):
    def __init__(self, entity_to_str, str_to_entity):
        super().__init__()
