#pragma once
#include <vector>
using namespace std;
class Observer {
public:
	virtual void update() = 0;
};

class Subject {
private:
	vector<Observer*> observers;
public:
	void addObserver(Observer* o)
	{
		this->observers.push_back(o);
	}
	void notify()
	{
		for (auto o : this->observers)
		{
			o->update();
		}
	}
};