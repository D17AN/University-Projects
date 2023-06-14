#include "PresenterWindow.h"
#include <cstdlib>
#include <ctime>
#include <random>

PresenterWindow::PresenterWindow(Controller& _c, QWidget* parent) :
	QWidget(parent), ui(new Ui::PresenterWindowClass()), c{_c}{
	ui->setupUi(this);
	this->setWindowTitle(QString::fromStdString("Presenter"));
	this->c.addObserver(this);
	this->connectSignalsAndSlots();

	this->update();
}

PresenterWindow::~PresenterWindow(){
	delete ui;
}

void PresenterWindow::update(){
	this->ui->listWidgetQuestions->clear();
	std::vector<Question> questions = this->c.getAllSortedById();
	for (const Question& q : questions){
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(q.toString()));
		this->ui->listWidgetQuestions->addItem(item);
	}
}

void PresenterWindow::connectSignalsAndSlots(){
	QObject::connect(this->ui->pushButtonAddQuestion, &QPushButton::clicked, this, &PresenterWindow::handleAddQuestion);
}

void PresenterWindow::handleAddQuestion(){
	std::string text, answer;
	int id;
	try{
		std::string auxId = this->ui->lineEditId->text().toStdString();
		text = this->ui->lineEditText->text().toStdString();
		answer = this->ui->lineEditAnswer->text().toStdString();
		Utils::formatSentence(auxId);
		Utils::formatSentence(text);
		Utils::formatSentence(answer);
		id = std::stoi(auxId);
	}
	catch (std::exception& e){
		QMessageBox errorBox;
		errorBox.setText(e.what());
		errorBox.exec();
		return;
	}
	
	try{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
		int score = std::rand() % 100 + 1;
		this->c.addQuestion(id, text, answer, score);

	}
	catch (std::exception& e){
		QMessageBox errorBox;
		errorBox.setText(e.what());
		errorBox.exec();
		return;
	}
}
