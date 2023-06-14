#pragma once

#include <string>
#include <istream>
#include <ostream>
#include <vector>
#include "Utils.h"
using namespace std;

class User{
private:
	string name, type;
	int id;

public:
	User();
	User(string& name, int id, string& type);
	User(const User& other);

	string getName()const { return this->name; }
	int getId()const{ return this->id; }
	string getType()const{ return this->type; }

	void setName(string& name){ this->name = name; }
	void setType(string& type){ this->type = type; }

	string toString()const;

	friend ostream& operator<<(ostream& os, const User& u);
	friend istream& operator>>(istream& is, User& u);
};
