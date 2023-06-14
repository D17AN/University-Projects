#include "Controller.h"

Controller::Controller(QuestionsRepository& _questionsRepo) : questionsRepo{_questionsRepo}{
}

Controller::~Controller(){
}

void Controller::addQuestion(const int& id, const std::string& text, 
	const std::string& answer, const int& score){
	if (text == ""){
		throw std::exception("Enter a question!");
	}

	std::vector<Question>& questions = this->questionsRepo.getAll();
	
	auto pos = std::find_if(questions.begin(), questions.end(), [&](const Question& q){
		return q.getId() == id;
		});

	if (pos != questions.end()){
		throw std::exception("A question with the same id already exists.");
	}

	Question q{id, text, answer, score};
	this->questionsRepo.addQuestion(q);
	this->notify();
}

int Controller::answerQuestion(const int& id, const std::string& answer){
	std::vector<Question> questions = this->questionsRepo.getAll();
	auto questionIterator = std::find_if(questions.begin(), questions.end(), [&id](const Question& q){
		return q.getId() == id;
		});

	if (questionIterator == questions.end()){
		throw std::exception("The question with the given id doesn't exist.");
	}

	int score = questionIterator->getAnswer() == answer ? questionIterator->getScore() : 0;
	return score;
}

std::vector<Question> Controller::getAllSortedById(){
	std::vector<Question> questions = this->questionsRepo.getAll();
	std::sort(questions.begin(), questions.end(), [](const Question& q1, const Question& q2){
		return q1.getId() < q2.getId();
		});
	return questions;
}

std::vector<Question> Controller::getAllSortedByScore(){
	std::vector<Question> questions = this->questionsRepo.getAll();
	std::sort(questions.begin(), questions.end(), [](const Question& q1, const Question& q2){
		return q1.getScore() > q2.getScore();
		});
	return questions;
}
