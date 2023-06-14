#pragma once
#include "customexcpetion.h"
#include "controller.h"
#include "repository.h"
#include "domain.h"
#include "utils.h"
#include <iostream>
#include <cstdlib>
#define DEFAULT_BASKET_CSV "CSVBasket.csv"
#define DEFAULT_BASKET_HTML "HTMLBasket.html"

class UI{
private:
	ControllerAdministrator& controllerAdministrator;
	ControllerUser& controllerUser;
	bool mainIsRunning;
	bool administratorModeIsRunning;
	bool userModeIsRunning;

public:
	UI(ControllerAdministrator& a, ControllerUser& u);
	~UI();
	void runProgram();
	static void run();

private:
	void runAdministratorMode();
	void runUserMode();
	void runUserNavigationMode();
	static void displayStartingTextMenu();
	static void displayAdministratorTextMenu();
	static void displayUserTextMenu();
	static void displayUserNavigationCatalogMenu();
	static void displayTrenchCoats(std::vector<TrenchCoat>& v);
	void addAdministrator();
	void removeAdministrator();
	void updateAdministrator();
};