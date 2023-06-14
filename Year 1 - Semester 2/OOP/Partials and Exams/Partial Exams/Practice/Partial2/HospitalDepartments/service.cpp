#include "service.h"

Service::Service(std::vector<HospitalDepartment*>& _v) : v{_v}
{
}

void Service::addDepartment(HospitalDepartment* h)
{
	this->v.push_back(h);
}

std::vector<HospitalDepartment*>& Service::getAllDepartments()
{
	return this->v;
}

std::vector<HospitalDepartment*> Service::getAllEfficientDepartments() const
{
	std::vector<HospitalDepartment*> res;
	std::copy_if(this->v.begin(), this->v.end(), std::back_inserter(res), [&](HospitalDepartment* h){
		if (h->isEfficient())
			return true;
		return false;
		});
	return res;
}

void Service::writeToFile(const std::string& fileName)
{
	std::fstream g{fileName, std::ios::out | std::ios::trunc};
	std::for_each(this->v.begin(), this->v.end(), [&](HospitalDepartment* h){
		g << h->toString() << "\n";
		});
	g.close();
}

Service::~Service()
{
}
