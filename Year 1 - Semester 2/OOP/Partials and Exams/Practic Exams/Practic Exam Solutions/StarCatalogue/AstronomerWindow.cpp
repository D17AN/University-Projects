#include "AstronomerWindow.h"

#include "AstronomerWindow.h"
#include "ui_AstronomerWindow.h"
#include <QMessageBox>


AstronomerWindow::AstronomerWindow(Service& srv, Astronomer& a, QWidget* parent) :
    QWidget(parent), ui(new Ui::AstronomerWindowClass), srv(srv), ast(a) {
    ui->setupUi(this);
    srv.addObserver(this);
    model = new MyTable(srv.getAllStars());
    ui->tableView->setModel(model);
    update();
    connect();
    this->setWindowTitle(QString::fromStdString(ast.getName()));
}

AstronomerWindow::~AstronomerWindow() {
    delete ui;
}

void AstronomerWindow::add_star() {
    string name = ui->lineName->text().toStdString();
    int RA = ui->lineRA->text().toInt();
    int Dec = ui->lineDec->text().toInt();
    int diam = ui->lineDiam->text().toInt();
    string constellation = ast.getConstellation();
    if (diam <= 0 || name == "" || srv.search(name)){
        QMessageBox box;
        box.setText("Error adding");
        box.exec();
    }
    else{
        srv.add(name, constellation, RA, Dec, diam);
    }
}

void AstronomerWindow::update() {
    if (ui->checkBox->isChecked()){
        auto v = srv.getAllWithConst(ast.getConstellation());
        model->update(v);
    }
    else{
        model->update(srv.getAllStars());
    }
}

void AstronomerWindow::connect() {
    QObject::connect(ui->buttonAdd, &QPushButton::clicked, this, &AstronomerWindow::add_star);
    QObject::connect(ui->checkBox, &QCheckBox::stateChanged, this, &AstronomerWindow::update);
    QObject::connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &AstronomerWindow::view);
}

void AstronomerWindow::view() {
    auto rows = ui->tableView->selectionModel()->selectedIndexes();
    if (rows.empty()){
        QMessageBox box;
        box.setText("error with view");
        box.exec();
    }
    auto name = rows[0].data(Qt::DisplayRole).toString().toStdString();
}


