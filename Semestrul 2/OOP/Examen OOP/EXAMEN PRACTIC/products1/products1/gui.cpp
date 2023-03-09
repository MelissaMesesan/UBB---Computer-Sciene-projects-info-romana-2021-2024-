#include "gui.h"
#include "service.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QSlider>
#include <QListWidget>
#include <QGroupBox>
#include <QComboBox>
#include "modelView.h"
#include <QtCore>
#include <iostream>
#include <QColor>
#include <QVariant>

using namespace std;

void GUI::initialize() {
	QHBoxLayout* lyMain = new QHBoxLayout;
	this->setLayout(lyMain);

	//left
	QWidget* left = new QWidget;
	QVBoxLayout* lyLeft = new QVBoxLayout;
	left->setLayout(lyLeft);

	QWidget* form = new QWidget;
	QFormLayout* lyForm = new QFormLayout;
	form->setLayout(lyForm);
	editId = new QLineEdit;
	editName = new QLineEdit;
	editType = new QLineEdit;
	editPrice = new QLineEdit;

	lyForm->addRow(lblId, editId);
	lyForm->addRow(lblName, editName);
	lyForm->addRow(lblType, editType);
	lyForm->addRow(lblPrice, editPrice);

	btnAdd = new QPushButton("adauga");
	lyForm->addWidget(btnAdd);
	lyLeft->addWidget(form);

	btnFilter = new QPushButton("filtreaza");
	lyLeft->addWidget(btnFilter);

	priceSld = new QSlider;

	priceSld->setMinimum(1.0);
	priceSld->setMaximum(100.0);
	lyMain->addWidget(priceSld);

	QWidget* right = new QWidget;
	QVBoxLayout* lyRight = new QVBoxLayout;
	right->setLayout(lyRight);

	lyRight->addWidget(tableV);

	lyMain->addWidget(left);
	lyMain->addWidget(right);

}

void GUI::connect() {
	QObject::connect(btnAdd, &QPushButton::clicked, this, &GUI::guiAdd);

	QObject::connect(btnFilter, &QPushButton::clicked, this, [&]() {
		double price = priceSld->value();
		this->pret = price;
		model->setProds(srv.getAll());
		reloadTable(srv.getAll());
		});
}

void GUI::reloadTable(vector<Product>p) {
	model->setProds(p);

}

void GUI::guiAdd() {
	try {

		int id = editId->text().toInt();
		string name = editName->text().toStdString();
		string type = editType->text().toStdString();
		double price = editPrice->text().toDouble();

		editId->clear();
		editName->clear();
		editType->clear();
		editPrice->clear();

		srv.Add(id, name, type, price);
		this->reloadTable(srv.getAll());
	}
	catch (RepoException& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.getErrorMessage()));
	}
	
	
	this->reloadTable(srv.getAll());
	
}