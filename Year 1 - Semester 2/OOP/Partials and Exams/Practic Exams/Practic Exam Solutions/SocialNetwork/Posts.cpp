#include "Posts.h"

Posts::Posts(int id, const string &text, int day, int month, int year, const string &user) : 
    id(id), text(text), day(day), month(month), year(year), user(user) {}

Posts::Posts() {
    id = 0;
    text = "";
    day = 0;
    month = 0;
    year = 0;
    user = "";
}

Posts::~Posts() {

}

int Posts::getId() const {
    return id;
}

void Posts::setId(int id) {
    Posts::id = id;
}

const string &Posts::getText() const {
    return text;
}

void Posts::setText(const string &text) {
    Posts::text = text;
}

int Posts::getDay() const {
    return day;
}

void Posts::setDay(int day) {
    Posts::day = day;
}

int Posts::getMonth() const {
    return month;
}

void Posts::setMonth(int month) {
    Posts::month = month;
}

int Posts::getYear() const {
    return year;
}

void Posts::setYear(int year) {
    Posts::year = year;
}

const string &Posts::getUser() const {
    return user;
}

void Posts::setUser(const string &user) {
    Posts::user = user;
}

ostream &operator<<(ostream &os, const Posts &posts) {
    os <<  posts.id << "," << posts.text << "," << posts.day << "," << posts.month << "," << posts.year << "," << posts.user;
    return os;
}

vector<std::string> tokenize3(string str, char delimiter)
{
    vector <string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

istream &operator>>(istream &is, Posts &p){
    string line;
    getline(is, line);

    vector<string> tokens = tokenize3(line, ',');
    if (tokens.size() != 6)
        return is;
    p.setId(stoi(tokens[0]));
    p.setText(tokens[1]);
    p.setDay(stoi(tokens[2]));
    p.setMonth(stoi(tokens[3]));
    p.setYear(stoi(tokens[4]));
    p.setUser(tokens[5]);
    return is;
}