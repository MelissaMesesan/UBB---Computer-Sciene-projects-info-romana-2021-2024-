#include "MyModel.h"


int MyModel::rowCount(const QModelIndex& parent) const
{
	return service.get_all().size();
}

int MyModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant MyModel::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		int row = index.row();
		int column = index.column();

		switch (column)
		{
		case 0:
			return QString(QString::number(service.get_all()[row].get_id()));
		case 1:
			return QString(QString::fromStdString(service.get_all()[row].get_title()));
		case 2:
			return QString(QString::fromStdString(service.get_all()[row].get_artist()));
		case 3:
			return QString(QString::number(service.get_all()[row].get_rank()));
		case 4:
			return QString(QString::number(service.get_rank_count(service.get_all()[row].get_rank())));
		}
	}
	return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:
			return QString("Id");
		case 1:
			return QString("Titlu");
		case 2:
			return QString("Artist");
		case 3:
			return QString("Rank");
		case 4:
			return QString("How many rank?");
		}
	}
	return QVariant();
}

void MyModel::set_me()
{
	QModelIndex top_left = createIndex(0, 0);
	QModelIndex bottom_right = createIndex(rowCount(), columnCount());
	emit layoutChanged();
	emit dataChanged(top_left, bottom_right);
}

MyModel::~MyModel()
{
}