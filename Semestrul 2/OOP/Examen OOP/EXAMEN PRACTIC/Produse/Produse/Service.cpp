#include "Service.h"

void Service::add(int id, string name, string type, double price)
{
	/*
	FUnctie care adauca un  produs in lista
	pre : id - int , name - string , type - string , price - double
	Raises: ValidateException daca produsul nu e valid d.p.d.v.l
	*/
	Prod p{ id,name,type,price };
	val.validate(p);
	repo.add(p);
	notify();
}

const vector<Prod>& Service::getAll()
{
	/*
	Returneaza toate elementele
	out: vector - contine toate produsele*/
	return repo.getAll();
}