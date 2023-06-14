#include "repository.h"

void Repository::addBill(const Bill& bill)
{
	auto it = std::find(bills.begin(), bills.end(), bill);
	if (it != bills.end())
		throw std::exception("Bill already exists!");
	bills.push_back(bill);
}

void Repository::deleteBill(const Bill& bill)
{
	auto it = std::find(bills.begin(), bills.end(), bill);
	if (it == bills.end())
		throw std::exception("Bill does not exist!");
	bills.erase(it);
}

std::vector<Bill>& Repository::getAll()
{
	return this->bills;
}
