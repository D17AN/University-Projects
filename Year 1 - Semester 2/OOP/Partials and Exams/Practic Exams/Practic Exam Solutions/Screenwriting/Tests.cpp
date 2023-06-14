#include "Tests.h"

void Tests::runTests(){
	Tests::testAddIdea();
	Tests::testUpdateIdeaStatus();
}

void Tests::testAddIdea(){
	IdeasRepository repo;
	IdeasController c{repo};
	assert(c.getAll().size() == 0);
	Idea t1;
	try{
		c.addIdea(t1);
		assert(false);
	}
	catch (...){
		assert(true);
	}
	assert(c.getAll().size() == 0);

	t1.setDescription("idea1");
	try{
		c.addIdea(t1);
		assert(false);
	}
	catch (...){
		assert(true);
	}
	assert(c.getAll().size() == 0);
	t1.setAct(1);

	c.addIdea(t1);
	assert(c.getAll().size() == 1);
	
	try{
		c.addIdea(t1);
		assert(false);
	}
	catch (...){
		assert(true);
	}

	assert(c.getAll().size() == 1);

}

void Tests::testUpdateIdeaStatus(){
	IdeasRepository repo;
	IdeasController c{repo};
	assert(c.getAll().size() == 0);
	Idea t1{"idea1", "proposed", "andrei", 1};
	c.addIdea(t1);
	c.updateIdeaStatus(t1, "accepted");
	try{
		c.updateIdeaStatus(t1, "accepted");
		assert(false);
	}
	catch (...){
		assert(true);
	}
}
