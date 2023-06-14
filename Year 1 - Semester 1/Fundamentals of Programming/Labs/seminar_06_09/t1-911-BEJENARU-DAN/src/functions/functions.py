"""
Implement the solution here.
You may add other source files.
Make sure you commit & push the source code before the end of the test.

Solutions using user-defined classes will not be graded.
"""
from random import randint

def all_digits_distinct(value):
    """
    checks if a number has all digits distinct
    :param value: a given number
    :return: True if it's distinct, False otherwise
    """
    f = [0] * 10 # generate a frequency list
    value_copy = value
    while value_copy > 0:
        f[value_copy % 10] += 1
        value_copy = value_copy // 10 # substracting the last digit

    for i in range(0, 10):
        if f[i] > 1:
            return False
    return True


def check_four_digits_value(value):
    """
    Check if a number has 4 digits
    :param value:
    :return:
    """
    digits = 0
    if value == 0:
        digits = 1

    while value > 0:
        digits = digits + 1
        value = value // 10

    if digits == 4:
        return True

    return False


def generate_fourdigits_distinct_number():
    """
    Generate a four digits number with all the digits distinct
    :return:
    """
    while True:
        value = randint(1000, 9999) # generate a number with 4 digits
        if all_digits_distinct(value) == True:
            return value


def cheat_code(value):
    """
    Checks if the user number is a cheat code
    :param value: a given value
    :return: True if is a cheat code, False otherwise
    """
    if value == 8086:
        return True
    return False


def codes(computer_value, user_value):
    """
    Determines how many codes are
    :param computer_value: the computer value
    :param user_value: the user value
    :return: how many codes exist
    """

    list1 = [] # list of the digits of the computer value
    a = computer_value # saving the computer value in a
    while a > 0:
        digit = a % 10
        list1.append(digit)
        a = a // 10

    list1.reverse() # reverse the order of the list

    list2 = []  # list of all digits of the user
    b = user_value # save the value of the user
    while b > 0:
        digit = b % 10
        list2.append(digit)
        b = b // 10

    list2.reverse()

    codes_nr = 0 # the number of codes
    for i in range(0, 4):
        if list1[i] == list2[i]:
            codes_nr += 1

    return codes_nr


def runners(computer_value, user_value):
    """
    Determines how many runners are
    :param computer_value: the computer value
    :param user_value: the user value
    :return: how many runners exist
    """

    list1 = []  # list of the digits of the computer value
    a = computer_value  # saving the computer value in a
    while a > 0:
        digit = a % 10
        list1.append(digit)
        a = a // 10

    list1.reverse()  # reverse the order of the list

    list2 = []  # list of all digits of the user
    b = user_value  # save the value of the user
    while b > 0:
        digit = b % 10
        list2.append(digit)
        b = b // 10

    list2.reverse()

    runners_nr = 0
    for i in range(0, 4):
        if list1[i] != list2[i] and list2[i] in list1:
            runners_nr = runners_nr + 1

    return runners_nr
