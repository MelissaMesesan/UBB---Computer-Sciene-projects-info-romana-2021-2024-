#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Practic.h"

class Practic : public QMainWindow
{
    Q_OBJECT

public:
    Practic(QWidget *parent = nullptr);
    ~Practic();

private:
    Ui::PracticClass ui;
};
