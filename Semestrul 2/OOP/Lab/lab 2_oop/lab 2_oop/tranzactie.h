#pragma once

typedef struct {
	int day, amount;
	char type[10], description[20];
}Transaction;

/*
	create a new transaction
*/
Transaction creeaza(int day, int amount, char type[20], char description[20]);

/*
Returneaza ziua unui transferului
Input - o variabila de tip Transaction
Output - int day
*/
int getDay(Transaction t, int day);

/*
Returneaza ziua unui transferului
Input - o variabila de tip Transaction
Output - int day
*/
int getAmount(Transaction t, int amount);

void setDay(Transaction* t, int day);
void setAmount(Transaction* t, int amount);
void setType(Transaction* p, char type[20]);
void setDescription(Transaction* p, char description[20]);