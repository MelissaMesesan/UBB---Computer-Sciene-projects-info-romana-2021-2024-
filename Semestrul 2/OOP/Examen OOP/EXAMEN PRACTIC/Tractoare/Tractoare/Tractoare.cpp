#include "Tractoare.h"
#include <QMessageBox>
#include <QDebug>

void Trucks_GUI::setup()
{
	list = new QListWidget();
	add_button = new QPushButton("Add");
	add_button->setStyleSheet("color: red");
	del_button = new QPushButton("Delete");
	l1 = new QLabel("Truck id");
	id_le = new QLineEdit();
	l2 = new QLabel("Brand");
	combo_brand = new QComboBox();
	combo_brand->addItem(QString("Volvo"));
	combo_brand->addItem(QString("Scania"));
	combo_brand->addItem(QString("Man"));
	combo_brand->addItem(QString("Mercedes"));
	l3 = new QLabel("Mileage");
	mileage_le = new QLineEdit();
	l4 = new QLabel("Year");
	combo_year = new QComboBox();
	for (int i = 2018; i >= 2000; i--)
	{
		combo_year->addItem(QString::number(i));
	}
	l5 = new QLabel("Price: 500");
	price_slider = new QSlider(Qt::Horizontal);
	price_slider->setMinimum(500);
	price_slider->setMaximum(200000);


	connect(list, &QListWidget::currentItemChanged, this, &Trucks_GUI::current_truck);
	connect(add_button, &QPushButton::clicked, this, &Trucks_GUI::add_event);
	connect(del_button, &QPushButton::clicked, this, &Trucks_GUI::del_event);
	connect(price_slider, &QSlider::valueChanged, this, &Trucks_GUI::price_event);

	main_layout = new QHBoxLayout();
	left_layout = new QVBoxLayout();
	left_layout->addWidget(l1);
	left_layout->addWidget(id_le);
	left_layout->addWidget(l2);
	left_layout->addWidget(combo_brand);
	left_layout->addWidget(l3);
	left_layout->addWidget(mileage_le);
	left_layout->addWidget(l4);
	left_layout->addWidget(combo_year);
	left_layout->addWidget(l5);
	left_layout->addWidget(price_slider);
	left_layout->addWidget(add_button);
	left_layout->addWidget(del_button);
	main_layout->addWidget(list);
	main_layout->addLayout(left_layout);

	this->setLayout(main_layout);
	this->setWindowTitle("ListWidget");
	this->setFixedSize(800, 300);
}



void Trucks_GUI::update_me()
{
	list->clear();

	QFont bold, italic, underline;
	bold.setBold(true);
	italic.setItalic(true);
	underline.setUnderline(true);

	for (auto& i : service.get_all())
	{
		QListWidgetItem* item = new QListWidgetItem();
		QString str = QString::number(i.get_id()) + "    Brand:";
		str += QString::fromStdString(i.get_brand()) + "    Mileage:";
		str += QString::number(i.get_mileage()) + "    Year:";
		str += QString::number(i.get_year()) + "    Price:";
		str += QString::number(i.get_price());
		item->setText(str);
		item->setData(12, i.get_id());

		if (i.get_price() < 10000)
		{
			item->setBackground(QBrush(Qt::green));
			item->setFont(italic);
		}
		else if (i.get_price() < 100000)
		{
			item->setBackground(QBrush(Qt::yellow));
			item->setFont(bold);
		}
		else
		{
			item->setBackground(QBrush(Qt::red));
			item->setFont(underline);
		}

		list->addItem(item);
	}
}

void Trucks_GUI::add_event()
{
	int id = id_le->text().toInt();
	std::string brand = combo_brand->itemText(combo_brand->currentIndex()).toStdString();
	int mileage = mileage_le->text().toInt();
	int year = combo_year->itemText(combo_year->currentIndex()).toInt();
	int price = price_slider->value();
	try
	{
		service.add(id, brand, mileage, year, price);
	}
	catch (std::exception& e)
	{
		QMessageBox msg;
		msg.setText(e.what());
		msg.exec();
	}
}

void Trucks_GUI::del_event()
{
	for (auto& i : list->selectedItems())
	{
		int id = i->data(12).toInt();
		service.del(id);
	}
}

void Trucks_GUI::price_event(const int& price)
{
	l5->setText(QString("Price: ") + QString::number(price));
}

void Trucks_GUI::current_truck(QListWidgetItem* current, QListWidgetItem* previous)
{

}