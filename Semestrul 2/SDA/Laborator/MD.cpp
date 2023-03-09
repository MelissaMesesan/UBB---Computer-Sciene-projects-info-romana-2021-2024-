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
	// The BC = WC = AC = Theta(1)
	this->m = 10;
	this->num_elem = 0;
	for (int i = 0; i < 10; i++) {
		this->keys.push_back(nullptr);
	}
	
}

TValoare MD::most_frequent_value() {
	vector<TValoare> values;
	vector<int> frequency;
	bool in_vector = false;

	for (int pos = 0; pos < this->m; pos++) {
		PNod nod = this->keys[pos];
		while (nod != nullptr) {
			in_vector = false;
			TValoare value = nod->e.second;
			for (int i=0; i<values.size(); i++)
				if (values[i] == value) {
					in_vector = true;
					frequency[i]++;
					break;
				}
			if (in_vector == false) {
				values.push_back(value);
				frequency.push_back(1);
			}
			nod = nod->urm;
		}
	}

	int max_val = -1;
	int max_val_pos = -1;

	for (int i = 0; i < frequency.size(); i++) {
		if (frequency[i] > max_val) {
			max_val = frequency[i];
			max_val_pos = i;
		}
	}

	if (max_val_pos < 0) return NULL;

	return values[max_val_pos];
}


void MD::adauga(TCheie c, TValoare v) {
	// The BC = WC = AC = Theta(1)
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
	// The BC = WC = AC = Theta(1)
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
	// The BC = WC = AC = Theta(1)
	
	int key = this->hashCode(c) % this->m;
	if (this->keys[key] == nullptr)
		return vector<TValoare>();

	PNod p = this->keys[key];
	vector<TValoare> res;
	while (p != nullptr) {
		if (p->e.first == c) {
			res.push_back(p->e.second);
		}
		p = p->urm;
	}

	return res;
	
}


int MD::dim() const {
	// The BC = WC = AC = Theta(1)
	return this->num_elem;
}


bool MD::vid() const {
	// The BC = WC = AC = Theta(1)
	for (int i = 0; i < this->m;i++) {
		if (keys[i] != nullptr)
			return false;
		} 
	return true;
}

IteratorMD MD::iterator() const {
	// The BC = WC = AC = Theta(1)
	return IteratorMD(*this);
}

int MD::hashCode(TCheie cheie) const {
	// The BC = WC = AC = Theta(1)
	return cheie + 30000;
}


MD::~MD() {
	
}


