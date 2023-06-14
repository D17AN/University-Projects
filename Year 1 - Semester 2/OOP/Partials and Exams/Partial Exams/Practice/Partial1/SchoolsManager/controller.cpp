#include "controller.h"

void Controller::addSchool(const School& school)
{
	return this->repository.addSchool(school);
}

void Controller::deleteSchool(const School& school)
{
	return this->repository.deleteSchool(school);
}

const std::vector<School>& Controller::getAll() const
{
	return this->repository.getAll();
}

const std::vector<School> Controller::getAllUnvisitedAfterDate(Date date)
{
	std::vector<School>& v = this->repository.getAll();
	std::vector<School> res;
	std::for_each(v.begin(), v.end(), [&date, &res](School& s) {
		if (s.getDate() < date && s.getVisited() == false)
			s.setVisited(true);
		else if (s.getDate() > date && s.getVisited() == false)
			res.push_back(s);
		});
	return res;
}
