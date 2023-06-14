#pragma once
#include <string>
#include <istream>
#include <ostream>
#include <vector>
#include "Utils.h"

class Programmer{
private:
	std::string name;
	int id;

public:
	Programmer();
	Programmer(const std::string& _name, const int& _id);
	
	std::string getName()const;
	int getId()const;
	void setName(const std::string& _name);
	void setId(const int& _id);

	std::string toString()const;
	
	friend std::istream& operator>>(std::istream& is, Programmer& p);
	friend std::ostream& operator<<(std::ostream& os, const Programmer& p);

	~Programmer();
};