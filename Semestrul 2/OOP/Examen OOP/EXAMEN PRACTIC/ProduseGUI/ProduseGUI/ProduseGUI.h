#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProduseGUI.h"
#include "Service.h"
#include "My_model.h"
#include <QTableView>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
//#include "modify_widget.h"

class ProduseGUI : public QWidget
{
	Q_OBJECT
private:
	
	Service& serv;

	void setup();
	void add_event();
	void del_event();
	void update_me();
	void clicked_me(const QModelIndex&);
	/*virtual void paintEvent(QPaintEvent* event) override
	{
		qDebug("redeseneaazmmaa");

		QPainter pnt{ this };

		int limim = serv.get_nr_genre("pop");
		for (int i = 1; i <= limim; i++)
			pnt.drawEllipse(QPoint(0, 0), 10 * i, 10 * i);

		limim = serv.get_nr_genre("rock");
		for (int i = 1; i <= limim; i++)
			pnt.drawEllipse(QPoint(0, this->height()), 10 * i, 10 * i);

		limim = serv.get_nr_genre("folk");
		for (int i = 1; i <= limim; i++)
			pnt.drawEllipse(QPoint(this->width(), 0), 10 * i, 10 * i);

		limim = serv.get_nr_genre("disco");
		for (int i = 1; i <= limim; i++)
			pnt.drawEllipse(QPoint(this->width(), this->height()), 10 * i, 10 * i);

	}*/
public:
	ProduseGUI(Service& serv) : serv{ serv } { setup(); };

	//modify_widget* w1, * w2, * w3, * w4;
	QWidget* aux1, * aux2, * aux3, * aux4;
	QWidget* widget;
	QGridLayout* layout;
	QTableView* table;
	my_model* model;
	//adaugare/stregere
	QPushButton* add, * del;
	QLabel* id_l, * nume_l, * tip_l, * pret_l;
	QLineEdit* id_le, * nume_le, * tip_le, * pret_le;

};