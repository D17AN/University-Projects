#pragma once
#include "controller.h"
#include <iostream>
class UI{
private:
	Controller& ctrl;
	void printMenu();
	void addBillUI();
	void deleteBillUI();
	void displayAllUI(const std::vector<Bill>& v);

public:
	UI(Controller& c);
	void run();
};