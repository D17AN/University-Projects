#include "Observer.h"
#include <algorithm>

void Subject::addObserver(Observer* o)
{
    this->observers.push_back(o);
}


void Subject::notify()
{
    for (auto o : this->observers)
        o->update();
}
