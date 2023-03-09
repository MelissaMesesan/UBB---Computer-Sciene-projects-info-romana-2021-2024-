#include "Tractoare.h"
#include "TableViewTrucks.h"
#include "ListViewTrucks.h"
#include "DrawTrucks.h"
#include <QtWidgets/QApplication>

#include "Repo.h"
#include "Service.h"
#include "Validator.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	Repo repo{ "trucks.txt" };
	Validator validator{};
	Service service{ repo, validator };


	Trucks_GUI w{ service };
	service.add_observer(&w);

	TableViewTrucks tw{ service };
	service.add_observer(&tw);

	ListViewTrucks lw{ service };
	service.add_observer(&lw);

	DrawTrucks dt{ service };
	service.add_observer(&dt);

	w.show();
	tw.show();
	lw.show();
	dt.show();

	return a.exec();
}