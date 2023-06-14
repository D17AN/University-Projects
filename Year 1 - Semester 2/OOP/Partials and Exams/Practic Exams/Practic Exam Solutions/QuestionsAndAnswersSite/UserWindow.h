#pragma once

#include <QtWidgets/QWidget>
#include <QMessageBox>
#include "ui_UserWindow.h"
#include "Controller.h"
#include "User.h"
#include "Observer.h"
#include "Utils.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UserWindowClass; };
QT_END_NAMESPACE

class UserWindow : public QWidget, public Observer{
    Q_OBJECT

public:
    UserWindow(Controller& _c, User& _u, QWidget *parent = nullptr);
    ~UserWindow();
    void update()override;
    
private:
    Ui::UserWindowClass *ui;
    Controller& c;
    User& u;

private:
    void connectSignalsAndSlots();
    
    void addQuestion();
    void addAnswer();
    void showAnswers();
    void upvote();
    void changeVotes();
};
