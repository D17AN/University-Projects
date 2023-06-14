#include "TasksRepository.h"

TasksRepository::TasksRepository(const std::string& _fileName) : fileName{_fileName}{
	this->readFromFile();
}

void TasksRepository::addTask(const Task& t){
	this->tasks.push_back(t);
}

void TasksRepository::removeTask(const Task& t){
	auto startDeletePosition = std::remove_if(this->tasks.begin(), this->tasks.end(), [&t](const Task& other){
		return t.getDescription() == other.getDescription() && t.getStatus() == other.getStatus() &&
			t.getProgrammerId() == other.getProgrammerId();
		});
	if (startDeletePosition == this->tasks.end()){
		throw std::exception("The task doesn't exist!");
	}
	this->tasks.erase(startDeletePosition, this->tasks.end());
}

void TasksRepository::updateTask(const Task& t, const std::string& newStatus, const int& newProgrammerId){
	auto pos = std::find_if(this->tasks.begin(), this->tasks.end(), [&t](const Task& other){
		return t.getDescription() == other.getDescription() && t.getStatus() == other.getStatus() &&
			t.getProgrammerId() == other.getProgrammerId();
		});
	
	if (pos == this->tasks.end()){
		throw std::exception("The task to be updated doesn't exist!");
	}
	
	int index = pos - this->tasks.begin(); // get the position of the task relative to the beginning

	this->tasks[index].setStatus(newStatus);
	this->tasks[index].setProgrammerId(newProgrammerId);
}

std::vector<Task>& TasksRepository::getAll(){
	return this->tasks;
}

void TasksRepository::readFromFile(){
	std::fstream fin{this->fileName, std::ios::in};
	Task t;
	while (fin >> t){
		if (t.getDescription() == "")// if the data of the programmer wasn't read, it's not added
			continue;
		this->tasks.push_back(t);
	}
	fin.close();
}

void TasksRepository::saveToFile(){
	std::fstream fout{this->fileName, std::ios::out | std::ios::trunc};
	for (const Task& t : this->tasks){
		fout << t << "\n";
	}
}

TasksRepository::~TasksRepository(){
	this->saveToFile();
}
