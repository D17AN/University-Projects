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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindowClass
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidgetQuestions;
    QHBoxLayout *horizontalLayout;
    QLabel *labelQuestionText;
    QLineEdit *lineEditQuestionText;
    QPushButton *pushButtonAddQuestion;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidgetAnswers;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelAnswerText;
    QLineEdit *lineEditAnswerText;
    QPushButton *pushButtonAddAnswer;
    QSpinBox *spinBox;

    void setupUi(QWidget *UserWindowClass)
    {
        if (UserWindowClass->objectName().isEmpty())
            UserWindowClass->setObjectName(QString::fromUtf8("UserWindowClass"));
        UserWindowClass->resize(585, 349);
        widget = new QWidget(UserWindowClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 561, 331));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidgetQuestions = new QListWidget(widget);
        listWidgetQuestions->setObjectName(QString::fromUtf8("listWidgetQuestions"));

        verticalLayout->addWidget(listWidgetQuestions);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelQuestionText = new QLabel(widget);
        labelQuestionText->setObjectName(QString::fromUtf8("labelQuestionText"));

        horizontalLayout->addWidget(labelQuestionText);

        lineEditQuestionText = new QLineEdit(widget);
        lineEditQuestionText->setObjectName(QString::fromUtf8("lineEditQuestionText"));

        horizontalLayout->addWidget(lineEditQuestionText);

        pushButtonAddQuestion = new QPushButton(widget);
        pushButtonAddQuestion->setObjectName(QString::fromUtf8("pushButtonAddQuestion"));

        horizontalLayout->addWidget(pushButtonAddQuestion);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listWidgetAnswers = new QListWidget(widget);
        listWidgetAnswers->setObjectName(QString::fromUtf8("listWidgetAnswers"));

        verticalLayout_2->addWidget(listWidgetAnswers);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelAnswerText = new QLabel(widget);
        labelAnswerText->setObjectName(QString::fromUtf8("labelAnswerText"));

        horizontalLayout_2->addWidget(labelAnswerText);

        lineEditAnswerText = new QLineEdit(widget);
        lineEditAnswerText->setObjectName(QString::fromUtf8("lineEditAnswerText"));

        horizontalLayout_2->addWidget(lineEditAnswerText);

        pushButtonAddAnswer = new QPushButton(widget);
        pushButtonAddAnswer->setObjectName(QString::fromUtf8("pushButtonAddAnswer"));

        horizontalLayout_2->addWidget(pushButtonAddAnswer);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_2->addWidget(spinBox);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(UserWindowClass);

        QMetaObject::connectSlotsByName(UserWindowClass);
    } // setupUi

    void retranslateUi(QWidget *UserWindowClass)
    {
        UserWindowClass->setWindowTitle(QCoreApplication::translate("UserWindowClass", "UserWindow", nullptr));
        labelQuestionText->setText(QCoreApplication::translate("UserWindowClass", "Question text:", nullptr));
        pushButtonAddQuestion->setText(QCoreApplication::translate("UserWindowClass", "Add question", nullptr));
        labelAnswerText->setText(QCoreApplication::translate("UserWindowClass", "Answer text:", nullptr));
        pushButtonAddAnswer->setText(QCoreApplication::translate("UserWindowClass", "Add answer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindowClass: public Ui_UserWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
