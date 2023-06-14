#include "TasksController.h"

TasksController::TasksController(TasksRepository& _tasksRepo) : tasksRepo{_tasksRepo}, Subject(){
}

std::vector<Task> TasksController::getAll(){
	std::vector<Task>& tasks = this->tasksRepo.getAll();
	std::vector<Task> res;
	std::copy(tasks.begin(), tasks.end(), std::back_inserter(res));
	std::sort(res.begin(), res.end(), [](const Task& t1, const Task& t2){
		return t1.getStatus() < t2.getStatus();
		});
	return res;
}

void TasksController::addTask(const Task& t){
	this->tasksRepo.addTask(t);
	this->notify();
}

void TasksController::removeTask(const Task& t){
	this->tasksRepo.removeTask(t);
	this->notify();
}

void TasksController::updateTask(const Task& t, const std::string& newStatus, const int& newProgrammerId){
	this->tasksRepo.updateTask(t, newStatus, newProgrammerId);
	this->notify();
}

TasksController::~TasksController(){
}
