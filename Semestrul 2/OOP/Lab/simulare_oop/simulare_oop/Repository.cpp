#include "Repository.h"
#include <iostream>
#include <string>

int Repository::add(const Telefon& m)
{

	if (find(m.getID()))
		throw runtime_error("Telefonl exista deja!\n");

	this->lista.push_back(m);
	return 1;
}

int Repository::del(int id)
{
	auto it = find_if(lista.begin(), lista.end(), [=](const Telefon& m) {return m.getID() == id; });
	if (it != lista.end()) {
		lista.erase(it);
		return 1;
	}
	else {
		throw runtime_error("Nu exista telefonl!\n");
	}
}

int Repository::update(const Telefon& m)
{
	auto it = find_if(lista.begin(), lista.end(), [&](const Telefon& otm) {if (otm.getID() == m.getID()) return 1; else return 0; });

	if (it != lista.end()) {
		*it = m;
		return 1;
	}
	else {
		throw runtime_error("Nu exista telefonl!\n");
	}
}

int Repository::find(int id)
{
	auto it = find_if(lista.begin(), lista.end(), [=](const Telefon& m) {return m.getID() == id; });
	if (it != lista.end())
		return 1;
	return 0;
}

const Telefon& Repository::findPhone(int id)
{
	auto it = find_if(lista.begin(), lista.end(), [=](const Telefon& m) {return m.getID() == id; });
	return *it;
}

size_t Repository::size() noexcept
{
	return this->lista.size();
}

const vector<Telefon>& Repository::getAll()
{
	return lista;
}