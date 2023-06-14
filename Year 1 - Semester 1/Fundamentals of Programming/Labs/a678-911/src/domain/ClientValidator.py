from src.domain.Client import Client
from src.domain.Exceptions import ValidatorException

class ClientValidator:
    @staticmethod
    def validate(client):
        errors = []
        if not isinstance(client, Client):
            errors.append("Not a client!")
        if not client.client_id.isnumeric():
            errors.append("The id is not numerical!")
        elif int(client.client_id) < 1:
            errors.append("The id is not a positive integer!")

        if len(errors) > 0:
            raise ValidatorException(errors)


