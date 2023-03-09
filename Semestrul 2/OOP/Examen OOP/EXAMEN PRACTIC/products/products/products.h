#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_products.h"

class products : public QMainWindow
{
    Q_OBJECT

public:
    products(QWidget *parent = Q_NULLPTR);

private:
    Ui::productsClass ui;
};
