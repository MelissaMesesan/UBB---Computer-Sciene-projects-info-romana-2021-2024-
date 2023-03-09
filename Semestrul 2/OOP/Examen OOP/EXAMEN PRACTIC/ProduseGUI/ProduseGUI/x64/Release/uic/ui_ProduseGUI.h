/********************************************************************************
** Form generated from reading UI file 'ProduseGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUSEGUI_H
#define UI_PRODUSEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProduseGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProduseGUIClass)
    {
        if (ProduseGUIClass->objectName().isEmpty())
            ProduseGUIClass->setObjectName(QString::fromUtf8("ProduseGUIClass"));
        ProduseGUIClass->resize(600, 400);
        menuBar = new QMenuBar(ProduseGUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ProduseGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProduseGUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ProduseGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ProduseGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ProduseGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ProduseGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ProduseGUIClass->setStatusBar(statusBar);

        retranslateUi(ProduseGUIClass);

        QMetaObject::connectSlotsByName(ProduseGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProduseGUIClass)
    {
        ProduseGUIClass->setWindowTitle(QCoreApplication::translate("ProduseGUIClass", "ProduseGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProduseGUIClass: public Ui_ProduseGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUSEGUI_H
