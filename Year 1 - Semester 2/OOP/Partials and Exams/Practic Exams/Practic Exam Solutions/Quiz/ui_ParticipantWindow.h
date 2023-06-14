/********************************************************************************
** Form generated from reading UI file 'ParticipantWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTICIPANTWINDOW_H
#define UI_PARTICIPANTWINDOW_H

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

class Ui_ParticipantWindowClass
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidgetQuestions;
    QHBoxLayout *horizontalLayout;
    QLabel *labelAnswer;
    QLineEdit *lineEditAnswer;
    QPushButton *pushButtonAnswer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelScore;
    QLabel *labelValueScore;

    void setupUi(QWidget *ParticipantWindowClass)
    {
        if (ParticipantWindowClass->objectName().isEmpty())
            ParticipantWindowClass->setObjectName(QString::fromUtf8("ParticipantWindowClass"));
        ParticipantWindowClass->resize(395, 319);
        widget = new QWidget(ParticipantWindowClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 371, 301));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidgetQuestions = new QListWidget(widget);
        listWidgetQuestions->setObjectName(QString::fromUtf8("listWidgetQuestions"));

        verticalLayout->addWidget(listWidgetQuestions);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelAnswer = new QLabel(widget);
        labelAnswer->setObjectName(QString::fromUtf8("labelAnswer"));

        horizontalLayout->addWidget(labelAnswer);

        lineEditAnswer = new QLineEdit(widget);
        lineEditAnswer->setObjectName(QString::fromUtf8("lineEditAnswer"));

        horizontalLayout->addWidget(lineEditAnswer);

        pushButtonAnswer = new QPushButton(widget);
        pushButtonAnswer->setObjectName(QString::fromUtf8("pushButtonAnswer"));

        horizontalLayout->addWidget(pushButtonAnswer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelScore = new QLabel(widget);
        labelScore->setObjectName(QString::fromUtf8("labelScore"));

        horizontalLayout_2->addWidget(labelScore);

        labelValueScore = new QLabel(widget);
        labelValueScore->setObjectName(QString::fromUtf8("labelValueScore"));

        horizontalLayout_2->addWidget(labelValueScore);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ParticipantWindowClass);

        QMetaObject::connectSlotsByName(ParticipantWindowClass);
    } // setupUi

    void retranslateUi(QWidget *ParticipantWindowClass)
    {
        ParticipantWindowClass->setWindowTitle(QCoreApplication::translate("ParticipantWindowClass", "ParticipantWindow", nullptr));
        labelAnswer->setText(QCoreApplication::translate("ParticipantWindowClass", "Enter answer:", nullptr));
        pushButtonAnswer->setText(QCoreApplication::translate("ParticipantWindowClass", "Answer", nullptr));
        labelScore->setText(QCoreApplication::translate("ParticipantWindowClass", "Score:", nullptr));
        labelValueScore->setText(QCoreApplication::translate("ParticipantWindowClass", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParticipantWindowClass: public Ui_ParticipantWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTICIPANTWINDOW_H
