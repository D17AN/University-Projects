#pragma once
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Users{
private:
    string name;
public:
    Users(const string &name);
    Users();
    virtual ~Users();

    const string &getName() const;
    void setName(const string &name);

    friend ostream &operator<<(ostream &os, const Users &users);
    friend istream &operator>>(istream &is, Users &users);
};
