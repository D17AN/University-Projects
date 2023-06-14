#include "SearchWindow.h"

SearchWindow::SearchWindow(Controller& _c, QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::SearchWindowClass())
    , c{_c}
{
    ui->setupUi(this);
    this->c.addObserver(this);
    this->connectSignalsAndSlots();
}

SearchWindow::~SearchWindow(){
    delete ui;
}

void SearchWindow::update(){
    this->textChanged();
}

void SearchWindow::connectSignalsAndSlots(){
    QObject::connect(this->ui->lineEditSearch, &QLineEdit::textChanged, this, &SearchWindow::textChanged);
}

void SearchWindow::textChanged(){
    this->ui->listWidgetResults->clear();
    std::string text = this->ui->lineEditSearch->text().toStdString();
    Utils::formatSentence(text);
    std::vector<Question> questions = this->c.getAllQuestionsMatchingText(text);
    for (const Question& q : questions){
        this->ui->listWidgetResults->addItem(QString::fromStdString(q.toString()));
        std::vector<Answer> answers = this->c.getAllAnswersToQuestion(q.getId());
        int n = 0;
        for (const Answer& a : answers){
            this->ui->listWidgetResults->addItem(QString::fromStdString("   - " + a.toString()));
            n++;
            if (n == 3){
                break;
            }
        }
    }
}
