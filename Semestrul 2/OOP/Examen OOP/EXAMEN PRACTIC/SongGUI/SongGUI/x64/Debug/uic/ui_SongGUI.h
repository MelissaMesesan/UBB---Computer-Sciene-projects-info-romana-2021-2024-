/********************************************************************************
** Form generated from reading UI file 'SongGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGGUI_H
#define UI_SONGGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SongGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SongGUIClass)
    {
        if (SongGUIClass->objectName().isEmpty())
            SongGUIClass->setObjectName(QString::fromUtf8("SongGUIClass"));
        SongGUIClass->resize(600, 400);
        menuBar = new QMenuBar(SongGUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        SongGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SongGUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SongGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SongGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        SongGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SongGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SongGUIClass->setStatusBar(statusBar);

        retranslateUi(SongGUIClass);

        QMetaObject::connectSlotsByName(SongGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *SongGUIClass)
    {
        SongGUIClass->setWindowTitle(QCoreApplication::translate("SongGUIClass", "SongGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SongGUIClass: public Ui_SongGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGGUI_H
