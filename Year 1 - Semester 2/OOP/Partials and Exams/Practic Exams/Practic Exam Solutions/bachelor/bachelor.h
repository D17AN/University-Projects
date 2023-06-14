#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_bachelor.h"
#include "StudentRepo.h"
#include "QtStudentInfo.h"

class bachelor : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    bachelor(StudentRepo* r, std::string teachName, QWidget *parent = nullptr);
    ~bachelor();
    void update() override;
    

private:
    Ui::bachelorClass ui;
    StudentRepo* repo;
    std::string TeacherName;
    void populate();

public slots:
    void search();
    void addStudent();
    void editStudentInfo();
};
