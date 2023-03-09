#include "Controller.h"
#include <algorithm>

void Controller::addToRepo(int id, string name, string type, double price) {
	//valid.validate(id,name,type,price);
	Produs p{ id,name,type,price };
	repo.add(p);

}

vector<Produs> Controller::getSortedPrice() {
	auto allSort = repo.getAll();
	sort(allSort.begin(), allSort.end(), [](Produs& p1, Produs p2) {
		return p1.getPrice() < p2.getPrice();
		});
	return allSort;
}