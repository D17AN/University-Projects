#pragma once
#include "Answer.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>

class AnswersRepository{
private:
	std::vector<Answer> answers;
	std::string fileName;

public:
	AnswersRepository();
	AnswersRepository(const std::string& _fileName);
	~AnswersRepository();

	std::vector<Answer>& getAll();
	void addAnswer(const Answer& a);

	void loadFromFile();
	void saveToFile();
};