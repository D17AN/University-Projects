#pragma once
#include "Astronomers.h"

class AstronomersRepository {
private:
    string fileName = "Astronomers.txt";
    vector<Astronomer> astronomers;
public:
    AstronomersRepository();

    virtual ~AstronomersRepository();


    void readFromFile();
    void saveToFile();
    vector<Astronomer>& getAll();
};
