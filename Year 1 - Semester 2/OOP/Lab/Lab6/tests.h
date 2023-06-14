#pragma once
#include <assert.h>
#include "utils.h"
#include "domain.h"
#include "repository.h"
#include "controller.h"
#include "basket.h"
#include <sstream>
#include <vector>
#include <string>
#include <string.h>


class UtilsTest{
public:
	void runTests();
private:
	void testTokenize();
	void testFormatSentece();
};


class TrenchCoatTests{
public:
	void runTests();

private:
	void testCopyConstructor();
	void testGetSize();
	void testGetColor();
	void testGetPrice();
	void testGetQuantity();
	void testGetPhotographLink();
	void testSetPrice();
	void testSetQuantity();
	void testEqualityOperator();
	void testInequalityOperator();
	void testAssignmentOperator();
	void testInsertionOperator();
	void testExtractionOperator();
};


class TrenchCoatValidationTests{
public:
	void runTests();

private:
	void testIsSizeValid();
	void testIsColorValid();
	void testIsPriceValid();
	void testIsQuantityValid();
	void testIsPhotographLinkValid();
};


class RepositoryTests{
public:
	void runTests();

private:
	void testLoadFromFileConstructor();
	void testCopyConstructor();
	void testAdd();
	void testRemove();
	void testUpdate();
};


class BasketTests{
public:
	void runTests();

private:
	void testAdd();
	void testGet();
	void testTotal();
};



class Test{
public:
	void runTests();
};


class ControllerAdministratorTests{
public:
	void runTests();
private:
	void testAdd();
	void testRemove();
	void testUpdate();
};


class ControllerUserTests{
public:
	void runTests();
private:
	void testAddToBasket();
	void testGetRepo();
	void testGetBasket();
	void testGetBasketTotal();
};