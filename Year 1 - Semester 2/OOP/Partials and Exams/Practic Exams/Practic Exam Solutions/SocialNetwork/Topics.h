#pragma once
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Topics {
private:
    string text;
    vector<string> users_interested;
public:
    Topics(const string &text, const vector<string> &usersInterested);

    Topics();

    virtual ~Topics();

    const string &getText() const;

    void setText(const string &text);

    const vector<string> &getUsersInterested() const;

    void setUsersInterested(const vector<string> &usersInterested);

    friend ostream &operator<<(ostream &os, const Topics &topics);
    friend istream &operator>>(istream &is, Topics &topics);

    void add(string& name);
};
