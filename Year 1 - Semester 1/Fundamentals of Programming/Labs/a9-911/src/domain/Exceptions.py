class RepoException(Exception):
    def __init__(self, errors = ["Repository error!"]):
        self.__errors = errors


    def __str__(self):
        result = "\n"

        for er in self.__errors:
            result += er
            result += '\n'
        return result


class ValidatorException(Exception):
    def __init__(self, errors = ["Repository error!"]):
        self.__errors = errors


    def __str__(self):
        result = "\n"

        for er in self.__errors:
            result = result + "- " + er
            result += '\n'
        return result


