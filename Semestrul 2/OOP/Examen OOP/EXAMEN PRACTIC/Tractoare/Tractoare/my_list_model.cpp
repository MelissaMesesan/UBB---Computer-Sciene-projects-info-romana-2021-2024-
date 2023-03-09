#include "my_list_model.h"

int my_list_model::rowCount(const QModelIndex& parent) const
{
	return service.get_all().size();
}

QVariant my_list_model::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		int row = index.row();
		QString s;
		s += QString::fromStdString(service.get_all()[row].get_brand()) + QString(" ");
		s += QString::number(service.get_all()[row].get_price());
		return s;
	}
	return QVariant();
}

void my_list_model::set_trucks()
{
	QModelIndex top_left = createIndex(0, 0);
	QModelIndex bottom_rigth = createIndex(rowCount(), 0);
	emit layoutChanged();
	emit dataChanged(top_left, bottom_rigth);
}

my_list_model::~my_list_model()
{
}