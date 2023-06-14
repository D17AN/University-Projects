#include "Participant.h"

Participant::Participant() : name{""}, score{-1}{
}

Participant::Participant(const std::string& _name, const int& _score) : name{_name}, score{_score}{
}

Participant::Participant(const Participant& other) : name{other.name}, score{other.score}{
}

Participant::~Participant(){
}

std::string Participant::getName() const{
	return this->name;
}

int Participant::getScore() const{
	return this->score;
}

void Participant::setName(const std::string& _name){
	this->name = _name;
}

void Participant::setScore(const int& _score){
	this->score = _score;
}

std::string Participant::toString() const{
	return this->name + "|" + std::to_string(this->score);
}

std::istream& operator>>(std::istream& is, Participant& p){
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = Utils::tokenize(line, '|');

	if (tokens.size() != 2){
		p.name = "";
		p.score = -1;
		return is;
	}

	p.name = tokens[0];
	p.score = std::stoi(tokens[1]);
	
	return is;
}

std::ostream& operator<<(std::ostream& os, const Participant& p){
	std::string str = p.name + "|" + std::to_string(p.score);
	os << str;
	return os;
}
