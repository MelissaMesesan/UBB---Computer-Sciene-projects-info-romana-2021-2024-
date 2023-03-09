#include <iostream>
#include "TestExtins.h"
#include "TestScurt.h"
#include "Multime.h"
#include "IteratorMultime.h"

using namespace std;


int main() {

	Multime m;

	m.adauga(3);
	m.adauga(2);
	m.adauga(1);
	m.adauga(4);
	IteratorMultime im = m.iterator();
	im.prim();
	cout << im.element() << endl;
	im.urmator();
	cout << im.element() << endl;
	im.urmator();
	cout << im.element() << endl;
	im.anterior();
	cout << im.element() << endl;
	im.anterior();
	cout << im.element() << endl;

	testAll();
	testAllExtins();

	cout<<"End";
}
