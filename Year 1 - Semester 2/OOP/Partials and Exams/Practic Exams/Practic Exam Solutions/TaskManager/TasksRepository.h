#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <exception>
#include "Task.h"

class TasksRepository{
private:
	std::vector<Task> tasks;
	std::string fileName;

public:
	TasksRepository(const std::string& _fileName);

	void addTask(const Task& t);

	/*
	* Remove task from repository
	* Input:
	*	- t: Task, the task to be removed.
	* Output:
	*	The repository no longer contains object t.
	* Exceptions:
	*	If t doesn't exist an exception is thrown.
	*/
	void removeTask(const Task& t);

	/*
	* Update a task from repository
	* Input:
	*	- t: Task, the task to be updated.
	* Output:
	*	The repository contains the new version of object t.
	* Exceptions:
	*	If t doesn't exist an exception is thrown.
	*/
	void updateTask(const Task& t, const std::string& newStatus, const int& newProgrammerId);

	std::vector<Task>& getAll();
	void readFromFile();
	void saveToFile();

	~TasksRepository();
};

