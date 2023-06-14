#include "UserWindow.h"


UserWindow::UserWindow(Service& srv, Users& u, QWidget* parent) :
    QWidget(parent), ui(new Ui::UserWindowClass), srv(srv), user(u) {
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString(user.getName()));
    connect();
    srv.addObserver(this);
    update();

}

UserWindow::~UserWindow() {
    delete ui;
}

void UserWindow::update() {
    ui->listPosts->clear();
    string name = user.getName();
    for (auto post : srv.getAllPosts(name)){
        string text = to_string(post.getId()) + "," + post.getText() + "," + to_string(post.getDay()) + "," + to_string(post.getMonth()) + "," + to_string(post.getYear()) + "," + post.getUser();
        ui->listPosts->addItem(QString::fromStdString(text));
    }
    ui->listSubscriptions->clear();
    for (auto topics : srv.getForUser(name)){
        string text = topics.getText();
        ui->listSubscriptions->addItem(QString::fromStdString(text));
    }
}

void UserWindow::connect() {
    QObject::connect(ui->buttonAddPost, &QPushButton::clicked, this, &UserWindow::add_post);
    QObject::connect(ui->buttonUpdatePost, &QPushButton::clicked, this, &UserWindow::update_post);
}

void UserWindow::add_subscription() {

}


void UserWindow::add_post() {
    string post = ui->lineAddPost->text().toStdString();
    /*vector<Topics> topics;
    for(int i=0;i<tokens.size();i++){

    }
    */
    int id = srv.getpostsize();
    string text = post;
    int d = 13;
    int m = 6;
    int y = 2023;
    string u = user.getName();
    srv.add(id, text, d, m, y, u);
}

void UserWindow::update_post() {

}
