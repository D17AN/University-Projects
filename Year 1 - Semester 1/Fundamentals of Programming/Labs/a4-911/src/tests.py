"""
    Testing module
"""
from functions import add_transaction, create_transaction, get_day, get_type, get_value, get_description, set_value, remove_transactions_from_a_day
from functions import remove_transactions_from_day1_to_day2, remove_transactions_type, replace_value_of_transaction, account_balance_before_day
from functions import transactions_sum_having_type_before_day, account_balance_before_day, transaction_having_type, transactions_having_property_than_value
from functions import sum_having_type, max_transanction_having_type_from_day, filter_type, filter_type_smaller_than_value


def test_getters():
    list = [{'day': 1, 'value': 10, 'type': "in", 'description': "pizza"}]
    assert get_day(list[0]) == 1, "Error getting the day of the transaction!"
    assert get_value(list[0]) == 10, "Error getting the value of the transaction!"
    assert get_type(list[0]) == "in", "Error getting the type of the transaction"
    assert get_description(list[0]) == "pizza", "Error getting the description of the transaction"


def test_setters():
    list = [{'day': 1, 'value': 10, 'type': "in", 'description': "pizza"}]
    set_value(list[0], 100)
    assert get_value(list[0]) == 100, "Error setting the the value of the transaction!"


def test_create_transaction():
    assert {'day': 1, 'value': 10, 'type': "in", 'description': "pizza"} == create_transaction(1, 10, "in", "pizza"), "Error creating transaction!"


def test_add_trasaction():
    list = []
    add_transaction(list, create_transaction(2, 1, "in", "restaurant"))
    assert list[0] == create_transaction(2, 1, "in", "restaurant"), "Error adding transaction!"


def test_remove_transaction_from_a_day():
    list = [create_transaction(1, 2, "in", "z"), create_transaction(3, 100, "out", "fg")]
    remove_transactions_from_a_day(list, 3)
    for el in list:
        assert get_day(el) != 3, "Error removing the transactions from day!"


def test_remove_transactions_from_day1_to_day2():
    list = [create_transaction(1, 2, "in", "z"), create_transaction(3, 100, "out", "fg")]
    remove_transactions_from_day1_to_day2(list, 1, 3)
    assert len(list) == 0, "Error removing the transactions from day1 to day2!"


def test_remove_transactions_type():
    list = [create_transaction(1, 2, "in", "z"), create_transaction(3, 100, "out", "fg")]
    remove_transactions_type(list, "in")
    for el in list:
        assert get_type(el) != "in", "Error removing the transactions with a certain type!"


def test_replace_value_of_transaction():
    list = []
    add_transaction(list, create_transaction(1, 2, "in", "z"))
    add_transaction(list,  create_transaction(3, 100, "out", "fg"))
    replace_value_of_transaction(list, 3, "out", "fg", 99)
    assert get_value(list[1]) == 99, "Error replacing the value of the transaction!"


def test_transactions_sum_having_type_before_day():
    list = []
    add_transaction(list, create_transaction(15, 2, "in", "z"))
    add_transaction(list, create_transaction(3, 100, "out", "fg"))
    add_transaction(list, create_transaction(15, 190, "in", "asd"))
    assert transactions_sum_having_type_before_day(list, "in", 15) == 192, "Error calculating the sum of all transactions before a day(including it)!"


def test_account_balance_before_day():
    list = []
    add_transaction(list, create_transaction(15, 2, "in", "z"))
    add_transaction(list, create_transaction(3, 100, "out", "fg"))
    add_transaction(list, create_transaction(15, 190, "in", "asd"))
    assert account_balance_before_day(list, 15) == 92, "Error calculating the balance before a day(including it)!"


def test_transaction_having_type():
    list = []
    add_transaction(list, create_transaction(15, 2, "in", "z"))
    add_transaction(list, create_transaction(3, 100, "out", "fg"))
    add_transaction(list, create_transaction(15, 190, "in", "asd"))
    assert transaction_having_type(list, "in".casefold()) == [create_transaction(15, 2, "in", "z"), create_transaction(15, 190, "in", "asd")], "Error creating list of same type of transactions!"


def test_transactions_having_property_than_value():
    list = []
    add_transaction(list, create_transaction(15, 2, "in", "z"))
    add_transaction(list, create_transaction(3, 100, "out", "fg"))
    add_transaction(list, create_transaction(15, 190, "in", "asd"))
    assert transactions_having_property_than_value(list, ">", 99) == [create_transaction(3, 100, "out", "fg"), create_transaction(15, 190, "in", "asd")], "Error creating the list having 'property' than value!"


def test_sum_having_type():
    list = []
    add_transaction(list, create_transaction(15, 2, "in", "z"))
    add_transaction(list, create_transaction(3, 100, "out", "fg"))
    add_transaction(list, create_transaction(15, 190, "in", "asd"))
    assert sum_having_type(list, "in") == 192, "Error returning the correct answer of function 'sum_having_type'"


def test_max_transanction_having_type_from_day():
    list = []
    add_transaction(list, create_transaction(15, 2, "in", "z"))
    add_transaction(list, create_transaction(3, 100, "out", "fg"))
    add_transaction(list, create_transaction(15, 190, "in", "asd"))
    assert max_transanction_having_type_from_day(list, "in", 15) == [create_transaction(15, 190, "in", "asd")], "Error returning the maximum(s) transaction(s), function max_transanction_having_type_from_day"


def test_filter_type():
    list = []
    add_transaction(list, create_transaction(15, 2, "in", "z"))
    add_transaction(list, create_transaction(3, 100, "out", "fg"))
    add_transaction(list, create_transaction(15, 190, "in", "asd"))
    filter_type(list, "in")
    assert list == [create_transaction(15, 2, "in", "z"), create_transaction(15, 190, "in", "asd")], "Error filtering the type!"


def test_filter_type_smaller_than_value():
    list = []
    add_transaction(list, create_transaction(15, 2, "in", "z"))
    add_transaction(list, create_transaction(3, 100, "out", "fg"))
    add_transaction(list, create_transaction(15, 190, "in", "asd"))
    filter_type_smaller_than_value(list, "in", 190)
    assert list == [create_transaction(15, 2, "in", "z")], "Error filtering the type smaller than value!"


def tests():
    test_getters()
    test_setters()
    test_create_transaction()
    test_add_trasaction()
    test_remove_transaction_from_a_day()
    test_remove_transactions_from_day1_to_day2()
    test_remove_transactions_type()
    test_replace_value_of_transaction()
    test_transactions_sum_having_type_before_day()
    test_account_balance_before_day()
    test_transaction_having_type()
    test_transactions_having_property_than_value()
    test_sum_having_type()
    test_max_transanction_having_type_from_day()
    test_filter_type()
    test_filter_type_smaller_than_value()