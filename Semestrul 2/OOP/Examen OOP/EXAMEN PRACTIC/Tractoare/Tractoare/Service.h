#pragma once

#include "Repo.h"
#include "Validator.h"
#include "Observable.h"

class Service : public Observable
{
private:
	Repo& repo;
	Validator& validator;
public:
	Service(Repo& repo, Validator& validator) : repo{ repo }, validator{ validator } {};

	void add(const int& id, const std::string& brand, const int& mileage, const int& year, const int& price);
	void del(const int& id);
	std::vector<Truck>& get_all();
	std::vector<Truck> get_between_prices(const int& low, const int& high);

	~Service();
};
