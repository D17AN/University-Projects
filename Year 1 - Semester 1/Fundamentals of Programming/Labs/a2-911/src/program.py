# Function section
# non-UI
import math

def create_complex_number(real_part, imaginary_part):
    return {'real': real_part, 'imaginary': imaginary_part}


def get_real_part(complex):
    return complex['real']


def get_imaginary_part(complex):
    return complex['imaginary']


def set_real_part(complex, value):
    complex['real'] = value


def set_imaginary_part(complex, value):
    complex['imaginary'] = value


def add_complex(complex_list, complex):
    complex_list.append(complex)


def remove_complex(complex_list, index):
    complex_list.pop(index)


def complex_modulo(complex):
    a = get_real_part(complex)
    b = get_imaginary_part(complex)
    return math.sqrt(pow(a, 2) + pow(b, 2))


def increasing_modulo(complex_list, list_lenght):
    """
    :return: returns the lenght of the longest sequence of complex numbers with increasing modulo
    """
    modulo1 = complex_modulo(complex_list[0])
    lenght_max = -1
    lenght = 1
    for i in range(1, list_lenght):
        modulo2 = complex_modulo(complex_list[i])
        if modulo2 > modulo1:  # comparing modulo of each consecutive pair of complex numbers to check if they're in asceding order
            lenght = lenght + 1  # incrementing the lenght of the current sub-list of complex numbers
        else:
            if lenght > lenght_max:  # when the sequence has been crossed, we check if it's bigger than the previous one
                lenght_max = lenght

            lenght = 1  # reset the lenght of the sequence
        modulo1 = modulo2

    if lenght_max < lenght:
        lenght_max = lenght

    return lenght_max


def all_increasing_modulo(complex_list, list_lenght):
    """
    :param complex_list: list that contains complex numbers
    :param list_lenght: the lenght of the complex list
    :return: A list of tuples that contains the start index and the end index of all the sequences with increasing modulo of maximum lenght
    """
    modulo_list = []
    lenght_max = increasing_modulo(complex_list, list_lenght)
    modulo1 = complex_modulo(complex_list[0])
    lenght = 1
    for i in range(1, list_lenght):
        modulo2 = complex_modulo(complex_list[i])
        if modulo2 > modulo1:
            lenght = lenght + 1
        else:
            if lenght == lenght_max:
                modulo_list.append((i - lenght_max, i - 1))
            lenght = 1
        modulo1 = modulo2

    if lenght == lenght_max:
        modulo_list.append((list_lenght - lenght_max, list_lenght - 1))

    return modulo_list


def distinct_complex(complex1, complex2):
    """
    :return: True if 2 complex numbers are distinct, False otherwise
    """
    a1 = get_real_part(complex1)
    a2 = get_real_part(complex2)
    b1 = get_imaginary_part(complex1)
    b2 = get_imaginary_part(complex2)
    if a1 == a2 and b1 == b2:
        return False
    return True


def contains_unique_elements(list, start_index, end_index):
    """
    :return: True if a list contains unique elements between start and end index, False otherwise
    """
    for i in range(start_index, end_index):
        for j in range(i + 1, end_index + 1):
            if distinct_complex(list[i], list[j]) == False:
                return False

    return True


def longest_distinct(complex_list, list_lenght):
    """
    :param complex_list: list of complex numbers
    :param list_lenght: lenght of the list
    :return: the lenght of the longest sequence of distinct complex numbers
    """
    lenght_max = 1
    for i in range(0, list_lenght):     # verify each sub-list of the list
        for j in range(list_lenght - 1, i, -1):
            if contains_unique_elements(complex_list, i, j) == True:     # if the sub-list contains distinct complex numbers
                lenght = j - i + 1      # calculates the lenght of it
                if lenght > lenght_max:     # if the lenght of the current sub-list is bigger than the previous one, a new maximum lenght was found
                    lenght_max = lenght
                break   # the maximum lenght of the list that starts with the index i was already found

    return lenght_max


def all_longest_distinct(complex_list, list_lenght):
    """
    :return: A list of tuples that contains the start index and the end index of all the sequences with distict complex numbers of maximum lenght
    """
    distinct_list = []
    lenght_max = longest_distinct(complex_list, list_lenght)
    for i in range(0, list_lenght):
        for j in range(list_lenght - 1, i - 1,  -1):
            if contains_unique_elements(complex_list, i , j) == True:
                lenght = j - i + 1
                if lenght == lenght_max:
                    distinct_list.append((i, j))
                break

    return distinct_list


