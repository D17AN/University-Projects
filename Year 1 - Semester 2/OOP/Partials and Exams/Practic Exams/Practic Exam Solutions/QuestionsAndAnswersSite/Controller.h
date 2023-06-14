#pragma once
#include "Subject.h"
#include "QuestionsRepository.h"
#include "AnswersRepository.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>


class Controller : public Subject{
private:
	QuestionsRepository& questionsRepo;
	AnswersRepository& answersRepo;

public:
	Controller(QuestionsRepository& _questionsRepo, AnswersRepository& _answersRepo);
	~Controller();

	std::vector<Question> getAllQuestions()const;
	std::vector<Answer> getAllAnswers()const;

	/*
	* Input:
	*	- questionId: int, the id of the question
	* Output:
	*	return: a vector of Answers associated with the given questionId
	*/
	std::vector<Answer> getAllAnswersToQuestion(int questionId);
	std::vector<Question> getAllQuestionsMatchingText(const std::string& text);

	/*
	* Adds a questions in repository
	* Input:
	*	- text: string, the text of the question
	*	- creator: string, the name of the person which created the question
	* Output:
	*	An object of type was created and added in the repository
	* Exceptions:
	*	- if the text is empty, an exception is thrown
	*/
	void addQuestion(const std::string& text, const std::string& creator);
	void addAnswer(const int& questionId, const std::string& creator, const std::string& text);
	void updateVotesAnswer(int answerId, int newNrVotes);

private:
	int getNumberAnswersToQuestion(int questionId)const;
	int getMaxQuestionId()const;
	int getMaxAnswerId()const;
};