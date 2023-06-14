#include "Programmer.h"

Programmer::Programmer() : name{""}, id{0} {}

Programmer::Programmer(const std::string& _name, const int& _id) : name{_name}, id{_id} {}

std::string Programmer::getName() const{
	return this->name;
}

int Programmer::getId() const{
	return this->id;
}

void Programmer::setName(const std::string& _name){
	this->name.assign(_name);
}

void Programmer::setId(const int& _id){
	this->id = _id;
}

std::string Programmer::toString() const{
	return this->name + "|" + std::to_string(this->id);
}

Programmer::~Programmer(){
}

std::istream& operator>>(std::istream& is, Programmer& p)
{
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = Utils::tokenize(line, '|');
	if (tokens.size() != 2){
		return is;
	}
	try{
		p.name.assign(tokens[0]);
		p.id = std::stoi(tokens[1]);
	}
	catch (...){
		
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Programmer& p)
{
	os << p.name << "|" << p.id;
	return os;
}
