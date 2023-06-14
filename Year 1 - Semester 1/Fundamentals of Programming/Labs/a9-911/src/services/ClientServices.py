from src.domain.Client import Client
from src.repository.HistoryOperationsRepository import Call, Operations


class ClientServices:
    def __init__(self, client_repo, client_validator, rental_services, history_service):
        self.__client_repo = client_repo
        self.__client_validator = client_validator
        self.__rental_services = rental_services
        self.__history_service = history_service


    def initialiaze_repo_service(self, n):
        self.__client_repo.generate_clients(n)


    def add_client_service(self, client_id, client_name):
        client = Client(client_id, client_name)
        self.__client_validator.validate(client)
        self.__client_repo.add_client(client)
        tuple_operation = (Call(self._remove_client_service, client_id, client_name),
                           Call(self._add_client_service, client_id, client_name))

        operations = Operations()
        operations.add_operation(tuple_operation)
        self.__history_service.register_operation(operations)


    def _add_client_service(self, client_id, client_name):  # for undo/redo
        client = Client(client_id, client_name)
        self.__client_validator.validate(client)
        self.__client_repo.add_client(client)


    def remove_client_service(self, client_id, client_name):
        client = Client(client_id, client_name)
        self.__client_validator.validate(client)
        self.__client_repo.remove_client(client)
        tuple_operation = (Call(self._add_client_service, client_id, client_name),
                           Call(self._remove_client_service, client_id, client_name))
        operations = Operations()
        operations.add_operation(tuple_operation)

        mark = []
        for index, rental in enumerate(self.__rental_services.list_rentals_service()):
            if rental.client_id == client_id:
                tuple_operation = (Call(self.__rental_services.add_rental_service, rental), None)
                operations.add_operation(tuple_operation)
                mark.append(index)

        self.__history_service.register_operation(operations)
        for index in sorted(mark, reverse=True):
            self.__rental_services.delete_rental_by_index_service(index)


    def _remove_client_service(self, client_id, client_name):    # for undo/redo
        client = Client(client_id, client_name)
        self.__client_validator.validate(client)
        self.__client_repo.remove_client(client)

        mark = []
        for index, rental in enumerate(self.__rental_services.list_rentals_service()):
            if rental.client_id == client_id:
                mark.append(index)

        for index in sorted(mark, reverse=True):
            self.__rental_services.delete_rental_by_index_service(index)


    def update_client_service(self, old_client_id, old_client_name, new_client_name):
        old_client = Client(old_client_id, old_client_name)
        new_client = Client(old_client_id, new_client_name)
        self.__client_validator.validate(old_client)
        self.__client_validator.validate(new_client)
        self.__client_repo.update_client(old_client, new_client)
        tuple_operation = (Call(self._update_client_service, old_client_id, new_client_name, old_client_name),
                           Call(self._update_client_service, old_client_id, old_client_name, new_client_name))
        operations = Operations()
        operations.add_operation(tuple_operation)
        self.__history_service.register_operation(operations)


    def _update_client_service(self, old_client_id, old_client_name, new_client_name):   # for undo/redo
        old_client = Client(old_client_id, old_client_name)
        new_client = Client(old_client_id, new_client_name)
        self.__client_validator.validate(old_client)
        self.__client_validator.validate(new_client)
        self.__client_repo.update_client(old_client, new_client)


    def filter_clients_service(self, client_id, client_name):
        result = []
        for client in self.__client_repo.clients_list:
            if client_id != None and client_id != client.client_id:
                continue
            if client_name != None and client_name not in client.client_name:
                continue
            result.append(client)
        return result


    def list_clients_service(self):
        return self.__client_repo.clients_list



