#include "service.h"

Service::Service(std::vector<Building*>& _v)
{
	this->v = _v;
}

void Service::addBuilding(Building* b)
{
	this->v.push_back(b);
}

std::vector<Building*>& Service::getAllBuildings() 
{
	return this->v;
}

std::vector<Building*> Service::getAllToBeRestored(int year)
{
	std::vector<Building*> res;
	std::for_each(this->v.begin(), this->v.end(), [&](Building* b){
		if (b->mustBeRestored() && b->getConstructionYear() <= year){
			res.push_back(b);
		}
		});
	return res;
}

std::vector<Building*> Service::getAllToBeDemolished()
{
	std::vector<Building*> res;
	std::for_each(this->v.begin(), this->v.end(), [&](Building* b){
		if (b->canBeDemolished()){
			res.push_back(b);
		}
		});
	return res;
}

void Service::writeToFile(const std::string& fileName, const std::vector<Building*>& v)
{
	std::fstream fout{fileName, std::ios::out | std::ios::trunc};
	std::for_each(v.begin(), v.end(), [&](Building* b){
		fout << b->toString() << "\n";
		});
	fout.close();
}



Service::~Service()
{
}
