#pragma once
#include <QAbstractTableModel>
#include "produs.h"
#include <vector>
#include <qdebug.h>
#include <QBrush>
#include "gui.h"

using namespace std;

class modelView : public QAbstractTableModel{
	vector<Product> prods;
	double& price;

public:

	modelView(const vector<Product>& songs, double& price) : prods{ songs }, price{ price } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return prods.size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		if (role == Qt::BackgroundRole)
		{
			Product p = prods[index.row()];
			if (double(p.getPrice()) <= double(price)) {
				return QBrush{ Qt::red };
				
			}
		}
		if (role == Qt::DisplayRole) {
			Product p = prods[index.row()];
			if (index.column() == 0)
				return QString::number(p.getId());
			else if (index.column() == 1)
				return QString::fromStdString(p.getName());
			else if (index.column() == 2)
				return QString::fromStdString(p.getType());
			else if (index.column() == 3)
				return QString::number(p.getPrice());
			else if (index.column() == 4)
				return QString::number(p.getVoc());
			
		}
		return QVariant{};
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role) const {
		if (role == Qt::DisplayRole) {
			if (orientation == Qt::Horizontal) 
			{
				if (section == 0) 
					return "ID";
				if (section == 1)
					return "NUME";
				if (section == 2)
					return "TIP";
				if (section == 3)
					return "PRET";
				if (section == 4)
					return "NR.VOCALE";
				
				return "";
			}
		}
		return QVariant{};
	}

	void setProds(const vector<Product>& prods)
	{
		this->prods = prods;
		auto topLeft = createIndex(0, 0);
		auto bottomR = createIndex(rowCount(), columnCount());
		emit dataChanged(topLeft, bottomR);
		emit layoutChanged();
	}


};