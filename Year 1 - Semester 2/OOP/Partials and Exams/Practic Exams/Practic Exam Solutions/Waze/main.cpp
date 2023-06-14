#include <QtWidgets/QApplication>
#include "repo.h"
#include "Report.h"
#include "Driver.h"
#include "DriverWindow.h"
#include "cont.h"
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo;
    Controller cont(repo);
    vector<DriverWindow*> windows;

    for (auto &d : repo.getDrivers())
    {
        auto window = new DriverWindow(cont, d);
        windows.push_back(window);
        window->show();
    }
    return a.exec();
}
