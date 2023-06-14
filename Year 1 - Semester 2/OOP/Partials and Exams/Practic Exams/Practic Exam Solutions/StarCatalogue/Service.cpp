#include "Service.h"

Service::Service(StarsRepository &srepo) : starsRepo(srepo) {}

Service::~Service() {

}

vector<Star>& Service::getAllStars() {
    vector<Star>& stars = starsRepo.getAll();
    std::sort(stars.begin(), stars.end(), [](const Star& s1, const Star& s2){
        return s1.getConstellation() < s2.getConstellation();
        });
    return stars;
}

vector<Star> Service::getAllWithConst(string constellation){
    vector<Star> new_arr;
    for (auto s : getAllStars()){
        if(s.getConstellation() == constellation){
            new_arr.push_back(s);
        }
    }
    return new_arr;
}

void Service::add(string name, string constellation, int ra, int dec, int diameter) {
    Star s(name, constellation, ra, dec, diameter);
    starsRepo.add(s);
    notify();
}

void Service::update(const Star& s, string newName, int ra, int dec, int diameter){
    vector<Star>& stars = starsRepo.getAll();
    auto starIterator = find_if(stars.begin(), stars.end(), [&s](const Star& other){
        return s.getName() == other.getName() && s.getConstellation() == other.getConstellation();
        });
    
    if (starIterator == stars.end()){
        throw std::exception("the stars doesn't exist.");
    }

    if (newName == ""){
        throw std::exception("the name must not be empty.");
    }

    if (diameter < 11){
        throw std::exception("the diameter must be bigger than 9.");
    }

    starIterator->setName(newName);
    starIterator->setRa(ra);
    starIterator->setDec(dec);
    starIterator->setDiameter(diameter);

    notify();
}

bool Service::search(string& name) {
    for(auto s:starsRepo.getAll()){
        if(s.getName() == name)
            return true;
    }
    return false;
}

