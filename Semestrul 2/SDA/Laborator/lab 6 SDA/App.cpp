#include <iostream>
#include "TestExtins.h"
#include "TestScurt.h"
#include "MD.h"
using namespace std;

int main() {

	MD *md = new MD();
	md->adauga(1, 1);
	md->adauga(2, 2);
	md->adauga(3, 3);
	md->adauga(1, 4);
	md->adauga(4, 1);
	md->adauga(5, 1);
	md->adauga(6, 1);
	md->adauga(6, 2);


	cout << "Most frequent: " << md->most_frequent_value() << endl;


testAll();
testAllExtins();

	cout<<"End";

}
