#include "UserWindow.h"

UserWindow::UserWindow(Controller& _c, User& _u, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserWindowClass())
    , c{_c}
    , u{_u}
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString(this->u.getName()));
    this->c.addObserver(this);
    this->update();
    this->connectSignalsAndSlots();
    this->ui->pushButtonAddAnswer->setDisabled(true);
    this->ui->spinBox->setDisabled(true);
}

UserWindow::~UserWindow(){
    delete ui;
}

void UserWindow::update(){
    if (this->ui->listWidgetQuestions->selectedItems().empty() == false){
        this->showAnswers();
    }
    this->ui->listWidgetQuestions->clear();
    for (const Question& question : this->c.getAllQuestions()){
        this->ui->listWidgetQuestions->addItem(QString::fromStdString(question.toString()));
    }
}

void UserWindow::connectSignalsAndSlots(){
    //in order the spinbox to work you need to select both an item from questionsList and answersList
    QObject::connect(this->ui->pushButtonAddQuestion, &QPushButton::clicked, this, &UserWindow::addQuestion);
    QObject::connect(this->ui->listWidgetQuestions, &QListWidget::itemClicked, this, &UserWindow::showAnswers);
    QObject::connect(this->ui->pushButtonAddAnswer, &QPushButton::clicked, this, &UserWindow::addAnswer);
    QObject::connect(this->ui->listWidgetAnswers, &QListWidget::itemClicked, this, &UserWindow::upvote);
    QObject::connect(this->ui->spinBox, &QSpinBox::valueChanged, this, &UserWindow::changeVotes);
}

void UserWindow::addQuestion(){
    std::string questionText = this->ui->lineEditQuestionText->text().toStdString();
    Utils::formatSentence(questionText);
    try{
        this->c.addQuestion(questionText, this->u.getName());
    }
    catch (std::exception& e){
        QMessageBox errorBox;
        errorBox.setText(e.what());
        errorBox.exec();
    }
}

void UserWindow::addAnswer(){
    std::string answerText = this->ui->lineEditAnswerText->text().toStdString();
    Utils::formatSentence(answerText);
    std::string line = this->ui->listWidgetQuestions->selectedItems()[0]->text().toStdString();
    std::vector<std::string> tokens = Utils::tokenize(line, '|');
    int questionId = std::stoi(tokens[0]);
    try{
        this->c.addAnswer(questionId, this->u.getName(), answerText);
    }
    catch (std::exception& e){
        QMessageBox errorBox;
        errorBox.setText(e.what());
        errorBox.exec();
    }
}

void UserWindow::showAnswers(){
    this->ui->listWidgetAnswers->clear();
    if (this->ui->listWidgetQuestions->selectedItems().empty()){
        return;
    }
    std::string line = this->ui->listWidgetQuestions->selectedItems()[0]->text().toStdString();
    std::vector<std::string> tokens = Utils::tokenize(line, '|');
    int questionId = std::stoi(tokens[0]);
    std::vector<Answer> answersToQuestion = this->c.getAllAnswersToQuestion(questionId);
    for (const Answer& answer : answersToQuestion){
        this->ui->listWidgetAnswers->addItem(QString::fromStdString(answer.toString()));
        if (answer.getCreator() == this->u.getName()){
            this->ui->listWidgetAnswers->item(this->ui->listWidgetAnswers->count() - 1)->setBackground(Qt::yellow);
        }
    }
    this->ui->pushButtonAddAnswer->setDisabled(false);
}

void UserWindow::upvote(){
    this->ui->spinBox->setDisabled(false);
    if (this->ui->listWidgetAnswers->selectedItems().empty()){
        return;
    }
    std::string line = this->ui->listWidgetAnswers->selectedItems()[0]->text().toStdString();
    std::vector<std::string> tokens = Utils::tokenize(line, '|');
    
    std::string creator = tokens[2];
    int nrVotes = std::stoi(tokens[4]);
    
    if (this->u.getName() == creator){
        this->ui->spinBox->setDisabled(true);
        return;
    }

    this->ui->spinBox->setValue(nrVotes);
}

void UserWindow::changeVotes(){
    int nrVotes = this->ui->spinBox->value();
    if (this->ui->listWidgetAnswers->selectedItems().empty()){
        return;
    }
    std::string line = this->ui->listWidgetAnswers->selectedItems()[0]->text().toStdString();
    std::vector<std::string> tokens = Utils::tokenize(line, '|');
    int answerId = std::stoi(tokens[0]);
    try{
        this->c.updateVotesAnswer(answerId, nrVotes);
    }
    catch (std::exception& e){
        QMessageBox errorBox;
        errorBox.setText(e.what());
        errorBox.exec();
    }
}
