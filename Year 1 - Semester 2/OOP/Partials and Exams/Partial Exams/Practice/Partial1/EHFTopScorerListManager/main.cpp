#include "ui.h"
#include "Tests.h"
int main(){
	Test t;
	t.run();
	Repository repo;
	Controller c{repo};
	UI ui{c};
	ui.run();
	return 0;
}