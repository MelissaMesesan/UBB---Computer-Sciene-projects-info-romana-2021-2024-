#pragma once

#include "Repo.h"

class Service
{
private:
	Repo& repo;
public:
	Service(Repo& repo) : repo{ repo } {};

	std::vector<Produs>& get_all();

	void add(const int& id, const std::string& nume, const std::string& tip, const double& pret);

	void del(const int& id);

	~Service();
};
