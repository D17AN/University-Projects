#include "DevelopWindow.h"

DevelopWindow::DevelopWindow(Idea& _idea, QWidget* parent) : 
	QWidget{parent}, ui(new Ui::DevelopWindowClass), idea{_idea}{
	this->ui->setupUi(this);
	this->connectSignalsAndSlots();
	this->ui->textEdit->setText(QString::fromStdString(idea.getDescription()));
}

DevelopWindow::~DevelopWindow(){
	delete ui;
}

void DevelopWindow::connectSignalsAndSlots(){
	QObject::connect(this->ui->pushButtonSave, &QPushButton::clicked, this, &DevelopWindow::save);
}

void DevelopWindow::save(){
	std::string path = QFileDialog::getSaveFileName().toStdString();
	std::fstream fout{path, std::ios::out | std::ios::trunc};
	fout << this->ui->textEdit->toPlainText().toStdString();
}
