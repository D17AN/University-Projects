#include "ProgrammerWindow.h"

ProgrammerWindow::ProgrammerWindow(TasksController& _c, Programmer& _programmer, QWidget *parent)
    : QWidget(parent), ui(new Ui::ProgrammerWindowClass()), programmer{_programmer}, c{_c}
{
    ui->setupUi(this);
    this->c.addObserver(this);
    this->update();
    this->connectSignalsAndSlots();
    this->setWindowTitle(QString::fromStdString(
        this->programmer.getName() + " " + std::to_string(this->programmer.getId())));
    this->ui->buttonStart->setDisabled(true);
    this->ui->buttonDone->setDisabled(true);
    this->ui->buttonDelete->setDisabled(true);
}

void ProgrammerWindow::update(){
    this->ui->listWidgetTasks->clear();
    std::vector<Task> tasks = this->c.getAll();
    for (const Task& t : tasks){
        auto item = new QListWidgetItem(QString::fromStdString(t.toString()));
        this->ui->listWidgetTasks->addItem(item);
    }
}

ProgrammerWindow::~ProgrammerWindow(){
    delete ui;
}

void ProgrammerWindow::addTask(){
    std::string description = this->ui->lineEditDescription->text().toStdString();
    Utils::formatSentence(description);
    if (description == ""){
        QMessageBox errorBox;
        errorBox.setText(QString::fromStdString("Enter a description!"));
        errorBox.exec();
        return;
    }
    std::string status = "open";
    int programmerId = this->programmer.getId();
    Task t{description, status, programmerId};
    this->c.addTask(t);
}

void ProgrammerWindow::deleteTask(){
    std::string line = this->ui->listWidgetTasks->selectedItems()[0]->text().toStdString();
    std::vector<std::string> tokens = Utils::tokenize(line, '|');
    std::string description, status;
    int programmerId;
    description = tokens[0];
    status = tokens[1];
    programmerId = std::stoi(tokens[2]);
    Task t{description, status, programmerId};
    
    try{
        this->c.removeTask(t);
    }
    catch (std::exception& e){
        QMessageBox errorBox;
        errorBox.setText(e.what());
        errorBox.exec();
    }
}

void ProgrammerWindow::startTask(){
    std::string line = this->ui->listWidgetTasks->selectedItems()[0]->text().toStdString();
    std::vector<std::string> tokens = Utils::tokenize(line, '|');
    std::string description, status;
    int programmerId;
    description = tokens[0];
    status = tokens[1];
    programmerId = std::stoi(tokens[2]);
    Task t{description, status, programmerId};

    try{
        if (t.getStatus() != "open"){
            throw MyException{"The file must be open to start the task!"};
        }
    }
    catch (MyException& e){
        QMessageBox errorBox;
        errorBox.setText(e.what());
        errorBox.exec();
        return;
    }

    try{
        this->c.updateTask(t, "in_progress", this->programmer.getId());
    }
    catch (std::exception& e){
        QMessageBox errorBox;
        errorBox.setText(e.what());
        errorBox.exec();
    }
}

void ProgrammerWindow::doneTask(){
    std::string line = this->ui->listWidgetTasks->selectedItems()[0]->text().toStdString();
    std::vector<std::string> tokens = Utils::tokenize(line, '|');
    std::string description, status;
    int programmerId;
    description = tokens[0];
    status = tokens[1];
    programmerId = std::stoi(tokens[2]);
    Task t{description, status, programmerId};

    try{
        this->c.updateTask(t, "closed", this->programmer.getId());
    }
    catch (std::exception& e){
        QMessageBox errorBox;
        errorBox.setText(e.what());
        errorBox.exec();
    }

}

void ProgrammerWindow::connectSignalsAndSlots()
{
    QObject::connect(this->ui->buttonAdd, &QPushButton::clicked, this, &ProgrammerWindow::addTask);
    QObject::connect(this->ui->buttonDelete, &QPushButton::clicked, this, &ProgrammerWindow::deleteTask);
    QObject::connect(this->ui->buttonStart, &QPushButton::clicked, this, &ProgrammerWindow::startTask);
    QObject::connect(this->ui->buttonDone, &QPushButton::clicked, this, &ProgrammerWindow::doneTask);
    QObject::connect(this->ui->listWidgetTasks, &QListWidget::itemClicked, this, &ProgrammerWindow::selectTask);
}

void ProgrammerWindow::selectTask(){
    this->ui->buttonDelete->setDisabled(false);
    this->ui->buttonStart->setDisabled(false);

    auto item = this->ui->listWidgetTasks->selectedItems()[0];
    std::string line = item->text().toStdString();
    std::vector<std::string> tokens = Utils::tokenize(line, '|');
    if (tokens[1] == "in_progress" && std::stoi(tokens[2]) == this->programmer.getId()){
        this->ui->buttonDone->setDisabled(false);
    }
    else{
        this->ui->buttonDone->setDisabled(true);
    }

    if (tokens[1] == "closed"){
        this->ui->buttonDone->setDisabled(true);
        this->ui->buttonStart->setDisabled(true);
    }
}
