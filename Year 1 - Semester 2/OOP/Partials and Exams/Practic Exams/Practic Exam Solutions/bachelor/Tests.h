#pragma once
#include "StudentRepo.h"
#include <assert.h>


void test_addCoord()
{
	StudentRepo repo("tests.txt");
	Student s("5");
	repo.addStudent(s);
	repo.changeStudentCoord(s.toString(), "test");
	assert(repo.getStudents().back().getCoordinator() == "test");
}

void test_search()
{
	StudentRepo repo("tests.txt");
	std::vector<Student> list = repo.searchStudent("5");
	assert(list[0].getTitle() == "No title");
}

void test_all()
{
	test_addCoord();
	test_search();
}