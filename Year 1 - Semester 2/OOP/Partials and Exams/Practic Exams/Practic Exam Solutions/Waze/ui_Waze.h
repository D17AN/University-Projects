/********************************************************************************
** Form generated from reading UI file 'Waze.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAZE_H
#define UI_WAZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WazeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WazeClass)
    {
        if (WazeClass->objectName().isEmpty())
            WazeClass->setObjectName(QString::fromUtf8("WazeClass"));
        WazeClass->resize(600, 400);
        menuBar = new QMenuBar(WazeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        WazeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WazeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        WazeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(WazeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        WazeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(WazeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WazeClass->setStatusBar(statusBar);

        retranslateUi(WazeClass);

        QMetaObject::connectSlotsByName(WazeClass);
    } // setupUi

    void retranslateUi(QMainWindow *WazeClass)
    {
        WazeClass->setWindowTitle(QCoreApplication::translate("WazeClass", "Waze", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WazeClass: public Ui_WazeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAZE_H
