"""
  User interface module
"""
from datetime import date

from functions import create_transaction, add_transaction, remove_transactions_from_a_day, remove_transactions_type
from functions import remove_transactions_from_day1_to_day2, replace_value_of_transaction, transaction_having_type
from functions import transactions_having_property_than_value, account_balance_before_day, sum_having_type
from functions import max_transanction_having_type_from_day, filter_type, filter_type_smaller_than_value
from functions import copy_transactions_list


def command_input():
    """
    :return: the command introduced by the user
    """
    command = input("prompt>")
    return command


def split_command(command):
    """
    :param command: the command introduced by the user
    :return: the command word and command parameters
    """
    tokens = command.split(maxsplit=1)   # splits the input in the command word and command parameters
    command_word, command_params = None, None
    command_word = tokens[0]
    if len(tokens) == 2:     # the parameters might not exist
        command_params = tokens[1]

    command_word = command_word.strip().casefold()      # trying to convert the command_word to small cases and to remove any additional spaces
    return command_word, command_params


"""
A) Adding commands 
"""


def add_transaction_command(transactions_list, command_params):
    """
    adding to the transactions_list a transaction in the current day
    """
    today = date.today()  # retaining today date
    try:
        if command_params == None:
            raise ValueError("The parameters are missing!")

        tokens = command_params.split()
        if len(tokens) > 3:
            raise ValueError("Too many parameters!")
        """
         transaction_value = tokens[0]
         transaction_type = tokens[1]
         transaction_description = tokens[2]
        """

        if not(tokens[1].strip().casefold() == "in" or tokens[1].strip().casefold() == "out"):
            raise ValueError("Invalid type value!")
        transaction = create_transaction(int(today.day), int(tokens[0].strip()), tokens[1].strip().casefold(), tokens[2].strip().casefold())
        add_transaction(transactions_list, transaction)
        print("Transaction has been added succesfully!")
    except ValueError as ve:
        print(str(ve))
    except IndexError as ie:
        print(str(ie))


def insert_transaction_command(transactions_list, command_params):
    """
    inserting in the transactions_list a transaction in the speciefed day
    """
    try:
        if command_params == None:
            raise ValueError("The parameters are missing!")
        tokens = command_params.split()

        if len(tokens) > 4:
            raise ValueError("Too many parameters!")
        """
         transaction_day = tokens[0]
         transaction_value = tokens[1]
         transaction_type = tokens[2]
         transaction_description = tokens[3]
        """
        if not(1 <= int(tokens[0].strip()) <= 31):
            raise ValueError("The day is not in the range [0, 31]!")

        if tokens[2].casefold() != "in" and tokens[2].casefold() != "out":
            raise ValueError("Invalid type, only 'in' or 'out' allowed!")

        transaction = create_transaction(int(tokens[0].strip()), int(tokens[1].strip()), tokens[2].strip().casefold(), tokens[3].strip().casefold())
        add_transaction(transactions_list, transaction)
        print("Transaction has been added succesfully!")
    except ValueError as ve:
        print(str(ve))
    except IndexError as ie:
        print(str(ie))


"""
    B) Removing/ Replacing commands
"""


def remove_transactions_from_a_day_command(transactions_list, tokens):
    """
    :param transactions_list: a list of transactions
    :param tokens: a list of all parameters introduced by the user
    removes all the transactions from a day
    """
    try:
        day = int(tokens[0].strip())
        remove_transactions_from_a_day(transactions_list, day)
        print("Transactions from day", day, "have been deleted!")
    except ValueError as ve:
        print(str(ve))
    except IndexError as ie:
        print(str(ie))


def remove_transactions_type_command(transactions_list, tokens):
    """
    :param transactions_list: a list of transactions
    :param tokens: a list of all parameters introduced by the user
    removes all the transactions of a certain type
    """
    try:
        type = tokens[0].strip().casefold()
        remove_transactions_type(transactions_list, type)
        print("Transactions with type", type, "have been deleted!")
    except ValueError as ve:
        print(str(ve))
    except IndexError as ie:
        print(str(ie))


