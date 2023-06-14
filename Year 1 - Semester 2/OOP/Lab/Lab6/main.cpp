#include "tests.h"
#include "ui.h"
int main() {
	Test().runTests();

	Repository repo("repositoryInit.txt");
	Basket basket;
	ControllerAdministrator controllerAdministrator{repo};
	ControllerUser controllerUser{repo, basket};
	
	UI ui{controllerAdministrator, controllerUser};
	ui.runProgram();
	
	return 0;
}