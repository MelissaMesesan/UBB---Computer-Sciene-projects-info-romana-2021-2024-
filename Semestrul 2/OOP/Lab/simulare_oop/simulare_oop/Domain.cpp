#include "Domain.h"
#include <iostream>



Telefon::Telefon(const Telefon& ot)
{
	this->id = ot.id;
	this->brand = ot.brand;
	this->model = ot.model;
	this->pret = ot.pret;
}


const string& Telefon::getBrand() const noexcept
{
	return this->brand;
}

const string& Telefon::getModel() const noexcept
{
	return this->model;
}

const string& Telefon::getPret() const noexcept
{
	return this->pret;
}

int Telefon::getID() const noexcept
{
	return this->id;
}


void Telefon::setBrand(const string& br)
{
	this->brand = br;
}

void Telefon::setModel(const string& _model)
{
	this->model = _model;
}

void Telefon::setPret(const string& _pret)
{
	this->pret = _pret;
}

ostream& operator<<(ostream& os, const Telefon& m)
{
	os << m.getID() << "," << m.getModel() << "," << m.getBrand() << "," << "," << m.getPret();
	return os;
}