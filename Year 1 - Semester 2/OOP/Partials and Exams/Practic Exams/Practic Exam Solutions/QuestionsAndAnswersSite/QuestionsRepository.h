#pragma once
#include "Question.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>

class QuestionsRepository{
private:
	std::vector<Question> questions;
	std::string fileName;

public:
	QuestionsRepository();
	QuestionsRepository(const std::string& _fileName);
	~QuestionsRepository();

	std::vector<Question>& getAll();
	void addQuestion(const Question& q);

	void loadFromFile();
	void saveToFile();
};