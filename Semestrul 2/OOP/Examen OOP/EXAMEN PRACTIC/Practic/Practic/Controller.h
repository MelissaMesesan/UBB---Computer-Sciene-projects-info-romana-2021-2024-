#pragma once
#include "Repository.h"
class Controller {
private:
	Repository& repo;
	//Validator valid;
public:
	Controller(Repository& r) : repo{ r } {}
	Controller(const Controller& c) = delete;

	vector<Produs> getAll() { return repo.getAll(); }
	void addToRepo(int id, string name, string type, double price);
	vector<Produs> getSortedPrice();

	~Controller() = default;
};