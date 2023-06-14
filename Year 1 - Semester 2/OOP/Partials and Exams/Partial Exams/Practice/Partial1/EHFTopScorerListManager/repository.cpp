#include "repository.h"

const std::vector<Player>& Repository::get() const
{
    return this->v;
}

int Repository::search(const Player& p) const
{
    auto it = std::find_if(this->v.begin(), this->v.end(), [&p](const Player& other){
        return p == other;
        });
    if (it == v.end()){
        return -1;
    }
    return it - v.begin();
}

void Repository::add(const Player& p)
{
    int i = this->search(p);
    if (i == -1){
        this->v.push_back(p);
    }
    else{
        throw std::exception("The player already exists!\n");
    }
}
