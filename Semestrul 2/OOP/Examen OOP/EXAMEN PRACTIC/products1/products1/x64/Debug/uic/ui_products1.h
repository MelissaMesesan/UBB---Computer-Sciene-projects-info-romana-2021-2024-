/********************************************************************************
** Form generated from reading UI file 'products1.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTS1_H
#define UI_PRODUCTS1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_products1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *products1Class)
    {
        if (products1Class->objectName().isEmpty())
            products1Class->setObjectName(QString::fromUtf8("products1Class"));
        products1Class->resize(600, 400);
        menuBar = new QMenuBar(products1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        products1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(products1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        products1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(products1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        products1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(products1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        products1Class->setStatusBar(statusBar);

        retranslateUi(products1Class);

        QMetaObject::connectSlotsByName(products1Class);
    } // setupUi

    void retranslateUi(QMainWindow *products1Class)
    {
        products1Class->setWindowTitle(QCoreApplication::translate("products1Class", "products1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class products1Class: public Ui_products1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTS1_H
