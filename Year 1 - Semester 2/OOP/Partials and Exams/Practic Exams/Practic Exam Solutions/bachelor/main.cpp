#include "bachelor.h"
#include <QtWidgets/QApplication>
#include "TeacherRepo.h"
#include "StudentRepo.h"
#include "Tests.h"
int main(int argc, char *argv[])
{
    test_all();
    QApplication a(argc, argv);
    TeacherRepo t_repo("teachers.txt");
    StudentRepo s_repo("students.txt");
    
    for(auto x:t_repo.getTeachers())
    {
        bachelor* w = new bachelor(&s_repo, x.getName());
        w->setWindowTitle(QString::fromStdString(x.getName()));
        w->show();
    }

    return a.exec();
}
