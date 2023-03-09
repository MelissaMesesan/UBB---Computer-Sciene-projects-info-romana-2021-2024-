#include "repo.h"
#include <stdio.h>

/* creeaza lista */
ListaTranzactii* creeareLista()
{
	ListaTranzactii* list = (ListaTranzactii*)malloc(sizeof(ListaTranzactii));
	list->vect = creeareVector(0, equalTranzactie, copyTranzactie, distrugeTranzactie);
	return list;
}

/* distruge elementele */
void destroyElemsRepo(ListaTranzactii* lista) {
	destroyElems(lista->vect);
}

/* distruge lista */
void distrugeLista(ListaTranzactii* lista)
{
	distrugeVector(lista->vect);
	free(lista);
}

/* dimensiune */
int getDimList(ListaTranzactii* lista)
{
	return getDim(lista->vect);
}

Vector* getVect(ListaTranzactii* lista) {
	return copyVector(lista->vect, distrugeTranzactie);
}

/* adauga */
int adaugaTranzactie(ListaTranzactii* lista, Tranzactie* tr)
{
	int poz = cautaTranzactie(lista, tr);
	if (poz != -1) return TRANZACTIA_NU_EXISTA;
	adaugaElem(lista->vect, tr);
	return SUCCES;
}

/* stergere */
Tranzactie* stergeTranzactie(ListaTranzactii* lista, Tranzactie* tr)
{
	int poz = cautaTranzactie(lista, tr);
	if (poz == -1) return (Tranzactie*)TRANZACTIA_NU_EXISTA;
	return stergeElem(lista->vect, tr);
}

/* modifica */
Tranzactie* modificaTranzactie(ListaTranzactii* lista, Tranzactie* tr_vechi, Tranzactie* tr_nou)
{
	int poz = cautaTranzactie(lista, tr_vechi);
	if (poz == -1) return (Tranzactie*)TRANZACTIA_NU_EXISTA;
	Tranzactie* to_delete = setElem(lista->vect, poz, copyTranzactie(tr_nou));
	return to_delete;
}

Tranzactie* setTranzactie(ListaTranzactii* lista, int poz, Tranzactie* tr_nou)
{
	if (poz < 0 || poz > getDim(lista->vect)) return (Tranzactie*)TRANZACTIA_NU_EXISTA;
	Tranzactie* to_delete = setElem(lista->vect, poz, tr_nou);
	return to_delete;
}

/* cauta */
int cautaTranzactie(ListaTranzactii* lista, Tranzactie* tr)
{
	return cautaElem(lista->vect, tr);
}

Tranzactie* getTranzactie(ListaTranzactii* lista, int poz)
{
	return getElem(lista->vect, poz);
}

/* test */
void testRepo()
{
	ListaTranzactii* list = creeareLista(0);
	assert(getDimList(list) == 0);
	Tranzactie* tr = creeareTranzactie(10, 20, "Descrieretr", "Tiptr");
	Tranzactie* tr1 = creeareTranzactie(20, 30, "Descrieretr1", "Tiptr1");
	assert(adaugaTranzactie(list, tr) == SUCCES);
	assert(adaugaTranzactie(list, tr1) == SUCCES);
	//assert(adaugaTranzactie(list, tr1) == TRANZACTIA_EXISTA_DEJA);
	assert(equalTranzactie(getTranzactie(list, 0), tr));
	assert(equalTranzactie(getTranzactie(list, 1), tr1));
	assert(cautaTranzactie(list, tr) == 0);
	assert(getDimList(list) == 2);
	Tranzactie* to_delete = stergeTranzactie(list, tr);
	assert((int)to_delete != TRANZACTIA_NU_EXISTA);
	Tranzactie* not_found = stergeTranzactie(list, tr);
	assert((int)not_found == TRANZACTIA_NU_EXISTA);
	assert(cautaTranzactie(list, tr) == TRANZACTIA_NU_EXISTA);
	Tranzactie* temp2 = modificaTranzactie(list, tr, tr1);
	assert((int)temp2 == TRANZACTIA_NU_EXISTA);
	Tranzactie* temp4 = modificaTranzactie(list, tr1, tr);
	assert((int)temp4 != TRANZACTIA_NU_EXISTA);
	Tranzactie* temp3 = setTranzactie(list, 3, tr);
	assert((int)temp3 == TRANZACTIA_NU_EXISTA);
	Tranzactie* to_delete2 = setTranzactie(list, 0, tr1);
	assert((int)to_delete2 != TRANZACTIA_NU_EXISTA);
	Vector* copieVect = getVect(list);
	destroyElems(copieVect);
	distrugeVector(copieVect);
	distrugeTranzactie(to_delete);
	distrugeTranzactie(to_delete2);
	destroyElemsRepo(list);
	distrugeLista(list);
}