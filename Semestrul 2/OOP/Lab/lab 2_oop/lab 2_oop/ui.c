#include<stdio.h>
#include "tranzactie.h"
#include "MyList.h"
#include "service.h"
void meniu() {
	printf("1. Adauga tranzactie \n");
	printf("2. Modifica tranzactie \n");
	printf("3. Sterge tranzactie \n");
	printf("4. Vizualizeaza tranzactiile de un anumit tip \n");
	printf("5. Vizualizeaza tranzactiaiile cu suma mai mare decat o suma data \n");
	printf("6. Vizualizeaza tranzactiile ordonate descrescator \n");
	printf("7. Vizualizeaza tranzactiile ordonate crescator \n");
	printf("0. IESIRE \n\n");
	printf("Alege o cerinta: \n");
}


void readTransaction(MyList* l) {
	printf("Day: \n");
	int day;
	scanf_s("%d", &day);
	printf("Amunt: \n");
	int amount;
	scanf_s("%d", &amount);
	printf("Type: \n");
	char type;
	scanf_s("%s", &type);
	printf("Description: \n");
	char description;
	scanf_s("%s", &description);
	int error = addTransaction(l, day, amount, type, description);
	if (error != 0) {
		printf("Invalid transaction \n");
	}
}

int run() {
	MyList allTransactions = createEmpty();
	int numar;
	meniu();
	scanf_s("%d", &numar);
	while (numar != 0) {
		if (numar == 1) {
			readTransaction(&allTransactions);
			break;
		}
		else if (numar == 2)
			return;
		else if (numar == 3)
			return;
		else if (numar == 4)
			return;
		else if (numar == 5)
			return;
		else if (numar == 6)
			return;
		else if (numar == 7)
			return;
		meniu();
		scanf_s("%d", &numar);
	}
}

int main() {
	run();
}
