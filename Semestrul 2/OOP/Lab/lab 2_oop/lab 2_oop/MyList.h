#pragma once
#include "tranzactie.h"
#define  TRANZACTIA_EXISTA_DEJA -2
#define TRANZACTIA_NU_EXISTA -1
#define SUCCES 0

typedef Transaction ElemType;
typedef struct {
	ElemType elem[50];
	int lg;
}MyList;


MyList createEmpty()


/*
	adauga tranzactie
*/

int adauga(MyList* l, Transaction t);

int sterge(MyList* l, Transaction t);


int modifica(MyList* lista, Transaction t_vechi, Transaction t_nou);


int setTransaction(MyList* lista, int poz, Transaction t_nou);


int find(MyList* l, Transaction t);


Transaction getTransaction(MyList* l, int poz);


int size(MyList* l);

