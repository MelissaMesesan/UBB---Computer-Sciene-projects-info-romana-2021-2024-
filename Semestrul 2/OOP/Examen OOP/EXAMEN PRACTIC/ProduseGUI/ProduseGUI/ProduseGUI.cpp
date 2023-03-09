#include "ProduseGUI.h"

#include <QMessageBox>
#include <exception>
#include <QPainter>

void ProduseGUI::setup()
{
	layout = new QGridLayout();

	table = new QTableView();
	model = new my_model(serv);
	table->setModel(model);

	/*
	w1 = new modify_widget(0);
	w2 = new modify_widget(0);
	w3 = new modify_widget(0);
	w4 = new modify_widget(0);

	layout->addWidget(w1, 0, 0);
	layout->addWidget(w2, 0, 2);
	layout->addWidget(w3, 2, 0);
	layout->addWidget(w4, 2, 2); */

	QVBoxLayout* lt = new QVBoxLayout();

	add = new QPushButton("Add");
	del = new QPushButton("Del");

	id_l = new QLabel("id");
	nume_l = new QLabel("nume");
	tip_l = new QLabel("tip");
	pret_l = new QLabel("pret");

	id_le = new QLineEdit();
	nume_le = new QLineEdit();
	tip_le = new QLineEdit();
	pret_le = new QLineEdit();

	lt->addWidget(table);
	lt->addWidget(id_l);
	lt->addWidget(id_le);
	lt->addWidget(nume_l);
	lt->addWidget(nume_le);
	lt->addWidget(tip_l);
	lt->addWidget(tip_le);
	lt->addWidget(pret_l);
	lt->addWidget(pret_le);
	lt->addWidget(add);
	lt->addWidget(del);


	layout->addLayout(lt, 1, 1);

	//widget = new QWidget();
	this->setLayout(layout);
	///this->setCentralWidget(widget);

	connect(add, &QPushButton::clicked, this, &ProduseGUI::add_event);
	connect(del, &QPushButton::clicked, this, &ProduseGUI::del_event);
	connect(table, &QAbstractItemView::clicked, this, &ProduseGUI::clicked_me);
	update_me();
}

void ProduseGUI::update_me()
{
	model->set_produse();
	this->repaint();
}

void ProduseGUI::clicked_me(const QModelIndex& index)
{
	qDebug("clicked");
}


void ProduseGUI::add_event()
{
	int id = id_le->text().toInt();
	std::string nume = nume_le->text().toStdString();
	std::string tip = tip_le->text().toStdString();
	double pret = pret_le->text().toDouble();

	try
	{
		serv.add(id, nume, tip, pret);
	}
	catch (std::exception& e)
	{
		QMessageBox msg;
		msg.setText(QString::fromStdString(e.what()));
		msg.exec();
	}
	update_me();
}


void ProduseGUI::del_event()
{
	
	int pos = table->currentIndex().row();
	if (pos > serv.get_all().size()) return;
	int id = serv.get_all()[pos].get_id();

	try
	{
		serv.del(id);
	}
	catch (std::exception& e)
	{
		QMessageBox msg;
		msg.setText(QString::fromStdString(e.what()));
		msg.exec();
	}
	update_me();
}