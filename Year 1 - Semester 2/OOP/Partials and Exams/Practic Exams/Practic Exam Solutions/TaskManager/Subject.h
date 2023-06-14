#pragma once
#include "Observer.h"
#include <vector>

class Subject{
private:
	std::vector<Observer*> observers;

public:
	void notify();
	void addObserver(Observer* o);
};