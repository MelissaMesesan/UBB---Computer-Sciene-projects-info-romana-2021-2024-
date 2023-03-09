#pragma once

#include "Service.h"
#include <QAbstractTableModel>

class MyModel : public QAbstractTableModel
{
private:
	Service& service;
public:
	MyModel(Service& service) : service{ service } {};

	/*
	Return number of rows
	*/
	int rowCount(const QModelIndex& parent = QModelIndex()) const;

	/*
	Returns number of columns
	*/
	int columnCount(const QModelIndex& parent = QModelIndex()) const;

	/*
	Returns data for each cell
	*/
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

	/*
	RETURNS data for header
	*/
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	void set_me();

	QString get_data(const int& x, const int& y)
	{
		return data(createIndex(x, y), Qt::DisplayRole).toString();
	}

	~MyModel();
};
