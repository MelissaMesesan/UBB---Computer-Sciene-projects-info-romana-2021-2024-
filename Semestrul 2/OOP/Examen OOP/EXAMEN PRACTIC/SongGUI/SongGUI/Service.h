#pragma once

#include "Repo.h"

class Service
{
private:
	Repo& repo;
public:
	/*
	Constructor
	int: repo - refference to Repo
	*/
	Service(Repo& repo) : repo{ repo } {};

	/*
	Returns refference to repo
	*/
	std::vector<Song>& get_all();

	/*
	Updates a song with new title and rank
	in:
	id - int
	title - std::string
	rank - int
	*/
	void update(const int& id, const std::string& title, const int& rank);

	/*
	Deletes song from repo
	in: id - int
	If the song is the last from the artist, exception is raised
	*/
	void del(const int& id);

	/*
	Returns number of songs with given rank
	in: rank - int between 0 and 10
	out: int
	*/
	int get_rank_count(const int& rank);

	/*
	Adds song to repo
	in:
	id - int
	title - std::string
	artist - std::string
	rank - std::string
	*/
	void add(const int& id, const std::string& title, const std::string& artist, const int& rank);

	~Service();
};