#pragma once

#include "controller.h"
#include <iostream>

class UI{
private:
	Controller& controller;

public:
	UI(Controller& controller);
	void run();

	void addSchool();
	void deleteSchool();
	void getAllUnvisitedAfterDate();
	void printAll(const std::vector<School>& v);

	void printMenu();

};