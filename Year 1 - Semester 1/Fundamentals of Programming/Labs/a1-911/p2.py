# Solve the problem from the second set here

# 1)
def leap_year(year):  # verify if a year is a leap year
    if year % 4 == 0 and year % 100 != 0:
        return 1
    if year % 400 == 0:
        return 1
    else:
        return 0


def determine_day_and_month(day_of_year, year):
    interval = [1, 32, 60, 91, 121, 152,
                182, 213, 244, 274, 305, 335, 365]  # retains the number of the first day of a month
    months = ["January", "February", "March", "April",
              "May", "June", "July", "August", "September",
              "October", "November", "December"]  # array that retains every month
    if leap_year(year) == 0:  # if is not a leap year
        for i in range(0, 12):
            if interval[i] <= day_of_year < interval[i + 1]:  # searching the month of the year
                day_of_month = day_of_year - interval[i] + 1
                return day_of_month, months[i]
    else:  # if is a leap year
        for i in range(2, 13):  # incrementing with 1 the number of the first day of the month from February to December
            interval[i] = interval[i] + 1

        for i in range(0, 12):
            if interval[i] <= day_of_year < interval[i + 1]:
                day_of_month = day_of_year - interval[i] + 1
                return day_of_month, months[i]


def read():
    year = int(input("year = "))
    day_of_the_year = int(input("day of the year = "))
    return year, day_of_the_year


def display(day_of_month, month, year):
    print("The date is", day_of_month, "/", month, "/", year, '\n')


def main():
    year, day_of_the_year = read()
    day_of_month, month = determine_day_and_month(day_of_the_year, year)
    display(day_of_month, month, year)


main()