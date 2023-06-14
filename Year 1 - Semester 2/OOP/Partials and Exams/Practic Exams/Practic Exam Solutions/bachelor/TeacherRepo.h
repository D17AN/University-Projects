#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Teacher.h"
class TeacherRepo
{
private:
	std::vector<Teacher> teachers;
	std::string filename;
public:
	TeacherRepo(std::string fname) { filename = fname; readFromFile(); }
	void addTeacher(Teacher t) { teachers.push_back(t); writeToFile(); }
	std::vector<Teacher> getTeachers() { return teachers; }

private:
	void readFromFile()
	{
		std::ifstream file(filename);
		std::string line, name;
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			std::getline(ss, name, '\n');
			addTeacher(Teacher(name));
		}
	}
	void writeToFile()
	{
		std::ofstream file(filename);
		for (auto& s : teachers)
			file << s.getName() << '\n';
	}
};

