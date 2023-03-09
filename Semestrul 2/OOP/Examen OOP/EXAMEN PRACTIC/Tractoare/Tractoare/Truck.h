#pragma once

#include <string>

class Truck
{
private:
	int id;
	std::string brand; //poate sa fie doar Volvo, Scania, Man, Mercedes
	int mileage;
	int year;
	int price;
public:
	Truck(const int& id, const std::string& brand, const int& mileage, const int& year, const int& price) :
		id{ id }, brand{ brand }, mileage{ mileage }, year{ year }, price{ price } {};

	int get_id();
	std::string get_brand();
	int get_mileage();
	int get_year();
	int get_price();
	bool operator==(const Truck& t);
	bool operator==(const int& id);
	~Truck();
};

