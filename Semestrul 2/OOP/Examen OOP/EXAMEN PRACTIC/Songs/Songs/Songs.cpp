#include "Songs.h"

#include <QMessageBox>
#include <exception>
#include <QPainter>

void exam1::setup()
{
	layout = new QGridLayout();

	table = new QTableView();
	model = new my_model(serv);
	table->setModel(model);

	w1 = new modify_widget(0);
	w2 = new modify_widget(0);
	w3 = new modify_widget(0);
	w4 = new modify_widget(0);

	layout->addWidget(w1, 0, 0);
	layout->addWidget(w2, 0, 2);
	layout->addWidget(w3, 2, 0);
	layout->addWidget(w4, 2, 2);

	QVBoxLayout* lt = new QVBoxLayout();

	add = new QPushButton("Add");
	del = new QPushButton("Del");

	id_l = new QLabel("id");
	title_l = new QLabel("title");
	artist_l = new QLabel("artist");
	genre_l = new QLabel("genre");

	id_le = new QLineEdit();
	title_le = new QLineEdit();
	artist_le = new QLineEdit();
	genre_le = new QLineEdit();

	lt->addWidget(table);
	lt->addWidget(id_l);
	lt->addWidget(id_le);
	lt->addWidget(title_l);
	lt->addWidget(title_le);
	lt->addWidget(artist_l);
	lt->addWidget(artist_le);
	lt->addWidget(genre_l);
	lt->addWidget(genre_le);
	lt->addWidget(add);
	lt->addWidget(del);


	layout->addLayout(lt, 1, 1);

	//widget = new QWidget();
	this->setLayout(layout);
	///this->setCentralWidget(widget);

	connect(add, &QPushButton::clicked, this, &exam1::add_event);
	connect(del, &QPushButton::clicked, this, &exam1::del_event);
	connect(table, &QAbstractItemView::clicked, this, &exam1::clicked_me);
	update_me();
}

void exam1::update_me()
{
	model->set_songs();
	this->repaint();
}

void exam1::clicked_me(const QModelIndex& index)
{
	qDebug("clicked");
}


void exam1::add_event()
{
	int id = id_le->text().toInt();
	std::string title = title_le->text().toStdString();
	std::string artist = artist_le->text().toStdString();
	std::string genre = genre_le->text().toStdString();

	try
	{
		serv.add(id, title, artist, genre);
	}
	catch (std::exception& e)
	{
		QMessageBox msg;
		msg.setText(QString::fromStdString(e.what()));
		msg.exec();
	}
	update_me();
}

void exam1::del_event()
{
	int id = id_le->text().toInt();

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