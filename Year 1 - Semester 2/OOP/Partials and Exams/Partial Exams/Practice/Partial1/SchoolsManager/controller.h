#pragma once
#include "repository.h"

class Controller{
private:
	Repository& repository;

public:
	Controller(Repository& repository) : repository{ repository } {}
	void addSchool(const School& school);

	/*
	* Deletes a school from the repository
	* @param school - the school to be deleted
	* @throws std::exception if the school does not exist
	* @return void	
	*/
	void deleteSchool(const School& school);

	const std::vector<School>& getAll()const;

	/*
	* Returns all the schools that have not been visited after a given date and marks those before the date as visited
	* @param date - the date
	* @return a vector of schools which have not been visited after the given date
	*/
	const std::vector<School> getAllUnvisitedAfterDate(Date date);

};