#include "Multime.h"
#include "IteratorMultime.h"
#include <iostream>

using namespace std;

//o posibila relatie
bool rel(TElem e1, TElem e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}

Multime::Multime(/*Relatie r*/) {
	this->root = nullptr;
	this->r = r;
	this->length = 0;
	// theta(1)
}


bool Multime::adauga(TElem e) {
    // case 1: adauga radacina
    if (this->length == 0) {
        this->root = initNode(e);  this->length++; return;
    }

    Nod* currentNode = this->root;
    while (true) {
        // case 2: elementul exista deja
        if (currentNode->info.first == e) {
            currentNode->info.second++; this->length++; return;
        }
        // case 3: adauga in stanga unde e gol
        if (!this->r(currentNode->info.first, e) && currentNode->left == nullptr) { //ex: 3<2 false
            Nod* new_node = initNode(e); currentNode->left = new_node;
            this->length++;
            return;
        }

        // case 4: adauga in dreapta unde e gol
        if (this->r(currentNode->info.first, e) && currentNode->right == nullptr)
        {
            Nod* new_node = initNode(e); currentNode->right = new_node;
            this->length++;
            return;
        }

        // merge la urmatorul nod in arborele din stanga
        if (!this->r(currentNode->info.first, e) && currentNode->left != nullptr)
            currentNode = currentNode->left;
        // merge la urmatorul nod in arborele din dreapta
        else if (this->r(currentNode->info.first, e) && currentNode->right != nullptr)
            currentNode = currentNode->right;
    }
	return false;

    //BC: we want to add the first node, which will became the root
    //WC: we want to add a node on the last level in the tree
    //=>O(n)

}


bool Multime::sterge(TElem e) {
	/* de adaugat */
	return false;
}


bool Multime::cauta(TElem elem) const {
	/* de adaugat */
	return false;
}


int Multime::dim() const {
	/* de adaugat */
	return 0;
}



bool Multime::vida() const {
	/* de adaugat */
	return true;
}

IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}


Multime::~Multime() {
	/* de adaugat */
}






