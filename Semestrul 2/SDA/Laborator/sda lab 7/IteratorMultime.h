#pragma once
#include "Multime.h"
#include <utility>

using namespace std;


typedef int TElem;

struct Stack
{
	PNod* array;
	int size;
};


class IteratorMultime
{
	friend class Multime;

private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMultime(const Multime& m);

	//contine o referinta catre containerul pe care il itereaza
	const Multime& mult;

	/* aici e reprezentarea  specifica a iteratorului */
	
	PNod currentNode;
	Stack stack;
	int currentPosition;
	void InOrderTraversal(PNod node);

public:

		//reseteaza pozitia iteratorului la inceputul containerului
		void prim();

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
		void urmator();

		//verifica daca iteratorul e valid (indica un element al containerului)
		bool valid() const;

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
		TElem element() const;

		void anterior();
};


