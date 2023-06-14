/********************************************************************************
** Form generated from reading UI file 'DevelopWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVELOPWINDOW_H
#define UI_DEVELOPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DevelopWindowClass
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QPushButton *pushButtonSave;

    void setupUi(QWidget *DevelopWindowClass)
    {
        if (DevelopWindowClass->objectName().isEmpty())
            DevelopWindowClass->setObjectName(QString::fromUtf8("DevelopWindowClass"));
        DevelopWindowClass->resize(400, 300);
        layoutWidget = new QWidget(DevelopWindowClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 381, 281));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        pushButtonSave = new QPushButton(layoutWidget);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        verticalLayout->addWidget(pushButtonSave);


        retranslateUi(DevelopWindowClass);

        QMetaObject::connectSlotsByName(DevelopWindowClass);
    } // setupUi

    void retranslateUi(QWidget *DevelopWindowClass)
    {
        DevelopWindowClass->setWindowTitle(QCoreApplication::translate("DevelopWindowClass", "DevelopWindow", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("DevelopWindowClass", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DevelopWindowClass: public Ui_DevelopWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVELOPWINDOW_H
