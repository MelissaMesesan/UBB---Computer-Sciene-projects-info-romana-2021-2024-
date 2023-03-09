#pragma once
#include "Domain.h"
#include <vector>

class Repository {
private:
	vector<Produs> all;
	string fName = "a.txt";
	void loadFromFile();
	void writeToFis();
public:

	Repository() {
		loadFromFile();
	};
	Repository(const Repository& r) = delete;

	void add(const Produs& p);
	vector<Produs> getAll();


	~Repository() = default;
};