#pragma once

#include <string>
#include <vector>
#include <exception>
#include "Song.h"
#include <map>

class Repo
{
private:
	std::string file_name;
	std::vector<Song> songs;
	void load_file();
	void save_file();
	std::map<std::string, int> map_genre;
	std::map<std::string, int> map_artist;
public:
	Repo(std::string file_name) : file_name{ file_name } {
		load_file();
	};

	/*
		adauga melodii in repo
	*/
	void add(Song s);

	/*
		sterge melodii din repo
		in: int id
	*/
	void del(int id);

	/*
		get all
		in: vector
	*/
	std::vector<Song>& get_all();

	/*
		numarul de artisti
		in: string artist
		out: int nr artisti
	*/
	int get_nr_artist(std::string artist);

	/*
		numarul de genuri
		in: string gen
		out: int nr genuri
	*/
	int get_nr_genre(std::string genre);

	/*
		destructor
	*/
	~Repo();
};
