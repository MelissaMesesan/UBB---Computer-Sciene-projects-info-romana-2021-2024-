#include "Songs.h"
#include <QtWidgets/QApplication>

#include "Repo.h"
#include "service.h"
#include "modify_widget.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	Repo repo{ "song.txt" };
	service serv{ repo };

	exam1 w{ serv };
	w.show();
	return a.exec();
	return 0;
}