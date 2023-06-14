#include "controller.h"
#include<assert.h>
#include<stdio.h>
void domainTests(){
	Medicine* m1, * m2;
	m1 = medicineConstructor("abc", (float)80.41, 4, (float)14.2);
	m2 = medicineConstructor("abc", (float)80.41, 2, (float)14);
	assert(medicineEqual(m1, m2) == 1);
	assert(strcmp(medicineGetName(m1), "abc") == 0);
	medicineSetQuantity(m1, 5);
	assert(m1->quantity == 5);
	medicineDeconstructor(m1);
	medicineDeconstructor(m2);
}

void vectorTests(){
	Vector* v = vectorConstructor(10);
	assert(v->capacity == 10 && v->size == 0);

	//test add element
	Medicine* m1;
	m1 = medicineConstructor("abc", (float)80.41, 4, (float)14.2);

	vectorAddElem(v, m1);
	assert(v->size == 1);
	assert(medicineEqual(m1, v->elems[0]) == 1);

	assert(vectorSearchElem(v, m1, medicineEqual) != -1);
	
	vectorDeletePosition(v, 0);

	assert(vectorSearchElem(v, m1, medicineEqual) == -1);

	assert(v->size == 0);
	
	vectorDestructor(v);
}


void historyTests(){
	Vector* v1 = vectorConstructor(10);
	Vector* v2 = vectorConstructor(10);
	History* h = historyConstructor(10);

	//add tests
	historyAdd(h, v1);
	historyAdd(h, v2);
	assert(h->size == 2);
	
	//redo test
	assert(redo(h, &v1) == -1);

	//undo test
	assert(undo(h, &v2) == 1);

	//redo test
	assert(redo(h, &v1) == 1);

	historyDeconstructor(h);
	vectorDestructor(v1);
	vectorDestructor(v2);
}


void repositoryTests(){
	Repository* repo = repositoryConstructor(10);

	Medicine* m1;
	m1 = medicineConstructor("abc", (float)80.41, 4, (float)14.2);

	repositoryAdd(repo, m1);
	assert(repo->data->size == 1);
	assert((repo->data->elems[0]) == m1);

	//test update
	repositoryUpdate(repo, m1, 2, 10);
	assert(repo->data->elems[0]->quantity == 2);
	
	//test remove
	repositoryRemove(repo, m1);
	repositoryRemove(repo, m1);
	assert(repo->data->size == 0);
	
	repositoryDestructor(repo);
}


void controllerTests(){
	Repository* repo = repositoryConstructor(10);
	Medicine* m1, *m2;
	m1 = medicineConstructor("abc", (float)80.41, 4, (float)14.2);
	m2 = medicineConstructor("abd", (float)80.21, 10, (float)14.2);
	repositoryAdd(repo, m1);
	repositoryAdd(repo, m2);
	Controller* controller = controllerConstructor(repo);
	
	Vector* v1 = controllerFilterNameContainingSubstring(controller, "ab");
	assert(v1->size == 2);
	vectorDestructor(v1);
	
	Vector* v2 = controllerFilterQuantityLessThanX(controller, 5);
	assert(v2->size == 1);
	vectorDestructor(v2);

	controllerDestructor(controller);
}


void runTests(){
	domainTests();
	vectorTests();
	historyTests();
	repositoryTests();
	controllerTests();
}