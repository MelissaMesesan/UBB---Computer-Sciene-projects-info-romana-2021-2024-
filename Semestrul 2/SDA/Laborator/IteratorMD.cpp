#include "IteratorMD.h"
#include "MD.h"

using namespace std;

IteratorMD::IteratorMD(const MD& c): c(c) {
	// The BC = AC = Theta(1), WC = Theta(m)

	this->pozCurent = 0;
	deplasare();
}

TElem IteratorMD::element() const{
	// The BC = WC = AC = Theta(1). 
	return this->curent->e;
}

bool IteratorMD::valid() const {
	// The BC = WC = AC = Theta(1)
	if (this->pozCurent < this->c.dim() && this->curent != NULL)
		return true;
	return false;
}

void IteratorMD::urmator() {
	// The BC = AC = Theta(1), WC = Theta(m)
	this->curent = this->curent->urm;
	if (this->curent == NULL) {
		this->pozCurent++;
		deplasare();
	}
}

void IteratorMD::prim() {
	// The BC = AC = Theta(1), WC = Theta(m)
	this->pozCurent = 0;
	deplasare();
}

void IteratorMD::deplasare() {
	while (this->pozCurent < this->c.m && this->c.keys[this->pozCurent] == NULL) {
		this->pozCurent++;
	}
	if (this->pozCurent < this->c.m) {
		this->curent = this->c.keys[this->pozCurent];
	}
}
