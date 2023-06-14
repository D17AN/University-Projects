#include "bachelor.h"

bachelor::bachelor(StudentRepo* r, std::string teachName, QWidget* parent)
    : repo(r), TeacherName(teachName), QMainWindow(parent)
{
    ui.setupUi(this);
    repo->addObserver(this);
    populate();
}

bachelor::~bachelor()
{}

void bachelor::update()
{
    this->populate();
}

void bachelor::populate()
{
    this->ui.listWidget->clear();
    this->ui.listWidget_2->clear();
    for (auto& s : repo->getStudents())
        if (s.getCoordinator() == TeacherName)
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(s.toString()), this->ui.listWidget);
    for (auto& s : repo->getStudents())
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(s.toString()), this->ui.listWidget_2);
    
}


void bachelor::search()
{
    std::string str = this->ui.lineEdit->text().toStdString();
    this->ui.listWidget_2->clear();
    for(auto& s: this->repo->searchStudent(str))
           QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(s.toString()), this->ui.listWidget_2);

}

void bachelor::addStudent()
{
    QListWidgetItem* it = this->ui.listWidget_2->currentItem();
    std::string str = it->text().toStdString();
    this->repo->changeStudentCoord(str, TeacherName);
    populate();
}

void bachelor::editStudentInfo()
{
    QListWidgetItem* it = this->ui.listWidget->currentItem();
    std::string str = it->text().toStdString();
    for(auto& s: this->repo->getStudents())
        if (s.toString() == str)
        {
            QtStudentInfo* w = new QtStudentInfo(this->repo, s);
            w->show();
        }
}
