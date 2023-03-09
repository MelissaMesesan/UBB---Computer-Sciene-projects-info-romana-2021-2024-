#include "Repo.h"
#include<fstream>

void Repo::load_file() {
	std::ifstream f;
	f.open(file_name);
	if (!f.is_open())
		throw std::exception("Fisierul nu s-a putut deschide");
	int id;
	std::string nume, tip;
	double pret;
	while (f >> id)
	{
		f.get();
		std::getline(f, nume);
		std::getline(f, tip);
		f>>(f, pret);
		prod.push_back(Produs{ id,nume,tip,pret });

	}
	f.close();
}

void Repo::save_file()
{
	std::ofstream o(file_name);
	if (!o.is_open())
		throw std::exception("Fisireul nu s-a putut deschide");

	for (auto& i : prod)
	{
		o << i.get_id() << '\n';
		o << i.get_nume() << '\n';
		o << i.get_tip() << '\n';
		o << i.get_pret() << '\n';
	}
	o.close();
}

void Repo::add(Produs p) {
	std::vector<Produs>::iterator it = find(prod.begin(), prod.end(), p);
	if (it != prod.end())
		throw std::exception("Produsul exista deja in repo!");
	prod.push_back(p);
	save_file();
}

void Repo::del(int id)
{
	std::vector<Produs>::iterator it = find(prod.begin(), prod.end(), id);
	if (it == prod.end())
		throw std::exception("Produsul nu exista in repo!");
	prod.erase(it);
	save_file();
}

std::vector<Produs>& Repo::get_all()
{
	return prod;
}