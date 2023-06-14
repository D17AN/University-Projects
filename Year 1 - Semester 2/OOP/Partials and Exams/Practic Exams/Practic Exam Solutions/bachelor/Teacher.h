#pragma once
#include <string>
class Teacher
{
private:
	std::string name;
public:
	Teacher(std::string n = "") { name = n; }
	std::string getName() { return name; }

};

