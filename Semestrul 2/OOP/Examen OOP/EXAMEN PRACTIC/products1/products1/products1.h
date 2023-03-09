#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_products1.h"

class products1 : public QMainWindow
{
    Q_OBJECT

public:
    products1(QWidget *parent = nullptr);
    ~products1();

private:
    Ui::products1Class ui;
};
