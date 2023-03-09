#include "UI.h"
#include <iostream>
#include <fstream>
#include <cstring>

using std::string;

void UI::filterUI()
{
	string cmd;
	cout << "Introduceti modul filtrarii(Brand = 1 / Pret = 2): ";
	cin >> cmd;
	if (cmd == "1") {
		string brand;

		cout << "Introduceti brand'ul ";
		cin >> brand;

		vector<Telefon>v = srv.filter(brand);
		for (const auto& el : v)
			cout << "ID: " << el.getID() << " Model:" << el.getModel() << " Brand:" << el.getBrand() << " Pret:" << el.getPret() << '\n';


	}

	else if (cmd == "2") {
		string pret;

		cout << "Introduceti pret: ";
		cin >> pret;

		vector<Telefon>v = srv.filter(pret);
		for (const auto& el : v)
			cout << "ID: " << el.getID() << " Model:" << el.getModel() << " Brand:" << el.getBrand() << " Pret:" << el.getPret() << '\n';

	}

	else cout << "Comanda invalida!";
	cout << "\n\n\n";
}
void UI::sortUI()
{
	string cmd;
	cout << "Sortare dupa (Pret = 1, Brand = 2, Model = 3): ";
	getline(cin, cmd);

	if (cmd == "1") {
		vector<Telefon>v = srv.sort([](const Telefon& m1, const Telefon& m2) {if (m1.getPret() < m2.getPret()) return true; else return false; });
		for (const auto& el : v)
			cout << "ID: " << el.getID() << " Model:" << el.getModel() << " Brand:" << el.getBrand() << " Pret:" << el.getPret() << '\n';


	}
	else if (cmd == "2") {
		vector<Telefon>v = srv.sort([](const Telefon& m1, const Telefon& m2) {if (m1.getBrand() < m2.getBrand()) return true; else return false; });
		for (const auto& el : v)
			cout << "ID: " << el.getID() << " Model:" << el.getModel() << " Brand:" << el.getBrand() << " Pret:" << el.getPret() << '\n';
	}

	else if (cmd == "3") {
		vector<Telefon>v = srv.sort([](const Telefon& m1, const Telefon& m2) {if (m1.getModel() < m2.getModel()) return true; else return false; });
		for (const auto& el : v)
			cout << "ID: " << el.getID() << " Model:" << el.getModel() << " Brand:" << el.getBrand() << " Pret:" << el.getPret() << '\n';
	}

	else cout << "Comanda invalida\n";
	cout << "\n\n\n";
}
void UI::showUI()
{
	cout << "Lista de comenzi:\n\n";
	cout << "'1' - adauga o Telefon\n";
	cout << "'3' - modifica o Telefon\n";
	cout << "'4' - tipareste un Telefon\n";
	cout << "'0' - iesire\n";
	cout << "'menu' - tipareste acest meniu\n";
}
void UI::addUI()
{
	string id;
	string brand;
	string model;
	string pret;
	cout << "Introduceti ID:\n";
	getline(cin, id);
	cout << "Introduceti brand'ul:\n";
	getline(cin, brand);
	cout << "Introduceti model:\n";
	getline(cin, model);
	cout << "Introduceti pret:\n";
	getline(cin, pret);
	if (id.length() > 16)
		cout << "ID-ul este prea mare!\n";
	else {
		int id_int = 0;

	}
	cout << "\n\n\n";
}

void UI::findPhoneUI()
{
	string id;
	cout << "Introduceti ID: ";
	cin >> id;
	if (id.length() > 16) {
		cout << "ID invalid!\n";
	}
	/*else {
			const int id_int = stoi(id);
			Telefon el = serv.srv_findPhone(id_int);
			cout << "ID: " << el.getID() << " Model:" << el.getModel() << " Brand:" << el.getBrand() << " Pret:" << el.getPret() << '\n';
		}*/

	cout << "\n\n\n";
}

void UI::run() {
	string cmd;
	while (1) {

		cout << "menu - pentru a vedea lista de comenzi!\n";
		cout << "Introduceti comanda\n>>>";


		getline(cin, cmd);
		if (cmd == "1")
			addUI();
		else if (cmd == "0")
			return;
		else if (cmd == "5")
			findPhoneUI();
		else if (cmd == "6")
			filterUI();
		else if (cmd == "7")
			sortUI();
		else if (cmd == "menu")
			showUI();
	}
}