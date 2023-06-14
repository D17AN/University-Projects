#pragma once
#include "Utils.h"
#include <string>
#include <istream>
#include <ostream>

class Idea{
private:
	std::string description;
	std::string status; //proposed, accepted
	std::string creator;
	int act; //1, 2, 3

public:
	Idea();
	Idea(const std::string& _description, const std::string& _status, const std::string& _creator, const int& _act);
	Idea(const Idea& i);
	~Idea();

	std::string getDescription()const;
	std::string getStatus()const;
	std::string getCreator()const;
	int getAct()const;

	void setDescription(const std::string& _description);
	void setStatus(const std::string& _status);
	void setCreator(const std::string& _creator);
	void setAct(const int& _act);

	std::string toString()const;

	friend std::istream& operator>>(std::istream& is, Idea& i);
	friend std::ostream& operator<<(std::ostream& os, const Idea& i);
};

