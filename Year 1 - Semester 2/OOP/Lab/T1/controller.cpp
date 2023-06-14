#include "controller.h"

Controller::Controller(Repository& _repo) : repo{_repo} {}

void Controller::add(const Protein& p)
{
	this->repo.add(p);
}

void Controller::remove(const Protein& p)
{
	this->repo.remove(p);
}

const std::vector<Protein>& Controller::getAll() const
{
	return this->repo.getAll();
}

std::vector<Protein> Controller::getByName(const std::string& _name) const
{
	const std::vector<Protein>& v = this->repo.getAll();
	std::vector<Protein> res;
	std::copy_if(v.begin(), v.end(), std::back_inserter(res), [&_name](const Protein& p) {
		return p.getName() == _name;
		});
	std::sort(res.begin(), res.end(), [](const Protein& p1, const Protein& p2) {
		return p1.getOrganism() < p2.getOrganism();
		});
	return res;
}
