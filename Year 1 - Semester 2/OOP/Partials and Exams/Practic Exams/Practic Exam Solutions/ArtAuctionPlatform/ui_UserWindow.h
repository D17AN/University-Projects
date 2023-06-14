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
#include <QtWidgets/QComboBox>
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
    QListWidget *listWidgetItems;
    QComboBox *comboBox;
    QPushButton *pushButtonAdd;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditName;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditCategory;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEditPrice;
    QLabel *label_3;

    void setupUi(QWidget *UserWindowClass)
    {
        if (UserWindowClass->objectName().isEmpty())
            UserWindowClass->setObjectName(QString::fromUtf8("UserWindowClass"));
        UserWindowClass->resize(600, 400);
        listWidgetItems = new QListWidget(UserWindowClass);
        listWidgetItems->setObjectName(QString::fromUtf8("listWidgetItems"));
        listWidgetItems->setGeometry(QRect(30, 20, 351, 251));
        comboBox = new QComboBox(UserWindowClass);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 290, 68, 22));
        pushButtonAdd = new QPushButton(UserWindowClass);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(510, 120, 75, 24));
        widget = new QWidget(UserWindowClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(390, 30, 199, 83));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditName = new QLineEdit(widget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        horizontalLayout->addWidget(lineEditName);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEditCategory = new QLineEdit(widget);
        lineEditCategory->setObjectName(QString::fromUtf8("lineEditCategory"));

        horizontalLayout_2->addWidget(lineEditCategory);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEditPrice = new QLineEdit(widget);
        lineEditPrice->setObjectName(QString::fromUtf8("lineEditPrice"));

        horizontalLayout_3->addWidget(lineEditPrice);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(UserWindowClass);

        QMetaObject::connectSlotsByName(UserWindowClass);
    } // setupUi

    void retranslateUi(QWidget *UserWindowClass)
    {
        UserWindowClass->setWindowTitle(QCoreApplication::translate("UserWindowClass", "UserWindow", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("UserWindowClass", "Add Item", nullptr));
        label->setText(QCoreApplication::translate("UserWindowClass", "Item name", nullptr));
        label_2->setText(QCoreApplication::translate("UserWindowClass", "Category", nullptr));
        label_3->setText(QCoreApplication::translate("UserWindowClass", "Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindowClass: public Ui_UserWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
