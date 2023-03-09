#pragma once
#include <string>

class Produs
{
private: 
	int id;
	std::string nume, tip;
	double pret;

public:
	Produs(const int& id, const std::string& nume, const std::string& tip, const double& pret) :
		id{ id }, nume{ nume }, tip{ tip }, pret{ pret } {};
	int get_id();
	std::string get_nume();
	std:: string get_tip();
	double get_pret();

	bool operator==(const int&);
	bool operator==(const Produs&);
};
