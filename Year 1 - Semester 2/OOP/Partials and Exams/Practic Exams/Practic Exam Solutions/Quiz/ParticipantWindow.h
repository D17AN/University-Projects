#pragma once

#include <QtWidgets/QWidget>
#include <QMessageBox>
#include "ui_ParticipantWindow.h"
#include "Controller.h"
#include "Observer.h"
#include "Participant.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ParticipantWindowClass; };
QT_END_NAMESPACE

class ParticipantWindow : public QWidget, Observer
{
    Q_OBJECT

public:
    ParticipantWindow(Controller& _c, Participant& _p, QWidget *parent = nullptr);
    ~ParticipantWindow();
    void update()override;

private:
    Ui::ParticipantWindowClass *ui;
    Controller& c;
    Participant& p;
    std::vector<int> answeredQuestionsId;

    void connectSignalsAndSlots();
    void handleClickItem();
    void handleAddAnswer();

};
