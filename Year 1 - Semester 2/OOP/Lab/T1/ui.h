#pragma once
#include "controller.h"

class UI{
private:
	Controller& c;
	
	void printMenu();
	void addProtein();
	void removeProtein();
	void displayProteins(const std::vector<Protein>& v);
	void displayProteinsByName();

public:
	UI(Controller& _c) : c{ _c } {}
	void run();
};