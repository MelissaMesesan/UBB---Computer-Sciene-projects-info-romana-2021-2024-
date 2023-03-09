#pragma once
#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::istream;

class Telefon
{
private:
	int id;
	string brand;
	string model;
	string pret;

public:
	Telefon(int id, const string& brand, const string& model, const string& pret) :id{ id }, brand{ brand }, model{ model }, pret{ pret }{}
	Telefon(const Telefon& ot);


	/// Functia care returneaza brandul
	const string& getBrand() const noexcept;

	/// Functia care returneaza modelul
	const string& getModel() const noexcept;

	/// Functia care returneaza pretul
	const string& getPret() const noexcept;

	/// Functia care returneaza id
	int getID() const noexcept;

	/// Functia care seteaza producatorul
	void setBrand(const string& br);

	/// Functia care seteaza modelul
	void setModel(const string& model);

	/// Functia care seteaza pretul
	void setPret(const string& pret);

	friend ostream& operator<<(ostream& os, const Telefon& m);
	//friend istream& operator>>(istream& is, Masina& m);



	Telefon& operator=(const Telefon& ot) {
		this->id = ot.id;
		this->brand = ot.brand;
		this->model = ot.model;
		this->pret = ot.pret;
		return *this;
	}

	bool operator==(const Telefon& ot) noexcept {
		return ((this->id == ot.id) && (this->brand == ot.brand) && (this->model == ot.model) && (this->pret == ot.pret));
	}


};

