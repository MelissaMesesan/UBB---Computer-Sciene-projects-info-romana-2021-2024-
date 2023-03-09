#include"tranzactie.h"
#include<stdlib.h>
#include<string.h>

/*
	Creeaza o tranzactie
	Input - int day, int amount, char type[20], int description
	Output - o variabila de tip Tranzactie
*/
Transaction creeaza(int day, int amount, char type[20], char description[20])
{
	Transaction t;
	t.day = day;
	t.amount = amount;
	strcpy(t.type, type);
	strcpy(t.description, description);
	return t;
}


int getDay(Transaction t, int day)
{
	return t.day;
}

int getAmount(Transaction t,int amount)
{
	return t.day;
}

void setDay(Transaction* t, int day)
{
	t->day = day;
}

void setAmount(Transaction* t, int amount)
{
	t->amount = amount;
}

void setType(Transaction* t, char type[20])
{

	strcpy(t->type, type);
}

void setDescription(Transaction* t, char descripton[20])
{

	strcpy(t->description, descripton);
}