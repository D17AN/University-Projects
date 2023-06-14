class Call:
    def __init__(self, function_name, *function_params):
        self.__function_name = function_name
        self.__function_params = function_params


    def call(self):
        self.__function_name(*self.__function_params)



class Operations:
    def __init__(self):
        self.__operations = []


    def add_operation(self, tuple_operation):
        #index 0 of the tuple has the operation for undo, and index 1 for the redo
        self.__operations.append(tuple_operation)


    def execute_undo(self):
        for operation in self.__operations:
            operation[0].call()



    def execute_redo(self):
        for operation in self.__operations:
            if operation[1] != None: # if we have a redo operation
                operation[1].call()


class OperationsHistory:
    def __init__(self):
        self.__history = []
        self.__undo_index = -1
        self.__redo_index = 0


    def register_operation(self, operations):
        del self.__history[self.__redo_index:len(self.__history)]
        self.__history.append(operations)
        self.__undo_index = len(self.__history) - 1
        self.__redo_index = len(self.__history)


    def undo(self):
        if self.__undo_index < 0:
            raise IndexError("Undo cannot be performed!")
        self.__history[self.__undo_index].execute_undo()
        self.__undo_index -= 1
        self.__redo_index -= 1


    def redo(self):
        if self.__redo_index >= len(self.__history):
            raise IndexError("Redo cannot be performed!")
        self.__history[self.__redo_index].execute_redo()
        self.__undo_index += 1
        self.__redo_index += 1


