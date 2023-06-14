#pragma once

#include "domain.h"
#include <vector>
#include <algorithm>
#include <fstream>

class Service{
private:
	std::vector<Building*> v;

public:
	Service(std::vector<Building*>& _v);
	void addBuilding(Building* b);
	std::vector<Building*>& getAllBuildings();
	std::vector<Building*> getAllToBeRestored(int year);
	std::vector<Building*> getAllToBeDemolished();
	static void writeToFile(const std::string& fileName, const std::vector<Building*>& v);
	~Service();
};