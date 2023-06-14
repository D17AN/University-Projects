#pragma once
#include<vector>
#include "domain.h"
#include <algorithm>
#include <exception>
class Repository{
private:
	std::vector<Car> v;

public:
	const std::vector<Car>& get()const;
	int search(const Car& c);
	void add(const Car& c);
	void remove(const Car& c);
};