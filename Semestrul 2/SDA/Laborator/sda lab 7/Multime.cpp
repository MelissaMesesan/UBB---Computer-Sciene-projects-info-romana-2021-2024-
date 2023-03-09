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


Nod::Nod(TElem elem, PNod stanga, PNod dreapta) {
	this->elem = elem;
	this->stanga = stanga;
	this->dreapta = dreapta;
}// theta(1)

Multime::Multime() {
	this->radacina = nullptr;
	this->num_noduri = 0;
}// theta(1)


bool Multime::adauga(TElem elem) {
    if (this->num_noduri == 0) {
        this->radacina = initNode(elem);  
        this->num_noduri++; 
        return true;
    }

    PNod currentNode = this->radacina;
    while (true) {
        // case 2: elementul exista deja
        if (currentNode->elem == elem) {
            return false;
        }
        // case 3: adaugam in stanga unde e gol
        if (!rel(currentNode->elem, elem) && currentNode->stanga == nullptr) { //ex: 3<2 false
            PNod new_node = initNode(elem); currentNode->stanga = new_node;
            this->num_noduri++;
            return true;
        }

        // case 4: adaugam in dreapta unde e gol
        if (rel(currentNode->elem, elem) && currentNode->dreapta == nullptr)
        {
            PNod new_node = initNode(elem); currentNode->dreapta = new_node;
            this->num_noduri++;
            return true;
        }

        // mergem la urmatorul nod din arborele stang
        if (!rel(currentNode->elem, elem) && currentNode->stanga != nullptr)
            currentNode = currentNode->stanga;
        // mergem la urmatorul nod din arborele drept
        else if (rel(currentNode->elem, elem) && currentNode->dreapta!= nullptr)
            currentNode = currentNode->dreapta;
    }
}
//BC: am adaugat primul nod care este radacina
//WC: am adaugat nod pe ultimul nivel al arborelui
//=>O(n)

bool Multime::sterge_rec(PNod nod, PNod parinte, TElem elem)
{
    if (nod == nullptr)
        return false;

    if (nod->elem == elem) {
        // case1: nodul pe care vrem sa il stergem nu are descendenti
        if (nod->stanga == nullptr && nod->dreapta == nullptr) {
            // numai daca e radacina arborelui
            if (parinte == nullptr) {
                delete nod;
                this->radacina = nullptr;
                return true;
            }

            // altfel stergem parintele
            if (nod == parinte->stanga) {
                parinte->stanga = nullptr;
                delete nod;
                return true;
            }
            if (nod == parinte->dreapta) {
                parinte->dreapta = nullptr;
                delete nod;
                return true;
            }
        }

        // case2: nodul care trebuie sters nu are descendenti (stanga)
        if (nod->stanga != nullptr && nod->dreapta == nullptr) {
            // daca e radacina
            if (parinte == nullptr) {
                this->radacina = nod->stanga;
                delete nod;
                return true;
            }
            if (parinte->stanga == nod) {
                parinte->stanga = nod->stanga;
                delete nod;
                return true;
            }
            if (parinte->dreapta == nod) {
                parinte->dreapta = nod->stanga;
                delete nod;
                return true;
            }
        }

        // case3: nodul care trebuie sters nu are descendenti (dreapta)
        if (nod->stanga == nullptr && nod->dreapta != nullptr) {
            // if it's radacina
            if (parinte == nullptr) {
                this->radacina = nod->dreapta;
                delete nod;
                return true;
            }
            if (parinte->stanga == nod) {
                parinte->stanga = nod->dreapta;
                delete nod;
                return true;
            }
            if (parinte->dreapta == nod) {
                parinte->dreapta = nod->dreapta;
                delete nod;
                return true;
            }
        }

        // case4: nodul care trebuie sters are 2 descendenti
        if (nod->stanga != nullptr && nod->dreapta != nullptr) {
            // luam valoare maxim din partea arborelui stang a nodului
            PNod maximum_nod = maximum(nod);
            TElem value = maximum_nod->elem;

            // stergem nodul maxim
            sterge_rec(this->radacina, nullptr, value);

            // punem nodul maxim in nodul curent
            nod->elem = value;
            return true;
        }
    }

    // daca inca nu a fost gasit
    if (!rel(nod->elem, elem))
        return sterge_rec(nod->stanga, nod, elem);
    else return sterge_rec(nod->dreapta, nod, elem);
} //best case: O(n); worst case O(n^2) -> case4

PNod Multime::maximum(PNod nod)
{
	if (nod == nullptr)
		return nullptr;

	nod = nod->stanga;

	// incepem din partea dreapta
	while (nod->dreapta!= nullptr)
		nod = nod->dreapta;
	return nod;
} // O(n)

bool Multime::sterge(TElem elem) {
	if (!cauta(elem))
		return false;

	if (sterge_rec(this->radacina, nullptr, elem))
	{
		this->num_noduri--;
		return true;
	}
	else return false;
} // la fel ca la sterge_rec


bool Multime::cauta(TElem elem) const {
    PNod node = this->radacina;
    // case 1: arborele nu exista
    if (node == nullptr)
        return false;

    while (true) {
        // case 2: elementul a fost gasit
        if (node->elem == elem)
            return true;
        // case 3: ar trebui sa fie in stanga dar nu e => urmatorul nod stang
        if (!rel(node->elem, elem) && node->stanga != nullptr) {
            node = node->stanga; continue;
        }
        // case 4: ar trebui sa fie in drreapta dar nu e => urmatorul nod dreapt
        if (rel(node->elem, elem) && node->dreapta != nullptr) {
            node = node->dreapta; continue;
        }
        // case 5: ajunge la capatul din stanga si nu afost gasit
        if (!rel(node->elem, elem) && node->stanga == nullptr)
            return false;
        // case 6: ajunge la capatul din dreapta si nu afost gasit
        if (rel(node->elem, elem) && node->dreapta == nullptr)
            return false;
    }
} // O(n)


int Multime::dim() const {
	return this->num_noduri;
} // theta(1)



bool Multime::vida() const {
	if (this->radacina == nullptr)
		return true;
	return false;
} // theta(1)

IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

void Multime::distrug_rec(PNod p) {
	/*if (p != nullptr) {
		distrug_rec(p->stanga);
		distrug_rec(p->dreapta);
		delete p;
	}*/
}

Multime::~Multime() {
	distrug_rec(this->radacina);
}

PNod Multime::initNode(TElem e) const
{
    auto* nod = new Nod(e, nullptr, nullptr);
    return nod;

} //theta(1)
