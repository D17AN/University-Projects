/********************************************************************************
** Form generated from reading UI file 'bachelor.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACHELOR_H
#define UI_BACHELOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bachelorClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QListWidget *listWidget_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *bachelorClass)
    {
        if (bachelorClass->objectName().isEmpty())
            bachelorClass->setObjectName(QString::fromUtf8("bachelorClass"));
        bachelorClass->resize(713, 361);
        centralWidget = new QWidget(bachelorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 641, 271));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        listWidget_2 = new QListWidget(widget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));

        verticalLayout_2->addWidget(listWidget_2);


        horizontalLayout->addLayout(verticalLayout_2);

        bachelorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(bachelorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 713, 22));
        bachelorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(bachelorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        bachelorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(bachelorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        bachelorClass->setStatusBar(statusBar);

        retranslateUi(bachelorClass);
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), bachelorClass, SLOT(search()));
        QObject::connect(listWidget_2, SIGNAL(itemClicked(QListWidgetItem*)), bachelorClass, SLOT(addStudent()));
        QObject::connect(pushButton, SIGNAL(clicked()), bachelorClass, SLOT(editStudentInfo()));

        QMetaObject::connectSlotsByName(bachelorClass);
    } // setupUi

    void retranslateUi(QMainWindow *bachelorClass)
    {
        bachelorClass->setWindowTitle(QCoreApplication::translate("bachelorClass", "bachelor", nullptr));
        pushButton->setText(QCoreApplication::translate("bachelorClass", "edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bachelorClass: public Ui_bachelorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACHELOR_H
