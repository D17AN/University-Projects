class Client:
    def __init__(self, id, name):
        """
        Construct a object of type Client with the entities id and name
        :param id: the id of a client
        :param name: the name of a client
        """
        self.__client_id = id
        self.__client_name = name


    def __str__(self):
        """
        :return: How should represented an object of type Client
        """
        return str(self.__client_name) + " with id " + str(self.__client_id)

    def __eq__(self, other_client):
        if not isinstance(other_client, Client):
            raise ValueError("Error, not allowed comparing objects from different classes!")
        return self.__client_id == other_client.__client_id and self.__client_name == other_client.__client_name


    @property
    def client_id(self):
        """
        Getter for the id of a client
        :return: the id of a client
        """
        return self.__client_id


    @client_id.setter
    def client_id(self, new_client_id):
        """
        Setter for the id of a client
        :param new_client_id: the id of a client which must be attributed to the the object of type client
        """
        self.__client_id = new_client_id


    @property
    def client_name(self):
        """
        Getter for the name of a client
        :return: the name of a client
        """
        return self.__client_name


    @client_name.setter
    def client_name(self, new_client_name):
        """
        Setter for the name of a client
        :param new_client_name: the name of a client which must be attributed to the object of type Client
        :return:
        """
        self.__client_name = new_client_name

