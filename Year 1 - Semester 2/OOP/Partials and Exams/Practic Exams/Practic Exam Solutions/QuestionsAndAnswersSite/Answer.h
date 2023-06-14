#pragma once
#include "Utils.h"
#include <string>
#include <vector>
#include <istream>
#include <ostream>

class Answer{
private:
	int id, questionId, nrVotes;
	std::string creator, text;

public:
	Answer();
	Answer(const int& _id, const int& _questionId, const std::string& _creator, 
		const std::string& _text, const int& _nrVotes);
	Answer(const Answer& a);
	~Answer();

	int getId()const;
	int getQuestionId()const;
	std::string getCreator()const;
	std::string getText()const;
	int getNrVotes()const;

	void setId(const int& _id);
	void setQuestionId(const int& _questionId);
	void setCreator(const std::string& _creator);
	void setText(const std::string& _text);
	void setNrVotes(const int& _nrVotes);

	std::string toString()const;
	friend std::istream& operator>>(std::istream& is, Answer& a);
	friend std::ostream& operator<<(std::ostream& os, const Answer& a);
};