def remove_transactions_from_day1_to_day2_command(transactions_list, tokens):
    """
    :param transactions_list: a list of transactions
    :param tokens: a list of all parameters introduced by the user
    removes all the transactions starting from day1 to day2
    """
    try:
        day1 = int(tokens[0].strip())
        key_word = tokens[1].strip().casefold()
        day2 = int(tokens[2].strip())
        if key_word != "to":
            raise ValueError("Invalid keyword between the days, it should be 'to'!")

        remove_transactions_from_day1_to_day2(transactions_list, day1, day2)
        print("Transactions from day", day1, "to", day2 , "have been deleted!")
    except ValueError as ve:
        print(str(ve))
    except IndexError as ie:
        print(str(ie))


def remove_transactions_command(transactions_list, command_params):
    """
    :param transactions_list: a list of transactions
    :param command_params: command parameters introduced by the user
    removes from a transactions_list a transaction(s) of a certain type, from a certain day or from a interval of days
    """
    try:
        if command_params == None:
            raise ValueError("The parameters are missing!")
        tokens = command_params.split()
        if len(tokens) == 1:    # if command_params has only a param, it means that we have to remove a transactions by day or type
            if tokens[0].strip().casefold() == "in" or tokens[0].strip().casefold() == "out":
                remove_transactions_type_command(transactions_list, tokens)
            else:
                if 0 <= int(tokens[0].strip().casefold()) <= 31:
                    remove_transactions_from_a_day_command(transactions_list, tokens)
                else:
                    raise ValueError("Error, day should be between [0,31]!")
        elif len(tokens) == 3:   # it means we need to remove all the transcations from an interval of days
            remove_transactions_from_day1_to_day2_command(transactions_list, tokens)
        else:
            raise ValueError("Not valid number of parameters!")
    except ValueError as ve:
        print(str(ve))
    except IndexError as ie:
        print(str(ie))


def replace_value_of_transaction_command(transactions_list, command_params):
    """
    :param transactions_list: a list of transactions
    :param command_params: the parameters introduced by the user
    replaces a value of a transaction with a specified day, type and description
    """
    try:
        if command_params == None:
            raise ValueError("The parameters are missing!")

        tokens = command_params.split()
        if len(tokens) > 5:
            raise ValueError("Too many parameters!")

        day = int(tokens[0].strip())
        type = tokens[1].strip().casefold()
        description = tokens[2].strip().casefold()
        key_word = tokens[3].strip().casefold()
        new_value = int(tokens[4].strip())
        if key_word != "with":
            raise ValueError("Invalid keyword, it should be 'with'!")

        replace_value_of_transaction(transactions_list, day, type, description, new_value)
        print("The Value of transaction from day", day, "with type", type, "and description", description, "has been changed!")
    except ValueError as ve:
        print(str(ve))
    except IndexError as ie:
        print(str(ie))


"""
    C) Display commands
"""
def list(transactions_list):
    """
    :param transactions_list: list of transactions
    :print: a list of transactions
    """
    for i in range(0, len(transactions_list)):
        print(transactions_list[i], end="\n")


def display_command(transactions_list, command_params):
    """
    :param transactions_list: a list of transactions
    :param command_params: parameters introduced by the user
    :print: displays a list
    """
    try:
        if command_params == None:
            list(transactions_list)
        else:
            tokens = command_params.split()
            if len(tokens) == 1:
                param1 = tokens[0].strip().casefold()
                if param1 in ("in", "out"):
                    list(transaction_having_type(transactions_list, param1))  # displaying the list of transactions having a certain type
            elif len(tokens) == 2:
                param1 = tokens[0].strip().casefold()
                param2 = tokens[1].strip().casefold()
                param2 = int(param2)
                if param1 == "balance":
                    if 0 <= param2 <= 31:
                        print("The account balance before day", param2, "(including it):", account_balance_before_day(transactions_list, param2)) # displaying the balance of the account before a day(including it)
                    else:
                        raise ValueError("Error, the day should be between 0 and 31!")
                else:
                    if param1 in ('>', '<', '='):
                        print("The list containing all the values", param1, "than/with", param2, "\n")
                        list(transactions_having_property_than_value(transactions_list, param1, param2))    # displaying all the transactions '>'/'<'/'=' than/with a value
                    else:
                        raise ValueError("Error, the property should be", "/".join(("<", ">", "=")))
            else:
                raise ValueError("Too many parameters!")
    except ValueError as ve:
        print(str(ve))
    except IndexError as ie:
        print(str(ie))


