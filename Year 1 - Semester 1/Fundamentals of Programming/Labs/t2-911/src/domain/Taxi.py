class Taxi:
    def __init__(self, taxi_id, x, y):
        self.id = taxi_id
        self.x = x
        self.y = y
        self.fare = 0


    def __str__(self):
        return "Taxi: " + str(self.id).ljust(1) + str(" at location (" + str(self.x) + ", " + str(self.y) + ")" + " with fare " + str(self.fare)).rjust(1)


    def __eq__(self, other):
        if isinstance(other, Taxi):
            raise Exception("Not valid comparison")
        if self.id == other.id and self.x == other.x and self.y == other.y:
            return True
        return False


