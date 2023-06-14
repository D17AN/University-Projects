/********************************************************************************
** Form generated from reading UI file 'ProgrammerWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMMERWINDOW_H
#define UI_PROGRAMMERWINDOW_H

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

class Ui_ProgrammerWindowClass
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidgetTasks;
    QVBoxLayout *verticalLayout;
    QPushButton *buttonAdd;
    QPushButton *buttonDelete;
    QPushButton *buttonStart;
    QPushButton *buttonDone;
    QHBoxLayout *horizontalLayout;
    QLabel *labelDescription;
    QLineEdit *lineEditDescription;

    void setupUi(QWidget *ProgrammerWindowClass)
    {
        if (ProgrammerWindowClass->objectName().isEmpty())
            ProgrammerWindowClass->setObjectName(QString::fromUtf8("ProgrammerWindowClass"));
        ProgrammerWindowClass->resize(525, 375);
        widget = new QWidget(ProgrammerWindowClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 501, 351));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        listWidgetTasks = new QListWidget(widget);
        listWidgetTasks->setObjectName(QString::fromUtf8("listWidgetTasks"));
        listWidgetTasks->setMaximumSize(QSize(414, 318));

        horizontalLayout_2->addWidget(listWidgetTasks);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        buttonAdd = new QPushButton(widget);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));

        verticalLayout->addWidget(buttonAdd);

        buttonDelete = new QPushButton(widget);
        buttonDelete->setObjectName(QString::fromUtf8("buttonDelete"));

        verticalLayout->addWidget(buttonDelete);

        buttonStart = new QPushButton(widget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));

        verticalLayout->addWidget(buttonStart);

        buttonDone = new QPushButton(widget);
        buttonDone->setObjectName(QString::fromUtf8("buttonDone"));

        verticalLayout->addWidget(buttonDone);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelDescription = new QLabel(widget);
        labelDescription->setObjectName(QString::fromUtf8("labelDescription"));

        horizontalLayout->addWidget(labelDescription);

        lineEditDescription = new QLineEdit(widget);
        lineEditDescription->setObjectName(QString::fromUtf8("lineEditDescription"));

        horizontalLayout->addWidget(lineEditDescription);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ProgrammerWindowClass);

        QMetaObject::connectSlotsByName(ProgrammerWindowClass);
    } // setupUi

    void retranslateUi(QWidget *ProgrammerWindowClass)
    {
        ProgrammerWindowClass->setWindowTitle(QCoreApplication::translate("ProgrammerWindowClass", "ProgrammerWindow", nullptr));
        buttonAdd->setText(QCoreApplication::translate("ProgrammerWindowClass", "Add", nullptr));
        buttonDelete->setText(QCoreApplication::translate("ProgrammerWindowClass", "Delete", nullptr));
        buttonStart->setText(QCoreApplication::translate("ProgrammerWindowClass", "Start", nullptr));
        buttonDone->setText(QCoreApplication::translate("ProgrammerWindowClass", "Done", nullptr));
        labelDescription->setText(QCoreApplication::translate("ProgrammerWindowClass", "Description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgrammerWindowClass: public Ui_ProgrammerWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMERWINDOW_H
