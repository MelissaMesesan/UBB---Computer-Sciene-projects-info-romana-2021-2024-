#pragma once
#include "qwidget.h"
#include "qpushbutton.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "qlistwidget.h"
#include "qtablewidget.h"
#include "qlistview.h"
#include "qtableview.h"
#include "qmessagebox.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "qformlayout.h"
#include "qgraphicsview.h"
#include "qgraphicsscene.h"
#include "qslider.h"
#include "qgraphicsrectitem"
#include "qpainter.h"
#include "Service.h"
#include "MyTableModel.h"
#include <algorithm>
#include <unordered_map>
#include "Obs.h"

class Gui :public QWidget {
	Service& serv;
	QTableView* table = new QTableView;
	MyTableModel* model;

	QLineEdit* id = new QLineEdit;
	QLineEdit* name = new QLineEdit;
	QLineEdit* type = new QLineEdit;
	QLineEdit* price = new QLineEdit;

	QPushButton* addBtn = new QPushButton{ "add" };
	QSlider* slider = new QSlider;
	QLabel* pretSlider = new QLabel;

	void initButtons();
	void initSignals();
	void loadAll(vector<Prod> all);
	void create(const vector<Prod>& all);
public:
	Gui(Service& serv) :serv{ serv } {
		initButtons();
		initSignals();
		model = new MyTableModel(serv.getAll());
		table->setModel(model);
		loadAll(serv.getAll());
		create(serv.getAll());
	}
};

class GuiProd : public QWidget, public Observer {
	string type;
	QLabel* nr = new QLabel{ "0" };
	Service& serv;
	virtual void update()override;
	QVBoxLayout* lay = new QVBoxLayout;
public:
	GuiProd(string type, Service& serv) :type{ type }, serv{ serv } {
		this->setMaximumWidth(300);
		this->setMaximumHeight(150);
		this->setMinimumWidth(300);
		this->setMinimumHeight(100);
		serv.attach(this);
		lay->addWidget(nr);
		this->setLayout(lay);
		this->setWindowTitle(QString::fromStdString(type));
		update();
		this->show();
	}
	~GuiProd() {
		serv.detach(this);
	}

};
