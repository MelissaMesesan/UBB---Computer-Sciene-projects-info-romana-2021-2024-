#pragma once
#include "repo.h"
#include "produs.h"
#include <vector>
#include <algorithm>


class Store {

	Repo& repo;

public:
	Store(Repo& repo): repo{ repo } {}
	Store(const Store& ot) = delete;

	vector<Product>getAll() {
		vector<Product>v = this->repo.getAll();
		sort(v.begin(), v.end(), [](Product& p1, Product& p2) {
			return p1.getPrice() < p2.getPrice();
			});
		return v;
	}

	int Add(int id, const string& name, const string& type, double price);

	vector<Product>filter(double price);




};

