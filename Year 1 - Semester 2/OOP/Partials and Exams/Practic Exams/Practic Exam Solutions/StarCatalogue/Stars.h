#pragma once

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Star {
private:
    string name, constellation;
    int RA, Dec, diameter;
public:
    Star(const string &name, const string &constellation, int ra, int dec, int diameter);
    Star();
    virtual ~Star();

    friend ostream &operator<<(ostream &os, const Star &stars);
    friend istream &operator>>(istream &is, Star &stars);




    const string &getName() const;

    void setName(const string &name);

    const string &getConstellation() const;

    void setConstellation(const string &constellation);

    int getRa() const;

    void setRa(int ra);

    int getDec() const;

    void setDec(int dec);

    int getDiameter() const;

    void setDiameter(int diameter);
};
