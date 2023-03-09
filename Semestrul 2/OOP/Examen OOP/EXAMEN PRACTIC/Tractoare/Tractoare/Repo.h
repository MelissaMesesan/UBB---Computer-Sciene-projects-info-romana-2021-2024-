#pragma once

#include "Truck.h"
#include <vector>

class Repo
{
private:
	std::string file_name;
	std::vector<Truck> trucks;
	void load_file();
	void save_file();
public:
	Repo(const std::string& file_name) : file_name{ file_name }
	{
		load_file();
	};
	void add(const Truck& t);
	void del(const int& id);
	std::vector<Truck>& get_all();
	~Repo();
};
