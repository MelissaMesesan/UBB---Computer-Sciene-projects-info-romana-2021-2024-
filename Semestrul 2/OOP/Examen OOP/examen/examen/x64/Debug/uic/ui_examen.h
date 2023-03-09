/********************************************************************************
** Form generated from reading UI file 'examen.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMEN_H
#define UI_EXAMEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_examenClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *examenClass)
    {
        if (examenClass->objectName().isEmpty())
            examenClass->setObjectName(QString::fromUtf8("examenClass"));
        examenClass->resize(600, 400);
        menuBar = new QMenuBar(examenClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        examenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(examenClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        examenClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(examenClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        examenClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(examenClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        examenClass->setStatusBar(statusBar);

        retranslateUi(examenClass);

        QMetaObject::connectSlotsByName(examenClass);
    } // setupUi

    void retranslateUi(QMainWindow *examenClass)
    {
        examenClass->setWindowTitle(QCoreApplication::translate("examenClass", "examen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class examenClass: public Ui_examenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMEN_H
