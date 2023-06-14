#include "Question.h"

Question::Question() : 
	id{0}, text{""}, creator{""}{
}

Question::Question(const int& _id, const std::string& _text, const std::string& _creator) : 
	id{_id}, text{_text}, creator{_creator}{

}

Question::Question(const Question& other) : 
	id{other.id}, text{other.text}, creator{other.creator}{
}

Question::~Question(){
}

int Question::getId() const{
	return this->id;
}

std::string Question::getText() const{
	return this->text;
}

std::string Question::getCreator() const{
	return this->creator;
}

void Question::setId(const int& _id){
	this->id = _id;
}

void Question::setText(const std::string& _text){
	this->text.assign(_text);
}

void Question::setCreator(const std::string& _creator){
	this->creator.assign(_creator);
}

std::string Question::toString() const{
	return std::to_string(this->id) + "|" + this->text + "|" + this->creator;
}

std::istream& operator>>(std::istream& is, Question& q){
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = Utils::tokenize(line, '|');
	if (tokens.size() != 3){
		q.id = 0;
		q.text = "";
		q.creator = "";
		return is;
	}
	
	q.id = std::stoi(tokens[0]);
	q.text.assign(tokens[1]);
	q.creator.assign(tokens[2]);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Question& q){
	os << q.id << "|" << q.text << "|" << q.creator;
	return os;
}
