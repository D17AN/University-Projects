#include "CodeRevision.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProgrammersRepository programmersRepo("Programmers.txt");
    SourceFilesRepository sourceFilesRepo("SourceFiles.txt");
    Controller c{sourceFilesRepo};
    
    for (Programmer& p : programmersRepo.getAll()){
        CodeRevisionGUI* g = new CodeRevisionGUI(c, p);
        g->show();
    }
    return a.exec();
}
