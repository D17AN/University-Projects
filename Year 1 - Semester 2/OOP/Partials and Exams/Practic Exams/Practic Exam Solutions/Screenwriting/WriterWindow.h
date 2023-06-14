#pragma once

#include <QtWidgets/QWidget>
#include <QMessageBox>
#include "ui_WriterWindow.h"
#include "DevelopWindow.h"
#include "TableModel.h"
#include "Writer.h"
#include <exception>

QT_BEGIN_NAMESPACE
namespace Ui { class WriterWindowClass; };
QT_END_NAMESPACE

class WriterWindow : public QWidget
{
    Q_OBJECT

public:
    WriterWindow(IdeasController& _c, Writer& _w, TableModel* _tableModel, QWidget *parent = nullptr);
    ~WriterWindow();

private:
    Ui::WriterWindowClass *ui;
    IdeasController& c;
    Writer& writer;
    TableModel* model;

private:
    void connectSignalsAndSlots();
    
    void addIdea();
    void acceptIdea();
    void savePlot();
    void developIdea();
};
