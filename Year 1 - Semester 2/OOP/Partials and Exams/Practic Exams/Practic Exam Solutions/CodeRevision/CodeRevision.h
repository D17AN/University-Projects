#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ProgrammersRepository.h"
#include "Controller.h"
#include "utils.h"
#include "ui_CodeRevision.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class CodeRevisionClass;
}
QT_END_NAMESPACE


class CodeRevisionGUI : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    CodeRevisionGUI(Controller& _c, Programmer& _programmer, QMainWindow *parent = nullptr);
    ~CodeRevisionGUI();

    void connectSignalAndSlots();

    void addSourceFile();
    void selectSourceFile();
    void revise();

    void update()override;

private:
    Ui::CodeRevisionClass* ui;
    Controller& c;
    Programmer& programmer;
};
