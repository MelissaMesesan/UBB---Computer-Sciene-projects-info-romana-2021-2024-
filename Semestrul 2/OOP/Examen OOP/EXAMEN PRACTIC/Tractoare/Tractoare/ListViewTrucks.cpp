#include "ListViewTrucks.h"


void ListViewTrucks::setup()
{
	list_view = new QListView();
	model = new my_list_model(service);
	list_view->setModel(model);

	main_layout = new QHBoxLayout();
	main_layout->addWidget(list_view);
	this->setLayout(main_layout);
	this->setFixedSize(200, 300);
}

void ListViewTrucks::update_me()
{
	model->set_trucks();
}

ListViewTrucks::~ListViewTrucks()
{
}