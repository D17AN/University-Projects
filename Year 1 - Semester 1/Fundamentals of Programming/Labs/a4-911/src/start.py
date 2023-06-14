"""
  Start the program by running this module
"""
from functions import create_transaction, copy_transactions_list
from ui import list, commands_list, command_input, split_command
from tests import tests

def generate_transactions():
    return [create_transaction(1, 1000, "in", "bonus"), create_transaction(15, 300, "out", "abonament"),
            create_transaction(3, 7000, "out", "skinuri"), create_transaction(17, 235000, "in", "salariu"),
            create_transaction(15, 500, "out", "cumparaturi"), create_transaction(30, 43, "out", " cumparaturi"),
            create_transaction(4, 150, "out", "gaz"), create_transaction(15, 40, "out", "internet"),
            create_transaction(3, 50, "out", "pizza"), create_transaction(25, 1700, "out", "chirie")]


def main():
    tests()
    transactions_list = generate_transactions()
    undo_list = []
    commands_list(transactions_list, undo_list)


main()



