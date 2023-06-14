#include "UserWindow.h"
#include <QtWidgets/QApplication>
#include "UserRepo.h"
#include "ItemsRepository.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserRepo userRepo;
    ItemsRepository itemsRepo;
    Controller ctrl(itemsRepo);
    
    for (User& u : userRepo.getUsers()){
        UserWindow* w = new UserWindow(ctrl, u);
        w->show();
    }

    
    return a.exec();
}
