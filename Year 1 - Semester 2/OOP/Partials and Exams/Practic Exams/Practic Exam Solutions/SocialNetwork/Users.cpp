#include "Users.h"

Users::Users(const string &name) : name(name) {}

Users::Users() {
    name = "";
}

Users::~Users() {

}

const string &Users::getName() const {
    return name;
}

void Users::setName(const string &name) {
    Users::name = name;
}

ostream &operator<<(ostream &os, const Users &users) {
    os << users.name;
    return os;
}
std::vector<std::string> tokenize(std::string str, char delimiter)
{
    std::vector <std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream &operator>>(std::istream &is, Users &u){
    std::string line;
    getline(is, line);

    u.setName(line);
    return is;
}
