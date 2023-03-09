#pragma once

#include <QWidget>
#include <QListView>
#include <QHBoxLayout>
#include "my_list_model.h"
#include "Observer.h"

class ListViewTrucks : public QWidget, public Observer
{
private:
	Service& service;
	QListView* list_view;
	my_list_model* model;
	QHBoxLayout* main_layout;
	void setup();
public:
	ListViewTrucks(Service& service) : service{ service }
	{
		setup();
	};

	void update_me() override;

	~ListViewTrucks();
};
