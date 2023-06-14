#include "QtStudentInfo.h"

QtStudentInfo::QtStudentInfo(StudentRepo* r, Student &s, QWidget *parent)
	: repo(r), student(s), QMainWindow(parent)
{
	ui.setupUi(this);
	populate();
}

QtStudentInfo::~QtStudentInfo()
{}

void QtStudentInfo::populate()
{
	this->ui.label_7->setText(QString::fromStdString(student.getId()));
	this->ui.label_8->setText(QString::fromStdString(student.getName()));
	this->ui.lineEdit_3->setText(QString::fromStdString(student.getEmail()));
	this->ui.label_9->setText(QString::number(student.getYear()));
	this->ui.lineEdit_5->setText(QString::fromStdString(student.getTitle()));
	this->ui.label_10->setText(QString::fromStdString(student.getCoordinator()));
}

void QtStudentInfo::save()
{
	student.setEmail(this->ui.lineEdit_3->text().toStdString());
	student.setTitle(this->ui.lineEdit_5->text().toStdString());
	this->repo->updateStudent(this->student);
	this->destroy();
}

void QtStudentInfo::cancel()
{
	this->destroy();
}


