#include "Tests.h"

void Tests::runTest(){
	Tests::testRemoveTask();
	Tests::testUpdateTask();
}

void Tests::testRemoveTask(){
	TasksRepository repo{"TestTasks.txt"};
	int originalSize = repo.getAll().size();
	
	Task t1{"task3", "open", 1};
	Task t2{"task4", "closed", 1};
	repo.addTask(t1);
	repo.addTask(t2);
	
	assert(originalSize == repo.getAll().size() - 2);
	repo.removeTask(t1);

	assert(repo.getAll().size() == originalSize + 1);
	
	try{
		repo.removeTask(t1);
		assert(false);
	}
	catch (...){
		assert(true);
	}
	repo.removeTask(t2);
}

void Tests::testUpdateTask(){
	TasksRepository repo{"TestTasks.txt"};

	int originalSize = repo.getAll().size();

	Task t1{"task3", "open", 1};
	Task t2{"task4", "closed", 1};
	repo.addTask(t1);
	repo.addTask(t2);

	assert(originalSize == repo.getAll().size() - 2);
	
	repo.updateTask(t1, "in_progress", 1);
	assert(repo.getAll()[originalSize].getStatus() == "in_progress");

	try{
		repo.updateTask(t1, "in_progress", 1);
		assert(false);
	}
	catch (...){
		assert(true);
	}
	t1.setStatus("in_progress");
	repo.removeTask(t1);
	repo.removeTask(t2);
}
