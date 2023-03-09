#pragma once

#include <QWidget>
#include "Tractoare.h"
#include "Service.h"
#include <QListWidget>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>

class Trucks_GUI : public QWidget, public Observer
{
	Q_OBJECT
public:
	Trucks_GUI(Service& service) : service{ service }
	{
		setup();
		update_me();
	};
	virtual void update_me() override;
private:
	Service& service;
	void setup();
	//layouts
	QHBoxLayout* main_layout;
	QVBoxLayout* left_layout;
	//componenst
	QListWidget* list;
	QPushButton* add_button, * del_button;
	QLineEdit* id_le, * mileage_le;
	QLabel* l1, * l2, * l3, * l4, * l5;
	QComboBox* combo_brand, * combo_year;
	QSlider* price_slider;

	//methods
	void add_event();
	void del_event();
	void price_event(const int& price);
	void current_truck(QListWidgetItem* current, QListWidgetItem* previous);
};