#pragma once

#include "Controller.h"
#include <assert.h>

class Tests{
public:
	static void runTests();

private:
	static void testAddQuestion();
	static void testUpdateParticipantScore();
};