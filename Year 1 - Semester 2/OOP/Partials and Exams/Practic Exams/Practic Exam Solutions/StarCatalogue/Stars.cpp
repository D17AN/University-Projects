#include "Stars.h"

Star::Star(const string &name, const string &constellation, int ra, int dec, int diameter) : 
    name(name), constellation(constellation), RA(ra), Dec(dec), diameter(diameter) {}

Star::~Star() {

}

Star::Star() {
    name = "";
    constellation = "";
    RA = 0;
    Dec = 0;
    diameter = 0;
}

const string &Star::getName() const {
    return name;
}

void Star::setName(const string &name) {
    Star::name = name;
}

const string &Star::getConstellation() const {
    return constellation;
}

void Star::setConstellation(const string &constellation) {
    Star::constellation = constellation;
}

int Star::getRa() const {
    return RA;
}

void Star::setRa(int ra) {
    RA = ra;
}

int Star::getDec() const {
    return Dec;
}

void Star::setDec(int dec) {
    Dec = dec;
}

int Star::getDiameter() const {
    return diameter;
}

void Star::setDiameter(int diameter) {
    Star::diameter = diameter;
}

ostream &operator<<(ostream &os, const Star &stars) {
    os <<  stars.name << "," << stars.constellation << "," << stars.RA << "," << stars.Dec << "," << stars.diameter;
    return os;
}

std::vector<std::string> tokenize2(std::string str, char delimiter)
{
    std::vector <std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream &operator>>(std::istream &is, Star &s){
    std::string line;
    getline(is, line);

    std::vector<std::string> tokens = tokenize2(line, ',');
    if (tokens.size() != 5)
        return is;
    s.setName(tokens[0]);
    s.setConstellation(tokens[1]);
    s.setRa(std::stoi(tokens[2]));
    s.setDec(std::stoi(tokens[3]));
    s.setDiameter(std::stoi(tokens[4]));
    return is;
}
