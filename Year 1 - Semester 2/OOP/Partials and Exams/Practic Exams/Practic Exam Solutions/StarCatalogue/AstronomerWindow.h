#pragma once

#include <QtWidgets/QWidget>
#include "ui_AstronomerWindow.h"
#include "Service.h"
#include "ARepo.h"
#include "MyTable.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AstronomerWindowClass; };
QT_END_NAMESPACE


class AstronomerWindow : public QWidget, public Observer {
    Q_OBJECT

public:
    explicit AstronomerWindow(Service& srv, Astronomer& a, QWidget* parent = nullptr);

    ~AstronomerWindow() override;


    void connect();
    void add_star();
    void update() override;
    void view();
private:
    Ui::AstronomerWindowClass* ui;
    Service& srv;
    Astronomer ast;
    MyTable* model;
};
