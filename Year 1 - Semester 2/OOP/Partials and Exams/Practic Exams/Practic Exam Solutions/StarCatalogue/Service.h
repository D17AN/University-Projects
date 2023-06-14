#pragma once
#include "SRepo.h"
#include "Observer.h"
#include <algorithm>
#include <iterator>
#include <exception>

class Service : public Subject {
private:
    StarsRepository& starsRepo;
public:
    Service(StarsRepository &srepo);

    virtual ~Service();

    vector<Star>& getAllStars();
    vector<Star> getAllWithConst(string constellation);

    bool search(string& name);

    void add(string name, string constellation, int ra, int dec, int diameter);
    void update(const Star& s, string newName, int ra, int dec, int diameter);
};

