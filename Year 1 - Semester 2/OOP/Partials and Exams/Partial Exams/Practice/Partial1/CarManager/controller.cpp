#include "controller.h"

const std::vector<Car>& Controller::get() const{
	return this->repo.get();
}

void Controller::add(const Car& c){
	this->repo.add(c);
}

void Controller::remove(const Car& c){
	this->repo.remove(c);
}

const std::vector<Car> Controller::getSortedByManufacturerAndModel()
{
	std::vector<Car> res;
	const std::vector<Car>& v = this->repo.get();
	std::copy(v.begin(), v.end(), std::back_inserter(res));
	std::sort(res.begin(), res.end(), [](const Car& c1, const Car& c2){
		return c1.getName() < c2.getName() || (c1.getName() == c2.getName() && c1.getModel() < c2.getModel());
		});
	return res;
}

const std::vector<Car> Controller::getVintageCars(){
	const std::vector<Car>& v = this->repo.get();
	std::vector<Car> res;
	std::copy_if(v.begin(), v.end(), std::back_inserter(res), [](const Car& c){
		return 2023 - c.getYear() + 1 >= 45;
		});
	std::sort(res.begin(), res.end(), [](const Car& c1, const Car& c2){
		return c1.getColour() < c2.getColour();
		});
	return res;
}


