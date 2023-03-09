#include "SongGUI.h"
#include <QtWidgets/QApplication>

#include "test.h"

int main(int argc, char* argv[])
{
	test_all();
	QApplication a(argc, argv);

	Repo repo{ "songs.txt" };
	Service service{ repo };
	SongGUI w{ service };
	w.show();
	return a.exec();
}