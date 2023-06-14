from src.repository.ClientRepository import ClientRepository
from src.domain.Client import Client
from src.domain.ClientValidator import ClientValidator

class ClientFileRepository(ClientRepository):
    def __init__(self, file_name):
        super().__init__()
        self.__file_name = file_name
        self.__entity_validator = ClientValidator()


    def read_file(self):
        try:
            with open(self.__file_name, "rt") as read:
                for index, line in enumerate(read.readlines()):
                    if line != "\n":
                        tokens = line.upper().split("|")
                        if len(tokens) != 2:
                            raise Exception(f"Line {index} of the file {str(self.__file_name)} has"
                                            f" {len(tokens)} parameters, but only 2 are requiered!")
                        client_id = tokens[0].strip()
                        client_name = tokens[1].strip()
                        client = Client(client_id, client_name)
                        self.__entity_validator.validate(client)
                        self.add_client(client)
        except IOError:
            raise IOError("File not found!")
        except EOFErro1r:
            pass


    def save_file(self):
        try:
            with open(self.__file_name, "wt") as write:
                for client in self.clients_list:
                    line = str(client.client_id) + " | " + str(client.client_name) + "\n"
                    write.write(line)
        except IOError:
            raise IOError("File not found!")
