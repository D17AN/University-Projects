#include "Subject.h"

void Subject::notify(){
	for (Observer* o : this->observers){
		o->update();
	}
}

void Subject::addObserver(Observer* o){
	this->observers.push_back(o);
}
