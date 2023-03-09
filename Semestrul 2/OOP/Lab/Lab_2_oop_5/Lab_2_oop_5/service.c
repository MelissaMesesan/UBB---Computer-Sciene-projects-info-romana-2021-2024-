#include "service.h"


/* creeaza service */
Service* creeareService(ListaTranzactii* lista, int(*validare)(Tranzactie*))
{
	Service* cont = (Service*)malloc(sizeof(Service));
	cont->lista = lista;
	cont->validare = validare;
	return cont;
}

/* distruge elementele */
void destroyElemsServ(Service* cont) {
	destroyElemsRepo(cont->lista);
}

/* distruge service*/
void distrugeService(Service* cont) {
	distrugeLista(cont->lista);
	free(cont);
}

/* dimensiune */
int getDimCont(Service* cont)
{
	return getDimList(cont->lista);
}

/* toate elementele */
Vector* getAllElems(Service* cont) {
	return getVect(cont->lista);
}

/* lista de tranzactii */
ListaTranzactii* getLista(Service* cont)
{
	return cont->lista;
}

/* adaugare */
int adaugare(Service* cont, int zi, int suma, char* descriere, char* tip)
{
	Tranzactie* tr = creeareTranzactie(zi, suma, descriere, tip);
	int val = cont->validare(tr);
	if (val) {
		distrugeTranzactie(tr);
		return val;
	}
	val = adaugaTranzactie(cont->lista, tr);
	if (val) {
		distrugeTranzactie(tr);
		return val;
	}
	return SUCCES;
}

/* stergere */
Tranzactie* stergere(Service* cont, char* descriere, char* tip)
{
	Tranzactie* tr = creeareTranzactie(1, 1, descriere, tip);
	int val = cont->validare(tr);
	if (val) {
		distrugeTranzactie(tr);
		return (Tranzactie*)val;
	}
	Tranzactie* to_delete = stergeTranzactie(cont->lista, tr);
	distrugeTranzactie(tr);
	return to_delete;
}
/* actualizare */
Tranzactie* actualizare(Service* cont, char* descriere, char* tip, int zi_nou, int suma_noua, char* descriere_noua, char* tip_nou)
{
	Tranzactie* tr_nou = creeareTranzactie(zi_nou, suma_noua, descriere_noua, tip_nou);
	Tranzactie* tr_vechi = creeareTranzactie(1, 1, descriere, tip);
	int val = cont->validare(tr_vechi);
	if (val) {
		distrugeTranzactie(tr_nou);
		distrugeTranzactie(tr_vechi);
		return (Tranzactie*)val;
	}
	val = cont->validare(tr_nou);
	if (val) {
		distrugeTranzactie(tr_nou);
		distrugeTranzactie(tr_vechi);
		return (Tranzactie*)val;
	}
	Tranzactie* to_delete = modificaTranzactie(cont->lista, tr_vechi, tr_nou);
	distrugeTranzactie(tr_nou);
	distrugeTranzactie(tr_vechi);
	return to_delete;
}

/* filtrare */
Vector* filtrare(Service* cont, char* tip, int zi, int suma)
{
	Tranzactie* tr;
	char* tip_temp;
	Vector* lista_filtrata = creeareVector(0, equalTranzactie, copyTranzactie, distrugeTranzactie);

	for (int i = 0; i < getDimCont(cont); ++i) {
		tr = getTranzactie(cont->lista, i);
		tip_temp = getTip(tr);
		if (strlen(tip)) if (strcmp(tip, tip_temp)) continue;
		if (zi > 0) if (getzi(tr) != zi) continue;
		if (suma > 0) if (getsuma(tr) != suma) continue;
		adaugaElem(lista_filtrata, tr);
	}
	return lista_filtrata;
}

void swaptrerte(Vector* lista, int poz, int poz1) {
	Tranzactie* tr1 = getElem(lista, poz1);
	Tranzactie* tr = setElem(lista, poz, tr1);
	setElem(lista, poz1, tr);
}

int verificaSortare(Vector* vect, char* filtru) {
	if (strcmp(filtru, "tip") && strcmp(filtru, "zi")) return FILTRU_INVALID;
	Tranzactie* tr, * tr1;
	for (int i = 0; i < getDim(vect) - 1; ++i) {
		tr = getElem(vect, i);
		tr1 = getElem(vect, i + 1);
		if (!strcmp(filtru, "tip"))
		{
			char* tip = getTip(tr);
			char* tip1 = getTip(tr1);
			if (strcmp(tip, tip1) > 0) return NESORTAT;
		}
		else if (!strcmp(filtru, "zi")) if (getzi(tr) > getzi(tr1)) return NESORTAT;
	}
	return SORTAT;
}

