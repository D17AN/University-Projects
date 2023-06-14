class Student:
    def __init__(self, id, name, group):
        """
        initialiase a student
        :param id: the id of a student
        :param name: name of the student
        :param group: the group from which belongs the student
        """
        if not isinstance(id, int):
            raise ValueError("Bad id, only integers allowed!")

        if not isinstance(name, str):
            raise ValueError("Bad name, the name is not a string!")

        if group < 0 or not isinstance(group, int):
            raise ValueError("Bad group option, the group must be a positive integer!")
        self.__student_id = id
        self.__student_name = name
        self.__student_group = group


    @property
    def id(self):
        """
        :return: the id of a student
        """
        return self.__student_id


    @id.setter
    def id(self, new_id):
        """
        :param new_id: the new id of the student
        sets the id of a student
        """
        self.__student_id = new_id


    @property
    def name(self):
        """
        :return: the name of a student
        """
        return self.__student_name


    @name.setter
    def name(self, new_name):
        """
        :param new_name: the new name of the student
        sets the name of a student
        """
        self.__student_name = new_name


    @property
    def group(self):
        """
        :return: the group from which the student belongs
        """
        return self.__student_group


    @group.setter
    def group(self, new_group):
        """
        :param new_group: the new group of the student
        sets the group of a student
        """
        self.__student_group = new_group


    def __str__(self):
        """
        :return: How will be printed a student
        """
        return "Student " + str(self.id) + " with name " + str(self.name.upper()) + " from group " + str(self.group)

