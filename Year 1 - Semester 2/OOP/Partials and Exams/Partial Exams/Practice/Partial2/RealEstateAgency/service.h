#pragma once
#include "domain.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <exception>
class RealEstateAgency{
private:
	std::vector<Client*> clients;
	std::vector<Dwelling> dwellings;

public:
	RealEstateAgency(std::vector<Client*>& _clients, std::vector<Dwelling>& _dwellings) : clients{_clients}, dwellings{_dwellings} {}
	Dwelling addDwelling(const double& price, const bool& isProfitable);
	void updateClient(std::string& name, double& newIncome);
	std::vector<Client*> getInterestedClients(const Dwelling& d)const;
	std::vector<Client*> getClients()const{ return this->clients; }
	std::vector<Dwelling> getDwellings()const{ return this->dwellings; }
	void writeToFile(const std::string& fileName)const;
	~RealEstateAgency();
};