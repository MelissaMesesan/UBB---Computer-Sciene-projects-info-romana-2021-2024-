#include "TableViewTrucks.h"

#include <QDebug>
#include <QModelIndex>

void TableViewTrucks::setup()
{
	table_view = new QTableView();
	model = new my_table_model(service);
	table_view->setModel(model);
	table_view->setColumnHidden(0, true);

	connect(table_view, &QTableView::doubleClicked, this, &TableViewTrucks::double_click_event);

	main_layout = new QHBoxLayout();
	main_layout->addWidget(table_view);
	this->setLayout(main_layout);
	this->setWindowTitle("Double click to delete");
	this->setFixedSize(530, 400);
}

void TableViewTrucks::double_click_event(const QModelIndex& index)
{
	int row = index.row();

	int id = model->get_me_data(row, 0).toInt();

	service.del(id);
}

TableViewTrucks::~TableViewTrucks()
{
}

void TableViewTrucks::update_me()
{
	model->set_trucks();
	table_view->setColumnHidden(0, true);
}