/********************************************************************************
** Form generated from reading UI file 'QtVisualStatistic.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTVISUALSTATISTIC_H
#define UI_QTVISUALSTATISTIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtVisualStatisticClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtVisualStatisticClass)
    {
        if (QtVisualStatisticClass->objectName().isEmpty())
            QtVisualStatisticClass->setObjectName(QString::fromUtf8("QtVisualStatisticClass"));
        QtVisualStatisticClass->resize(600, 400);
        menuBar = new QMenuBar(QtVisualStatisticClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtVisualStatisticClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtVisualStatisticClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtVisualStatisticClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtVisualStatisticClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtVisualStatisticClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtVisualStatisticClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtVisualStatisticClass->setStatusBar(statusBar);

        retranslateUi(QtVisualStatisticClass);

        QMetaObject::connectSlotsByName(QtVisualStatisticClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtVisualStatisticClass)
    {
        QtVisualStatisticClass->setWindowTitle(QCoreApplication::translate("QtVisualStatisticClass", "QtVisualStatistic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtVisualStatisticClass: public Ui_QtVisualStatisticClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTVISUALSTATISTIC_H
