/********************************************************************************
** Form generated from reading UI file 'Produse.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUSE_H
#define UI_PRODUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProduseClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProduseClass)
    {
        if (ProduseClass->objectName().isEmpty())
            ProduseClass->setObjectName(QString::fromUtf8("ProduseClass"));
        ProduseClass->resize(600, 400);
        menuBar = new QMenuBar(ProduseClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ProduseClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProduseClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ProduseClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ProduseClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ProduseClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ProduseClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ProduseClass->setStatusBar(statusBar);

        retranslateUi(ProduseClass);

        QMetaObject::connectSlotsByName(ProduseClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProduseClass)
    {
        ProduseClass->setWindowTitle(QCoreApplication::translate("ProduseClass", "Produse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProduseClass: public Ui_ProduseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUSE_H
