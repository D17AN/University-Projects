#pragma once
#include "domain.h"

class Repository
{
private:
	std::vector<Protein> v;

public:
	Repository();
	Repository(std::vector<Protein>& _v);

	/*
	* Add protein to  repository
	* Input: p - Protein
	* Output: the protein is added to the repository
	* Throws: exception if the protein already exists
	*/
	void add(const Protein& p);
	void remove(const Protein& p);
	int search(const Protein& p);
	std::vector<Protein>& getAll();
};