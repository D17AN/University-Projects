
from datetime import date
"""
    Write non-UI functions below
"""


def create_transaction(day, value, type, description):
    """
    :return: a dictionary that contains the data of a transaction
    """
    return {'day': day, 'value': value, 'type': type, 'description': description}


def get_day(transaction):
    """
    :return: the day of the transaction
    """
    return transaction['day']


def get_value(transaction):
    """
    :return: the amount of money of the transaction
    """
    return transaction['value']


def get_type(transaction):
    """
    :return: the type of the transaction
    """
    return transaction['type']


def get_description(transaction):
    """
    :return: the description of the transaction
    """
    return transaction['description']


def set_value(transaction, value):
    """
    modify the amount of money of a existing transaction
    """
    transaction['value'] = value


def generate_transactions():
    return [create_transaction(1, 1000, "in", "bonus"), create_transaction(15, 300, "out", "abonament"),
            create_transaction(3, 7000, "out", "skinuri"), create_transaction(17, 235000, "in", "salariu"),
            create_transaction(15, 500, "out", "cumparaturi"), create_transaction(30, 43, "out", " cumparaturi"),
            create_transaction(4, 150, "out", "gaz"), create_transaction(15, 40, "out", "internet"),
            create_transaction(3, 50, "out", "pizza"), create_transaction(25, 1700, "out", "chirie")]


def add_transaction(transactions_list, transaction):
    transactions_list.append(transaction)


def remove_transaction(transactions_list, index):
    transactions_list.pop(index)


def remove_transactions_from_a_day(transactions_list, day):
    """
    removes all the transactions from a speciefied day
    """
    lenght = len(transactions_list)
    i = 0
    while i < lenght:
        if get_day(transactions_list[i]) == day:
            remove_transaction(transactions_list, i)
            lenght = lenght - 1
        else:
            i = i + 1


def remove_transactions_from_day1_to_day2(transactions_list, day1, day2):
    """
       removes all the transactions from day1 to day2
    """
    lenght = len(transactions_list)
    i = 0
    while i < lenght:
        if day1 <= get_day(transactions_list[i]) <= day2:
            remove_transaction(transactions_list, i)
            lenght = lenght - 1
        else:
            i = i + 1


def remove_transactions_type(transactions_list, type):
    """
        removes all the transactions of a certain type
    """
    lenght = len(transactions_list)
    i = 0
    while i < lenght:
        if get_type(transactions_list[i]) == type:
            remove_transaction(transactions_list, i)
            lenght = lenght - 1
        else:
            i = i + 1


def replace_value_of_transaction(transactions_list, day, type, description, new_value):
    """
        replace the value of a transaction with a new one
    """
    for i in range(0, len(transactions_list)):
        transaction = transactions_list[i]
        if get_day(transaction) == day and get_type(transaction) == type and get_description(transaction) == description:
            set_value(transactions_list[i], new_value)
            break


def display_list(transactions_list):
    for i in range(0, len(transactions_list)):
        print(transactions_list[i], end="\n")


def display_transaction_type(transactions_list, type):
    """
    print all the transcations of a certain type
    """
    for i in range(0, len(transactions_list)):
        if get_type(transactions_list[i]) == type:
            print(transactions_list[i], end="\n")


def display_all_transactions_having_property_than_value(transactions_list, property, value):
    """
    :param property: = / > / <
    :prints: all the transactions which respect the property
    """
    for i in range(0, len(transactions_list)):
        if property == '=':
            if get_value(transactions_list[i]) == value:
                print(transactions_list[i], end="\n")
        elif property == '>':
            if get_value(transactions_list[i]) > value:
                print(transactions_list[i], end="\n")
        elif property == '<':
            if get_value(transactions_list[i]) < value:
                print(transactions_list[i], end="\n")


def in_transactions_sum_before_day(transactions_list, day):
    """
    :return: sum of all 'in' transactions
    """
    s = 0
    for i in range(0, len(transactions_list)):
        if get_day(transactions_list[i]) <= day and get_type(transactions_list[i]) == "in":
            s = s + get_value(transactions_list[i])

    return s


