#pragma once
#include "cont.h"
#include <qwidget.h>
#include "Observer.h"
#include "qlayout.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qlistwidget.h"
#include "qformlayout.h"
#include "qlineedit.h"
#include "qmessagebox.h"
#include "qslider.h"

class DriverWindow : public QWidget, public Observer {

private:
	Controller &cont;
	Driver &d;
public:
	DriverWindow(Controller &cont, Driver& d, QWidget *parent  = nullptr);
private:
	QVBoxLayout* mainLayout;
	QLabel* driverInfoLabel;
	QListWidget* reportsListWidget;
	QFormLayout* addReportFormLayout;
	QLabel* descritpionLabel;
	QLabel* latitudeLabel;
	QLabel* longitudeLabel;
	QLineEdit* descriptionLineEdit;
	QLineEdit* latitudeLineEdit;
	QLineEdit* longitudeLineEdit;
	QPushButton* addButton;
	QPushButton* validateButton;
	QSlider* driverSlider;
	QPushButton* northButton;
	QPushButton* southButton;
	QPushButton* eastButton;
	QPushButton* westButton;

	void initGUI();
	void connectSignals();
	void updateReports();
public:
	void update() override;
private slots:
	void handleAdd();
	void handleValidate();
	void handleSelectionChanged();
	void handleSliderChanged();
	void handleNorth();
	void handleSouth();
	void handleEast();
	void handleWest();
};