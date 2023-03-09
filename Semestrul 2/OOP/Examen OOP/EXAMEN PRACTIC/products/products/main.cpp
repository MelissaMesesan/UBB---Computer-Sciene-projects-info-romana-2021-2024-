#include "products.h"
#include <QtWidgets/QApplication>
#include "gui.h"
#include "service.h"
#include "repo.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Repo repo{"produse.txt"};
    Store s(repo);
    GUI gui(s);
    gui.show();
    return a.exec();
}
