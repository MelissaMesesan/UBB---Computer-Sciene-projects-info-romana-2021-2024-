#pragma once
#include "Repository.h"
#include "FileRepository.h"
#include "Domain.h"
#include <functional>
#include <memory>

class Service
{
protected:

	Repository& repo;

public:

	Service(Repository& rep);

	/// Functie care creeaza, valideaza si adauga in repo o Disciplina
	int srv_add(int id, const string& brand, const string& model, const string& pret);

	/// Functie care actualizeaza o Disciplina dupa id-ul dat cu atributele date ca si parametri
	int srv_update(int id, const string& brand, const string& model, const string& pret);

	/// Functie care cauta si returneaza o Disciplina
	const Telefon& srv_findPhone(int id) const;

	/// Functia care filtreaza in functie de parametrul dat
	vector<Telefon> filter(const string& what) const;

	/// Functia care sorteaza in functie de parametrul dat
	vector<Telefon> sort(function<bool(const Telefon& m1, const Telefon& m2)>compareFunction) const;

	/// Functia care returneaza getAll
	vector<Telefon> srv_getAll() const;
};
