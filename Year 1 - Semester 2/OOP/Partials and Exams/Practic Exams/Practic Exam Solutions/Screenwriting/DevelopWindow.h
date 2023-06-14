#pragma once
#include <QtWidgets/QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include "ui_DevelopWindow.h"
#include "TableModel.h"
#include "Idea.h"
#include <exception>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class DevelopWindowClass; }
QT_END_NAMESPACE


class DevelopWindow : public QWidget{
	Q_OBJECT
	
public:
	DevelopWindow(Idea& _idea, QWidget* parent = nullptr);
	~DevelopWindow();

private:
	Ui::DevelopWindowClass* ui;
	Idea& idea;

	void connectSignalsAndSlots();
	void save();
};