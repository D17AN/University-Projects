#pragma once

#include "service.h"
#include <iostream>
#include <exception>
class UI{
private:
	Service& c;

	void printMenu();
	void printAddBuildingMenu();
	void addBuilding();
	void addBlock();
	void addHouse();
	void displayBuildings(std::vector<Building*>& v);
	void displayRestoredBuildings();
	void saveToFile();

public:
	UI(Service& _c) : c{_c} {}
	void run();
	~UI();

};
