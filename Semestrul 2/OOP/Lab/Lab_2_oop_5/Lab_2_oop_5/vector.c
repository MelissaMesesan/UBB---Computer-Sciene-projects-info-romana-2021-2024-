#include "vector.h"
#include "functii.h"


Vector* creeareVector(const int cap, Compara cmp, Copie copy, Sterge del)
{
	Vector* vect = (Vector*)malloc(sizeof(Vector));
	vect->dim = 0;
	vect->cap = cap;
	vect->elems = (TElem*)malloc(sizeof(TElem) * cap);
	vect->cmp = cmp;
	vect->copy = copy;
	vect->del = del;
	return vect;
}

int getDim(Vector* vect) {
	return vect->dim;
}

void destroyElems(Vector* vect)
{
	for (int i = 0; i < vect->dim; ++i) {
		vect->del(vect->elems[i]);
	}
}

void distrugeVector(Vector* vect)
{
	free(vect->elems);
	free(vect);
}

TElem getElem(Vector* vect, int poz)
{
	return vect->elems[poz];
}

TElem setElem(Vector* vect, int poz, TElem elem)
{
	if (poz == -1) return (TElem)poz;
	TElem temp = vect->elems[poz];
	vect->elems[poz] = elem;
	return temp;
}

void setCap(Vector* vect, const int cap)
{
	vect->cap = (1 > cap) ? 1 : cap;
	vect->dim = (vect->dim < cap) ? vect->dim : cap;
	TElem* copy_vect = (TElem*)malloc(sizeof(TElem) * vect->cap);
	for (int i = 0; i < getDim(vect); ++i) {
		copy_vect[i] = vect->elems[i];
	}
	free(vect->elems);
	vect->elems = copy_vect;
}

Vector* copyVector(Vector* vect, Sterge fct)
{
	TElem temp;
	Vector* copie = creeareVector(vect->cap, vect->cmp, vect->copy, fct);
	for (int i = 0; i < getDim(vect); ++i) {
		temp = vect->copy(getElem(vect, i));
		adaugaElem(copie, temp);
	}
	return copie;
}

void adaugaElem(Vector* vect, TElem elem)
{
	if (vect->dim == vect->cap)
		setCap(vect, vect->cap * 2);
	vect->elems[vect->dim] = elem;
	vect->dim++;
}

TElem stergeElem(Vector* vect, TElem elem)
{
	int poz = cautaElem(vect, elem);
	if (poz == -1) return NULL;
	TElem temp_elem = vect->elems[poz];
	for (int i = poz; i < getDim(vect) - 1; ++i) {
		vect->elems[i] = vect->elems[i + 1];
	}
	vect->dim--;
	return temp_elem;
}

int cautaElem(Vector* vect, TElem elem)
{
	for (int i = 0; i < getDim(vect); ++i) {
		if (vect->cmp(elem, getElem(vect, i))) return i;
	}
	return -1;
}

void testVector()
{
	Vector* vect = creeareVector(0, cmp_int, copy_int, del_int);
	int a = 5, c = 6, b = 7;
	int* pa = (int*)malloc(sizeof(int));
	int* pb = (int*)malloc(sizeof(int));
	*pa = 1;
	*pb = 2;
	adaugaElem(vect, &a);
	adaugaElem(vect, &b);
	adaugaElem(vect, &a);
	adaugaElem(vect, &b);
	int poz = cautaElem(vect, &b);
	setElem(vect, poz, &a);
	assert(getDim(vect) == 4);
	assert(cautaElem(vect, &b) == 3);
	assert(cautaElem(vect, &c) == -1);
	TElem to_free = stergeElem(vect, &a);
	assert(getDim(vect) == 3);
	assert(stergeElem(vect, &c) == NULL);
	adaugaElem(vect, pa);
	poz = cautaElem(vect, pa);
	free(getElem(vect, poz));
	adaugaElem(vect, vect->copy(&c));
	poz = cautaElem(vect, &c);
	free(getElem(vect, poz));
	free(pb);
	assert(getDim(vect) == 5);
	Vector* copie = copyVector(vect, del_int2);
	destroyElems(copie);
	distrugeVector(copie);
	destroyElems(vect);
	distrugeVector(vect);
}