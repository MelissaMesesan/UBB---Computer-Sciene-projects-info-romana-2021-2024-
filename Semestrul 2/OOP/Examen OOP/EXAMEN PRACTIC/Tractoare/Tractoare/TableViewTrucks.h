#pragma once

#include <QWidget>
#include <QTableView>
#include <QHBoxLayout>
#include "my_table_model.h"
#include "Service.h"
#include "Observer.h"
//baga niste semnale bro
class TableViewTrucks : public QWidget, public Observer
{
private:
	Service& service;

	QTableView* table_view;
	my_table_model* model;

	QHBoxLayout* main_layout;

	void setup();
	void double_click_event(const QModelIndex& index);
public:
	TableViewTrucks(Service& service) : service{ service }
	{
		setup();
	};
	~TableViewTrucks();

	void update_me() override;
};