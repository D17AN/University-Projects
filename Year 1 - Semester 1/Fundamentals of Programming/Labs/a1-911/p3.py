# Solve the problem from the third set here
# 2)
def finding_the_nth_element(n):
    if n == 1:
        return 1

    i = 1  # initializing an iterator
    nr = 2
    while i < n:  # while the nth element wasn't found
        divisor = 2
        nr_copy = nr
        while nr_copy > 1:  # decomposing in prime factors
            if nr_copy % divisor == 0:  # if a prime divisor was found
                i = i + 1
                while nr_copy % divisor == 0:  # divide the number with the prime divisor until it won't be divisible
                    nr_copy = nr_copy // divisor
            divisor = divisor + 1
            if i == n:  # if the nth element was found
                return divisor - 1
        nr = nr + 1


def read():
    n = int(input("n = "))
    return n


def display(value):
    print("The nth element of the sequence is", value)


def main():
    n = read()
    value = finding_the_nth_element(n)
    display(value)


main()
