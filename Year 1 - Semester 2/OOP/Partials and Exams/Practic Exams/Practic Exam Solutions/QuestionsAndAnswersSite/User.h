#pragma once
#include "Utils.h"
#include <string>
#include <vector>
#include <istream>
#include <ostream>

class User{
private:
	std::string name;

public:
	User();
	User(const std::string& _name);
	User(const User& other);
	~User();

	std::string getName()const;
	void setName(const std::string& _name);

	std::string toString();
	friend std::istream& operator>>(std::istream& is, User& u);
	friend std::ostream& operator<<(std::ostream& os, const User& u);
};