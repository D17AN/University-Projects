#include "MainWindow.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Repository repo("repositoryInit.txt");

	Basket* basket = nullptr;

	ControllerAdministrator controllerAdministrator{repo};
	ControllerUser controllerUser{repo, basket};

	MainWindow w{controllerAdministrator, controllerUser};
	w.setWindowTitle("Start");
	w.show();

	return a.exec();
}