Vector* sortare(Service* cont, char* filtru)
{
	Vector* lista_sortata = getVect(cont->lista);
	Tranzactie* tr, * tr1;
	char* tip, * tip1;
	for (int i = 0; i < getDim(lista_sortata) - 1; ++i) {
		for (int j = i + 1; j < getDim(lista_sortata); ++j) {
			tr = getElem(lista_sortata, i);
			tr1 = getElem(lista_sortata, j);
			if (!strcmp(filtru, "tip")) {
				tip = getTip(tr);
				tip1 = getTip(tr1);
				if (strcmp(tip1, tip) < 0) swaptrerte(lista_sortata, i, j);
			}
			else if (!strcmp(filtru, "zi")) {
				if (getzi(tr1) < getzi(tr)) swaptrerte(lista_sortata, i, j);
			}
			else return lista_sortata;
		}
	}
	return lista_sortata;
}

/* test */
void testService()
{
	ListaTranzactii* list = creeareLista();
	Vector* list_f;
	Service* cont = creeareService(list, validator);
	assert(adaugare(cont, 10, 10, "descriereTestController", "casa") == SUCCES);
	assert(adaugare(cont, 30, 20, "descriereTestController1", "apartament") == SUCCES);
	//assert(adaugare(cont, 10, 10, "descriereTestController", "casa") == TRANZACTIA_EXISTA_DEJA);
	assert(adaugare(cont, 10, 10, "descriereTestController", "tipTestController") == TIP_INVALID);
	assert(getDimCont(cont) == 2);
	Tranzactie* temp = actualizare(cont, "descriereTestController", "casa", 10, 10, "descriereTestControllerModificata", "teren");
	assert((int)temp != TRANZACTIA_NU_EXISTA);
	Tranzactie* temp1 = actualizare(cont, "descriereTestController", "casa", 10, 10, "descriereTestControllerModificata1", "apartament");
	assert((int)temp1 == TRANZACTIA_NU_EXISTA);
	Tranzactie* temp2 = stergere(cont, "descriereTestController1", "apartament");
	assert((int)temp2 != TRANZACTIA_NU_EXISTA);
	Tranzactie* temp3 = stergere(cont, "descriereTestController1", "apartament");
	assert((int)temp3 == TRANZACTIA_NU_EXISTA);
	assert(adaugare(cont, 10, 10, "descriereTestController1", "apartament") == SUCCES);
	assert(adaugare(cont, 1, 100, "descriereTestController2", "casa") == SUCCES);
	list_f = filtrare(cont, "casa", 0, 0);
	assert(getDim(list_f) == 1);
	distrugeVector(list_f);
	list_f = filtrare(cont, "teren", 0, 10);
	assert(getDim(list_f) == 1);
	distrugeVector(list_f);
	list_f = filtrare(cont, "", 10, 10);
	assert(getDim(list_f) == 2);
	distrugeVector(list_f);
	list_f = sortare(cont, "suma");
	assert(verificaSortare(list_f, "suma") == FILTRU_INVALID);
	destroyElems(list_f);
	distrugeVector(list_f);
	list_f = sortare(cont, "zi");
	assert(verificaSortare(list_f, "zi") == SORTAT);
	destroyElems(list_f);
	distrugeVector(list_f);
	list_f = sortare(cont, "tip");
	assert(verificaSortare(list_f, "zi") == NESORTAT);
	assert(verificaSortare(list_f, "tip") == SORTAT);
	destroyElems(list_f);
	distrugeVector(list_f);
	ListaTranzactii* copie_lista = getLista(cont);
	Vector* copie_vector = getAllElems(cont);
	destroyElems(copie_vector);
	distrugeVector(copie_vector);
	Tranzactie* poz_c, * poz;
	for (int i = 0; i < getDimList(copie_lista); ++i) {
		poz_c = getTranzactie(copie_lista, i);
		poz = getTranzactie(cont->lista, i);
		assert(equalTranzactie(poz_c, poz));
	}
	distrugeTranzactie(temp);
	distrugeTranzactie(temp2);
	destroyElemsRepo(cont->lista);
	distrugeService(cont);
}