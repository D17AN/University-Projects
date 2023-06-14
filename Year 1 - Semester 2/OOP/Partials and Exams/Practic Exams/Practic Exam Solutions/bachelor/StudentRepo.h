#pragma once
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "Student.h"
#include "Observer.h"


class StudentRepo : public Subject
{
private:
	std::vector<Student> students;
	std::string filename;
public:
    StudentRepo(std::string fname) { filename = fname; readFromFile(); sortRepo(); }
    
    void addStudent(Student s) 
    { 
        for (auto& st : students) 
            if (st.getId() == s.getId())
                return; 
        students.push_back(s);
        writeToFile();
    }
    void updateStudent(Student s) 
    {
        for (auto& st : students)
            if (st.getName() == s.getName())
                st = s;
        writeToFile();
        notify();
    }

    // simply goes through the list of students and if it finds one whose fields contain the given substring they are added to a new vector
    // that is later returned
    std::vector<Student> searchStudent(std::string str)
    {
        std::vector<Student> list;
        for (auto& s : students)
            if (str == "" || s.getId().find(str) != std::string::npos || s.getName().find(str) != std::string::npos)
                list.push_back(s);
        return list;
    }

    // goes through the list and if it finds the corresponding student and they don't have a coordinator then they get assigned one
    void changeStudentCoord(std::string str, std::string newTeacher) 
    {
        for (auto& s : students)
            if (s.toString() == str)
                if(s.getCoordinator()=="")
                    s.setCoordinator(newTeacher);
        writeToFile();
        notify();

    }
	std::vector<Student> getStudents() { return students; }



private:
    
    void sortRepo()
    {
        int year = 2023;
        for(int i=0;i<students.size()-1;++i)
            for (int j = i + 1; j < students.size(); ++j)
            {
                if (students[i].getYear() != year && students[j].getYear() == year)
                {
                    Student aux = students[i];
                    students[i] = students[j];
                    students[j] = aux;
                }
                else
                    if (students[i].getYear() != year && students[j].getYear() != year && students[i].getYear() < students[j].getYear())
                    {
                        Student aux = students[i];
                        students[i] = students[j];
                        students[j] = aux;
                    }
            }
    }

	void readFromFile()
	{
        std::ifstream file(filename);
        std::string line, temp;
        std::string id, name, email,title,coordinator;
        int year;
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::getline(ss, id, ',');
            std::getline(ss, name, ',');
            std::getline(ss, email, ',');
            std::getline(ss, temp, ',');
            year = std::stoi(temp);
            std::getline(ss, title, ',');
            std::getline(ss, coordinator, '\n');
            addStudent(Student(id, name, email, year, title, coordinator));
        }

        

	}
	void writeToFile()
	{
        std::ofstream file(filename);
        for (auto& s : students)
            file << s.getId() << ',' << s.getName() << ',' << s.getEmail() << ',' << s.getYear() << ',' << s.getTitle() << ',' << s.getCoordinator() << '\n';
	}
};

