#include "GUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Repository repo;
	Controller ctrl{ repo };
	GUI gui{ &ctrl };
	gui.show();
	gui.reloadList(ctrl.getSortedPrice());
	vector<Produs> adaugate;
	vector<GuiType*> sirFinal;
	auto all = ctrl.getSortedPrice();
	for (const auto& el : all) {
		auto i = find_if(adaugate.begin(), adaugate.end(), [&](const Produs& a) {
			return a.getType() == el.getType();
			});
		if (i == adaugate.end()) {
			adaugate.push_back(el);
			GuiType* g = new GuiType{ el.getType() };
			sirFinal.push_back(g);
		}
	}
	for (auto& el : sirFinal) {
		(*el).show();
	}

	return a.exec();
}
