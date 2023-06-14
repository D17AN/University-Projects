from src.TaxiServices.TaxiServices import TaxiServices
from src.repository.TaxisRepo import TaxisRepo
from src.domain.Taxi import Taxi

import unittest
class Tests(unittest.TestCase):
    def setUp(self):
        self.repo = TaxisRepo()

    def test_update(self):
        taxi1 = Taxi(1, 0, 0)
        self.repo.add_taxi(taxi1)
        taxi2 = Taxi(2, 0, 0)
        self.repo.update_taxi(0, taxi2)
        self.assertEqual(self.repo.taxis_list, [taxi2])


    def tearDown(self):
        self.repo = None