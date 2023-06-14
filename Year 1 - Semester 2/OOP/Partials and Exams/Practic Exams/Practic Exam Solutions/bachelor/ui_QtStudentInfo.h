/********************************************************************************
** Form generated from reading UI file 'QtStudentInfo.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSTUDENTINFO_H
#define UI_QTSTUDENTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtStudentInfoClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtStudentInfoClass)
    {
        if (QtStudentInfoClass->objectName().isEmpty())
            QtStudentInfoClass->setObjectName(QString::fromUtf8("QtStudentInfoClass"));
        QtStudentInfoClass->resize(354, 407);
        centralWidget = new QWidget(QtStudentInfoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 20, 49, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 70, 49, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 120, 49, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 170, 49, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 220, 49, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(68, 270, 71, 20));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(150, 120, 113, 21));
        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(150, 220, 113, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(160, 20, 49, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(160, 70, 49, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(160, 170, 49, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(150, 270, 49, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 310, 75, 24));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 310, 75, 24));
        QtStudentInfoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtStudentInfoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 354, 22));
        QtStudentInfoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtStudentInfoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtStudentInfoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtStudentInfoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtStudentInfoClass->setStatusBar(statusBar);

        retranslateUi(QtStudentInfoClass);
        QObject::connect(pushButton_2, SIGNAL(clicked()), QtStudentInfoClass, SLOT(cancel()));
        QObject::connect(pushButton, SIGNAL(clicked()), QtStudentInfoClass, SLOT(save()));

        QMetaObject::connectSlotsByName(QtStudentInfoClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtStudentInfoClass)
    {
        QtStudentInfoClass->setWindowTitle(QCoreApplication::translate("QtStudentInfoClass", "QtStudentInfo", nullptr));
        label->setText(QCoreApplication::translate("QtStudentInfoClass", "id", nullptr));
        label_2->setText(QCoreApplication::translate("QtStudentInfoClass", "name", nullptr));
        label_3->setText(QCoreApplication::translate("QtStudentInfoClass", "email", nullptr));
        label_4->setText(QCoreApplication::translate("QtStudentInfoClass", "year", nullptr));
        label_5->setText(QCoreApplication::translate("QtStudentInfoClass", "title", nullptr));
        label_6->setText(QCoreApplication::translate("QtStudentInfoClass", "coordinator", nullptr));
        label_7->setText(QCoreApplication::translate("QtStudentInfoClass", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("QtStudentInfoClass", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("QtStudentInfoClass", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("QtStudentInfoClass", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("QtStudentInfoClass", "save", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QtStudentInfoClass", "cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtStudentInfoClass: public Ui_QtStudentInfoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSTUDENTINFO_H
