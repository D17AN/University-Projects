#include "Idea.h"

Idea::Idea() : description{""}, status{""}, creator{""}, act{0}{
}

Idea::Idea(const std::string& _description, const std::string& _status, const std::string& _creator, 
	const int& _act) : 
	description{_description}, status{_status}, creator{_creator}, act{_act}{
}

Idea::Idea(const Idea& i){
	this->description.assign(i.description);
	this->status.assign(i.status);
	this->creator.assign(i.creator);
	this->act = i.act;
}

Idea::~Idea(){
}

std::string Idea::getDescription() const{
	return this->description;
}

std::string Idea::getStatus() const{
	return this->status;
}

std::string Idea::getCreator() const{
	return this->creator;
}

int Idea::getAct() const{
	return this->act;
}

void Idea::setDescription(const std::string& _description){
	this->description.assign(_description);
}

void Idea::setStatus(const std::string& _status){
	this->status.assign(_status);
}

void Idea::setCreator(const std::string& _creator){
	this->creator.assign(_creator);
}

void Idea::setAct(const int& _act){
	this->act = _act;
}

std::string Idea::toString() const{
	return this->description + "|" + this->status + "|" + this->creator + "|" + std::to_string(this->act);
}

std::istream& operator>>(std::istream& is, Idea& i){
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = Utils::tokenize(line, '|');
	if (tokens.size() != 4){
		return is;
	}
	
	std::string description, status, creator;
	int act;
	try{
		description.assign(tokens[0]);
		status.assign(tokens[1]);
		creator.assign(tokens[2]);
		act = std::stoi(tokens[3]);
	}
	catch (...){
		return is;
	}

	i.description.assign(description);
	i.status.assign(status);
	i.creator.assign(creator);
	i.act = act;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Idea& i){
	os << i.description << "|" << i.status << "|" << i.creator << "|" << std::to_string(i.act);
	return os;
}
