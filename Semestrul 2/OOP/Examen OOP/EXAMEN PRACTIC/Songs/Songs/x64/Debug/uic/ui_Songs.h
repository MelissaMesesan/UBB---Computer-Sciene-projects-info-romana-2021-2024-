/********************************************************************************
** Form generated from reading UI file 'Songs.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGS_H
#define UI_SONGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SongsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SongsClass)
    {
        if (SongsClass->objectName().isEmpty())
            SongsClass->setObjectName(QString::fromUtf8("SongsClass"));
        SongsClass->resize(600, 400);
        menuBar = new QMenuBar(SongsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        SongsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SongsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SongsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SongsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        SongsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SongsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SongsClass->setStatusBar(statusBar);

        retranslateUi(SongsClass);

        QMetaObject::connectSlotsByName(SongsClass);
    } // setupUi

    void retranslateUi(QMainWindow *SongsClass)
    {
        SongsClass->setWindowTitle(QCoreApplication::translate("SongsClass", "Songs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SongsClass: public Ui_SongsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGS_H
