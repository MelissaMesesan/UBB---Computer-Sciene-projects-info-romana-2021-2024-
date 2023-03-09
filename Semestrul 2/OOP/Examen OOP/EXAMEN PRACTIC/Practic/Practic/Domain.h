#pragma once
#include <string>

using namespace std;

class Produs {
private:
	int id;
	string name;
	string type;
	double price;
public:

	Produs(int i, const string n, const string t, double p) : id{ i }, name{ n }, type{ t }, price{ p } {}
	Produs(const Produs& p) : id{ p.id }, name{ p.name }, type{ p.type }, price{ p.price } {}

	void setId(int i) { id = i; }
	void setName(const string n) { name = n; }
	void setType(const string t) { type = t; }
	void setPrice(double p) { price = p; }

	const int getId() const { return id; }
	const string getName() const { return name; }
	const string getType() const { return type; }
	const double getPrice() const { return price; }

	Produs() = default;

};