#pragma once
#include <algorithm>
#include <QAbstractTableModel>
#include "qcolor.h"
#include "qdebug.h"
#include <vector>

class MyTableModel :public QAbstractTableModel {
	vector<Prod> all;
	int filter;
public:
	MyTableModel(const vector<Prod>& all) :all{ all } {}
	int columnCount(const QModelIndex& parent = QModelIndex())const override {
		return 5;
	}
	int rowCount(const QModelIndex& parent = QModelIndex())const override {
		return all.size();
	}
	void refresh(const vector<Prod>& elems, int filter1) {
		filter = filter1;
		all = elems;
		emit layoutChanged();
	}
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override {

		if (role == Qt::DisplayRole) {
			qDebug() << "Give me (" << index.row() << "," << index.column() << ")"<<'\n';
			int row = index.row();
			Prod p = all[row];
			switch (index.column())
			{
			case 0:
				return QString::number(p.getId());
				break;
			case 1:
				return QString::fromStdString(p.getName());
				break;
			case 2:
				return QString::fromStdString(p.getType());
				break;
			case 3:
				return QString::number(p.getPrice());
				break;
			case 4:
				string n = p.getName();
				string vocala;
				int nr = 0;
				for (auto c : n) {
					vocala = c;
					string vocale = "aeiouAEIOU";
					if (vocale.find(vocala) != string::npos)
						nr++;
				}
				return QString::number(nr);
				break;
			}
		}
		if (role == Qt::BackgroundRole) {
			int row = index.row();
			Prod p = all[row];
			if (p.getPrice() <= filter)
				return QColor(Qt::red);
			else
				return QColor(Qt::white);
		}
		return QVariant{};
	}
};