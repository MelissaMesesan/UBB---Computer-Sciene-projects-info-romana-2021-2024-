#include "Truck.h"

int Truck::get_id()
{
	return id;
}

std::string Truck::get_brand()
{
	return brand;
}

int Truck::get_mileage()
{
	return mileage;
}

int Truck::get_year()
{
	return year;
}

int Truck::get_price()
{
	return price;
}

bool Truck::operator==(const Truck& t)
{
	return this->id == t.id;
}

bool Truck::operator==(const int& id)
{
	return this->id == id;
}

Truck::~Truck()
{
}