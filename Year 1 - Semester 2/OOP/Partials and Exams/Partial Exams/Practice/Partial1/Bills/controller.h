#pragma once
#include "repository.h"

class Controller
{
private:
	Repository& repo;

public:
	Controller(Repository& repo) : repo{ repo } {}

	void addBill(const Bill& bill);

	/*
	* Deletes a bill from the repository.
	* @param bill - the bill to be deleted.
	* Throws an exception if the bill does not exist.
	*/
	void deleteBill(const Bill& bill);
	
	/*
	* Calculates the total unpaid bills
	* @return - double the total unpaid bills.
	*/
	double getTotalUnpaidBills();

	
	const std::vector<Bill>& getAll()const;


	std::vector<Bill> getAllUnpaidSortedByDate();

};