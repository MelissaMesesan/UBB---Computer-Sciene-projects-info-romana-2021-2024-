#include "Service.h"


void Service::add(const int& id, const std::string& brand, const int& mileage, const int& year, const int& price)
{
	Truck t{ id,brand,mileage,year,price };
	validator.validate(t);
	repo.add(t);
	notify_observers();
}

void Service::del(const int& id)
{
	repo.del(id);
	notify_observers();
}

std::vector<Truck>& Service::get_all()
{
	return repo.get_all();
}

std::vector<Truck> Service::get_between_prices(const int& low, const int& high)
{
	std::vector<Truck> to_return;

	for (auto& i : repo.get_all())
		if (i.get_price() >= low && i.get_price() <= high)
			to_return.push_back(i);

	return to_return;
}

Service::~Service()
{
}