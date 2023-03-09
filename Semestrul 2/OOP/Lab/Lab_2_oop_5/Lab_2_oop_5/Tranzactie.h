#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Tranzactie {
	int suma, zi;
	char* descriere, * tip;
} Tranzactie;

Tranzactie* creeareTranzactie(int zi, int suma, char* descriere, char* tip);
void distrugeTranzactie(Tranzactie* of);
Tranzactie* copyTranzactie(Tranzactie* of);
char* getdescriere(Tranzactie* of);
char* getTip(Tranzactie* of);
int getzi(Tranzactie* of);
int getsuma(Tranzactie* of);
void setdescriere(Tranzactie* of, char* descriere);
void setTip(Tranzactie* of, char* tip);
void setzi(Tranzactie* of, int zi);
void setsuma(Tranzactie* of, int suma);
int equalTranzactie(Tranzactie* of, Tranzactie* of1);
void testTranzactie();