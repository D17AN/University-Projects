#include "ARepo.h"

AstronomersRepository::AstronomersRepository() {
    readFromFile();
}

AstronomersRepository::~AstronomersRepository() {
    saveToFile();
}

#include <fstream>

void AstronomersRepository::readFromFile() {
    std::ifstream f(fileName);
    while(!f.eof()){
        Astronomer q;
        f>> q;
        if(q.getName() == "")
            return;
        this->astronomers.push_back(q);
    }
    f.close();

}

void AstronomersRepository::saveToFile() {
    std::ofstream f(fileName);
    f.clear();
    for(const auto& q:astronomers){
        f<<q<<"\n";
    }
    f.close();
}

vector<Astronomer>& AstronomersRepository::getAll() {
    return astronomers;
}
