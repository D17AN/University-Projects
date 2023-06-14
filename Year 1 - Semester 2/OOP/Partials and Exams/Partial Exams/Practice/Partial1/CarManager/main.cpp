#include "ui.h"

int main(){
	Repository repo;
	Controller c{repo};
	UI ui{c};
	ui.run();
	return 0;
}