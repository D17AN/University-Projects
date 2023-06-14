#include "SourceFile.h"

SourceFile::SourceFile() : name{""}, status{""}, creator{""}, reviewer{""} {}

SourceFile::SourceFile(const std::string& _name, const std::string& _status, const std::string& _creator, const std::string& _reviewer):
	name{_name}, status{_status}, creator{_creator}, reviewer{_reviewer}{}

SourceFile::~SourceFile(){
}

std::string SourceFile::getName() const{
	return this->name;
}

std::string SourceFile::getStatus() const{
	return this->status;
}

std::string SourceFile::getCreator() const{
	return this->creator;
}

std::string SourceFile::getReviewer() const{
	return this->reviewer;
}

void SourceFile::setName(const std::string& _name){
	this->name.assign(_name);
}

void SourceFile::setStatus(const std::string& _status){
	this->status.assign(_status);
}

void SourceFile::setCreator(const std::string& _creator){
	this->creator.assign(_creator);
}

void SourceFile::setReviewer(const std::string& _reviewer){
	this->reviewer.assign(_reviewer);
}

std::string SourceFile::toString() const{
	return this->name + "|" + this->status + "|" + this->creator + "|" + this->reviewer;
}


std::ostream& operator<<(std::ostream& os, const SourceFile& sf)
{
	os << sf.name << "|" << sf.status << "|" << sf.creator << "|" << sf.reviewer;
	return os;
}

std::istream& operator>>(std::istream& is, SourceFile& sf){
	std::string line = "";
	getline(is, line);
	std::vector<std::string> tokens = Utils::tokenizeString(line, '|');

	if (tokens.size() != 4){
		return is;
	}

	sf.name.assign(tokens[0]);
	sf.status.assign(tokens[1]);
	sf.creator.assign(tokens[2]);
	sf.reviewer.assign(tokens[3]);

	return is;
}
