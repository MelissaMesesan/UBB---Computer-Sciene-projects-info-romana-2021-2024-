#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>

using namespace std;

Nod::Nod(TElem e, PNod urm) {
	this->e = e;
	this->urm = urm;
}

MD::MD() {
	/* de adaugat */
	this->m = 10;
	this->num_elem = 0;
	for (int i = 0; i < 10; i++) {
		this->keys.push_back(nullptr);
	}
	
}


void MD::adauga(TCheie c, TValoare v) {
	/* de adaugat */
	int key = this->hashCode(c) % this->m;
	TElem e = make_pair(c, v);
	PNod value = new Nod(e, nullptr);
	if (this->keys[key] == nullptr)
	{
		this->keys[key] = value;
		this->num_elem++;
		return;
	}
	PNod p = this->keys[key];
	while (p->urm != nullptr) {
		p = p->urm;
	}
	p->urm = value;
	this->num_elem++;
}


bool MD::sterge(TCheie c, TValoare v) {
	/* de adaugat */
	int key = this->hashCode(c) % this->m;
	if(this->keys[key] == nullptr)
		return false;

	if (this->keys[key]->e.first == c && this->keys[key]->e.second == v) {
		this->keys[key] = this->keys[key]->urm;
		this->num_elem--;
		return true;
	}
	PNod p = this->keys[key];
	PNod ant = p;
	p = p->urm;
	while (p != nullptr) {
		if (p->e.first == c && p->e.second == v) {
			ant->urm = p->urm;
			this->num_elem--;
			return true;
		}
		ant = p;
		p = p->urm;
	}
	return false;
}


vector<TValoare> MD::cauta(TCheie c) const {
	/* de adaugat */
	int key = this->hashCode(c) % this->m;
	if (this->keys[key] == nullptr)
		return vector<TValoare>();

	PNod p = this->keys[key];
	vector<TValoare> res;
	while (p != nullptr) {
		res.push_back(p->e.first);
		p = p->urm;
	}

	return res;
	
}


int MD::dim() const {
	/* de adaugat */
	return this->num_elem;
}


bool MD::vid() const {
	/* de adaugat */
	for (int i = 0; i < this->m;i++) {
		if (keys[i] != nullptr)
			return false;
		} 
	return true;
}

IteratorMD MD::iterator() const {
	return IteratorMD(*this);
}

int MD::hashCode(TCheie cheie) const {
	return cheie + 30000;
}

MD::~MD() {
	/* de adaugat */
}

