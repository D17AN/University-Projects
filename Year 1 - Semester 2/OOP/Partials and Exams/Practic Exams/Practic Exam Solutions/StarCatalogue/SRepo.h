#pragma once

#include "Stars.h"
#include <algorithm>

class StarsRepository {
private:
    vector<Star> stars;
    string fileName = "Stars.txt";
public:
    StarsRepository();

    virtual ~StarsRepository();

    void readFromFile();
    void saveToFile();
    vector<Star>& getAll();

    void add(Star& s);
};

