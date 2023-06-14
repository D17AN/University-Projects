#define _CRTDBG_MAP_ALLOC
#include "ui.h"
#include<crtdbg.h>
#include "test.h"
int main(int argc, char* argv[]){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//runTests();
	
	Repository* repo = repositoryConstructor();
	Controller* controller = controllerConstructor(repo);
	UI* ui = uiConstructor(controller);
	History* h = historyConstructor(10);

	uiInit(ui);
	uiRunProgram(ui, h);
	uiDeconstructor(ui);
	historyDeconstructor(h);
	_CrtDumpMemoryLeaks();
	
	return 0;
}