#pragma once

#include <QAbstractListModel>
#include "Service.h"

class my_list_model : public QAbstractListModel
{
private:
	Service& service;
public:
	my_list_model(Service& service) : service{ service } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	void set_trucks();

	~my_list_model();
};
