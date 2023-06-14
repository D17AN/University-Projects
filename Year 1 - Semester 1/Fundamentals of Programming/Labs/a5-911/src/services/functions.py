from src.domain.Student import Student
from copy import deepcopy

class functions:
    def __init__(self):
        """
        initialiase a list of students
        """
        self.__students_list = []
        self.__undo_list = []


    def __copy_students_list(self):
        new_list = []
        for student in self.__students_list:
            new_list.append(deepcopy(student))
        return new_list


    """
    1) Add student functionality
    """
    def add_student(self, id, name, group):
        """
        Adds a student to a list
        :param id: the id of the new student
        :param name: the name of the new student
        :param group: the group from which belongs the new student
        """
        for student in self.__students_list:
            if student.id == id:
                raise ValueError("Already exists another student with the same id!")

        self.__undo_list.append(self.__copy_students_list()) # saving the previous version of the list
        new_student = Student(id, name, group)
        self.__students_list.append(new_student)


    def generate_students(self):
        self.add_student(1, "Samson Lucian", 911)
        self.add_student(2, "Popescu Adrian", 911)
        self.add_student(3, "Bucur Constantin", 911)
        self.add_student(4, "Manu Carina", 911)
        self.add_student(5, "Castan Petru", 917)
        self.add_student(6, "Balint Margareta", 913)
        self.add_student(7, "Pop Sabina", 914)
        self.add_student(8, "Gheorghe Dorel", 914)
        self.add_student(9, "Luca Calin", 915)
        self.add_student(10, "Nuc Andreea", 917)


    def test_add_student(self):
        self.add_student(1, "Marinescu George", 2)
        student = self.__students_list[0]
        assert student.id == 1 and student.name == "Marinescu George" and student.group == 2, "Adding error!"
        try:
            self.add_student("asds", "Marinescu George", 2)
            assert False
        except ValueError as ve:
            assert True


    """
    2) Display functionality
    """
    def display(self):
        for student in self.__students_list:
            print(student)


    """
    3) Filter functionality//Delete all the students from a given group
    """
    def __delete_student(self, student):
        """
        :param student: The student that must be deleted
        """
        self.__students_list.remove(student)


    def remove_group(self, group):
        """
        :param group: the group that must be eliminated
        remove all the students from group
        """
        ok = 0 # 0 if something wasn't deleted, 1 otherwise
        n = len(self.__students_list)
        i = 0
        while i < n:
            student = self.__students_list[i]
            if student.group == group:
                if ok == 0:
                    ok = 1
                    self.__undo_list.append(self.__copy_students_list())  # saving the previous version of the list
                self.__delete_student(student)
                n = n - 1 # decrementing the size of the list
            else:
                i = i + 1


    def test_remove_group(self):
        self.add_student(4, "Manu Carina", 911)
        self.add_student(5, "Castan Petru", 917)
        self.add_student(6, "Balint Margareta", 913)
        self.remove_group(911)
        for student in self.__students_list:
            assert student.group != 911, "The remove functions doesn't work properly!"


    def __copy_last_undo_list(self):
        new_list = []
        i = len(self.__undo_list) - 1
        for student in self.__undo_list[i]:
            new_list.append(deepcopy(student))
        return new_list


    def undo(self):
        if len(self.__undo_list) == 0:
            raise ValueError("The list of students it's at the earliest version!")
        else:
            self.__students_list[:] = self.__copy_last_undo_list() # restoring to the last version of the student list
            self.__undo_list.pop() # removing the last element of the undo list


    def get_lenght_undo_list(self):
        return len(self.__undo_list)


    def test_undo(self):
        self.add_student(1, "Samson Lucian", 911)
        self.add_student(2, "Popescu Adrian", 911)
        self.add_student(3, "Bucur Constantin", 911)
        self.add_student(4, "Manu Carina", 911)
        self.add_student(5, "Castan Petru", 917)
        new_list = self.__copy_students_list()
        self.remove_group(911)
        self.undo()

        ok = 1 # assume that the lists are equal
        for index in range(len(new_list)):
            stud1 = self.__students_list[index]
            stud2 = new_list[index]
            if stud2.id != stud1.id or stud2.name != stud1.name or stud1.group != stud2.group:
                ok = 0

        assert ok == 1, "Undo functionality doesn't work properly!"


def tests():
    m1 = functions()
    m2 = functions()
    m3 = functions()
    m1.test_add_student()
    m2.test_remove_group()
    m3.test_undo()













