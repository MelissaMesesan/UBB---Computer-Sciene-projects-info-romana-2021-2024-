#pragma once
#include "produs.h"
#include <vector>

using std::vector;

class RepoException {
private:
	string errorMsg;
public:
	RepoException(string errorMsg) : errorMsg{ errorMsg } {};

	string getErrorMessage() const
	{
		return errorMsg;
	}
};


class Repo {
	string filename;
	vector<Product>all;

public:
	Repo(string file) :filename{ file } {
		loadFromFile();
	};
	void loadFromFile();
	void loadToFile();
	void addProduct(Product& p);
	vector<Product>getAll() {
		return all;
	}
};