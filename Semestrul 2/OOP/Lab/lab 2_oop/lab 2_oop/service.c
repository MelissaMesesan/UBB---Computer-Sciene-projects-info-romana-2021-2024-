#include <string.h>
#include <assert.h>
#include "service.h"
#include"MyList.h"

/*
	add a transaction
*/
int addTransaction(MyList* l, int day, int amount, char* type, char* description) {
	Transaction t = createTransaction(day, amount, type, description);
	int succ = valideaza(t);
	if (succ != 0)
		return succ;
	add(l, t);
	return 0; //all ok
}

/*void testAddTransaction() {
		MyList l = createEmpty();
		//try to add invalide transactions

		int error = addPet(&l);
		assert(error != 0);
		assert(error(&l) == 0);
	}
}
*/