#include "Writer.h"

Writer::Writer() : name{""}, expertise{""}{
}

Writer::Writer(const std::string& _name, const std::string& _expertise) : name{_name}, expertise{_expertise}{
}

Writer::Writer(const Writer& w){
	this->name.assign(w.name);
	this->expertise.assign(w.expertise);
}

Writer::~Writer(){
}

std::string Writer::getName() const{
	return this->name;
}

std::string Writer::getExpertise() const{
	return this->expertise;
}

void Writer::setName(const std::string& _name){
	this->name.assign(_name);
}

void Writer::setExpertise(const std::string& _expertise){
	this->expertise.assign(_expertise);
}

std::string Writer::toString() const{
	return this->name + "|" + this->expertise;
}

std::istream& operator>>(std::istream& is, Writer& w){
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = Utils::tokenize(line, '|');
	if (tokens.size() != 2){
		return is;
	}

	w.name.assign(tokens[0]);
	w.expertise.assign(tokens[1]);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Writer& w){
	os << w.name << "|" << w.expertise;
	return os;
}