"""
    D) Obtain different characteristics of the transactions
"""
def sum_having_type_command(transactions_list, command_params):
    """
    :param transactions_list: a list of transactions
    :param command_params: command paramaters introduced by the user
    :print: sum of all 'type' transactions from a list
    """
    try:
        if command_params == None:
            raise ValueError("The parameters are missing!")

        tokens = command_params.split()
        if len(tokens) > 1:
            raise ValueError("Too many parameters!")

        type = tokens[0].strip().casefold()
        if not(type in ("in", "out")):
            raise ValueError("Error, not valid type, it should be 'in'/'out'!")
        print("The sum of all", type, "type", "is", sum_having_type(transactions_list, type))
    except ValueError as ve:
        print(str(ve))
    except IndexError as ie:
        print(str(ie))


def max_transanction_having_type_from_day_command(transactions_list, command_params):
    try:
        if command_params == None:
            raise ValueError("The parameters are missing!")

        tokens = command_params.split()
        if len(tokens) > 2:
            raise ValueError("Too many parameters!")

        type = tokens[0].strip().casefold()
        day = int(tokens[1].strip().casefold())

        if not(type in ("in", "out")):
            raise ValueError("Error, not valid type, it should be 'in'/'out'!")

        if not(0 <= day <= 31):
            raise ValueError("Error, the day should be between [0,31]!")

        l = max_transanction_having_type_from_day(transactions_list, type, day)
        print("The maximum(s) transaction(s) having type", type, "from day", day, "is/are:", end=":\n")
        if len(l) == 0:
            print("None!")
        else:
            list(l)
    except ValueError as ve:
        print(str(ve))
    except IndexError as ie:
        print(str(ie))


def filter_command(transactions_list, command_params):
    try:
        if command_params == None:
            raise ValueError("The parameters are missing!")

        tokens = command_params.split()
        type = tokens[0].strip().casefold()
        if not (type in ("in", "out")):
            raise ValueError("Error, the type should be 'in'/'out'!")

        if len(tokens) == 1:
                filter_type(transactions_list, type)
        elif len(tokens) == 2:
            value = int(tokens[1].strip())
            filter_type_smaller_than_value(transactions_list, type, value)
        else:
            raise ValueError("Too many parameters!")
        print("The filter has been applied succesfully!")
    except ValueError as ve:
        print(str(ve))
    except IndexError as ie:
        print(str(ie))


def undo_command(transactions_list, undo_list, command_params):
    try:
        if command_params != None:
            raise ValueError("Command doesn't allow parameters!")
        if len(undo_list) == 0:
            raise ValueError("Doesn't exist any earlier version!")
        transactions_list[:] = copy_transactions_list(undo_list[len(undo_list) - 1])
        undo_list.pop(len(undo_list) - 1)
        print("The transactions list has been succesfully restored to the previous version!")
    except ValueError as ve:
        print(str(ve))
    except IndexError as ie:
        print(str(ie))


def commands_list(transactions_list, undo_list):
    while True:
        command = command_input()
        command_word, command_params = split_command(command)
        if command_word == "add":
            undo_list.append(copy_transactions_list(transactions_list))
            add_transaction_command(transactions_list, command_params)
        elif command_word == "insert":
            undo_list.append(copy_transactions_list(transactions_list))
            insert_transaction_command(transactions_list, command_params)
        elif command_word == "remove":
            undo_list.append(copy_transactions_list(transactions_list))
            remove_transactions_command(transactions_list, command_params)
        elif command_word == "replace":
            undo_list.append(copy_transactions_list(transactions_list))
            replace_value_of_transaction_command(transactions_list, command_params)
        elif command_word == "list":
            display_command(transactions_list, command_params)
        elif command_word == "sum":
            sum_having_type_command(transactions_list, command_params)
        elif command_word == "max":
            max_transanction_having_type_from_day_command(transactions_list, command_params)
        elif command_word == "filter":
            undo_list.append(copy_transactions_list(transactions_list))
            filter_command(transactions_list, command_params)
        elif command_word ==  "undo":
            undo_command(transactions_list, undo_list, command_params)
        elif command_word == "exit":
            return
        else:
            print("Bad command!")

