#pragma once
#include "Tranzactie.h"
#include "vector.h"
#define TRANZACTIA_EXISTA_DEJA -2
#define TRANZACTIA_NU_EXISTA -1
#define SUCCES 0

typedef struct ListaTranzactii {
	Vector* vect;
} ListaTranzactii;

ListaTranzactii* creeareLista();
void destroyElemsRepo(ListaTranzactii* lista);
void distrugeLista(ListaTranzactii* lista);
int getDimList(ListaTranzactii* lista);
Vector* getVect(ListaTranzactii* lista);
int adaugaTranzactie(ListaTranzactii* lista, Tranzactie* of);
Tranzactie* stergeTranzactie(ListaTranzactii* lista, Tranzactie* of);
Tranzactie* modificaTranzactie(ListaTranzactii* lista, Tranzactie* of_vechi, Tranzactie* of_nou);
Tranzactie* setTranzactie(ListaTranzactii* lista, int poz, Tranzactie* of_nou);
int cautaTranzactie(ListaTranzactii* lista, Tranzactie* of);
Tranzactie* getTranzactie(ListaTranzactii* lista, int poz);
void testRepo();