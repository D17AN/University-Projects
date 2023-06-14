#include "Topics.h"

Topics::Topics(const string &text, const vector<string> &usersInterested) : 
    text(text), users_interested(usersInterested) {}

Topics::Topics() {
    text = "";
}

Topics::~Topics() {

}

const string &Topics::getText() const {
    return text;
}

void Topics::setText(const string &text) {
    Topics::text = text;
}

const vector<string> &Topics::getUsersInterested() const {
    return users_interested;
}

void Topics::setUsersInterested(const vector<string> &usersInterested) {
    users_interested = usersInterested;
}

ostream &operator<<(ostream &os, const Topics &topics) {
    string text = topics.text;
    for(auto t:topics.users_interested){
        text += "," + t;
    }
    os << text;

    return os;
}

vector<string> tokenize2(string str, char delimiter)
{
    vector <string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

istream &operator>>(istream &is, Topics &t){
    string line;
    getline(is, line);
    if(line == "")
        return is;

    vector<string> tokens = tokenize2(line, ',');
    vector<string> topics;
    t.setText(tokens[0]);
    for(int i = 1; i<tokens.size();i++){
        topics.push_back(tokens[i]);
    }
    t.setUsersInterested(topics);
    return is;
}

void Topics::add(string &name) {
    users_interested.push_back(name);
}
