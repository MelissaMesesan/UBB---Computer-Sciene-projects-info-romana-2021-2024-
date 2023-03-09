#pragma once
#include "Prod.h"
#include <vector>
#include <fstream>
class RepoError {
	string errors;
public:
	RepoError(string ers) :errors{ ers } {}
	string getErrors() {
		return errors;
	}
};

class Repo {
	vector<Prod> elems;
	string filename;
	void loadFromFile();
	void writeToFile();
public:
	Repo(string file) :filename{ file } {
		loadFromFile();
	}
	void add(Prod p);
	const vector<Prod>& getAll()const;

};