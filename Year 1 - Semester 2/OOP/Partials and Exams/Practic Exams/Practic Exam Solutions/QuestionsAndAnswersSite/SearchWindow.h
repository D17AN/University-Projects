#pragma once

#include <QtWidgets/QWidget>
#include <QMessageBox>
#include "ui_SearchWindow.h"
#include "Controller.h"
#include "Observer.h"
#include "Utils.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SearchWindowClass; };
QT_END_NAMESPACE

class SearchWindow : public QWidget, Observer
{
    Q_OBJECT

public:
    SearchWindow(Controller& _c, QWidget* parent = nullptr);
    ~SearchWindow();
    void update()override;

private:
    void connectSignalsAndSlots();
    void textChanged();

private:
    Ui::SearchWindowClass* ui;
    Controller& c;

};