#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Songs.h"
#include "service.h"
#include "my_model.h"
#include <QTableView>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include "modify_widget.h"

class exam1 : public QWidget
{
	Q_OBJECT
private:
	service& serv;

	void setup();
	void add_event();
	void del_event();
	void update_me();
	void clicked_me(const QModelIndex&);
	virtual void paintEvent(QPaintEvent* event) override
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

	}
public:
	exam1(service& serv) : serv{ serv } { setup(); };

	modify_widget* w1, * w2, * w3, * w4;
	QWidget* aux1, * aux2, * aux3, * aux4;
	QWidget* widget;
	QGridLayout* layout;
	QTableView* table;
	my_model* model;
	//adaugare/stregere
	QPushButton* add, * del;
	QLabel* id_l, * title_l, * genre_l, * artist_l;
	QLineEdit* id_le, * title_le, * genre_le, * artist_le;

};