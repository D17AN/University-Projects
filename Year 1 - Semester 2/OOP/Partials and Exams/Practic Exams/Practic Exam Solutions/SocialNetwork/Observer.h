#pragma once
#include <vector>

class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer() {}
};

class Observable
{
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* o);
    void notify_all_observables();
};
