#pragma once

#include "TasksRepository.h"
#include "Subject.h"
#include <vector>
#include <algorithm>
#include <iterator>

class TasksController : public Subject{
private:
	TasksRepository& tasksRepo;

public:
	TasksController(TasksRepository& _tasksRepo);

	std::vector<Task> getAll();
	void addTask(const Task& t);
	void removeTask(const Task& t);
	void updateTask(const Task& t, const std::string& newStatus, const int& newProgrammerId);
	~TasksController();
};