#include "Subject.h"

void Subject::addObserver(Observer* o){
	this->observers.push_back(o);
}

void Subject::notify(){
	for (Observer* o : this->observers){
		o->update();
	}
}
