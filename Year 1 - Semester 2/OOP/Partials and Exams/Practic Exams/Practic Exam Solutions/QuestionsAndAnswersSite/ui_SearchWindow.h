/********************************************************************************
** Form generated from reading UI file 'SearchWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWINDOW_H
#define UI_SEARCHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchWindowClass
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelSearch;
    QLineEdit *lineEditSearch;
    QListWidget *listWidgetResults;

    void setupUi(QWidget *SearchWindowClass)
    {
        if (SearchWindowClass->objectName().isEmpty())
            SearchWindowClass->setObjectName(QString::fromUtf8("SearchWindowClass"));
        SearchWindowClass->resize(459, 300);
        widget = new QWidget(SearchWindowClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 441, 281));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelSearch = new QLabel(widget);
        labelSearch->setObjectName(QString::fromUtf8("labelSearch"));

        verticalLayout->addWidget(labelSearch);

        lineEditSearch = new QLineEdit(widget);
        lineEditSearch->setObjectName(QString::fromUtf8("lineEditSearch"));

        verticalLayout->addWidget(lineEditSearch);


        verticalLayout_2->addLayout(verticalLayout);

        listWidgetResults = new QListWidget(widget);
        listWidgetResults->setObjectName(QString::fromUtf8("listWidgetResults"));

        verticalLayout_2->addWidget(listWidgetResults);


        retranslateUi(SearchWindowClass);

        QMetaObject::connectSlotsByName(SearchWindowClass);
    } // setupUi

    void retranslateUi(QWidget *SearchWindowClass)
    {
        SearchWindowClass->setWindowTitle(QCoreApplication::translate("SearchWindowClass", "SearchWindow", nullptr));
        labelSearch->setText(QCoreApplication::translate("SearchWindowClass", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchWindowClass: public Ui_SearchWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
