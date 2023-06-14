#pragma once

#include <QMessageBox>
#include <QtWidgets/QWidget>

#include "Users.h"
#include "Service.h"
#include "Observer.h"
#include "ui_UserWindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class UserWindowClass; }
QT_END_NAMESPACE

class UserWindow : public QWidget, public Observer {
    Q_OBJECT

public:
    explicit UserWindow(Service& srv, Users& u, QWidget* parent = nullptr);

    ~UserWindow() override;
    void update() override;
    void connect();

    void add_subscription();
    void add_post();
    void update_post();
private:
    Ui::UserWindowClass* ui;
    Service& srv;
    Users& user;
};
