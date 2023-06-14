/********************************************************************************
** Form generated from reading UI file 'PresenterWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESENTERWINDOW_H
#define UI_PRESENTERWINDOW_H

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

class Ui_PresenterWindowClass
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidgetQuestions;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelId;
    QLineEdit *lineEditId;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelText;
    QLineEdit *lineEditText;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelAnswer;
    QLineEdit *lineEditAnswer;
    QPushButton *pushButtonAddQuestion;

    void setupUi(QWidget *PresenterWindowClass)
    {
        if (PresenterWindowClass->objectName().isEmpty())
            PresenterWindowClass->setObjectName(QString::fromUtf8("PresenterWindowClass"));
        PresenterWindowClass->resize(453, 326);
        widget = new QWidget(PresenterWindowClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 431, 311));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        listWidgetQuestions = new QListWidget(widget);
        listWidgetQuestions->setObjectName(QString::fromUtf8("listWidgetQuestions"));

        verticalLayout_3->addWidget(listWidgetQuestions);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelId = new QLabel(widget);
        labelId->setObjectName(QString::fromUtf8("labelId"));

        horizontalLayout->addWidget(labelId);

        lineEditId = new QLineEdit(widget);
        lineEditId->setObjectName(QString::fromUtf8("lineEditId"));

        horizontalLayout->addWidget(lineEditId);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelText = new QLabel(widget);
        labelText->setObjectName(QString::fromUtf8("labelText"));

        horizontalLayout_2->addWidget(labelText);

        lineEditText = new QLineEdit(widget);
        lineEditText->setObjectName(QString::fromUtf8("lineEditText"));

        horizontalLayout_2->addWidget(lineEditText);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelAnswer = new QLabel(widget);
        labelAnswer->setObjectName(QString::fromUtf8("labelAnswer"));

        horizontalLayout_3->addWidget(labelAnswer);

        lineEditAnswer = new QLineEdit(widget);
        lineEditAnswer->setObjectName(QString::fromUtf8("lineEditAnswer"));

        horizontalLayout_3->addWidget(lineEditAnswer);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        pushButtonAddQuestion = new QPushButton(widget);
        pushButtonAddQuestion->setObjectName(QString::fromUtf8("pushButtonAddQuestion"));

        verticalLayout_2->addWidget(pushButtonAddQuestion);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(PresenterWindowClass);

        QMetaObject::connectSlotsByName(PresenterWindowClass);
    } // setupUi

    void retranslateUi(QWidget *PresenterWindowClass)
    {
        PresenterWindowClass->setWindowTitle(QCoreApplication::translate("PresenterWindowClass", "PresenterWindow", nullptr));
        labelId->setText(QCoreApplication::translate("PresenterWindowClass", "Id", nullptr));
        labelText->setText(QCoreApplication::translate("PresenterWindowClass", "Text", nullptr));
        labelAnswer->setText(QCoreApplication::translate("PresenterWindowClass", "Answer", nullptr));
        pushButtonAddQuestion->setText(QCoreApplication::translate("PresenterWindowClass", "Add question", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PresenterWindowClass: public Ui_PresenterWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESENTERWINDOW_H
