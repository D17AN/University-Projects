#include "DriverWindow.h"
#include <sstream>
DriverWindow::DriverWindow(Controller& cont, Driver& d, QWidget* parent)
	: cont(cont), d(d), QWidget(parent)
{
	this->cont.addObserver(this);
	this->initGUI();
	this->connectSignals();
}

void DriverWindow::initGUI()
{
	this->setWindowTitle(this->d.getName().c_str());
	mainLayout = new QVBoxLayout(this);
	driverInfoLabel = new QLabel(this->d.toString().c_str(), this);
	mainLayout->addWidget(driverInfoLabel);
	reportsListWidget = new QListWidget(this);
	mainLayout->addWidget(reportsListWidget);

	addReportFormLayout = new QFormLayout(this);
	descritpionLabel = new QLabel("Description:", this);
	latitudeLabel = new QLabel("Latitude:", this);
	longitudeLabel = new QLabel("Longitude:", this);
	descriptionLineEdit = new QLineEdit(this);
	latitudeLineEdit = new QLineEdit(this);
	longitudeLineEdit = new QLineEdit(this);
	addReportFormLayout->addRow(descritpionLabel, descriptionLineEdit);
	addReportFormLayout->addRow(latitudeLabel, latitudeLineEdit);
	addReportFormLayout->addRow(longitudeLabel, longitudeLineEdit);
	mainLayout->addItem(addReportFormLayout);
	addButton = new QPushButton("Add", this);
	mainLayout->addWidget(addButton);
	validateButton = new QPushButton("Validate", this);
	mainLayout->addWidget(validateButton);
	driverSlider = new QSlider(this);
	driverSlider->setValue(10);
	mainLayout->addWidget(driverSlider);
	QGridLayout* buttonsLayout = new QGridLayout(this);
	northButton = new QPushButton("North", this);
	southButton = new QPushButton("South", this);
	eastButton = new QPushButton("East", this);
	westButton = new QPushButton("West", this);
	buttonsLayout->addWidget(northButton, 0, 1);
	buttonsLayout->addWidget(westButton, 0, 2);
	buttonsLayout->addWidget(eastButton, 0, 3);
	buttonsLayout->addWidget(southButton, 0, 4);
	mainLayout->addItem(buttonsLayout);
	this->update();
	if (this->d.getStatus() == "baby")
	{
		this->setStyleSheet("background-color: white;");
	}
	if (this->d.getStatus() == "knight")
	{
		this->setStyleSheet("background-color: lightgray;");
	}
	if (this->d.getStatus() == "grown-up")
	{
		this->setStyleSheet("background-color: gray;");
	}
	
}

void DriverWindow::connectSignals()
{
	QObject::connect(addButton, &QPushButton::clicked, this, &DriverWindow::handleAdd);
	QObject::connect(validateButton, &QPushButton::clicked, this, &DriverWindow::handleValidate);
	QObject::connect(reportsListWidget, &QListWidget::itemSelectionChanged, this, &DriverWindow::handleSelectionChanged);
	QObject::connect(driverSlider, &QSlider::valueChanged, this, &DriverWindow::handleSliderChanged);
	QObject::connect(northButton, &QPushButton::clicked, this, &DriverWindow::handleNorth);
	QObject::connect(southButton, &QPushButton::clicked, this, &DriverWindow::handleSouth);
	QObject::connect(eastButton, &QPushButton::clicked, this, &DriverWindow::handleEast);
	QObject::connect(westButton, &QPushButton::clicked, this, &DriverWindow::handleWest);
}

void DriverWindow::updateReports()
{
	vector<Report> reports = this->cont.getReportsInRadius(this->d.getLatitude(), this->d.getLongitude(),10);
	this->reportsListWidget->clear();
	for (Report r : reports)
	{
		auto item = new QListWidgetItem(r.toString().c_str());
		this->reportsListWidget->addItem(item);
	}

	if (this->d.getScore() > 10 && this->d.getScore() < 15)
	{
		this->d.setStatus("grown-up");
		this->setStyleSheet("background-color: gray;");
	}
	if (this->d.getScore() > 15)
	{
		this->d.setStatus("knight");
		this->setStyleSheet("background-color: lightgray;");
	}

	this->driverInfoLabel->setText(this->d.toString().c_str());
}

void DriverWindow::update()
{
	this->updateReports();
}

void DriverWindow::handleAdd()
{
	string description = this->descriptionLineEdit->text().toStdString();
	string latitude = this->latitudeLineEdit->text().toStdString();
	string longitude = this->longitudeLineEdit->text().toStdString();
	if (description.size() > 0 && latitude.size() > 0 && longitude.size() > 0)
	{
		stringstream s;
		s << description << ";" << d.getName() << ";" << latitude << ";" << longitude << ";" << 0 << ";" << 0;
		Report r;
		s >> r;
		try
		{
			this->cont.addReport(r, this->d);
			descriptionLineEdit->clear();
			latitudeLineEdit->clear();
			longitudeLineEdit->clear();
		}
		catch (exception& ex)
		{
			QMessageBox::information(this, "Error", ex.what(), QMessageBox::Ok);
		}
	}
	else
	{
		QMessageBox::information(this, "Error", "Empty fields", QMessageBox::Ok);
	}
}

void DriverWindow::handleValidate()
{
	string obj = this->reportsListWidget->currentItem()->text().toStdString();
	stringstream s{ obj };
	Report r;
	s >> r;
	if (r.getReporter() != this->d.getName())
	{
		this->cont.increaseReportVotes(r);
		if (r.getVotes() + 1 == 2)
		{
			this->cont.validateReport(r);
			string driver = r.getReporter();
			this->cont.increaseDriverScore(driver);
			QMessageBox::information(this, "ok", "validated report", QMessageBox::Ok);
			
		}
	}
}

void DriverWindow::handleSelectionChanged()
{
	string obj = this->reportsListWidget->currentItem()->text().toStdString();
	stringstream s{ obj };
	Report r;
	s >> r;
	if (r.getReporter() == this->d.getName())
	{
		validateButton->setDisabled(true);
	}
	else
	{
		validateButton->setDisabled(false);
	}

}

void DriverWindow::handleSliderChanged()
{
	int value = this->driverSlider->value();
	vector<Report> reports = this->cont.getReportsInRadius(this->d.getLatitude(), this->d.getLongitude(),value);
	this->reportsListWidget->clear();
	for (Report r : reports)
	{
		auto item = new QListWidgetItem(r.toString().c_str());
		this->reportsListWidget->addItem(item);
	}
}

void DriverWindow::handleNorth()
{
	this->cont.moveDriverNorth(this->d);
}

void DriverWindow::handleSouth()
{
	this->cont.moveDriverSouth(this->d);
}

void DriverWindow::handleEast()
{
	this->cont.moveDriverEast(this->d);
}

void DriverWindow::handleWest()
{
	this->cont.moveDriverWest(this->d);
}
