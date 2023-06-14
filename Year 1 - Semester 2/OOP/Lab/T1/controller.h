#pragma once
#include "repository.h"

class Controller{
private:
	Repository& repo;
public:
	Controller(Repository& _repo);

	/*
	* Add protein to  repository
	* Input: p - Protein
	* Output: the protein is added to the repository
	* Throws: exception if the protein already exists
	*/
	void add(const Protein& p);
	void remove(const Protein& p);
    const std::vector<Protein>& getAll() const;

	/*
	* Show organism with the given name sorted by organism
	* Input: name - string
	* Output: the proteins with the given name sorted by organism
	*/
	std::vector<Protein> getByName(const std::string& _name) const;
};