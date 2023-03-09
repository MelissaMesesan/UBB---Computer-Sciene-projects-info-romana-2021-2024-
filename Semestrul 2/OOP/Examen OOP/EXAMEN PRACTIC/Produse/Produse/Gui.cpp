#include "Gui.h"

void Gui::initButtons()
{
	/*
	Creeaza interfata grafica
	*/
	QVBoxLayout* mainLay = new QVBoxLayout;
	this->setLayout(mainLay);

	QHBoxLayout* horLay = new QHBoxLayout;
	mainLay->addLayout(horLay);
	horLay->addWidget(table);

	QVBoxLayout* colLay = new QVBoxLayout;
	horLay->addLayout(colLay);

	QFormLayout* form = new QFormLayout;
	form->addRow(new QLabel{ "id" }, id);
	form->addRow(new QLabel{ "name" }, name);
	form->addRow(new QLabel{ "type" }, type);
	form->addRow(new QLabel{ "price" }, price);
	colLay->addLayout(form);
	colLay->addWidget(pretSlider);

	QHBoxLayout* buttons = new QHBoxLayout;
	buttons->addWidget(addBtn);
	colLay->addLayout(buttons);

	slider->setOrientation(Qt::Horizontal);
	colLay->addWidget(slider);

	mainLay->addStretch();
}

void Gui::initSignals()
{
	QObject::connect(addBtn, &QPushButton::clicked, [&]() {
		/*
		Connectarea butonului de adauga
		se adauga un produs cu campuri luate din liniile de editare
		*/
		int idInt = id->text().toInt();
		string nameS = name->text().toStdString();
		string typeS = type->text().toStdString();
		double priceD = price->text().toDouble();
		try {
			serv.add(idInt, nameS, typeS, priceD);
			loadAll(serv.getAll());
		}
		catch (ValidateException& ex) {
			QMessageBox::warning(nullptr, "eroare", QString::fromStdString(ex.getErrors()));
		}
		catch (RepoError& ex)
		{
			QMessageBox::warning(nullptr, "eroare", QString::fromStdString(ex.getErrors()));
		}
		});
	QObject::connect(slider, &QSlider::valueChanged, [&]() {
		pretSlider->setText(QString::fromStdString(std::to_string(slider->value())));
		loadAll(serv.getAll());
		});
}

void Gui::loadAll(vector<Prod> all)
{
	/*
	Reincarca toate elementele
	in: all
	pre: all - vector de produse
	*/
	sort(all.begin(), all.end(), [](const Prod& p1, const Prod& p2) {
		return p1.getPrice() < p2.getPrice(); });
	model->refresh(all, slider->value());
}

void Gui::create(const vector<Prod>& all)
{
	/*
	Cream o fereastra pt fiecare tip diferit de produs
	in: all
	pre: all - vector de produse
	*/
	unordered_map<string, int> d;
	for (auto& prod : all) {
		d[prod.getType()]++;
	}
	for (auto& tip : d) {
		new GuiProd(tip.first, serv);
	}
}

void GuiProd::update()
{
	/*
	Actualizeaza numarul de elemente corespunzatoare ferestrei
	*/
	int count = 0;
	vector<Prod> all = serv.getAll();
	count = count_if(all.begin(), all.end(), [&](const Prod& p) {return p.getType() == type; });
	nr->setText(QString::fromStdString(std::to_string(count)));
}