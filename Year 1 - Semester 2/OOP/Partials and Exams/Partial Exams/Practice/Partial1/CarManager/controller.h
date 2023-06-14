#pragma once
#include "repository.h"


class Controller{
private:
	Repository& repo;
public:
	Controller(Repository& repo) : repo{repo}{}
	const std::vector<Car>& get()const;
	void add(const Car& c);
	void remove(const Car& c);
	const std::vector<Car> getSortedByManufacturerAndModel();
	const std::vector<Car> getVintageCars();
};