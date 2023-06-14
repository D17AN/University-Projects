#pragma once
#include "controller.h"
#include <iostream>

class UI{
private:
	Controller& cntr;

	void menu();
	void display(const std::vector<Player>& v);
	void add();
	void displayByTeam();

public:
	UI(Controller& cntr);
	void run();
};