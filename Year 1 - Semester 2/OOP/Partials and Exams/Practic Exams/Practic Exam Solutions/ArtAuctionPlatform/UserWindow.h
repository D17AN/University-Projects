#pragma once

#include <QtWidgets/QWidget>
#include "ui_UserWindow.h"
#include "Controller.h"
#include "User.h"
#include "Observer.h"
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class UserWindowClass; };
QT_END_NAMESPACE

class UserWindow : public QWidget, public Observer
{
    Q_OBJECT

public:
    UserWindow(Controller& ctrl, User& u, QWidget *parent = nullptr);
    ~UserWindow();

    void update() override;

private:
    Ui::UserWindowClass *ui;
    Controller& ctrl;
    User& user;

    void connectSignalsAndSlots();
    void handleComboBox();
    void handleAddItem();
};
