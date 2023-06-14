#include "main.h"

int main(int argc, char *argv[])
{
    Tests::runTests();
    QApplication a(argc, argv);
    IdeasRepository ideasRepo{"Ideas.txt"};
    WritersRepository writersRepo{"Writers.txt"};
    IdeasController ideasController{ideasRepo};
    TableModel tableModel{ideasController};

    std::vector<Writer> writers = writersRepo.getAll();
    for (Writer& writer : writers){
        WriterWindow* w = new WriterWindow{ideasController, writer, &tableModel};
        w->show();
    }
    return a.exec();
}
