#include "Tranzactie.h"

/* creeaza tranzactie */
Tranzactie* creeareTranzactie(int zi, int suma, char* descriere, char* tip)
{
	Tranzactie* tr = (Tranzactie*)malloc(sizeof(Tranzactie));
	tr->zi = zi;
	tr->suma = suma;
	tr->descriere = _strdup(descriere);
	tr->tip = _strdup(tip);
	return tr;
}

/* distruge tranzactie */
void distrugeTranzactie(Tranzactie* tr) {
	free(tr->descriere);
	free(tr->tip);
	free(tr);
}

/* get */
char* getdescriere(Tranzactie* tr) {
	return tr->descriere;
}

char* getTip(Tranzactie* tr) {
	return tr->tip;
}

int getzi(Tranzactie* tr)
{
	return tr->zi;
}

int getsuma(Tranzactie* tr)
{
	return tr->suma;
}

/* set */
void setdescriere(Tranzactie* tr, char* descriere)
{
	free(tr->descriere);
	tr->descriere = _strdup(descriere);
}

void setTip(Tranzactie* tr, char* tip)
{
	free(tr->tip);
	tr->tip = _strdup(tip);
}

void setzi(Tranzactie* tr, int zi)
{
	tr->zi = zi;
}

void setsuma(Tranzactie* tr, int suma)
{
	tr->suma = suma;
}

Tranzactie* copyTranzactie(Tranzactie* tr) {
	Tranzactie* tr_copy = creeareTranzactie(getzi(tr), getsuma(tr), getdescriere(tr), getTip(tr));
	return tr_copy;
}

int equalTranzactie(Tranzactie* tr, Tranzactie* tr1)
{
	if (strcmp(tr->tip, tr1->tip)) return 0;
	if (strcmp(tr->descriere, tr1->descriere)) return 0;
	return 1;
}

/* test */
void testTranzactie() {
	int zi = 10;
	int suma = 20;
	char* descriere = _strdup("descriereTest");
	char* tip = _strdup("TipTest");
	Tranzactie* tr = creeareTranzactie(zi, suma, descriere, tip);
	Tranzactie* tr2 = tr;
	Tranzactie* tr3 = copyTranzactie(tr);
	assert(getzi(tr) == zi);
	assert(getsuma(tr) == suma);
	assert(strcmp(getdescriere(tr), descriere) == 0);
	assert(strcmp(getTip(tr), tip) == 0);
	zi = 20;
	suma = 1000;
	setzi(tr, zi);
	setsuma(tr, suma);
	assert(getzi(tr) == zi);
	assert(getsuma(tr) == suma);
	Tranzactie* tr1 = creeareTranzactie(zi, suma, descriere, tip);
	free(tip);
	free(descriere);

	descriere = _strdup("descriere2test");
	tip = _strdup("Tip2test");
	setdescriere(tr, descriere);
	setTip(tr, tip);
	assert(!equalTranzactie(tr, tr1));
	assert(!equalTranzactie(tr, tr3));
	assert(equalTranzactie(tr, tr2));
	free(tip);
	free(descriere);
	distrugeTranzactie(tr);
	distrugeTranzactie(tr1);
	distrugeTranzactie(tr3);
}