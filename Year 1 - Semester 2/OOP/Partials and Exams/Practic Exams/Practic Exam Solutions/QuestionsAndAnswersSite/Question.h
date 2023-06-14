#pragma once
#include "Utils.h"
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <ostream>

class Question{
private:
	int id;
	std::string text, creator;

public:
	Question();
	Question(const int& _id, const std::string& _text, const std::string& _creator);
	Question(const Question& other);
	~Question();

	int getId()const;
	std::string getText()const;
	std::string getCreator()const;

	void setId(const int& _id);
	void setText(const std::string& _text);
	void setCreator(const std::string& _creator);

	std::string toString()const;
	friend std::istream& operator>>(std::istream& is, Question& q);
	friend std::ostream& operator<<(std::ostream& os, const Question& q);
};