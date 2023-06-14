#pragma once

#pragma once

#include <QtWidgets/QWidget>
#include <QMessageBox>
#include "ui_PresenterWindow.h"
#include "Controller.h"
#include "Observer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PresenterWindowClass; };
QT_END_NAMESPACE

class PresenterWindow : public QWidget, Observer
{
    Q_OBJECT

public:
    PresenterWindow(Controller& _c, QWidget* parent = nullptr);
    ~PresenterWindow();
    
    void update()override;

private:
    Ui::PresenterWindowClass* ui;
    Controller& c;

    void connectSignalsAndSlots();
    void handleAddQuestion();
};
