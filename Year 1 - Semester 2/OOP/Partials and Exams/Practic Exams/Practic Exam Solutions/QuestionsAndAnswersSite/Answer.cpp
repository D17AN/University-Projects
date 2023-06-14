#include "Answer.h"

Answer::Answer() : id{0}, questionId{0}, creator{""}, text{""}, nrVotes{0}{
}

Answer::Answer(const int& _id, const int& _questionId, const std::string& _creator, 
	const std::string& _text, const int& _nrVotes) :
	id{_id}, questionId{_questionId}, creator{_creator}, text{_text}, nrVotes{_nrVotes}{
}

Answer::Answer(const Answer& a) : id{a.id}, questionId{a.questionId}, creator{a.creator}, 
	text{a.text}, nrVotes{a.nrVotes}{
}

Answer::~Answer(){
}

int Answer::getId() const{
	return this->id;
}

int Answer::getQuestionId() const{
	return this->questionId;
}

std::string Answer::getCreator() const{
	return this->creator;
}

std::string Answer::getText() const{
	return this->text;
}

int Answer::getNrVotes() const{
	return this->nrVotes;
}

void Answer::setId(const int& _id){
	this->id = _id;
}

void Answer::setQuestionId(const int& _questionId){
	this->questionId = _questionId;
}

void Answer::setCreator(const std::string& _creator){
	this->creator.assign(_creator);
}

void Answer::setText(const std::string& _text){
	this->text.assign(_text);
}

void Answer::setNrVotes(const int& _nrVotes){
	this->nrVotes = _nrVotes;
}

std::string Answer::toString() const{
	return std::to_string(this->id) + "|" + std::to_string(this->questionId) + "|" 
		+ this->creator + "|" + this->text + "|" + std::to_string(this->nrVotes);
}

std::istream& operator>>(std::istream& is, Answer& a){
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = Utils::tokenize(line, '|');
	
	if (tokens.size() != 5){
		a.id = 0;
		a.questionId = 0;
		a.creator = "";
		a.text = "";
		a.nrVotes = 0;
		return is;
	}

	a.id = std::stoi(tokens[0]);
	a.questionId = std::stoi(tokens[1]);
	a.creator = tokens[2];
	a.text = tokens[3];
	a.nrVotes = std::stoi(tokens[4]);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Answer& a){
	std::string res = std::to_string(a.id) + "|" + std::to_string(a.questionId) + "|" + 
		a.creator + "|" + a.text + "|" + std::to_string(a.nrVotes);
	os << res;
	return os;
}
