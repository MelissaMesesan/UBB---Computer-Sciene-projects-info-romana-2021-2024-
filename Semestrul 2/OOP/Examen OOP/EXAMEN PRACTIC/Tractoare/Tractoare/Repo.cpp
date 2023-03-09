#include "Repo.h"

#include <exception>
#include <fstream>
#include <algorithm>

void Repo::load_file()
{
	std::ifstream f;
	f.open(this->file_name);
	if (!f.is_open())
		throw std::exception("File could not be loaded for repo");

	int id;
	std::string brand; //poate sa fie doar Volvo, Scania, Man, Mercedes
	int mileage;
	int year;
	int price;
	while (f >> id)
	{
		f.get();
		std::getline(f, brand);
		f >> mileage >> year >> price;
		trucks.push_back(Truck{ id,brand,mileage,year,price });
	}
	f.close();
}

void Repo::save_file()
{
	std::ofstream o;
	o.open(this->file_name);
	if (!o.is_open())
		throw std::exception("Repo could not be saved to file");

	for (auto& i : trucks)
	{
		o << i.get_id() << '\n';
		o << i.get_brand() << '\n';
		o << i.get_mileage() << '\n';
		o << i.get_year() << '\n';
		o << i.get_price() << '\n';
	}

	o.close();
}

void Repo::add(const Truck& t)
{
	std::vector<Truck>::iterator it = find(trucks.begin(), trucks.end(), t);
	if (it != trucks.end())
		throw std::exception("The truck already exists in repo");
	trucks.push_back(t);
	save_file();
}

void Repo::del(const int& id)
{
	std::vector<Truck>::iterator it = find(trucks.begin(), trucks.end(), id);
	if (it == trucks.end())
		throw std::exception("The truck doesn't exist in repo");
	trucks.erase(it);
	save_file();
}

std::vector<Truck>& Repo::get_all()
{
	return trucks;
}

Repo::~Repo()
{
}