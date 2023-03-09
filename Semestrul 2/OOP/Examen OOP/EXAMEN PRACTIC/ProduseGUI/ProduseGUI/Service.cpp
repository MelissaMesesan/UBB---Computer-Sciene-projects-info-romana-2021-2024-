#include"service.h"

std::vector<Produs>& Service::get_all() {
	return repo.get_all();
}

void Service::add(const int& id, const std::string& nume, const std::string& tip, const double& pret) {
	if (id < 1)
		throw std::exception("ID invalid!");
	if (pret < 1.00 || pret>100.00)
		throw std::exception("Pret invalid!");
	if (nume.size() == 0)
		throw std::exception("Nume invalid!");
	if (tip.size() == 0)
		throw std::exception("Tip invalid!");

	repo.add(Produs(id, nume, tip, pret));
}

void Service::del(const int& id)
{
	repo.del(id);
}

Service::~Service() {

}
