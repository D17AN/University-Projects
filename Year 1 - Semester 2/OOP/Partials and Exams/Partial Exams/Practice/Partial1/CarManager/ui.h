#pragma once
#include "controller.h"
#include <iostream>
class UI{
private:
	Controller& cntr;

public:
	UI(Controller& cntr);
	void display(const std::vector<Car>& v);
	void add();
	void remove();
	void menu();
	void run();
};