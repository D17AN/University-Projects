# Solve the problem from the first set here
# 3)
def breaking_in_digits(n):
    digits = [0]*10  # creating a frequency array and initializing all the values from 0 to 9 with the value 0
    n_copy = int(n)

    if n_copy == 0:  # particular case, when the input is 0
        digits[0] = 1

    while n_copy != 0:  # while remained digits in the number
        c = n_copy % 10  # take the last digit of the value
        digits[c] += 1  # incrementing the digit position in the frequency array
        n_copy //= 10  # cutting the last digit

    return digits


def min_number_with_same_digits(n):
    digits = breaking_in_digits(n)
    m = 0
    for i in range(1, 10, 1):  # find the smallest non-zero digit for putting in the front of the number
        if digits[i] != 0:
            m = m * 10 + i
            digits[i] -= 1
            break

    for i in range(0, 10, 1):  # constructing the minimal value by adding each digit of how many times appears in the original number
        for j in range(1, digits[i] + 1):
            m = m * 10 + i

    return m


def read():
    n = int(input("n = "))
    return n


def display(n):
    print(min_number_with_same_digits(n), "\n")


def main():
    n = read()
    display(n)


main()
