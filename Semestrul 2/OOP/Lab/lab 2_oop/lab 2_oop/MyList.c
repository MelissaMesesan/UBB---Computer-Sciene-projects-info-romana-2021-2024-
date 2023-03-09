#include "MyList.h"
#include "tranzactie.h"
#include <assert.h>
#include <string.h>

/*
	create an emty list
*/
MyList createEmpty() {
	MyList list;
	list.lg = 0;
	return list;
}


/*
	adauga tranzactie 
*/

int adauga(MyList* l, Transaction t) {
	int poz = find(l, t);
	if (poz != -1) return TRANZACTIA_EXISTA_DEJA;
	t.day = l->lg + 1;
	l->lista[l->lg] = t;
	l->lg++;
	return SUCCES;
}

int sterge(MyList* l, Transaction t)
{
	int poz = find(l, t);
	if (poz == -1)
		return TRANZACTIA_NU_EXISTA;
	t.day = poz;
	for (int i = poz; i < l->lg - 1; ++i) {
		l->lista[i] = l->lista[i + 1];
	}
	l->lg--;
	return SUCCES;
}

int modifica(MyList* lista, Transaction t_vechi, Transaction t_nou)
{
	int poz = find(lista, t_vechi);
	if (poz == -1) return TRANZACTIA_NU_EXISTA;
	lista->lista[poz] = t_nou;
	return SUCCES;
}

int setTransaction(MyList* lista, int poz, Transaction t_nou)
{
	if (poz < 0 || poz > size(lista)) return TRANZACTIA_NU_EXISTA;
	lista->lista[poz] = t_nou;
	return SUCCES;
}

int find(MyList* l, Transaction t)
{
	for (int i = 0; i < l->lg; ++i) {
		if (equalTransaction(t, getTransaction(l, i))) return i;
	}
	return TRANZACTIA_NU_EXISTA;
}

Transaction getTransaction(MyList* l, int poz)
{
	return l->lista[poz];
}

int size(MyList* l)
{
	return l->lg;
}