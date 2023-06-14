#include <QApplication>
#include <QPushButton>
#include "AstronomerWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    AstronomersRepository arepo{};
    StarsRepository srepo{};
    Service srv(srepo);

    for(auto& a: arepo.getAll()){
        auto GUI = new AstronomerWindow(srv,a);
        GUI->show();
    }

    return QApplication::exec();
}
