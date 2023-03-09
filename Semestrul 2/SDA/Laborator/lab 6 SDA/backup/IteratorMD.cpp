#include "IteratorMD.h"
#include "MD.h"

using namespace std;

IteratorMD::IteratorMD(const MD& c): c(c) {
	/* de adaugat */

	//this->c = c.keys;
	this->pozCurent = 0;
	deplasare();
}

TElem IteratorMD::element() const{
	return this->curent->e;
}

bool IteratorMD::valid() const {
	/* de adaugat */
	if (this->pozCurent < this->c.dim() && this->curent != NULL)
		return true;
	return false;
}

void IteratorMD::urmator() {
	/* de adaugat */
	this->curent = this->curent->urm;
	if (this->curent == NULL) {
		this->pozCurent++;
		deplasare();
	}
}

void IteratorMD::prim() {
	/* de adaugat */
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
