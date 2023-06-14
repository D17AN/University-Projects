#include "Question.h"

Question::Question() : id{0}, text{""}, answer{""}, score{-1}{
}

Question::Question(const int& _id, const std::string& _text, const std::string& _answer, const int& _score) : 
	id{_id}, text{_text}, answer{_answer}, score{_score}{
}

Question::Question(const Question& other) : 
	id{other.id}, text{other.text}, answer{other.answer}, score{other.score}{
}

Question::~Question(){
}

int Question::getId() const{
	return this->id;
}

std::string Question::getText() const{
	return this->text;
}

std::string Question::getAnswer() const{
	return this->answer;
}

int Question::getScore() const{
	return this->score;
}

void Question::setId(const int& _id){
	this->id = _id;
}

void Question::setText(const std::string& _text){
	this->text.assign(_text);
}

void Question::setAnswer(const std::string& _answer){
	this->answer.assign(_answer);
}

void Question::setScore(const int& _score){
	this->score = score;
}

std::string Question::toString() const{
	return std::to_string(this->id) + "|" + this->text + "|" + this->answer + 
		"|" + std::to_string(this->score);
}

std::istream& operator>>(std::istream& is, Question& q){
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = Utils::tokenize(line, '|');
	
	if (tokens.size() != 4){
		q.id = 0;
		q.text = "";
		q.answer = "";
		q.score = -1;
		return is;
	}

	q.id = std::stoi(tokens[0]);
	q.text = tokens[1];
	q.answer = tokens[2];
	q.score = std::stoi(tokens[3]);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Question& q){
	std::string str = std::to_string(q.id) + "|" + q.text + "|" + q.answer +
		"|" + std::to_string(q.score);
	os << str;
	return os;
}