def out_transactions_sum_before_day(transactions_list, day):
    """
    :return: sum of all 'out' transactions
    """
    s = 0
    for i in range(0, len(transactions_list)):
        if get_day(transactions_list[i]) <= day and get_type(transactions_list[i]) == "out":
            s = s + get_value(transactions_list[i])

    return s


def account_balance_before_day(transactions_list, day):
    sum1 = in_transactions_sum_before_day(transactions_list, day)
    sum2 = out_transactions_sum_before_day(transactions_list, day)
    account_balance = sum1 - sum2
    return account_balance


"""
    Write the command-driven UI below
"""


def add_transaction_command(transactions_list, command_params):
    """
    adding to the transactions_list a transaction in the current day
    """
    today = date.today()  # retaining today date
    try:
        tokens = command_params.split(" ")
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
    except:
        print("Invalid command, try again!")


def insert_transaction_command(transactions_list, command_params):
    """
    inserting in the transactions_list a transaction in the speciefed day
    """
    try:
        tokens = command_params.split(" ")
        """
         transaction_day = tokens[0]
         transaction_value = tokens[1]
         transaction_type = tokens[2]
         transaction_description = tokens[3]
        """
        if not(1 <= int(tokens[0].strip()) <= 31):
            raise ValueError("Not valid day!")

        if not(tokens[2].strip().casefold() == "in" or tokens[2].strip().casefold() == "out"):
            raise ValueError("Invalid type, only 'in' or 'out' allowed!")

        transaction = create_transaction(int(tokens[0].strip()), int(tokens[1].strip()), tokens[2].strip().casefold(), tokens[3].strip().casefold())
        add_transaction(transactions_list, transaction)
        print("Transaction has been added succesfully!")
    except:
        print("Invalid command, try again!")


def remove_transactions_from_a_day_command(transactions_list, tokens):
    try:
        day = int(tokens[0].strip())
        remove_transactions_from_a_day(transactions_list, day)
        print("Transaction has been deleted!")
    except:
        print("Invalid command, try again!")


def remove_transactions_type_command(transactions_list, tokens):
    try:
        type = tokens[0].strip().casefold()
        remove_transactions_type(transactions_list, type)
        print("Transaction has been deleted!")
    except:
        print("Invalid command, try again!")


def remove_transactions_from_day1_to_day2_command(transactions_list, tokens):
    try:
        day1 = int(tokens[0].strip())
        key_word = tokens[1].strip().casefold()
        day2 = int(tokens[2].strip())
        if key_word != "to":
            raise ValueError("Invalid keyword between the days, it should be 'to'!")

        remove_transactions_from_day1_to_day2(transactions_list, day1, day2)
        print("Transaction has been deleted!")
    except:
        print("Invalid command, try again!")


def remove_transaction_command(transactions_list, command_params):
    try:
        tokens = command_params.split(" ")
        if len(tokens) == 1:    # if command_params has only a param, it means that we have to remove a transactions by day or type
            if tokens[0].strip().casefold() != "in" and tokens[0].strip().casefold() != "out":
                remove_transactions_from_a_day_command(transactions_list, tokens)
            else:
                remove_transactions_type_command(transactions_list, tokens)
        elif len(tokens) == 3:   # it means we need to remove all the transcations from an interval of days
            remove_transactions_from_day1_to_day2_command(transactions_list, tokens)
    except:
        print("Invalid command, try again!")


def replace_value_of_transaction_command(transactions_list, command_params):
     try:
        tokens = command_params.split(" ")
        day = int(tokens[0].strip())
        type = tokens[1].strip().casefold()
        description = tokens[2].strip().casefold()
        key_word = tokens[3].strip().casefold()
        new_value = int(tokens[4].strip())
        if key_word != "with":
            raise ValueError("Invalid keyword, it should be 'with'!")

        replace_value_of_transaction(transactions_list, day, type, description, new_value)
     except:
        print("Invalid command, try again!")


