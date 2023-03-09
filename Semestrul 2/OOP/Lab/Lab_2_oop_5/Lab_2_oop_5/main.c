#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include <stdio.h>
#include "ui.h"

int main() {
	testTranzactie();
	testVector();
	testValidator();
	testRepo();
	testService();
	ListaTranzactii* repo = creeareLista();
	Service* cont = creeareService(repo, validator);
	UI* ui = creeareUI(cont);
	meniu(ui);
	distrugeService(cont);
	distrugeUI(ui);
	_CrtDumpMemoryLeaks();
	return 0;
}