# UI section
def print_menu():
    print("Choose:")
    print("1. Add a complex number.")
    print("2. Remove a complex number")
    print("3. Longest sequence of numbers having increasing modulus.")
    print("4. Longest sequence of distinct numbers.")
    print("5. Print the list of complex numbers.")
    print("6. Stop the program.")


def print_list(complex_list, start, end):
    """
    :param list: contains complex numbers
    :param start: first index from where the list is printed
    :param end: final index from where the list stops to print
    :print: a list of complex numbers
    """
    print("[", end = "")
    for i in range(start, end + 1):
        a = get_real_part(complex_list[i])
        b = get_imaginary_part(complex_list[i])
        print(a, end = "")
        if b < 0:
            print(" -", abs(b), "\bi", end = ", ")
        elif b > 0:
            print(" +", b, "\bi", end = ", ")
        else:
            print(end = ", ")

    print("\b\b]")


def add_complex_ui(complex_list):
    while True:
        a = input("Real part = ")
        b = input("Imaginary part = ")
        ok = 1 # assume that the values introduced are integers
        try:    #   try converting the values from strings to integers
            a = int(a)
            b = int(b)
        except:
            ok = 0  # the values are not integers

        if ok == 0:  # if at least one of the values it's not numeric, then the input is not valid
            print("Invalid input, try again!")
        else:
            print("\n")
            print("The list before adding the number:", end=" ")
            print_list(complex_list, 0, len(complex_list) - 1)
            z = create_complex_number(a, b)
            add_complex(complex_list, z)
            print("The list after adding the number:", end=" ")
            print_list(complex_list, 0, len(complex_list) - 1)
            print("\n")
            break


def remove_complex_ui(complex_list):
    while True:
        index = input("Which element would you want to delete?\n")
        ok = 1  # assume that the index is already an integer
        try:    # try converting the index to an integer
            index = int(index)
        except:
            ok = 0  # the index is not an integer

        if ok == False:  # if the input is not numeric, then it's invalid
            print("Invalid input, try again!")
        else:
            if index < 0 or index > len(complex_list) - 1:
                print("No element on inserted position, try again!")
            else:
                print("\n")
                print("The list before removing the element:", end=" ")
                print_list(complex_list, 0, len(complex_list) - 1)
                remove_complex(complex_list, index)
                print("The list after removing the number:", end=" ")
                print_list(complex_list, 0, len(complex_list) - 1)
                print("\n")
                break


def print_modulo_sequences_ui(complex_list, list_lenght):
    """
    :print: all the the sequences with increasing modulo of maximum lenght
    """
    index_list = all_increasing_modulo(complex_list, list_lenght)
    # list of tuples, which contain on the index 0 the starting position of the sequence and on index 1 the ending position of the sequence
    for i in range(0, len(index_list)):
        print(i+1, "\b)", end=" ")
        print_list(complex_list, index_list[i][0], index_list[i][1])
        print('\n')


def print_all_longest_distinct_ui(complex_list, list_lenght):
    """
    :print: all the the sequences with distinct complex numbers of maximum lenght
    """
    index_list = all_longest_distinct(complex_list, list_lenght)
    # list of tuples, which contain on the index 0 the starting position of the sequence and on index 1 the ending position of the sequence
    for i in range(0, len(index_list)):
        print(i + 1, "\b)", end=" ")
        print_list(complex_list, index_list[i][0], index_list[i][1])
        print('\n')


def main():
    complex_list = [{'real': 1, 'imaginary': 2}, {'real': 7, 'imaginary': -3},
                    {'real': 6, 'imaginary': 5}, {'real': 101, 'imaginary': -8},
                    {'real': 4, 'imaginary': 13}, {'real': 5, 'imaginary': 11},
                    {'real': 7, 'imaginary': -3}, {'real': 8, 'imaginary': 9},
                    {'real': -14, 'imaginary': 8}, {'real': 1, 'imaginary': 0}]

    while True:
        print_menu()
        option = input("What option do you want to choose?\n")
        if option == '1':
            add_complex_ui(complex_list)
        elif option == '2':
            remove_complex_ui(complex_list)
        elif option == '3':
            print_modulo_sequences_ui(complex_list, len(complex_list))
        elif option == '4':
            print_all_longest_distinct_ui(complex_list, len(complex_list))
        elif option == '5':
            print_list(complex_list, 0, len(complex_list)-1)
        elif option == '6':
            exit()
        else:
            print("Invalid option!")


main()
