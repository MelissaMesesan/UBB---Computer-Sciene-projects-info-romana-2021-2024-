#include "Repo.h"

void Repo::loadFromFile()
{
	/*
	Incarca toate produsele din fisier in memorie
	*/
	ifstream fin(filename);
	string id, name, type, price;
	while (getline(fin, id, ' ')) {
		getline(fin, name, ' ');
		getline(fin, type, ' ');
		getline(fin, price, '\n');
		int idInt = stoi(id);
		double priceDouble = stod(price);
		Prod p{ idInt,name,type,priceDouble };
		elems.push_back(p);
	}
	fin.close();
}

void Repo::writeToFile()
{
	/*
	Scrie toate produsele in fisier
	*/
	ofstream fout(filename);
	for (auto& prod : elems) {
		fout << prod.getId() << " " << prod.getName() << " " << prod.getType() << " " << prod.getPrice() << endl;
	}
	fout.close();
}

void Repo::add(Prod p)
{
	/*
	Adauga un produs in lista
	in:p
	pre: p Produs
	out: p se afla in fisier
	Raises: exceptie daca p exista deja
	*/
	for (auto& prod : elems)
		if (p.getId() == prod.getId())
			throw RepoError("Element existent!\n");
	elems.push_back(p);
	writeToFile();
}

const vector<Prod>& Repo::getAll() const
{
	/*
	Returneaza toate elemenetele
	Out: vector cu toate elementele*/
	return elems;
}