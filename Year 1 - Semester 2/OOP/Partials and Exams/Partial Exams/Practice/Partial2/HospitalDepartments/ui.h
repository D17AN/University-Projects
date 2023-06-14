#pragma once

#include "service.h"

class UI{
private:
	Service& c;
	void printMenu();
	void printMenuHospitalDepartment();
	void addHospitalDepartment();
	void addNeonatalUnit();
	void addSurgery();
	void display(const std::vector<HospitalDepartment*>& v);

public:
	UI(Service& _c) : c{_c} {}
	void run();
	~UI();
};