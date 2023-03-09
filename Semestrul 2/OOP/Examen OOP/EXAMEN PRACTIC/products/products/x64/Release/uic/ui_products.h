/********************************************************************************
** Form generated from reading UI file 'products.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTS_H
#define UI_PRODUCTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_productsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *productsClass)
    {
        if (productsClass->objectName().isEmpty())
            productsClass->setObjectName(QString::fromUtf8("productsClass"));
        productsClass->resize(600, 400);
        menuBar = new QMenuBar(productsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        productsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(productsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        productsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(productsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        productsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(productsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        productsClass->setStatusBar(statusBar);

        retranslateUi(productsClass);

        QMetaObject::connectSlotsByName(productsClass);
    } // setupUi

    void retranslateUi(QMainWindow *productsClass)
    {
        productsClass->setWindowTitle(QCoreApplication::translate("productsClass", "products", nullptr));
    } // retranslateUi

};

namespace Ui {
    class productsClass: public Ui_productsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTS_H
