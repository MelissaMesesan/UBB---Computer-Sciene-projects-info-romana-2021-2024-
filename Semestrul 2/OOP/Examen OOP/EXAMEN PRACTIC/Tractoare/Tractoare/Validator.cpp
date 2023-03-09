#include "Validator.h"

#include <exception>
#include <string>

Validator::Validator()
{
}

void Validator::validate(Truck& t)
{
	std::string error;
	if (t.get_id() < 1)
		throw std::exception("Id must be positive integer\n");
	if (t.get_brand() == std::string(""))
		throw std::exception("Brand doesn't exist\n");
	if (t.get_mileage() <= 0)
		throw std::exception("Mileage must be positive integer\n");
	if (t.get_price() <= 0)
		throw std::exception("Price must be positive integer\n");
	if (t.get_year() < 2000)
		throw std::exception("Year must be greater than 2000\n");
}


Validator::~Validator()
{
}