#include "repository.h"

Repository::Repository()
{
}

void Repository::addSchool(const School& school)
{
	auto it = std::find(this->schools.begin(), this->schools.end(), school);
	if (it != this->schools.end())
		throw std::exception("School already exists!");
	this->schools.push_back(school);
}

void Repository::deleteSchool(const School& school)
{
	auto it = std::find(this->schools.begin(), this->schools.end(), school);

	if (it == this->schools.end())
		throw std::exception("School not found!");

	this->schools.erase(it);
}

std::vector<School>& Repository::getAll()
{
	return this->schools;
}
