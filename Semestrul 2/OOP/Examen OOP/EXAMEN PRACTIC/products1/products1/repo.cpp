#include "produs.h"
#include <vector>
#include "repo.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

void Repo::addProduct(Product& p) {
	all.push_back(p);
	loadToFile();
}

void Repo::loadFromFile() {
	ifstream repoFile(this->filename);
	string line;
	while (getline(repoFile, line))
	{
		string name, type;
		int id = 0;
		double price;

		stringstream linestream(line);
		string current_item;
		int item_no = 0;
		while (getline(linestream, current_item, ','))
		{
			if (item_no == 0) id = stoi(current_item);
			if (item_no == 1) name = current_item;
			if (item_no == 2) type = current_item;
			if (item_no == 3) price = std::stod(current_item); 
			item_no++;
		}
		Product p{ id, name, type, price };

		Repo::addProduct(p);


	}
	repoFile.close();
}

void Repo::loadToFile() {
	ofstream prodOutput(this->filename);
	for (auto& prod : getAll()) {
		prodOutput << prod.getId() << "," << prod.getName() << ",";
		prodOutput << prod.getType() << "," << prod.getPrice() << endl;
	}
	prodOutput.close();
}