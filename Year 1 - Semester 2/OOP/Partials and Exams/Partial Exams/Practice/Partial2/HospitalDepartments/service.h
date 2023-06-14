#pragma once
#include "domain.h"

class Service{
private:
	std::vector<HospitalDepartment*> v;

public:
	Service(std::vector<HospitalDepartment*>& _v);
	void addDepartment(HospitalDepartment* h);
	std::vector<HospitalDepartment*>& getAllDepartments();
	std::vector<HospitalDepartment*> getAllEfficientDepartments()const;
	void writeToFile(const std::string& fileName);
	~Service();
};