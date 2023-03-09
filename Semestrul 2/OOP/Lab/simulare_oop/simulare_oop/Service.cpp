#include "Service.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <random>


using std::vector;

Service::Service(Repository& _rep) : repo{ _rep } {}



int Service::srv_add(int id, const string& brand, const string& model, const string& pret)
{
	Telefon m{ id,brand,model,pret };
	repo.add(m);
	return 1;
}


int Service::srv_update(int id, const string& brand, const string& model, const string& pret)
{
	Telefon m{ id,brand,model,pret };
	repo.update(m);
	return 1;
}

const Telefon& Service::srv_findPhone(int id) const
{
	return repo.findPhone(id);
}

vector<Telefon> Service::filter(const string& what) const
{
	vector<Telefon>v1;
	vector<Telefon>v2;
	v1 = repo.getAll();
	copy_if(v1.begin(), v1.end(), back_inserter(v2), [&](const Telefon& m) {return m.getBrand() == what; });
	return v1;

}

vector<Telefon> Service::sort(function<bool(const Telefon& m1, const Telefon& m2)>compareFunction) const
{
	vector<Telefon>v = repo.getAll();
	std::sort(v.begin(), v.end(), compareFunction);
	return v;
}

vector<Telefon> Service::srv_getAll() const
{
	return repo.getAll();

}