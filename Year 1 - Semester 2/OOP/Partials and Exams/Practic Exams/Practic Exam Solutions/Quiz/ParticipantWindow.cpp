#include "ParticipantWindow.h"

ParticipantWindow::ParticipantWindow(Controller& _c, Participant& _p, QWidget *parent)
    : QWidget(parent), ui(new Ui::ParticipantWindowClass()), c{_c}, p{_p}{
    ui->setupUi(this);
    this->c.addObserver(this);
    this->setWindowTitle(QString::fromStdString(this->p.getName()));
    this->connectSignalsAndSlots();
    this->ui->pushButtonAnswer->setDisabled(true);
    this->ui->labelValueScore->setText(QString::fromStdString(std::to_string(this->p.getScore())));
    this->update();
}

ParticipantWindow::~ParticipantWindow(){
    delete ui;
}

void ParticipantWindow::update(){
    this->ui->listWidgetQuestions->clear();
    std::vector<Question> questions = this->c.getAllSortedByScore();
    for (const Question& q : questions){
        auto text = QString::fromStdString(std::to_string(q.getId()) + "|" +
            q.getText() + "|" + std::to_string(q.getScore()));
        QListWidgetItem* item = new QListWidgetItem(text);

        int qid = q.getId();
        //check if the question is answered
        auto pos = std::find_if(this->answeredQuestionsId.begin(), this->answeredQuestionsId.end(), 
            [&qid](int questionId){
                return qid == questionId;
            });
        
        if (pos != this->answeredQuestionsId.end()){
            item->setBackground(Qt::green);
        }

        this->ui->listWidgetQuestions->addItem(item);
    }
}

void ParticipantWindow::connectSignalsAndSlots(){
    QObject::connect(this->ui->listWidgetQuestions, &QListWidget::itemClicked, this, &ParticipantWindow::handleClickItem);
    QObject::connect(this->ui->pushButtonAnswer, &QPushButton::clicked, this, &ParticipantWindow::handleAddAnswer);
}

void ParticipantWindow::handleClickItem()
{
    if (this->ui->listWidgetQuestions->selectedItems().empty()){
        this->ui->pushButtonAnswer->setDisabled(true);
        QMessageBox errorBox;
        errorBox.setText("Select a question!");
        errorBox.exec();
        return;
    }

    std::string line = this->ui->listWidgetQuestions->selectedItems()[0]->text().toStdString();
    std::vector<std::string> tokens = Utils::tokenize(line, '|');
    int qid = std::stoi(tokens[0]);
    //check if the question is already answered
    auto pos = std::find_if(this->answeredQuestionsId.begin(), this->answeredQuestionsId.end(),
        [&qid](int questionId){
            return qid == questionId;
        });

    if (pos != this->answeredQuestionsId.end()){
        this->ui->pushButtonAnswer->setDisabled(true);
        return;
    }
    
    this->ui->pushButtonAnswer->setDisabled(false);
}

void ParticipantWindow::handleAddAnswer(){
    
    if (this->ui->listWidgetQuestions->selectedItems().empty()){
        this->ui->pushButtonAnswer->setDisabled(true);
        QMessageBox errorBox;
        errorBox.setText("Select a question before answering!");
        errorBox.exec();
        return;
    }
    
    std::string line = this->ui->listWidgetQuestions->selectedItems()[0]->text().toStdString();
    std::vector<std::string> tokens = Utils::tokenize(line, '|');
    
    std::string possibleAnswer = this->ui->lineEditAnswer->text().toStdString();
    Utils::formatSentence(possibleAnswer);

    try{
        int qid = std::stoi(tokens[0]);
        int score = this->c.answerQuestion(qid, possibleAnswer);
        if (score != 0){
            this->answeredQuestionsId.push_back(qid);
        }
        this->p.setScore(p.getScore() + score);
        this->ui->labelValueScore->setText(QString::fromStdString(std::to_string(this->p.getScore())));
    }
    catch (std::exception& e){
        QMessageBox errorBox;
        errorBox.setText(e.what());
        errorBox.exec();
        return;
    }
    
    this->ui->pushButtonAnswer->setDisabled(true);
    this->update();
}
