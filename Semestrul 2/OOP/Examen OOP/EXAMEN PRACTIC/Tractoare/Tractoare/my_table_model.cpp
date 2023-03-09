#include "my_table_model.h"

#include <QFont>
#include <QBrush>

int my_table_model::rowCount(const QModelIndex& parent) const
{
	return service.get_all().size();
}

int my_table_model::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant my_table_model::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		int row = index.row();
		int column = index.column();
		QString str;
		int year;
		switch (column)
		{
		case 0:
			return QString::number(service.get_all()[row].get_id());
		case 1:
			return QString::fromStdString(service.get_all()[row].get_brand());
		case 2:
			return QString::number(service.get_all()[row].get_mileage());
		case 3:
			year = service.get_all()[row].get_year();
			str = QString::number(service.get_all()[row].get_year());
			if (year > 2014)
				str += QString(" (new)");
			return str;
		case 4:
			return QString::number(service.get_all()[row].get_price());
		}
	}
	else if (role == Qt::BackgroundRole)
	{
		int row = index.row();
		int column = index.column();

		if (index.column() == 4)
		{
			if (service.get_all()[row].get_price() < 10000)
				return QBrush(Qt::green);
			if (service.get_all()[row].get_price() < 100000)
				return QBrush(Qt::yellow);
			return QBrush(Qt::red);
		}
		else if (index.column() == 3)
		{
			if (service.get_all()[row].get_year() > 2014)
				return QBrush(Qt::magenta);
			return QVariant();
		}
	}
	else if (role == Qt::FontRole)
	{
		int row = index.row();
		int column = index.column();

		if (index.column() == 1)
		{
			QFont serifFont("Times", 10, QFont::Bold);
			if (service.get_all()[row].get_brand() == std::string("Volvo"))
				return serifFont;
			return QVariant();
		}
		if (index.column() == 3)
		{
			QFont serifFont;
			serifFont.setItalic(true);
			serifFont.setBold(true);
			if (service.get_all()[row].get_year() > 2014)
				return serifFont;
			return QVariant();
		}
	}
	return QVariant();
}

void my_table_model::set_trucks()
{
	QModelIndex top_left = createIndex(0, 0);
	QModelIndex bottom_right = createIndex(rowCount(), columnCount());
	emit layoutChanged();
	emit dataChanged(top_left, bottom_right);
}

QVariant my_table_model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:
			return QString("ID");
		case 1:
			return QString("BRAND");
		case 2:
			return QString("MILEAGE");
		case 3:
			return QString("YEAR");
		case 4:
			return QString("PRICE");
		}
	}
	else if (role == Qt::FontRole && orientation == Qt::Horizontal)
	{
		QFont f;
		f.setBold(true);
		return f;
	}
	return QVariant();
}

QString my_table_model::get_me_data(int x, int y) const
{
	return data(createIndex(x, y), Qt::DisplayRole).toString();
}

my_table_model::~my_table_model()
{

}