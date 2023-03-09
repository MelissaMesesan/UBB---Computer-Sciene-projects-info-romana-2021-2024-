#include "ProduseGUI.h"
#include <QtWidgets/QApplication>

#include "Repo.h"
#include "Service.h"
//#include "modify_widget.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	Repo repo{ "produse.txt" };
	Service serv{ repo };

	ProduseGUI w{ serv };
	w.show();
	return a.exec();
	return 0;
}