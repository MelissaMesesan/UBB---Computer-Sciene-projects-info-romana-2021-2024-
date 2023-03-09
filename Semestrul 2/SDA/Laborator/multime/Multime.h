#pragma once

#include <utility>

typedef int TElem;
typedef TElem TComp;
typedef std::pair<TElem, int> TPair; // valoare + frecventa
typedef bool(*Relatie)(TElem, TElem);

#define NULL_TELEM -11111;

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
//bool rel(TElem, TElem);

class IteratorMultime;

struct Nod {

	TPair info;
	Nod* left;
	Nod* right;
};


class Multime {

	friend class IteratorMultime;

private:
	Nod* root;
	int length;
	Relatie r;

	//initializez un nou nod arborelui
	Nod *initNode(TComp e) const;

	bool delete_rec(Nod* node, Nod* parent, TElem elem);

public:
		//constructorul implicit
		Multime();

		//adauga un element in multime
		//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
		bool adauga(TElem e);

		//sterge un element din multime
		//returneaza adevarat daca elementul a existat si a fost sters
		bool sterge(TElem e);

		//verifica daca un element se afla in multime
		bool cauta(TElem elem) const;


		//intoarce numarul de elemente din multime;
		int dim() const;

		//verifica daca multimea e vida;
		bool vida() const;

		//returneaza un iterator pe multime
		IteratorMultime iterator() const;

		// destructorul multimii
		~Multime();

};

