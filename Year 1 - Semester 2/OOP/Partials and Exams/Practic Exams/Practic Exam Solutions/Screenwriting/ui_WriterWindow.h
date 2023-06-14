/********************************************************************************
** Form generated from reading UI file 'WriterWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRITERWINDOW_H
#define UI_WRITERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WriterWindowClass
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableViewIdeas;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelDescription;
    QLineEdit *lineEditDescription;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelAct;
    QLineEdit *lineEditAct;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonAccept;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButtonDevelop;
    QPushButton *pushButtonSavePlot;

    void setupUi(QWidget *WriterWindowClass)
    {
        if (WriterWindowClass->objectName().isEmpty())
            WriterWindowClass->setObjectName(QString::fromUtf8("WriterWindowClass"));
        WriterWindowClass->resize(481, 378);
        widget = new QWidget(WriterWindowClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 461, 351));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableViewIdeas = new QTableView(widget);
        tableViewIdeas->setObjectName(QString::fromUtf8("tableViewIdeas"));

        verticalLayout_3->addWidget(tableViewIdeas);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelDescription = new QLabel(widget);
        labelDescription->setObjectName(QString::fromUtf8("labelDescription"));

        horizontalLayout->addWidget(labelDescription);

        lineEditDescription = new QLineEdit(widget);
        lineEditDescription->setObjectName(QString::fromUtf8("lineEditDescription"));

        horizontalLayout->addWidget(lineEditDescription);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelAct = new QLabel(widget);
        labelAct->setObjectName(QString::fromUtf8("labelAct"));

        horizontalLayout_2->addWidget(labelAct);

        lineEditAct = new QLineEdit(widget);
        lineEditAct->setObjectName(QString::fromUtf8("lineEditAct"));

        horizontalLayout_2->addWidget(lineEditAct);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButtonAdd = new QPushButton(widget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));

        horizontalLayout_3->addWidget(pushButtonAdd);

        pushButtonAccept = new QPushButton(widget);
        pushButtonAccept->setObjectName(QString::fromUtf8("pushButtonAccept"));

        horizontalLayout_3->addWidget(pushButtonAccept);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButtonDevelop = new QPushButton(widget);
        pushButtonDevelop->setObjectName(QString::fromUtf8("pushButtonDevelop"));

        verticalLayout_4->addWidget(pushButtonDevelop);

        pushButtonSavePlot = new QPushButton(widget);
        pushButtonSavePlot->setObjectName(QString::fromUtf8("pushButtonSavePlot"));

        verticalLayout_4->addWidget(pushButtonSavePlot);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_4);


        retranslateUi(WriterWindowClass);

        QMetaObject::connectSlotsByName(WriterWindowClass);
    } // setupUi

    void retranslateUi(QWidget *WriterWindowClass)
    {
        WriterWindowClass->setWindowTitle(QCoreApplication::translate("WriterWindowClass", "WriterWindow", nullptr));
        labelDescription->setText(QCoreApplication::translate("WriterWindowClass", "Description", nullptr));
        labelAct->setText(QCoreApplication::translate("WriterWindowClass", "Act", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("WriterWindowClass", "Add", nullptr));
        pushButtonAccept->setText(QCoreApplication::translate("WriterWindowClass", "Accept", nullptr));
        pushButtonDevelop->setText(QCoreApplication::translate("WriterWindowClass", "Develop", nullptr));
        pushButtonSavePlot->setText(QCoreApplication::translate("WriterWindowClass", "Save Plot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WriterWindowClass: public Ui_WriterWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRITERWINDOW_H
