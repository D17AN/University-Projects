#include "service.h"

double Car::computePrice() const
{
	if (this->nrDoors == 2){
		return 7000 + this->engine->getPrice();
	}
	else return 8500 + this->engine->getPrice();
}

std::string Car::toString() const
{
	return std::to_string(this->nrDoors) + "|" + this->engine->toString();
}

void Service::addCar(int nrDoors, const std::string& engineType, int autonomy)
{
	if (engineType == "electric"){
		Engine* engine = new ElectricEngine(3000, autonomy);
		Car c{nrDoors, engine};
		this->cars.push_back(c);
	}
	else if (engineType == "turbo"){
		Engine* engine = new TurboEngine(3000);
		Car c{nrDoors, engine};
		this->cars.push_back(c);
	}
	else{
		throw std::exception("Engine type doesn't exists!\n");
	}
}
