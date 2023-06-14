#pragma once

#include "Utils.h"
#include <string>
#include <istream>
#include <ostream>


class Participant{
private:
	std::string name;
	int score;

public:
	Participant();
	Participant(const std::string& _name, const int& _score);
	Participant(const Participant& other);
	~Participant();

	std::string getName()const;
	int getScore()const;
	
	void setName(const std::string& _name);
	void setScore(const int& _score);

	std::string toString()const;

	friend std::istream& operator>>(std::istream& is, Participant& p);
	friend std::ostream& operator<<(std::ostream& os, const Participant& p);
};