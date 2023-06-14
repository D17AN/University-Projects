#pragma once
#include "domain.h"
#include <vector>
#include <algorithm>
#include <exception>
class Repository
{
private:
	std::vector<Bill> bills;

public:
	void addBill(const Bill& bill);
	void deleteBill(const Bill& bill);
	
	std::vector<Bill>& getAll();
};