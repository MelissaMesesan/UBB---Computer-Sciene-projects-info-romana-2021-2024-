#pragma once
#include <QtWidgets/QApplication>
#include <QPushButton>
#include "service.h"
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

using namespace std;


class GUI :public QWidget {
private:
	Store& srv; double pret = 0;
	QTableView* tableV=new QTableView;
	modelView* model;

	QPushButton* btnAdd;
	QPushButton* btnFilter;

	QLabel* lblId = new QLabel{ "Id: " };
	QLabel* lblName = new QLabel{ "Nume: " };
	QLabel* lblType = new QLabel{ "Tip: " };
	QLabel* lblPrice = new QLabel{ "Pret: " };


	QLineEdit* editId;
	QLineEdit* editName;
	QLineEdit* editType;
	QLineEdit* editPrice;
	QSlider* priceSld;

	double price;

	
	
public:
	
	
	void print(vector<Product>p);
	void connect();
	void initialize();
	void reloadTable(vector<Product>p);
	GUI(Store& serv) :srv{ serv } {
		initialize();
		model = new modelView{ srv.getAll() , pret };
		reloadTable(srv.getAll());
		tableV->setModel(model);
		connect();
	}
	void guiAdd();


};