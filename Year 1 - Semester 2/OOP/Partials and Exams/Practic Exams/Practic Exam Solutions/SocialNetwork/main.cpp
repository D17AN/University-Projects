#include <QApplication>
#include <QPushButton>
#include "Urepo.h"
#include "UserWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    PRepo prepo{};
    TRepo trepo{};
    Urepo urepo{};
    Service srv(trepo, prepo);

    for(auto& u:urepo.get_all()){
        auto GUI = new UserWindow(srv, u);
        GUI->show();
    }

    return QApplication::exec();
}
