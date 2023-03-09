#pragma once
#include "Controller.h"
#include <QtWidgets\qlabel.h>
#include <QtWidgets\qboxlayout.h>
#include <QtWidgets\qlineedit.h>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qslider.h>
#include <QtWidgets\qtablewidget.h>
#include <qmessagebox.h>

class GuiType : public QWidget {
private:
	string type;
	void initGui();
public:
	GuiType(const string t) {
		type = t;
		QWidget::setWindowTitle(QString::fromStdString(t));
		initGui();
	}
	void update(int k);


	QLabel* lbl;
	QHBoxLayout* lay;

};
class GUI : public QWidget {
private:
	void initGui();
	void initSignals();
	Controller* ctrl;

public:
	GUI(Controller* c) {
		initGui();
		initSignals();
		ctrl = c;

	}

	vector<GuiType> listaFestre;

	//void paintEvent(QPaintEvent* event);

	void reloadList(vector<Produs> all);
	QHBoxLayout* mainL1;
	QVBoxLayout* mainL2;
	QHBoxLayout* mainL;
	QVBoxLayout* lay1;
	QVBoxLayout* lay2;
	QVBoxLayout* lay3;

	QPushButton* btnAdd;

	QLineEdit* inputId;
	QLineEdit* inputName;
	QLineEdit* inputType;
	QLineEdit* inputPrice;

	QLabel* labelId;
	QLabel* labelName;
	QLabel* labelType;
	QLabel* labelPrice;

	QTableWidget* table;

	QSlider* sld;




};