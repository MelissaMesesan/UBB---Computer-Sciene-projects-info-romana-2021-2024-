#pragma once
#include "Prod.h"
class ValidateException {
	string errors;
public:
	ValidateException(string ers) :errors{ ers } {}
	string getErrors() { return errors; }
};

class Validator {
public:
	Validator() {}
	void validate(Prod& p) {
		/*
		Verifica daca produsul e valid din punct de vedere logic
		in: p
		pre: p e de tip Prod
		Raises:
			arunca ValidateException daca produsul nu e valid
		*/
		string errors;
		if (p.getName() == "")
			errors += "Nume invalid!\n";
		if (p.getType() == "")
			errors += "Tip invalid!\n";
		if (!(p.getPrice() <= 100 && p.getPrice() >= 1))
			errors += "Pret invalid!\n";
		if (errors.size() != 0)
			throw ValidateException(errors);
	}
};
