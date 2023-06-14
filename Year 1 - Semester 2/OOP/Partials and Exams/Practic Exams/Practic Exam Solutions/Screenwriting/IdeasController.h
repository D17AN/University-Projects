#pragma once

#include "IdeasRepository.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

class IdeasController{
private:
	IdeasRepository& ideasRepo;

public:
	IdeasController(IdeasRepository& _ideasRepo);
	
	std::vector<Idea> getAll()const;

	std::vector<Idea> getAllAcceptedOfWriter(const std::string& name);

	/*
	* Add an idea to the repository
	* Input:
	*	- i: Idea, the idea to be added
	* Output:
	*	The repository contains all the elements from before and the given idea
	* Exceptions:
	*	- if the description is empty, an exception is thrown
	*	- if the act is not 1, 2, or 3, an exception is thrown
	*	- if an idea with the same act and description already exists, an exception is thrown
	*/
	void addIdea(const Idea& i);

	/*
	* Update idea status
	* Input:
	*	- i: Idea, the idea to be updated
	*	- newStatus: the new status of the idea
	* Output:
	*	The idea from the repository has had its status updated with the new status
	* Exceptions:
	*	- if the idea doesn't exists, an exception is thrown
	*	- if the idea status is not proposed, an exception is thrown
	*/
	void updateIdeaStatus(const Idea& i, const std::string newStatus);

	void saveToFileAcceptedIdeas(const std::string& fileName);

	~IdeasController();

};
