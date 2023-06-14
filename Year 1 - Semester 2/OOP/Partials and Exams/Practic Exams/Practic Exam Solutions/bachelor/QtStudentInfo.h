#pragma once

#include <QMainWindow>
#include "ui_QtStudentInfo.h"
#include "StudentRepo.h"

class QtStudentInfo : public QMainWindow
{
	Q_OBJECT

public:
	QtStudentInfo(StudentRepo* r, Student& s, QWidget *parent = nullptr);
	~QtStudentInfo();

private:
	Ui::QtStudentInfoClass ui;
	StudentRepo* repo;
	Student student;
	void populate();
public slots:
	void save();
	void cancel();
};
