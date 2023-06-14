#include "UserWindow.h"

UserWindow::UserWindow(Controller& ctrl, User& user, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserWindowClass())
    , ctrl(ctrl)
    , user(user)

{
    ui->setupUi(this);
    this->ctrl.addObserver(this);
    this->setWindowTitle(QString::fromStdString(user.getName()));
    this->ui->pushButtonAdd->setEnabled(this->user.getType() == "admin");
    this->connectSignalsAndSlots();
    update();
}

UserWindow::~UserWindow(){
    delete ui;
}

void UserWindow::update(){
    /*
    vector<string> categories = this->ctrl.getItemsCatogories();
    this->ui->comboBox->clear();
    for (int i = 0; i < categories.size(); i++){
        QString qCategory = QString::fromStdString(categories[i]);
        this->ui->comboBox->addItem(qCategory);
    }
    
    this->ui->listWidgetItems->clear();
    for (Item& item : this->ctrl.getItems()){
         if (item.getCategory() == this->ui->comboBox->currentText().toStdString() ||
            this->ui->comboBox->currentText().toStdString() == "all"){
            this->ui->listWidgetItems->addItem(QString::fromStdString(item.toString()));
        }
        this->ui->listWidgetItems->addItem(QString::fromStdString(item.toString()));
    }
    */
    
     this->ui->listWidgetItems->clear();
     for (Item& item : this->ctrl.getItems()){
           this->ui->listWidgetItems->addItem(QString::fromStdString(item.toString()));
     }
    

}

void UserWindow::connectSignalsAndSlots(){
    QObject::connect(this->ui->comboBox, &QComboBox::currentIndexChanged, this, &UserWindow::handleComboBox);
    QObject::connect(this->ui->pushButtonAdd, &QPushButton::clicked, this, &UserWindow::handleAddItem);
}

void UserWindow::handleComboBox(){
    update();
}

void UserWindow::handleAddItem(){
    string name = this->ui->lineEditName->text().toStdString();
    string category = this->ui->lineEditCategory->text().toStdString();
    int price = this->ui->lineEditPrice->text().toInt();
    Utils::formatSentence(name);
    Utils::formatSentence(category);

    if (name == "" || price < 0){
		QMessageBox::critical(this, "Error", "Invalid data");
		return;
	}

    Item item{ name, category, price };
    this->ctrl.addItem(item);
    update();
}
