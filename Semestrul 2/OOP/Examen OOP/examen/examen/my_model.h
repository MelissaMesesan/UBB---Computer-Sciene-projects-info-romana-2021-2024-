#pragma once

#include <QAbstractTableModel>
#include "Service.h"

class My_model : public QAbstractTableModel
{
private:
	Service& serv;
public:
	My_model(Service& serv) : serv{ serv } {};

	/*
		numara cate randuri sunt
		out: size din get_all
	*/
	virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	/*
		numara cate coloane sunt 
		out: int 6 (id, titlu, artist, gen, nr autori, nr gen)
	*/
	virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	/*
		seteaza pt fiecare coloana ca trebuie sa se puna
	*/
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	/*
		se creeaza index automat
	*/
	void set_songs();

	~My_model();
};