#include "my_model.h"



int My_model::rowCount(const QModelIndex& parent) const
{
	return serv.get_all().size();
}

int My_model::columnCount(const QModelIndex& parent) const
{
	return 6;
}

QVariant My_model::data(const QModelIndex& index, int role) const
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
			return QString(QString::fromStdString(serv.get_all()[row].get_title()));
		case 2:
			return QString(QString::fromStdString(serv.get_all()[row].get_artist()));
		case 3:
			return QString(QString::fromStdString(serv.get_all()[row].get_genre()));
		case 4:
			return QString("Genre number:") + QString(QString::number(serv.get_nr_genre(serv.get_all()[row].get_genre())));
		case 5:
			return QString("Artist number:") + QString(QString::number(serv.get_nr_artist(serv.get_all()[row].get_artist())));
		}
	}
	else if (role == Qt::BackgroundRole)
	{
		return QVariant();
	}
	return QVariant();
}

void My_model::set_songs()
{
	QModelIndex top_left = createIndex(0, 0);
	QModelIndex bottom_right = createIndex(rowCount(), columnCount());
	emit layoutChanged();
	emit dataChanged(top_left, bottom_right);
}

My_model::~My_model()
{
}