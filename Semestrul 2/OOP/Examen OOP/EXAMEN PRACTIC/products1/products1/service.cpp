#include "produs.h"
#include "service.h"
#include <algorithm>
#include "service.h"
#include <iterator>
#include <functional>

int Store::Add(int id, const string& name, const string& type, double price) {
	if (name.length() > 0 && price > 1.0 && price < 100.0) {
		Product p{ id, name, type, price };
		repo.addProduct(p);
	}
	else {
		throw RepoException("date invalide!");
	}
}

vector<Product> Store::filter(double price) {
	vector<Product>filtered;
	const vector<Product>& v = getAll();
	std::copy_if(v.begin(), v.end(), back_inserter(filtered), [=](const Product& p) {
		return p.getPrice() <= price;
		});
	return filtered;

}