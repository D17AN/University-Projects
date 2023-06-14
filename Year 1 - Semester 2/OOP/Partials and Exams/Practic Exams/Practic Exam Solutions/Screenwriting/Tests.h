#pragma once
#include "IdeasController.h"
#include <assert.h>

class Tests{
public:
	static void runTests();
private:
	static void testAddIdea();
	static void testUpdateIdeaStatus();
};