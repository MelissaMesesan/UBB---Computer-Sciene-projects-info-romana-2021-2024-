#include "validator.h"

int validator(Tranzactie* tr)
{
	if (tr->zi <= 0 || tr->suma <= 0) return NUMAR_INVALID;
	if (!strlen(tr->descriere) || !strlen(tr->tip)) return STRING_VID;
	if (strcmp(tr->tip, "casa") && strcmp(tr->tip, "apartament") && strcmp(tr->tip, "teren")) return TIP_INVALID;
	return SUCCES;
}

void testValidator()
{
	Tranzactie* tr = creeareTranzactie(0, 10, "descriere_validator", "tip_validator");
	assert(validator(tr) == NUMAR_INVALID);
	Tranzactie* tr1 = creeareTranzactie(0, -1, "descriere_validator", "tip_validator");
	assert(validator(tr1) == NUMAR_INVALID);
	Tranzactie* tr2 = creeareTranzactie(100, 10, "", "tip_validator");
	assert(validator(tr2) == STRING_VID);
	Tranzactie* tr3 = creeareTranzactie(100, 10, "descriere_validator", "tip_validator");
	assert(validator(tr3) == TIP_INVALID);
	Tranzactie* tr4 = creeareTranzactie(100, 10, "descriere_validator", "casa");
	assert(validator(tr4) == SUCCES);
	distrugeTranzactie(tr);
	distrugeTranzactie(tr1);
	distrugeTranzactie(tr2);
	distrugeTranzactie(tr3);
	distrugeTranzactie(tr4);
}