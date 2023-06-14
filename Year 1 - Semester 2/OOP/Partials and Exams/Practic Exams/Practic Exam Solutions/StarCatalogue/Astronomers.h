#pragma once

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Astronomer {
private:
    string name, constellation;
public:
    Astronomer(const string &name, const string &constellation);
    Astronomer();
    virtual ~Astronomer();

    friend ostream &operator<<(ostream &os, const Astronomer &astronomers);
    friend istream &operator>>(istream &is, Astronomer &astronomers);

    const string &getName() const;

    void setName(const string &name);

    const string &getConstellation() const;

    void setConstellation(const string &constellation);
};
