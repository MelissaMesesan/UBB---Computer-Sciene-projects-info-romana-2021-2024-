//2 a (1p)
#include <iostream>
using namespace std;
int except(bool thrEx) {
	if (thrEx) {
		throw 2;
	}
	return 3;
}
int main() {
	try {
		cout << except(1 < 1);
		cout << except(true);
		cout << except(false);
	}
	catch (int ex) {
		cout << ex;
	}
	cout << 4;
	return 0;
}