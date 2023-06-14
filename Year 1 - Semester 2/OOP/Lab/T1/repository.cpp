#include "repository.h"

Repository::Repository(){}

Repository::Repository(std::vector<Protein>& _v) : v{_v} {}

void Repository::add(const Protein& p)
{
	if (search(p) != -1){
		throw std::exception("Protein already exists!");
	}
	v.push_back(p);
}

void Repository::remove(const Protein& p)
{
	int pos = search(p);
	if (pos == -1){
		throw std::exception("Protein not found!");
	}
	auto it = std::remove_if(v.begin(), v.end(), [&p](const Protein& p1) {
		return p1 == p; 
		});
	v.erase(it, v.end());
}

int Repository::search(const Protein& p)
{
	auto it = std::find(v.begin(), v.end(), p);
	if (it == v.end())
		return -1;
	return it - v.begin();
}

std::vector<Protein>& Repository::getAll()
{
	return this->v;
}
