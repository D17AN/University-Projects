#pragma once
#include "controller.h"
#include "assert.h"
class Tests
{
private:
	static void testAdd();
	static void testGetByName();
	
public:
	static void runTests();
};