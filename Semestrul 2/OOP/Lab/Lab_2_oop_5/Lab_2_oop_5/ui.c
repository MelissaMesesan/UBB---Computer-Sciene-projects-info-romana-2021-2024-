#include "ui.h"

UI* creeareUI(Service* cont)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->cont = cont;
	return ui;
}

void distrugeUI(UI* ui) {
	free(ui);
}

void afisareEroare(int cod_eroare) {
	switch (cod_eroare) {
	case TRANZACTIA_EXISTA_DEJA: printf("\nEroare repo: -- tranzactia exista deja\n"); break;
	case TRANZACTIA_NU_EXISTA: printf("\nEroare repo: -- tranzactia nu exista\n"); break;
	case STRING_VID: printf("\nEroare la validare: -- String vid.\n"); break;
	case TIP_INVALID: printf("\nEroare la validare: -- Tip invalid.\n"); break;
	case NUMAR_INVALID: printf("\nEroare la validare: -- Numar invalid\n"); break;
	default: break;
	}
}

void adaugaretranzactia(UI* ui)
{
	char zi_str[50], suma_str[50], descriere[50], tip[50];
	printf("Introduceti tranzactia:\n");
	printf("Zi: ");
	scanf_s("%s", &zi_str, 50);
	printf("Suma: ");
	scanf_s("%s", &suma_str, 50);
	printf("Descriere: ");
	scanf_s("%s", &descriere, 50);
	printf("Tip: ");
	scanf_s("%s", &tip, 50);
	int zi = atoi(zi_str);
	int suma = atoi(suma_str);
	if (zi<=0 || zi>31) { printf("\nZi Invalida.\n"); return; }
	if (suma <= -1) { printf("\nSuma Invalida.\n"); return; }
	int eroare = adaugare(ui->cont, zi, suma, descriere, tip);
	afisareEroare(eroare);
}

void stergeretranzactia(UI* ui)
{
	char descriere[50], tip[50];
	printf("Introduceti descriere si tip.");
	printf("\nDescriere: ");
	scanf_s("%s", &descriere, 50);
	printf("\nTip: ");
	scanf_s("%s",&tip, 50);
	int eroare = (int)stergere(ui->cont, descriere, tip);
	afisareEroare(eroare);
}

void modificaretranzactia(UI* ui)
{
	char descriere_vechi[50], tip_vechi[50], descriere[50], tip[50];
	char zi_str[50], suma_str[50];
	printf("Introduceti descriere si tip existente: \n");
	printf("Descriere: ");
	scanf_s("%s", &descriere_vechi, 50);
	printf("\nTip: ");
	scanf_s("%s", &tip_vechi, 50);
	printf("Introduceti tranzactia noua: \n");
	printf("Zi: ");
	scanf_s("%s", &zi_str, 50);
	printf("\nSuma: ");
	scanf_s("%s", &suma_str, 50);
	printf("\nDescriere: ");
	scanf_s("%s", &descriere, 50);
	printf("\nTip: ");
	scanf_s("%s", &tip, 50);
	int zi = atoi(zi_str);
	int suma = atoi(suma_str);
	if (zi == -1 || zi==0 || zi>31) { printf("\nZi Invalida.\n"); return; }
	if (suma == -1) { printf("\nSuma Invalida.\n"); return; }
	int eroare = (int)actualizare(ui->cont, descriere_vechi, tip_vechi, zi, suma, descriere, tip);
	afisareEroare(eroare);
}

void afisareLista(Vector* lista) {
	Tranzactie* of;
	for (int i = 0; i < getDim(lista); ++i) {
		of = getElem(lista, i);

		printf("%d, %d, %s, %s\n", getzi(of), getsuma(of), getdescriere(of), getTip(of));
	}
	destroyElems(lista);
	distrugeVector(lista);
}

void filtraretranzactia(UI* ui)
{
	char tip[50];
	char zi_str[50], suma_str[50];
	printf("Introduceti filtru: \n");
	printf("Zi: ");
	scanf_s("%s", &zi_str, 50);
	printf("\nSuma: ");
	scanf_s("%s", &suma_str, 50);
	printf("\nTip: ");
	scanf_s("%s", &tip, 50);
	printf("\n");
	int zi = atoi(zi_str);
	int suma = atoi(suma_str);
	if (zi == -1 || zi==0 || zi>31) { printf("\nZi Invalid.\n"); return; }
	if (suma <= -1) { printf("\nSuma Invalida.\n"); return; }
	Vector* lista_f = filtrare(ui->cont, tip, zi, suma);
	afisareLista(lista_f);
}

void sortaretranzactia(UI* ui)
{
	char filtru[50];
	printf("Introduceti filtru: ");
	scanf_s("%s", &filtru, 50);
	Vector* lista_f = sortare(ui->cont, &filtru);
	afisareLista(lista_f);
}

void meniu(UI* ui)
{
	printf("	Meniu\n");
	printf("1. Adaugare tranzactia.\n");
	printf("2. Stergere tranzactia.\n");
	printf("3. Modificare tranzactii.\n");
	printf("4. Sortare tranzactii.\n");
	printf("5. Filtrare tranzactii.\n");
	printf("6. Afisare tranzactii.\n");
	printf("0. Iesire.\n");

	char comanda[255];
	while (1) {
		printf("Introduceti comanda: ");
		scanf_s("%s", comanda, 255);
		if (*comanda == '1') adaugaretranzactia(ui);
		else if (*comanda == '2') stergeretranzactia(ui);
		else if (*comanda == '3') modificaretranzactia(ui);
		else if (*comanda == '4') sortaretranzactia(ui);
		else if (*comanda == '5') filtraretranzactia(ui);
		else if (*comanda == '6') afisareLista(getAllElems(ui->cont));
		else if (*comanda == '0') break;
		//else printf("\nComanda Invalida\n");
	}
}