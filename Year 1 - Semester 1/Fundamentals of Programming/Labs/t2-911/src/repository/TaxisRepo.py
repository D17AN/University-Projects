class TaxisRepo:
    def __init__(self):
        self.taxis_list = []


    def add_taxi(self, taxi):
        self.taxis_list.append(taxi)


    def delete_taxi(self, taxi):
        self.taxis_list.remove(taxi)


    def update_taxi(self, index, new_taxi):
        self.taxis_list[index] = new_taxi
