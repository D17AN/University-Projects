from src.repository.ClientRepository import ClientRepository
from src.domain.Client import Client
import unittest

class Tests(unittest.TestCase):
    def setUp(self):
        self.__repo = ClientRepository()


    def test_add(self):
        self.__repo.add_client(Client("1", "Popescu Gigel"))
        self.__repo.add_client(Client("2", "Cazacu Aurelian"))
        self.assertNotIn(Client("3", "Popescu Marian"), self.__repo.clients_list)
        self.assertIn(Client("1", "Popescu Gigel"), self.__repo.clients_list)
        self.assertEqual(self.__repo.clients_list, [Client("1", "Popescu Gigel"), Client("2", "Cazacu Aurelian")])
        self.assertNotEqual(self.__repo.clients_list,[Client("3", "Popescu Gigel"), Client("2", "Cazacu Aurelian")])


    def test_remove(self):
        self.__repo.add_client(Client("1", "Popescu Gigel"))
        self.__repo.add_client(Client("2", "Cazacu Aurelian"))
        self.assertEqual(len(self.__repo.clients_list), 2)
        self.__repo.remove_client(Client("1", "Popescu Gigel"))
        self.assertEqual(len(self.__repo.clients_list), 1)
        self.assertNotIn(Client("1", "Popescu Gigel"), self.__repo.clients_list)
        self.assertIn(Client("2", "Cazacu Aurelian"), self.__repo.clients_list)


    def test_update(self):
        self.__repo.add_client(Client("1", "Popescu Gigel"))
        self.__repo.add_client(Client("2", "Cazacu Aurelian"))
        self.__repo.update_client(Client("2", "Cazacu Aurelian"), Client("2", "Preda Vasile"))
        self.assertNotIn(Client("2", "Cazacu Aurelian"), self.__repo.clients_list)
        self.assertIn(Client("2", "Preda Vasile"), self.__repo.clients_list)
        self.assertEqual([Client("1", "Popescu Gigel"), Client("2", "Preda Vasile")], self.__repo.clients_list)


    def tearDown(self):
        self.__repo = None