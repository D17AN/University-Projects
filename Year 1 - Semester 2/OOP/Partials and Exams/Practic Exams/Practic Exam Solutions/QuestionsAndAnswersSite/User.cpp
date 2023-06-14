#include "User.h"

User::User() : name{""}{
}

User::User(const std::string& _name) : name{_name}{
}

User::User(const User& other) : name{other.name}{
}

User::~User(){
}

std::string User::getName() const{
	return this->name;
}

void User::setName(const std::string& _name){
	this->name.assign(_name);
}

std::string User::toString(){
	return this->name;
}

std::istream& operator>>(std::istream& is, User& u){
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = Utils::tokenize(line, '|');
	
	if (tokens.size() != 1){
		u.name.assign("");
		return is;
	}

	u.name.assign(tokens[0]);
	return is;
}

std::ostream& operator<<(std::ostream& os, const User& u){
	os << u.name;
	return os;
}
