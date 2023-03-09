#pragma once
#include "Domain.h"
#include <string>
#include <vector>
#include <exception>

class Repo
{
private:
	std::string file_name;
	std::vector<Produs> prod;
	void load_file();
	void save_file();

public:
	Repo(std::string file_name) : file_name{ file_name } { load_file(); };
	void add(Produs p);
	void del(int id);
	std::vector<Produs>& get_all();
};
