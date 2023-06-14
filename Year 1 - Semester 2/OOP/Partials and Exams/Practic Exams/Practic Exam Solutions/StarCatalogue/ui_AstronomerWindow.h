/********************************************************************************
** Form generated from reading UI file 'AstronomerWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASTRONOMERWINDOW_H
#define UI_ASTRONOMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AstronomerWindowClass
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineRA;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineDec;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineDiam;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonAdd;
    QCheckBox *checkBox;

    void setupUi(QWidget *AstronomerWindowClass)
    {
        if (AstronomerWindowClass->objectName().isEmpty())
            AstronomerWindowClass->setObjectName(QString::fromUtf8("AstronomerWindowClass"));
        AstronomerWindowClass->resize(543, 400);
        layoutWidget = new QWidget(AstronomerWindowClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 521, 381));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineName = new QLineEdit(layoutWidget);
        lineName->setObjectName(QString::fromUtf8("lineName"));

        horizontalLayout_2->addWidget(lineName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineRA = new QLineEdit(layoutWidget);
        lineRA->setObjectName(QString::fromUtf8("lineRA"));

        horizontalLayout_3->addWidget(lineRA);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        lineDec = new QLineEdit(layoutWidget);
        lineDec->setObjectName(QString::fromUtf8("lineDec"));

        horizontalLayout_4->addWidget(lineDec);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        lineDiam = new QLineEdit(layoutWidget);
        lineDiam->setObjectName(QString::fromUtf8("lineDiam"));

        horizontalLayout_5->addWidget(lineDiam);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonAdd = new QPushButton(layoutWidget);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));

        horizontalLayout->addWidget(buttonAdd);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);


        horizontalLayout_6->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(horizontalLayout_6);


        retranslateUi(AstronomerWindowClass);

        QMetaObject::connectSlotsByName(AstronomerWindowClass);
    } // setupUi

    void retranslateUi(QWidget *AstronomerWindowClass)
    {
        AstronomerWindowClass->setWindowTitle(QCoreApplication::translate("AstronomerWindowClass", "AstronomerWindow", nullptr));
        label->setText(QCoreApplication::translate("AstronomerWindowClass", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("AstronomerWindowClass", "RA", nullptr));
        label_3->setText(QCoreApplication::translate("AstronomerWindowClass", "Dec", nullptr));
        label_4->setText(QCoreApplication::translate("AstronomerWindowClass", "Diameter", nullptr));
        buttonAdd->setText(QCoreApplication::translate("AstronomerWindowClass", "Add", nullptr));
        checkBox->setText(QCoreApplication::translate("AstronomerWindowClass", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AstronomerWindowClass: public Ui_AstronomerWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASTRONOMERWINDOW_H
