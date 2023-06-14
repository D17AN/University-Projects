import random
from src.domain.Client import Client
from src.domain.Exceptions import RepoException
from src.services.PyFilter.PyFilter import Collection
class ClientRepository:
    def __init__(self):
        """
        construct an object of type ClientRepository
        """
        self.__clients_list = Collection([])


    def generate_clients(self, n=20):
        """
        Generates n clients
        :param n: the number of clients to be generated
        """
        first_name_list = ["Andrei", "Cosmin", "Doru", "Ion", "Adrian", "Luigi", "Mario", "Florin"]
        last_name_list = ["Turcu", "Popescu", "Neculai", "Moremete", "Miculescu", "Cornea", "Busuioc"]
        cnp = "1"
        for i in range(n):
            first_name = random.choice(first_name_list).upper()
            last_name = random.choice(last_name_list).upper()
            client = Client(cnp, first_name + " " + last_name)
            cnp = str(int(cnp) + 1)
            self.__clients_list.append(client)

    @property
    def clients_list(self):
        """
        Getter for the clients list
        :return: a list of clients
        """
        return self.__clients_list


    """
    1) Add functionality
    """
    def check_id_unique(self, client_id):
        """
        Checks if a client id is unique
        :param new_client_id: a given client id
        :return: True if the client id is unique, false otherwise
        """
        for client in self.__clients_list:
            if client.client_id == client_id:
                return False

        return True


    def add_client(self, client):
        """
        Adds a client in the clients list
        :param client_id: a given client id
        :param client_name: a given client name
        """
        if self.check_id_unique(client.client_id) == False:
            raise RepoException(["The client id has already a correspondent in the clients repository!"])
        self.__clients_list.append(client)


    """
    2) Remove functionality
    """
    def remove_client(self, client):
        """
        Removes a client from the clients list
        :param client_id: the given id of the client
        :param client_name: the given name of the client
        """
        if self.check_id_unique(client.client_id) == True: # if the id of the client is unique it means that he's not in the repository
            raise RepoException(["The client is not in the repository!"])
        self.__clients_list.remove(client)


    """
    3) Update functionality
    """
    def __client_index(self, client1):
        """
        Finds the index of a client from the clients list
        :param client1: a given client
        :return: the index from the list of the given client
        """
        for i in range(0, len(self.__clients_list)):
            client2 = self.__clients_list[i]
            if client1 == client2:
                return i


    def update_client(self, old_client, new_client):
        """
        Updates a given client from the clients list
        :param old_client_id:
        :param old_client_name:
        :param new_client_id:
        :param new_client_name:
        """
        if self.check_id_unique(old_client.client_id) == True: # if the id of the client is unique it means that he's not in the repository
            raise RepoException(["The client is not in the repository!"])

        index = self.__client_index(old_client)
        self.__clients_list[index] = new_client


    def get_client_name(self, client_id):
        for client in self.__clients_list:
            if client.client_id == client_id:
                return client.client_name