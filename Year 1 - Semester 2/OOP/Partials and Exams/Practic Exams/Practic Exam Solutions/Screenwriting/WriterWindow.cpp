#include "WriterWindow.h"

WriterWindow::WriterWindow(IdeasController& _c, Writer& _w, TableModel* _tableModel, QWidget* parent)
    : QWidget(parent), ui(new Ui::WriterWindowClass()), c{_c}, writer{_w}, model{_tableModel}{
    ui->setupUi(this);
    this->ui->tableViewIdeas->setModel(model);
    this->ui->tableViewIdeas->show();
    this->setWindowTitle(QString::fromStdString(this->writer.getName()));
    if (this->writer.getExpertise() != "senior"){
        this->ui->pushButtonAccept->setDisabled(true);
    }
    this->connectSignalsAndSlots();
}

WriterWindow::~WriterWindow(){
    delete ui;
}

void WriterWindow::connectSignalsAndSlots(){
    QObject::connect(this->ui->pushButtonAdd, &QPushButton::clicked, this, &WriterWindow::addIdea);
    QObject::connect(this->ui->pushButtonAccept, &QPushButton::clicked, this, &WriterWindow::acceptIdea);
    QObject::connect(this->ui->pushButtonSavePlot, &QPushButton::clicked, this, &WriterWindow::savePlot);
    QObject::connect(this->ui->pushButtonDevelop, &QPushButton::clicked, this, &WriterWindow::developIdea);
}

void WriterWindow::addIdea(){
    std::string description = this->ui->lineEditDescription->text().toStdString();
    Utils::formatSentence(description);
    int act = this->ui->lineEditAct->text().toInt();
    try{
        Idea idea{description, "proposed", this->writer.getName(), act};
        this->model->addIdea(idea);
        this->ui->tableViewIdeas->resizeColumnsToContents();
    }
    catch (std::exception& e){
        QMessageBox errorBox;
        errorBox.setText(QString::fromStdString(e.what()));
        errorBox.exec();
    }
}

void WriterWindow::acceptIdea(){
    std::string description = this->ui->lineEditDescription->text().toStdString();
    Utils::formatSentence(description);
    int act = this->ui->lineEditAct->text().toInt();
    try{
        Idea idea{description, "", "", act};
        this->model->acceptIdea(idea, "accepted");
        this->ui->tableViewIdeas->resizeColumnsToContents();
    }
    catch (std::exception& e){
        QMessageBox errorBox;
        errorBox.setText(QString::fromStdString(e.what()));
        errorBox.exec();
    }
}

void WriterWindow::savePlot(){
    this->c.saveToFileAcceptedIdeas("AcceptedIdeas.txt");
    QMessageBox box;
    box.setText("The ideas were added.");
    box.exec();
}

void WriterWindow::developIdea(){
    std::vector<Idea> ideas = this->c.getAllAcceptedOfWriter(this->writer.getName());
    if (ideas.size() == 0){
        QMessageBox box;
        box.setText("You must to have at least 1 accepted idea.\n");
        box.exec();
        return;
    }
    for (Idea& i : ideas){
        DevelopWindow* dv = new DevelopWindow{i};
        dv->show();
    }
}
