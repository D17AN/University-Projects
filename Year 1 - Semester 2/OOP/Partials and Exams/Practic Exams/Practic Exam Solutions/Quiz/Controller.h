#pragma once

#include "Subject.h"
#include "QuestionsRepository.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>

class Controller : public Subject{
private:
	QuestionsRepository& questionsRepo;

public:
	Controller(QuestionsRepository& _questionsRepo);
	~Controller();

	/*
	* Add question to repository
	* Input:
	*	- id: int, the id of the question
	*	- text: string, the text of the question
	*	- answer: string, the asnwer of the question
	*	- score: int, the score of the question
	* Ouput:
	*	A new object of type question is created and added to the repository
	* 
	* Exceptions:
	*	- if the text is empty, an exception is thrown
	*	- if the another question has already the same id, an exception is thrown
	* 
	*/
	void addQuestion(const int& id, const std::string& text, const std::string& answer, const int& score);
	int answerQuestion(const int& id, const std::string& answer);
	
	std::vector<Question> getAllSortedById();
	std::vector<Question> getAllSortedByScore();

};