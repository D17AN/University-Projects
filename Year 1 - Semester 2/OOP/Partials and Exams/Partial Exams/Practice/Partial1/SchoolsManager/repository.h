#pragma once
#include "domain.h"
#include<vector>
#include<algorithm>
#include<exception>

class Repository{
private:
	std::vector<School> schools;

public:
	Repository();
	void addSchool(const School& school);
	void deleteSchool(const School& school);
	std::vector<School>& getAll();
};