#pragma once
#include "TasksRepository.h"
#include <assert.h>

class Tests{
public:
	static void runTest();

private:
	static void testRemoveTask();
	static void testUpdateTask();
};