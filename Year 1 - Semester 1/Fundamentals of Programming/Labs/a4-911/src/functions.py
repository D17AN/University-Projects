"""
  Program functionalities module
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


def transaction_having_type(transactions_list, type):
    """
    returns the list of all the transcations of a certain type
    """
    print_list = []
    for i in range(0, len(transactions_list)):
        if get_type(transactions_list[i]) == type:
            add_transaction(print_list, transactions_list[i])

    return print_list


def transactions_having_property_than_value(transactions_list, property, value):
    """
    :param property: = / > / <
    :returns: all the transactions which respect the property with the respect of the value
    """
    print_list = []
    for i in range(0, len(transactions_list)):
        if property == '=':
            if get_value(transactions_list[i]) == value:
                add_transaction(print_list, transactions_list[i])
        elif property == '>':
            if get_value(transactions_list[i]) > value:
                add_transaction(print_list, transactions_list[i])
        elif property == '<':
            if get_value(transactions_list[i]) < value:
                add_transaction(print_list, transactions_list[i])

    return print_list


def transactions_sum_having_type_before_day(transactions_list, type, day):
    """
    transactions_list = the list of transactions
    type = the type of the transactions 'in'/'out'
    :return: sum of all type transactions
    """
    s = 0
    for i in range(0, len(transactions_list)):
        if get_day(transactions_list[i]) <= day and get_type(transactions_list[i]) == type:
            s = s + get_value(transactions_list[i])

    return s


def account_balance_before_day(transactions_list, day):
    """
    :param transactions_list: the list of transactions
    :param day: the last day before the balance check
    :return: account balance before a certain day(including that day)
    """
    sum1 = transactions_sum_having_type_before_day(transactions_list, "in".casefold(), day)
    sum2 = transactions_sum_having_type_before_day(transactions_list, "out".casefold(), day)
    account_balance = sum1 - sum2
    return account_balance


def sum_having_type(transactions_list, type):
    """
    :param transactions_list: a list of transactions
    :param type: "in"/"out"
    :return: the sum of all transactions which have type 'type'
    """
    s = 0
    for transaction in transactions_list:
        if get_type(transaction) == type:
            s = s + get_value(transaction)

    return s


def max_transanction_having_type_from_day(transactions_list, type, day):
    """
    :param transactions_list: a list of transactions
    :param type: "in"/"out"
    :param value: the day of the transactions
    :return: a list of maximum transactions of type 'type' and day 'day'
    """
    maximum = -1
    max_list = []
    for transaction in transactions_list:
        if get_type(transaction) == type and get_day(transaction) == day:
            if get_value(transaction) > maximum:
                maximum = get_value(transaction)

    for transaction in transactions_list:
        if get_type(transaction) == type and get_day(transaction) == day:
            if get_value(transaction) == maximum:
                add_transaction(max_list, transaction)

    return max_list


def filter_type(transactions_list, type):
    """
    :param transactions_list: a list of transactions
    :param type: the type of transactions we want to filter
    keeps only type trasactions
    """
    if type == "in":
        remove_transactions_type(transactions_list, "out")
    else:
        remove_transactions_type(transactions_list, "in")


def filter_type_smaller_than_value(transactions_list, type, value):
    """
    :param transactions_list: a list of transactions
    :param type: the type of transactions we want to filter
    :param value: the upper bound of the value of a transaction of type 'type'
    keeps all 'type' transactions smaller than value(not inclunding it)
    """
    lenght = len(transactions_list)
    i = 0
    while i < lenght:
        if get_type(transactions_list[i]) != type or get_value(transactions_list[i]) >= value:
            remove_transaction(transactions_list, i)
            lenght = lenght - 1
        else:
            i = i + 1


def copy_transactions_list(transactions_list):
    """
    :param transactions_list: a list
    :return: a copy of that list
    """
    new_list = []
    for transaction in transactions_list:
        day = get_day(transaction)
        type = get_type(transaction)
        value = get_value(transaction)
        description = get_description(transaction)
        new_transaction = create_transaction(day, value, type, description)
        new_list.append(new_transaction)

    return new_list




