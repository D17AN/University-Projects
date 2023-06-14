from src.functions.functions import all_digits_distinct, check_four_digits_value,generate_fourdigits_distinct_number, cheat_code, codes, runners
import time


def ui():
    computer_choice = generate_fourdigits_distinct_number()
    t0 = time.time()
    while True:
        try:
            user_choice = int(input("user value = "))
        except ValueError as ve:
            print(str(ve))
        else:
            t1 = time.time() - t0
            if t1 > 59:
                print("Game over!")
                return

            if user_choice == computer_choice:
                print("Game won")
                return

            if check_four_digits_value(user_choice) == False:
                raise ValueError("the inserted number is not 4 digits long!")

            if cheat_code(user_choice) == True:
                print(computer_choice)
            else:
                print(user_choice, end="->")
                print(codes(computer_choice, user_choice), " codes and ", end="")
                print(runners(computer_choice, user_choice), "runners")
                if all_digits_distinct(user_choice) == False:
                    print("Game over, user lost!")
                    return


ui()


