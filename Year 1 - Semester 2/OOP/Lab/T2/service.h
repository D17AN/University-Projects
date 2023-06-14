#pragma once
#include "domain.h"

class Car{
private:
	int nrDoors;
	Engine* engine;

public:
	Car(int nDoors, Engine* engine) : nrDoors{ nDoors }, engine{ engine } {};
	double computePrice() const;
	std::string toString() const;
};


class Service {
private:
	std::vector<Car> cars;

public:
	Service(std::vector<Car>& _cars) : cars{ _cars } {};
	std::vector<Car>& getCars() { return this->cars; };
	void addCar(int nrDoors, const std::string& engineType, int autonomy);
	~Service(){};
};