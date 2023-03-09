#pragma once
#include "Repo.h"
#include "Validator.h"
#include "Obs.h"
class Service :public Observable {
	Repo& repo;
	Validator& val;
public:
	Service(Repo& rep, Validator& val) :repo{ rep }, val{ val }{}
	void add(int id, string name, string type, double price);
	const vector<Prod>& getAll();
};
