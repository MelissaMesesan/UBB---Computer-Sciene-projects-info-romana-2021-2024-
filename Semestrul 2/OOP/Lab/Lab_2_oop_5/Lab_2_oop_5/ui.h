#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "service.h"

typedef struct UI {
	Service* cont;
} UI;

UI* creeareUI(Service* cont);
void distrugeUI(UI* ui);
void adaugaretranzactia(UI* ui);
void stergeretranzactia(UI* ui);
void modificaretranzactia(UI* ui);
void filtraretranzactia(UI* ui);
void sortaretranzactia(UI* ui);
void meniu(UI* ui);