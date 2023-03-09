#pragma once

#include <QAbstractTableModel>
#include "Service.h"

class my_model : public QAbstractTableModel
{
private:
	Service& serv;
public:
	my_model(Service& serv) : serv{ serv } {};

	virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	void set_produse();

	~my_model();
};