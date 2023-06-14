#pragma once

#include "service.h"

class UI{
private:
	Service& s;
	void printMenu();
	void addCarUI();
	void displayCars(const std::vector<Car>& v);

public:
	UI(Service& _s) : s{ _s } {};
	void run();
	~UI();
};