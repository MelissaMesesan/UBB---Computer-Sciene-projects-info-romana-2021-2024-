#pragma once
#include "MD.h"

class MD;

class IteratorMD
{
	friend class MD;

private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMD(const MD& c);

	//contine o referinta catre containerul pe care il itereaza
	const MD& c;

	// daca lista de la locația curenta pozCurent a fost iterata pâna la final (curent devine invalid),
	// deplaseaza pozCurent pe urmatoarea locație din tabela care conține o lista nevida si 
	// poziționeaza curentpe primul nod din aceasta lista.
	void deplasare();

	
	/* aici e reprezentarea  specifica a iteratorului */
	int pozCurent;
	PNod curent;
	
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
};

