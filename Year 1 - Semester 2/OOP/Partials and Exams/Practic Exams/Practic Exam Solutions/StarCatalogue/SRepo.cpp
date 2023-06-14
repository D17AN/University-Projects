#include "SRepo.h"

StarsRepository::StarsRepository() {
    readFromFile();
}

StarsRepository::~StarsRepository() {
    saveToFile();
}

#include <fstream>

void StarsRepository::readFromFile() {
    std::ifstream f(fileName);
    while(!f.eof()){
        Star q;
        f>> q;
        if(q.getName() == "")
            return;
        this->stars.push_back(q);
    }
    f.close();

}

void StarsRepository::saveToFile() {
    std::ofstream f(fileName);
    f.clear();
    sort(stars.begin(), stars.end(), [](Star& s1, Star& s2){
        return s1.getConstellation() < s2.getConstellation() || 
            (s1.getConstellation() == s2.getConstellation() && s1.getDiameter() < s2.getDiameter());
        });
    for(const auto& q:stars){
        f<<q<<"\n";
    }
    f.close();
}

vector<Star>& StarsRepository::getAll() {
    return stars;
}

void StarsRepository::add(Star& s) {
    stars.push_back(s);
}

