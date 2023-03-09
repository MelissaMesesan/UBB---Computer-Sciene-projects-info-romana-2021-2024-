#include "Domain.h"

int Produs::get_id() {
	return id;
}

std::string Produs::get_nume() {
	return nume;
}

std::string Produs::get_tip() {
	return tip;
}

double Produs::get_pret() {
	return pret;
}

bool Produs::operator==(const int& id)
{
	return this->id == id;
}

bool Produs::operator==(const Produs& s)
{
	return this->id == s.id;
}