#include "Controller.h"

Controller::Controller(QuestionsRepository& _questionsRepo, AnswersRepository& _answersRepo) : 
	questionsRepo{_questionsRepo}, answersRepo{_answersRepo}{
}

Controller::~Controller(){
}

int Controller::getNumberAnswersToQuestion(int questionId) const{
	int nr = 0;
	std::vector<Answer>& answers = this->answersRepo.getAll();
	std::for_each(answers.begin(), answers.end(), [&nr, &questionId](const Answer& a){
		if (a.getQuestionId() == questionId){
			nr++;
		}
		});
	return nr;
}

int Controller::getMaxQuestionId() const{
	int maxId = 0;
	std::vector<Question> questions = this->questionsRepo.getAll();
	std::for_each(questions.begin(), questions.end(), [&maxId](const Question& q){
		int currId = q.getId();
		if (currId > maxId){
			maxId = currId;
		}
		});
	return maxId;
}

int Controller::getMaxAnswerId() const{
	int maxId = 0;
	std::vector<Answer> answers = this->answersRepo.getAll();
	std::for_each(answers.begin(), answers.end(), [&maxId](const Answer& a){
		int currId = a.getId();
		if (currId > maxId){
			maxId = currId;
		}
		});
	return maxId;
}

std::vector<Question> Controller::getAllQuestions() const{
	std::vector<Question> questions = this->questionsRepo.getAll();
	std::sort(questions.begin(), questions.end(), [&](const Question& q1, const Question& q2){
		return this->getNumberAnswersToQuestion(q1.getId()) > this->getNumberAnswersToQuestion(q2.getId());
		});
	return questions;
}

std::vector<Answer> Controller::getAllAnswers() const{
	return this->answersRepo.getAll();
}

std::vector<Answer> Controller::getAllAnswersToQuestion(int questionId){
	std::vector<Answer> res;
	std::vector<Answer>& answers = this->answersRepo.getAll();
	std::copy_if(answers.begin(), answers.end(), std::back_inserter(res), [&questionId](const Answer& a){
		return a.getQuestionId() == questionId;
		});
	std::sort(res.begin(), res.end(), [](const Answer& a1, const Answer& a2){
		return a1.getNrVotes() > a2.getNrVotes();
		});
	return res;
}

std::vector<Question> Controller::getAllQuestionsMatchingText(const std::string& text){
	std::vector<Question>& questions = this->questionsRepo.getAll();
	std::vector<Question> res;
	std::copy_if(questions.begin(), questions.end(), std::back_inserter(res), [&text](const Question& q){
		return q.getText().find(text) != std::string::npos;
		});
	return res;
}

void Controller::addQuestion(const std::string& text, const std::string& creator){
	int id = this->getMaxQuestionId() + 1;
	if (text == ""){
		throw std::exception("The text description must not be empty! Please provide a question!");
	}
	Question q{id, text, creator};
	this->questionsRepo.addQuestion(q);
	this->notify();
}

void Controller::addAnswer(const int& questionId, const std::string& creator, const std::string& text){
	int id = this->getMaxAnswerId() + 1;
	if (text == ""){
		throw std::exception("The text description must not be empty! Please provide an asnwer!");
	}
	Answer a{id, questionId, creator, text, 0};
	this->answersRepo.addAnswer(a);
	this->notify();
}

void Controller::updateVotesAnswer(int answerId, int newNrVotes){
	std::vector<Answer>& answers = this->answersRepo.getAll();
	auto pos = std::find_if(answers.begin(), answers.end(), [&answerId, &newNrVotes](const Answer& a){
		return a.getId() == answerId;
		});
	
	if (pos == answers.end()){
		throw std::exception("The answer with the given id doesn't exist!");
	}

	pos->setNrVotes(newNrVotes);
	this->notify();
}
