#pragma once

#include <QtWidgets/QWidget>
#include "ui_ProgrammerWindow.h"
#include "Programmer.h"
#include "TasksController.h"
#include <QMessageBox.h>
#include "CustomException.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ProgrammerWindowClass; };
QT_END_NAMESPACE

class ProgrammerWindow : public QWidget, Observer{
    Q_OBJECT

public:
    ProgrammerWindow(TasksController& _c, Programmer& _programmer, QWidget *parent = nullptr);
    void update()override;
    ~ProgrammerWindow();
    
private:
    void addTask();
    void deleteTask();
    void startTask();
    void doneTask();
    void connectSignalsAndSlots();
    void selectTask();
     
private:
    Ui::ProgrammerWindowClass *ui;
    Programmer& programmer;
    TasksController& c;
};
