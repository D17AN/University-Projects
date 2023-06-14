#include "ui.h"

int main()
{
	Repository repo;
	Controller ctrl(repo);
	UI ui(ctrl);
	ui.run();
	return 0;
}