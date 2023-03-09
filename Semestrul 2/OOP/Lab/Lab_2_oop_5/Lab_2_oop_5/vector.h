#pragma once
#include <stdlib.h>
#include <assert.h>

typedef void* TElem;
typedef int(*Compara)(TElem, TElem);
typedef TElem(*Copie)(TElem);
typedef void(*Sterge)(TElem);

typedef struct Vector {
	TElem* elems;
	int dim, cap;
	Compara cmp;
	Copie copy;
	Sterge del;
} Vector;

Vector* creeareVector(const int cap, Compara, Copie, Sterge);
int getDim(Vector* vect);
void destroyElems(Vector* vect);
void distrugeVector(Vector* vect);
void adaugaElem(Vector* vect, TElem elem);
TElem stergeElem(Vector* vect, TElem elem);
int cautaElem(Vector* vect, TElem elem);
TElem getElem(Vector* vect, int poz);
TElem setElem(Vector* vect, int poz, TElem elem);
void setCap(Vector* vect, const int cap);
Vector* copyVector(Vector* vect, Sterge del);
void testVector();
