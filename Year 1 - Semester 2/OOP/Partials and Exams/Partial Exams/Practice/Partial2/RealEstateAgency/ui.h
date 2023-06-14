#pragma once
#include "service.h"
#include<iostream>
#include <exception>
class UI{
private:
	RealEstateAgency& c;
	
	void printMenu();
	void updateClient();
	void showAll();
	void addDwelling();
	
	
public:
	UI(RealEstateAgency& _c) : c{_c} {}
	void run();
	~UI();
};