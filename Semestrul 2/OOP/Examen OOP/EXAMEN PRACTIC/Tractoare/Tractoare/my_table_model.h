#pragma once

#include "Service.h"
#include <QAbstractTableModel>

class my_table_model : public QAbstractTableModel
{
private:
	Service& service;
public:
	my_table_model(Service& service) : service{ service } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	//private?

	void set_trucks();

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	QString get_me_data(int x, int y) const;

	~my_table_model();
};
