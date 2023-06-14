/********************************************************************************
** Form generated from reading UI file 'UserWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindowClass
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listFeed;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListWidget *listPosts;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QListWidget *listSearch;
    QListWidget *listSubscriptions;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineSearc;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineAddPost;
    QPushButton *buttonAddPost;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *lineUpdatepost;
    QPushButton *buttonUpdatePost;

    void setupUi(QWidget *UserWindowClass)
    {
        if (UserWindowClass->objectName().isEmpty())
            UserWindowClass->setObjectName(QString::fromUtf8("UserWindowClass"));
        UserWindowClass->resize(489, 449);
        widget = new QWidget(UserWindowClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 461, 431));
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        listFeed = new QListWidget(widget);
        listFeed->setObjectName(QString::fromUtf8("listFeed"));

        verticalLayout->addWidget(listFeed);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        listPosts = new QListWidget(widget);
        listPosts->setObjectName(QString::fromUtf8("listPosts"));

        verticalLayout_2->addWidget(listPosts);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        listSearch = new QListWidget(widget);
        listSearch->setObjectName(QString::fromUtf8("listSearch"));

        verticalLayout_3->addWidget(listSearch);


        horizontalLayout_5->addLayout(verticalLayout_3);

        listSubscriptions = new QListWidget(widget);
        listSubscriptions->setObjectName(QString::fromUtf8("listSubscriptions"));

        horizontalLayout_5->addWidget(listSubscriptions);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineSearc = new QLineEdit(widget);
        lineSearc->setObjectName(QString::fromUtf8("lineSearc"));

        horizontalLayout->addWidget(lineSearc);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineAddPost = new QLineEdit(widget);
        lineAddPost->setObjectName(QString::fromUtf8("lineAddPost"));

        horizontalLayout_2->addWidget(lineAddPost);

        buttonAddPost = new QPushButton(widget);
        buttonAddPost->setObjectName(QString::fromUtf8("buttonAddPost"));

        horizontalLayout_2->addWidget(buttonAddPost);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        lineUpdatepost = new QLineEdit(widget);
        lineUpdatepost->setObjectName(QString::fromUtf8("lineUpdatepost"));

        horizontalLayout_3->addWidget(lineUpdatepost);

        buttonUpdatePost = new QPushButton(widget);
        buttonUpdatePost->setObjectName(QString::fromUtf8("buttonUpdatePost"));

        horizontalLayout_3->addWidget(buttonUpdatePost);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_4);


        retranslateUi(UserWindowClass);

        QMetaObject::connectSlotsByName(UserWindowClass);
    } // setupUi

    void retranslateUi(QWidget *UserWindowClass)
    {
        UserWindowClass->setWindowTitle(QCoreApplication::translate("UserWindowClass", "UserWindow", nullptr));
        label->setText(QCoreApplication::translate("UserWindowClass", "Feed", nullptr));
        label_2->setText(QCoreApplication::translate("UserWindowClass", "Posts", nullptr));
        label_3->setText(QCoreApplication::translate("UserWindowClass", "Subscriptions", nullptr));
        label_4->setText(QCoreApplication::translate("UserWindowClass", "Search:", nullptr));
        label_5->setText(QCoreApplication::translate("UserWindowClass", "Add Post", nullptr));
        buttonAddPost->setText(QCoreApplication::translate("UserWindowClass", "Add Post", nullptr));
        label_6->setText(QCoreApplication::translate("UserWindowClass", "Update", nullptr));
        buttonUpdatePost->setText(QCoreApplication::translate("UserWindowClass", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindowClass: public Ui_UserWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
