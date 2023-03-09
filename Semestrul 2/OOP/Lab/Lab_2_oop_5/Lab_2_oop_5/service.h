#pragma once
#include "repo.h"
#include "validator.h"
#define SORTAT 4
#define NESORTAT 5
#define FILTRU_INVALID 6

typedef struct Service {
	ListaTranzactii* lista;
	int(*validare)(Tranzactie*);
}Service;

Service* creeareService(ListaTranzactii* lista, int(*validare)(Tranzactie*));
void destroyElemsServ(Service* cont);
void distrugeService(Service* cont);
int getDimCont(Service* cont);
Vector* getAllElems(Service* cont);
ListaTranzactii* getLista(Service* cont);
int adaugare(Service* cont, int zi, int suma, char* descriere, char* tip);
Tranzactie* stergere(Service* cont, char* descriere, char* tip);
Tranzactie* actualizare(Service* cont, char* descriere, char* tip, int zi_nou, int suma_noua, char* descriere_noua, char* tip_nou);
Vector* filtrare(Service* cont, char* tip, int zi, int suma);
Vector* sortare(Service* cont, char* filtru);
void testService();