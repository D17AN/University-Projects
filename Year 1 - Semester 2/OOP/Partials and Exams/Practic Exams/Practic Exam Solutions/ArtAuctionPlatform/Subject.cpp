#include "Subject.h"

void Subject::notify()
{
	for (Observer* o : observers)
		o->update();
}

void Subject::addObserver(Observer* o)
{
	observers.push_back(o);
}
