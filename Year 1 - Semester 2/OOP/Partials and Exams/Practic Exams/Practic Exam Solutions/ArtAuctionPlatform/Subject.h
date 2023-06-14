#pragma once
#include "Observer.h"
#include <vector>
using namespace std;

class Subject
{
	vector<Observer*> observers;
public:
	void notify();
	void addObserver(Observer* o);
};