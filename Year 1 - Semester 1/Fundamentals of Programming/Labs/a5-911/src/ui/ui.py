from src.services.functions import functions, tests

class Console:
    def __init__(self):
        self.__functions = functions()

    def show_menu(self):
        print("Menu:", end="\n")
        print("1)Add student.", end="\n")
        print("2)Remove group.", end="\n")
        print("3)Display students list.", end="\n")
        print("4)Undo.", end ="\n")
        print("5)exit.", end="\n")


    def ui_add_student(self):
        try:
            id = int(input("id = "))
            name = str(input("name = "))
            group = int(input("group = "))
            if group < 0:
                raise ValueError("Group must be a positive integer!")
            self.__functions.add_student(id, name, group)
            print("The student has been succesfully added!")
        except ValueError as ve:
            print(str(ve))


    def ui_delete_group(self):
        try:
            group = int(input("Which group would you want to delete?\n"))
            self.__functions.remove_group(group)
            print("The group has been succesfully deleted!")
        except ValueError as ve:
            print(str(ve))


    def ui_undo(self):
        try:
            if self.__functions.get_lenght_undo_list() < 11:
                raise ValueError("The list of students it's at the earliest version!")
            self.__functions.undo()
            print("The undo operation has been a succes!")
        except ValueError as ve:
            print(str(ve))


    def ui_display(self):
        try:
           self.__functions.display()
           print("\n")
        except:
            print("Error displaying the list!")


    def start(self):
        self.__functions.generate_students()
        while True:
            try:
                self.show_menu()
                option = int(input("option = "))
                if option == 1:
                    self.ui_add_student()
                elif option == 2:
                    self.ui_delete_group()
                elif option == 3:
                    self.ui_display()
                elif option == 4:
                    self.ui_undo()
                elif option == 5:
                    return
            except ValueError as ve:
                print(str(ve))


tests()
ui = Console()
ui.start()
