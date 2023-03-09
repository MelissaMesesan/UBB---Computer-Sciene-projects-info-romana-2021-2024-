#pragma once

#include "Repo.h"
#include <vector>
#include <algorithm>

class Service
{
private:
	Repo& repo;
public:
	Service(Repo& repo) : repo{ repo } {};

	std::vector<Song>& get_all();

	/*
		adaugare si validare de date
	*/
	void add(const int& id, const std::string& title, const std::string& artist, const std::string& genre);

	/*
		stergere
		in: int id
	*/
	void del(const int& id);

	/*
		cate genuri
		in: string gen
	*/
	int how_many_genre(const std::string& genre);

	/*
		numarul de artisti
		in: string artisti
	*/
	int get_nr_artist(std::string artist);

	/*
		numarul de genuri
		in: string gen
	*/
	int get_nr_genre(std::string genre);

	/*
		destructor
	*/

	//std::vector<Song>filter(std::string artist);

	~Service();
};