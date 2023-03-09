#include "IteratorMultime.h"
#include "Multime.h"
#include <exception>


IteratorMultime::IteratorMultime(const Multime& m): mult(m) {
	this->currentNode = nullptr;
	this->currentPosition = 0;
	this->stack.size = 0;
	this->stack.array = new PNod[this->mult.num_noduri];

	InOrderTraversal(this->mult.radacina);

	if (this->stack.size != 0)
		this->currentNode = this->stack.array[this->currentPosition];
	else
		this->currentNode = nullptr;
}// O(n)

TElem IteratorMultime::element() const {
        if (!valid())
        throw exception();
    return this->currentNode->elem;
}//theta(1)

bool IteratorMultime::valid() const {
        if (this->currentPosition >= this->stack.size)
        return false;
    return true;
}//theta(1)

void IteratorMultime::urmator() {
        if (!valid())
        throw exception();
    this->currentPosition++;
    this->currentNode = this->stack.array[this->currentPosition];
}//theta(1)

void IteratorMultime::prim() {
	
    this->currentPosition = 0;
    this->currentNode = this->stack.array[0];
}//theta(1)

void IteratorMultime::InOrderTraversal(PNod node) {
    auto** auxiliaryStack = new PNod [this->mult.num_noduri];
    int index = 0;
    PNod currentNodeStack = node;

    // se pun in stiva toate nodurile stangi
    while (currentNodeStack != nullptr)
    {
        auxiliaryStack[index] = currentNodeStack;
        index++;
        currentNodeStack = currentNodeStack->stanga;
    }

    // cat timp stiva nu e goala
    while (index != 0)
    {
        // pop din stiva
        currentNodeStack = auxiliaryStack[index - 1];
        index--;

        this->stack.array[this->stack.size++] = currentNodeStack;
        // se viziteaza nodul curent (se adauga copiii din stanga a nodului parinte)
        currentNodeStack = currentNodeStack->dreapta;
        while (currentNodeStack != nullptr)
        {
            // push
            auxiliaryStack[index] = currentNodeStack;
            index++;
            currentNodeStack = currentNodeStack->stanga;
        }
    }
}
//complexitate timp: O(n)
//complexitate spatiu extra: O(n);

void IteratorMultime::anterior() {
    if (!valid())
        throw exception();

    if (this->currentPosition == 0)
        this->currentPosition = this->stack.size; //e invalid
    else {
        this->currentPosition--;
        this->currentNode = this->stack.array[this->currentPosition];
    }
} // theta(1)

