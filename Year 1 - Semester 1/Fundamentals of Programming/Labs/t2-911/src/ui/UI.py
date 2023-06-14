from src.TaxiServices.TaxiServices import TaxiServices
from src.repository.TaxisRepo import TaxisRepo
class UI:
    def __init__(self, repo):
        self.repo = repo
        self.taxi_services = TaxiServices(repo)


    def generate_taxi_instances(self, n):
        id = 1
        for i in range(n):
            self.taxi_services.generate_taxi(id)
            id += 1


    def taxi_ride(self):
        while True:
            try:
                print("Location ride?\n")
                x = input("x = ")
                y = input("y = ")
                if not(x.isnumeric() and y.isnumeric()):
                    raise Exception("Not valid input")
                index = self.taxi_services.closest_taxi(x, y)
                old_taxi = self.taxi_services.taxi_repo.taxis_list[index]
                fare = old_taxi.fare + self.taxi_services.calculate_distance(old_taxi.x, old_taxi.y, x, y)
                self.taxi_services.update_taxi(index, x, y, fare)
            except Exception as e:
                    print(e)
            else:
                break

    def print_taxis(self):
        for el in self.taxi_services.sort_taxis_by_fare():
            print(el)


    def start(self):
        self.generate_taxi_instances(10)
        while True:
            decision = input("What do you want to do?")
            if decision == "1":
                self.taxi_ride()
            if decision == "2":
                pass
            if decision == "3":
                exit()
            if decision == "4":
                self.print_taxis()


r = TaxisRepo()
g = UI(r)
g.start()
