/********************************************************************************
** Form generated from reading UI file 'CodeRevision.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEREVISION_H
#define UI_CODEREVISION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CodeRevisionClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *listWidgetSourceFiles;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelNameRevised;
    QLabel *labelValueRevised;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelNameToRevise;
    QLabel *labelValueToRevise;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelSourceFileName;
    QLineEdit *lineEditSourceFileName;
    QPushButton *buttonAddSourceFile;
    QPushButton *buttonRevise;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CodeRevisionClass)
    {
        if (CodeRevisionClass->objectName().isEmpty())
            CodeRevisionClass->setObjectName(QString::fromUtf8("CodeRevisionClass"));
        CodeRevisionClass->resize(522, 384);
        centralWidget = new QWidget(CodeRevisionClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 481, 321));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        listWidgetSourceFiles = new QListWidget(layoutWidget);
        listWidgetSourceFiles->setObjectName(QString::fromUtf8("listWidgetSourceFiles"));

        horizontalLayout_6->addWidget(listWidgetSourceFiles);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelNameRevised = new QLabel(layoutWidget);
        labelNameRevised->setObjectName(QString::fromUtf8("labelNameRevised"));

        horizontalLayout_4->addWidget(labelNameRevised);

        labelValueRevised = new QLabel(layoutWidget);
        labelValueRevised->setObjectName(QString::fromUtf8("labelValueRevised"));
        labelValueRevised->setEnabled(false);

        horizontalLayout_4->addWidget(labelValueRevised);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelNameToRevise = new QLabel(layoutWidget);
        labelNameToRevise->setObjectName(QString::fromUtf8("labelNameToRevise"));

        horizontalLayout_5->addWidget(labelNameToRevise);

        labelValueToRevise = new QLabel(layoutWidget);
        labelValueToRevise->setObjectName(QString::fromUtf8("labelValueToRevise"));

        horizontalLayout_5->addWidget(labelValueToRevise);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelSourceFileName = new QLabel(layoutWidget);
        labelSourceFileName->setObjectName(QString::fromUtf8("labelSourceFileName"));

        horizontalLayout_7->addWidget(labelSourceFileName);

        lineEditSourceFileName = new QLineEdit(layoutWidget);
        lineEditSourceFileName->setObjectName(QString::fromUtf8("lineEditSourceFileName"));

        horizontalLayout_7->addWidget(lineEditSourceFileName);

        buttonAddSourceFile = new QPushButton(layoutWidget);
        buttonAddSourceFile->setObjectName(QString::fromUtf8("buttonAddSourceFile"));

        horizontalLayout_7->addWidget(buttonAddSourceFile);


        verticalLayout_2->addLayout(horizontalLayout_7);

        buttonRevise = new QPushButton(layoutWidget);
        buttonRevise->setObjectName(QString::fromUtf8("buttonRevise"));

        verticalLayout_2->addWidget(buttonRevise);

        CodeRevisionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CodeRevisionClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 522, 22));
        CodeRevisionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CodeRevisionClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CodeRevisionClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CodeRevisionClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CodeRevisionClass->setStatusBar(statusBar);

        retranslateUi(CodeRevisionClass);

        QMetaObject::connectSlotsByName(CodeRevisionClass);
    } // setupUi

    void retranslateUi(QMainWindow *CodeRevisionClass)
    {
        CodeRevisionClass->setWindowTitle(QCoreApplication::translate("CodeRevisionClass", "CodeRevision", nullptr));
        labelNameRevised->setText(QCoreApplication::translate("CodeRevisionClass", "Revised:", nullptr));
        labelValueRevised->setText(QCoreApplication::translate("CodeRevisionClass", "TextLabel", nullptr));
        labelNameToRevise->setText(QCoreApplication::translate("CodeRevisionClass", "To revise:", nullptr));
        labelValueToRevise->setText(QCoreApplication::translate("CodeRevisionClass", "TextLabel", nullptr));
        labelSourceFileName->setText(QCoreApplication::translate("CodeRevisionClass", "Name:", nullptr));
        buttonAddSourceFile->setText(QCoreApplication::translate("CodeRevisionClass", "Add Source File", nullptr));
        buttonRevise->setText(QCoreApplication::translate("CodeRevisionClass", "Revise", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CodeRevisionClass: public Ui_CodeRevisionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEREVISION_H
