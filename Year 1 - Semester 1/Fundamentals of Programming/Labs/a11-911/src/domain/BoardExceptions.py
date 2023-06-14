class BoardException(Exception):
    def __init__(self, errors = ["Board error!"]):
        self.__errors = errors


    def __str__(self):
        result = "\n"

        for er in self.__errors:
            result += er
            result += '\n'
        return result
