#include "My_model.h"



int my_model::rowCount(const QModelIndex& parent) const
{
	return serv.get_all().size();
}

int my_model::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant my_model::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		int row = index.row();
		int column = index.column();



		switch (column)
		{
		case 0:
			return QString(QString::number(serv.get_all()[row].get_id()));
		case 1:
			return QString(QString::fromStdString(serv.get_all()[row].get_nume()));
		case 2:
			return QString(QString::fromStdString(serv.get_all()[row].get_tip()));
		case 3:
			return QString(QString::number(serv.get_all()[row].get_pret()));
		}
	}
	else if (role == Qt::BackgroundRole)
	{
		return QVariant();
	}
	return QVariant();
}

void my_model::set_produse()
{
	QModelIndex top_left = createIndex(0, 0);
	QModelIndex bottom_right = createIndex(rowCount(), columnCount());
	emit layoutChanged();
	emit dataChanged(top_left, bottom_right);
}

my_model::~my_model()
{
}