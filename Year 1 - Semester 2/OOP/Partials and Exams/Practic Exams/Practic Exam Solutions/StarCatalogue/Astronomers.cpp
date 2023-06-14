#include "Astronomers.h"

Astronomer::Astronomer(const string &name, const string &constellation) : name(name), constellation(constellation) {}

Astronomer::Astronomer() {
    name = "";
    constellation = "";
}

Astronomer::~Astronomer() {

}

const string &Astronomer::getName() const {
    return name;
}

void Astronomer::setName(const string &name) {
    Astronomer::name = name;
}

const string &Astronomer::getConstellation() const {
    return constellation;
}

void Astronomer::setConstellation(const string &constellation) {
    Astronomer::constellation = constellation;
}

ostream &operator<<(ostream &os, const Astronomer &astronomers) {
    os << astronomers.name << "," << astronomers.constellation;
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

std::istream &operator>>(std::istream &is, Astronomer &a){
    std::string line;
    getline(is, line);

    std::vector<std::string> tokens = tokenize(line, ',');
    if (tokens.size() != 2)
        return is;
    a.setName(tokens[0]);
    a.setConstellation(tokens[1]);
    return is;
}
