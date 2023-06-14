#pragma once
#include <string>
#include "Utils.h"
#include <istream>
#include <ostream>

class Writer{
private:
	std::string name;
	std::string expertise; //assistant, junior, senior

public:
	Writer();
	Writer(const std::string& _name, const std::string& _expertise);
	Writer(const Writer& w);
	~Writer();

	std::string getName()const;
	std::string getExpertise()const;
	void setName(const std::string& _name);
	void setExpertise(const std::string& _expertise);
	std::string toString()const;

	friend std::istream& operator>>(std::istream& is, Writer& w);
	friend std::ostream& operator<<(std::ostream& os, const Writer& w);
};