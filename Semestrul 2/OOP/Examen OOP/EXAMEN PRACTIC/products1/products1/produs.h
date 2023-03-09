#pragma once
#include <string>
#include <string.h>
#include <cstring>

using std::string;

class Product {

	int id;
	string name;
	string type;
	double price;

public:
	Product() = delete;
	Product(int id, const string& name, const string& type, double price) :id{ id }, name{ name }, type{ type }, price{ price }{}

	int getId() {
		return id;
	}
	string getName() const noexcept{
		return name;
	}
	string getType() const noexcept{
		return type;
	}
	double getPrice() const noexcept {
		return price;
	}
	int getVoc() {
		int count = 0;
		for (int i = 0; i < name.length(); i++) {
			if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u' || name[i] == 'A' || name[i] == 'E' || name[i] == 'I' || name[i] == 'O' || name[i] == 'U') {
				count++;
			}
		}
		return count;
	}
};