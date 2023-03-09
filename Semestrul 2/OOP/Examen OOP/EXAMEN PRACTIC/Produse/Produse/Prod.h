#pragma once
#include <string>
#include <algorithm>
using namespace std;

class Prod {
	int id;
	string name;
	string type;
	double price;
public:
	Prod(int id, string name, string type, double price) :id{ id }, name{ name }, type{ type }, price{ price }{}
	int getId()const {
		/*
		Getter function:
		out: id of product
		*/
		return id;
	}
	string getName()const {
		/*
		Getter function
		out: name of product
		*/
		return name;
	}
	string getType()const {
		/*
		Getter function
		out: type of product
		*/
		return type;
	}
	double getPrice()const {
		/*
		getter function
		out: price of product
		*/
		return price;
	}

};
