#include "Observer.h"

void Observable::addObserver(Observer* o)
{
    this->observers.push_back(o);
}


void Observable::notify_all_observables()
{
    for (auto o : this->observers)
        o->update();
}