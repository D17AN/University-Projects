#include "Programmer.h"

Programmer::Programmer() : name{""}, nrRevised{0}, nrMustRevise{0} {}

Programmer::Programmer(const std::string& _name, const int& _nrRevised, const int& _nrMustRevise) : name{_name}, 
	nrRevised{_nrRevised}, nrMustRevise{_nrMustRevise} {}

Programmer::~Programmer(){
}

std::string Programmer::getName() const{
	return this->name;
}

int Programmer::getNrRevisedFiles() const{
	return this->nrRevised;
}

int Programmer::getNrMustReviseFiles() const{
	return this->nrMustRevise;
}

void Programmer::setName(const std::string& _name){
	this->name.assign(_name);
}

void Programmer::setNrRevisedFiles(const int& _nrRevised){
	this->nrRevised = _nrRevised;
}

void Programmer::setNrMustReviseFiles(const int& _nrMustRevise){
	this->nrMustRevise = _nrMustRevise;
}

bool Programmer::operator==(const Programmer& other)
{
	return this->name == other.name;
}

std::string Programmer::toString() const{
	return this->name + "|" + std::to_string(this->nrRevised) + "|" + std::to_string(this->nrMustRevise);
}


std::ostream& operator<<(std::ostream& os, const Programmer& p){
	os << p.name << "|" << p.nrRevised << "|" << p.nrMustRevise;
	return os;
}

std::istream& operator>>(std::istream& is, Programmer& p){
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = Utils::tokenizeString(line, '|');

	if (tokens.size() != 3){
		return is;
	}
	p.name = tokens[0];
	p.nrRevised = std::stoi(tokens[1]); // error, if the token is not an integer
	p.nrMustRevise = std::stoi(tokens[2]); // error, if the token is not an integer
	return is;
}
