#include "SongGUI.h"

void SongGUI::setup()
{
	table = new QTableView();
	model = new MyModel(service);
	table->setModel(model);
	table->setFixedSize(500, 300);

	/*
	SPATIU JOS
	SELECTIE LINIE INTREAGA
	LISTA SORTATA BREEEE
	*/

	title_le = new QLineEdit();
	rank_slider = new QSlider(Qt::Horizontal);
	rank_slider->setMaximum(10);
	rank_slider->setMinimum(0);
	update_button = new QPushButton("Update");
	delete_button = new QPushButton("Delete");
	draw_widget = new QWidget();
	draw_widget->setFixedSize(500, 300);
	lrank = new QLabel("Rank: 0");

	connect(table, &QAbstractItemView::clicked, this, &SongGUI::click_event);
	connect(rank_slider, &QSlider::valueChanged, this, &SongGUI::slider_event);
	connect(update_button, &QPushButton::clicked, this, &SongGUI::update_event);
	connect(delete_button, &QPushButton::clicked, this, &SongGUI::delete_event);

	main_layout = new QVBoxLayout();
	main_layout->addWidget(table);
	main_layout->addWidget(title_le);
	main_layout->addWidget(lrank);
	main_layout->addWidget(rank_slider);
	main_layout->addWidget(update_button);
	main_layout->addWidget(delete_button);
	main_layout->addWidget(draw_widget);
	this->setLayout(main_layout);
	//this->setFixedSize(530, 800);
}

void SongGUI::click_event(const QModelIndex& i)
{
	qDebug() << i.row();
	title_le->setText(model->get_data(i.row(), 1));
	rank_slider->setValue(model->get_data(i.row(), 3).toInt());
	lrank->setText(QString("Rank: ") + QString::number(model->get_data(i.row(), 3).toInt()));
	current_id = model->get_data(i.row(), 0).toInt();
}

void SongGUI::slider_event(const int& val)
{
	lrank->setText(QString("Rank: ") + QString::number(val));
}

void SongGUI::update_event()
{
	try
	{
		if (current_id == -1)
			throw std::exception("Nu este selectata nicio melodie");
		service.update(current_id, title_le->text().toStdString(), rank_slider->value());
		update_me();
	}
	catch (std::exception& e)
	{
		QMessageBox msg;
		msg.setText(e.what());
		msg.exec();
	}
}

void SongGUI::delete_event()
{
	try
	{
		if (current_id == -1)
			throw std::exception("Nu este selectata nicio melodie");
		service.del(current_id);
		update_me();
	}
	catch (std::exception& e)
	{
		QMessageBox msg;
		msg.setText(e.what());
		msg.exec();
	}
}

void SongGUI::update_me()
{
	current_id = -1;
	rank_slider->setValue(0);
	title_le->setText(QString(""));
	model->set_me();
	this->repaint();
}

void SongGUI::paintEvent(QPaintEvent* event)
{
	QPainter pnt(this);

	//pnt.fillRect(this->width() - 100, this->height() - 100, -100, -100, QColor(Qt::red));

	int x = this->height();
	for (int i = 0; i <= 10; i++)
	{
		int how_many = service.get_rank_count(i);
		pnt.fillRect(((this->width() - 21) / 10) * i, x, 20, -how_many * 10, QColor(Qt::red));
		int y = 0;
	}
	qDebug("paint me daddy");
}