def display_by_type(transactions_list, tokens):
    try:
        type = tokens[0].strip().casefold()
        if not(type == "in" or type == "out"):
            raise ValueError("Invalid type!")

        display_transaction_type(transactions_list, type)
    except:
        print("Invalid command, try again!")


def display_all_transactions_having_property_than_value_command(transactions_list, tokens):
    try:
        property = tokens[0].strip().casefold()
        value = int(tokens[1].strip())
        display_all_transactions_having_property_than_value(transactions_list, property, value)
    except:
        print("Invalid command, try again!")


def display_balance_command(transactions_list, tokens):
    try:
        day = int(tokens[1].strip())
        print(account_balance_before_day(transactions_list, day))
    except:
        print("Invalid command, try again!")


def display_command(transactions_list, command_params):
      try:
            tokens = command_params.split(" ")
            if len(tokens) == 1:
                display_by_type(transactions_list, tokens)
            elif len(tokens) == 2:
                operation = tokens[0].strip().casefold()
                if operation == "balance":
                    display_balance_command(transactions_list, tokens)
                elif operation == ">" or operation == "<" or operation == "=":
                    display_all_transactions_having_property_than_value_command(transactions_list, tokens)
      except:
            print("Invalid command, try again!")


def test_add_trasaction():
    list = []
    add_transaction(list, create_transaction(2, 1, "in", "restaurant"))
    assert list[0] == create_transaction(2, 1, "in", "restaurant"), "Error adding transaction"


def test_remove_transaction_from_a_day():
    list = [create_transaction(1, 2, "in", "z"), create_transaction(3, 100, "out", "fg")]
    remove_transactions_from_a_day(list, 3)
    for el in list:
        assert get_day(el) != 3, "the removal failed!"


def test_remove_transactions_from_day1_to_day2():
    list = [create_transaction(1, 2, "in", "z"), create_transaction(3, 100, "out", "fg")]
    remove_transactions_from_day1_to_day2(list, 1, 3)
    assert len(list) == 0, "the removal failed!"


def test_transactions_type():
    list = [create_transaction(1, 2, "in", "z"), create_transaction(3, 100, "out", "fg")]
    remove_transactions_type(list, "in")
    for el in list:
        assert get_type(el) != "in", "the removal failed!"


def test_replace_value_of_transaction():
    list = []
    add_transaction(list, create_transaction(1, 2, "in", "z"))
    add_transaction(list,  create_transaction(3, 100, "out", "fg"))
    replace_value_of_transaction(list, 3, "out", "fg", 99)
    assert get_value(list[1]) == 99, "the replacing failed!"


def test_sum_before_day():
    list = []
    add_transaction(list, create_transaction(15, 2, "in", "z"))
    add_transaction(list, create_transaction(3, 100, "out", "fg"))
    add_transaction(list, create_transaction(15, 190, "in", "asd"))
    assert in_transactions_sum_before_day(list, 15) == 192, "Error"
    assert out_transactions_sum_before_day(list, 3) == 100, "Error"


def tests():
    test_transactions_type()
    test_add_trasaction()
    test_sum_before_day()
    test_replace_value_of_transaction()
    test_remove_transaction_from_a_day()
    test_remove_transactions_from_day1_to_day2()


def command_menu():
    tests()
    transactions_list = generate_transactions()
    while True:
        command = input("prompt> ")
        tokens = command.split(" ", maxsplit=1)
        if len(tokens) == 2:
            command_params = tokens[1]
        command_word = tokens[0]

        try:
            command_word = command_word.strip().casefold()
        except ValueError as ve:
            print(ve)

        if command_word == "add":
            add_transaction_command(transactions_list, command_params)
        elif command_word == "insert":
            insert_transaction_command(transactions_list, command_params)
        elif command_word == "remove":
            remove_transaction_command(transactions_list, command_params)
        elif command_word == "replace":
            replace_value_of_transaction_command(transactions_list, command_params)
        elif command_word == "display":
            display_list(transactions_list)
        elif command_word == "list":
            display_command(transactions_list, command_params)
        elif command_word == "exit":
            return
        else:
            print("Bad command!")


command_menu()



