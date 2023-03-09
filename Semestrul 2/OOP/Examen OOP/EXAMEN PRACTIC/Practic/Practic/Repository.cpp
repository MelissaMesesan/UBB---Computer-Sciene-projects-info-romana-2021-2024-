#include "Repository.h"
#include <fstream>

void Repository::add(const Produs& p) {
	all.push_back(p);
	writeToFis();
}
void Repository::writeToFis() {
	ofstream f(fName);
	int i;
	for (i = 0; i < all.size() - 1; i++) {
		f << all[i].getId() << endl;
		f << all[i].getName() << endl;
		f << all[i].getType() << endl;
		f << all[i].getPrice() << endl;
	}
	f << all[i].getId() << endl;
	f << all[i].getName() << endl;
	f << all[i].getType() << endl;
	f << all[i].getPrice();
}

vector<Produs> Repository::getAll() {
	return all;
}

void Repository::loadFromFile() {
	ifstream f(fName);
	all.clear();
	int id;
	string name, type;
	double price;
	while (!f.eof()) {

		f >> id;
		f >> name;
		f >> type;
		f >> price;
		Produs p{ id ,name,type, price };
		all.push_back(p);
	}
}