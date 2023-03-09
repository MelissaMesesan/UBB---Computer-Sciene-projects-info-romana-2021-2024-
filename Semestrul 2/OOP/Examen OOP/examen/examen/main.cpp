#include "Examen.h"
#include <QtWidgets/QApplication>
#include <fstream>
#include "Repo.h"
#include "service.h"
#include "modify_widget.h"


void test_songs()
{
	Song s{ 1, "a", "b", "pop" };

	assert(s.get_id() == 1);
	assert(s.get_artist() == std::string("a"));
	assert(s.get_title() == std::string("b"));
	assert(s.get_genre() == std::string("pop"));
}



int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	Repo repo{ "song.txt" };
	Service serv{ repo };

	GUI w{ serv };
	w.show();
	return a.exec();
	test_songs();
	return 0;
}