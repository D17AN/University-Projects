#include "ProgrammerWindow.h"
#include <QtWidgets/QApplication>
#include "TasksController.h"
#include "ProgrammersRepository.h"
#include "Tests.h"

int main(int argc, char *argv[])
{
    Tests::runTest();
    QApplication a(argc, argv);
    ProgrammersRepository programmersRepo{"Programmers.txt"};
    TasksRepository tasksRepo{"Tasks.txt"};
    TasksController c{tasksRepo};

    for (Programmer& p : programmersRepo.getAll()){
        ProgrammerWindow* g = new ProgrammerWindow(c, p);
        g->show();
    }
    return a.exec();
}
