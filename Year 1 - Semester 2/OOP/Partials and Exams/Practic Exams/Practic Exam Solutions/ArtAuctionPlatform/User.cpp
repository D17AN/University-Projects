#include "User.h"

User::User() : name{""}, id{0}, type{""}{
}

User::User(string& name, int id, string& type) : name{name}, id{id}, type{type}
{
}

User::User(const User& other) : name{other.name}, id{other.id}, type{other.type}
{
}

string User::toString() const
{
	string str = this->name + "|" + to_string(this->id) + "|" + this->type;
	return str;
}

ostream& operator<<(ostream& os, const User& u)
{
	string str = u.name + "|" + to_string(u.id) + "|" + u.type;
	os << str;
	return os;
}

istream& operator>>(istream& is, User& u)
{
	string line;
	getline(is, line);
	vector<string> tokens = Utils::tokenize(line, '|');
	if (tokens.size() != 3){
		u.name.assign("");
		u.id = 0;
		u.type = "";
		return is;
	}

	u.name.assign(tokens[0]);
	u.id = stoi(tokens[1]);
	u.type.assign(tokens[2]);
	return is;
}
