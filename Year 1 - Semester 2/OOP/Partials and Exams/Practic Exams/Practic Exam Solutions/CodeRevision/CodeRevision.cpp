#include "CodeRevision.h"

CodeRevisionGUI::CodeRevisionGUI(Controller& _c, Programmer& _programmer, QMainWindow* parent)
    : QMainWindow(parent), ui(new Ui::CodeRevisionClass), c{_c}, programmer{_programmer}
{
    ui->setupUi(this);
    this->update();
    this->setWindowTitle(QString::fromStdString(this->programmer.getName()));
    this->connectSignalAndSlots();
    this->c.addObserver(this);
    this->ui->buttonRevise->setDisabled(true);
}

CodeRevisionGUI::~CodeRevisionGUI(){
    delete this->ui;
}

void CodeRevisionGUI::connectSignalAndSlots()
{
    QObject::connect(this->ui->buttonAddSourceFile, &QPushButton::clicked, this, &CodeRevisionGUI::addSourceFile);
    QObject::connect(this->ui->listWidgetSourceFiles, &QListWidget::itemClicked, this, &CodeRevisionGUI::selectSourceFile);
    QObject::connect(this->ui->buttonRevise, &QPushButton::clicked, this, &CodeRevisionGUI::revise);
}

void CodeRevisionGUI::addSourceFile()
{
    std::string name = this->ui->lineEditSourceFileName->text().toStdString();
    Utils::formatSentence(name);
    
    if (name == ""){
        QMessageBox errorBox;
        errorBox.setText(QString::fromStdString("Enter a name!"));
        errorBox.exec();
        return;
    }

    try{
        this->c.addSourceFile(name, this->programmer.getName());
    }
    catch (std::exception& e){
        QMessageBox errorBox;
        errorBox.setText(QString::fromStdString(e.what()));
        errorBox.exec();
    }
}

void CodeRevisionGUI::selectSourceFile()
{
    auto item = this->ui->listWidgetSourceFiles->selectedItems()[0];
    std::string line = item->text().toStdString();
    std::vector<std::string> tokens = Utils::tokenizeString(line, '|');
    if (tokens[1] == "revised" || tokens[2] == this->programmer.getName()){
        this->ui->buttonRevise->setDisabled(true);
    }
    else{
        this->ui->buttonRevise->setDisabled(false);
    }
}

void CodeRevisionGUI::revise()
{
    auto item = this->ui->listWidgetSourceFiles->selectedItems()[0];
    std::string line = item->text().toStdString();
    std::vector<std::string> tokens = Utils::tokenizeString(line, '|');
    
    if (this->programmer.getNrMustReviseFiles() != 0){
        this->programmer.setNrRevisedFiles(this->programmer.getNrRevisedFiles() + 1);
        this->programmer.setNrMustReviseFiles(this->programmer.getNrMustReviseFiles() - 1);
        this->c.revise(tokens[0], this->programmer.getName());
    }

    if (this->programmer.getNrMustReviseFiles() == 0){
        QMessageBox greeting;
        greeting.setText("Congratulions! You reviewed the maximum amount of files.");
        greeting.exec();
        return;
    }

}

void CodeRevisionGUI::update(){
    this->ui->listWidgetSourceFiles->clear();
    std::vector<SourceFile> sourceFiles = this->c.sortedByName();
    for (SourceFile& sf : sourceFiles){
        this->ui->listWidgetSourceFiles->addItem(QString::fromStdString(sf.toString()));
        if (sf.getStatus() != "revised"){
            QFont font;
            font.setBold(true);
            this->ui->listWidgetSourceFiles->item(this->ui->listWidgetSourceFiles->count() - 1)->setFont(font);
        }
        else{
            this->ui->listWidgetSourceFiles->item(this->ui->listWidgetSourceFiles->count() - 1)->setBackground(Qt::green);
        }
    }
    this->ui->labelValueRevised->setText(QString::fromStdString(std::to_string(this->programmer.getNrRevisedFiles())));
    this->ui->labelValueToRevise->setText(QString::fromStdString(std::to_string(this->programmer.getNrMustReviseFiles())));
}
