#include "GUI.h"
#include <qpainter.h>



void GuiType::initGui() {
	lay = new QHBoxLayout;
	lbl = new QLabel("1");

	lay->addWidget(lbl);

	setLayout(lay);
}

void GuiType::update(int k) {
	lbl->setText(QString::fromStdString(to_string(k)));
}

void GUI::initGui() {

	mainL1 = new QHBoxLayout;
	mainL2 = new QVBoxLayout;
	mainL = new QHBoxLayout;
	lay1 = new QVBoxLayout;
	lay2 = new QVBoxLayout;
	lay3 = new QVBoxLayout;

	sld = new QSlider;

	btnAdd = new QPushButton("Adauga");

	inputId = new QLineEdit;
	inputName = new QLineEdit;
	inputType = new QLineEdit;
	inputPrice = new QLineEdit;

	labelId = new QLabel("Id: ");
	labelName = new QLabel("Nume: ");
	labelType = new QLabel("Tip: ");
	labelPrice = new QLabel("Pret : ");

	table = new QTableWidget;

	lay1->addStretch();
	lay1->addWidget(labelId);
	lay1->addWidget(labelName);
	lay1->addWidget(labelType);
	lay1->addWidget(labelPrice);
	lay1->addStretch();

	lay2->addStretch();
	lay2->addWidget(inputId);
	lay2->addWidget(inputName);
	lay2->addWidget(inputType);
	lay2->addWidget(inputPrice);
	lay2->addStretch();

	lay3->addStretch();
	lay3->addWidget(btnAdd);
	lay3->addStretch();
	lay3->addWidget(table);
	lay3->addStretch();


	mainL1->addLayout(lay1);
	mainL1->addLayout(lay2);
	mainL1->addLayout(lay3);

	mainL2->addStretch();
	mainL2->addWidget(sld);
	mainL2->addStretch();

	mainL->addLayout(mainL1);
	mainL->addLayout(mainL2);

	setLayout(mainL);

}
void GUI::reloadList(vector<Produs> all) {

	table->setRowCount(all.size());
	table->setColumnCount(4);

	int i{ 0 };
	for (const auto& el : all) {
		table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(to_string(el.getId()))));
		table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(el.getName())));
		table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(el.getType())));
		table->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(to_string(el.getPrice()))));


		i++;
	}
}


void GUI::initSignals() {
	QPushButton::connect(btnAdd, &QPushButton::clicked, [&]() {
		int id = inputId->text().toInt();
		string name = inputName->text().toStdString();
		string type = inputType->text().toStdString();
		double price = inputPrice->text().toDouble();

		ctrl->addToRepo(id, name, type, price);

		auto all = ctrl->getSortedPrice();
		reloadList(all);


		for (auto& el : listaFestre) {
			el.update(5);
		}
		});

	/*QSlider::connect(sld, &QSlider::sliderMoved, [&]() {
		int val = sld->value();
		int i = 0;
		for (auto const& el : ctrl->getSortedPrice()) {
			if (el.getPrice() < val) {
				table->item(i, 0)->setBackgroundColor(QColor::fromRgb(255, 0, 0, 255));
				table->item(i, 1)->setBackgroundColor(QColor::fromRgb(255, 0, 0, 255));
				table->item(i, 2)->setBackgroundColor(QColor::fromRgb(255, 0, 0, 255));
				table->item(i, 3)->setBackgroundColor(QColor::fromRgb(255, 0, 0, 255));
			}
			else {
				table->item(i, 0)->setBackgroundColor(Qt::red);
				table->item(i, 1)->setBackgroundColor(QColor::fromRgb(255, 255, 255, 255));
				table->item(i, 2)->setBackgroundColor(QColor::fromRgb(255, 255, 255, 255));
				table->item(i, 3)->setBackgroundColor(QColor::fromRgb(255, 255, 255, 255));
			}
			i++;
		}
		});*/

}