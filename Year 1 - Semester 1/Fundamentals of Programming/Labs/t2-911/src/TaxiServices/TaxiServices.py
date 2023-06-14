from random import randint
from src.domain.Taxi import Taxi
class TaxiServices:
    def __init__(self, repo):
        self.taxi_repo = repo


    def calculate_distance(self, x1, y1, x2, y2):
        return abs(int(x1) - int(x2)) + abs(int(y1) - int(y2))


    def add_taxi(self, id, x, y):
        taxi = Taxi(id, x, y)
        self.taxi_repo.add_taxi(taxi)


    def update_taxi(self, index, x, y, fare):
        old_taxi = self.taxi_repo.taxis_list[index]
        new_id = old_taxi.id
        new_fare = fare
        new_taxi = Taxi(new_id, x, y)
        new_taxi.fare = fare
        self.taxi_repo.update_taxi(index, new_taxi)


    def generate_taxi(self, id):
        while True:
            x2 = randint(0, 100)
            y2 = randint(0, 100)
            ok = 1
            for taxi in self.taxi_repo.taxis_list:
                d = self.calculate_distance(taxi.x, taxi.y, x2, y2)
                if d < 5:
                    ok = 0
            if ok == 1:
                self.add_taxi(id, x2, y2)
                break


    def closest_taxi(self, x1, y1):
        min_d = 1000
        min_taxi = -1
        for index, taxi in enumerate(self.taxi_repo.taxis_list):
            d = self.calculate_distance(x1, y1, taxi.x, taxi.y)
            if d < min_d:
                min_d = d
                taxi_index = index

        return taxi_index


    def sort_taxis_by_fare(self):
        return sorted(self.taxi_repo.taxis_list, reverse=False, key=lambda taxi: taxi.fare)



