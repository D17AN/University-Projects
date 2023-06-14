#pragma once

#include "Utils.h"
#include <string>
#include <istream>
#include <ostream>

class Question{
private:
	int id, score;
	std::string text, answer;

public:
	Question();
	Question(const int& _id, const std::string& _text, const std::string& _answer, const int& _score);
	Question(const Question& other);
	~Question();

	int getId()const;
	std::string getText()const;
	std::string getAnswer()const;
	int getScore()const;

	void setId(const int& _id);
	void setText(const std::string& _text);
	void setAnswer(const std::string& _answer);
	void setScore(const int& _score);

	std::string toString()const;
	
	friend std::istream& operator>>(std::istream& is, Question& q);
	friend std::ostream& operator<<(std::ostream& os, const Question& q);
};