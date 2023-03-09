#pragma once

#include <vector>
#include <map>
#include <exception>
#include <fstream>
#include <algorithm>
#include "Song.h"

class Repo
{
private:
	std::vector<Song> songs;
	std::map<int, int> rank_count;
	std::map<std::string, int> artist_count;
	std::string file_name;
	/*
	Loads items from file: file_name
	*/
	void load_file();

	/*
	Saves items to file: file_name
	*/
	void save_file();
public:
	/*
	Constructor
	in: file_name std::string - file name for data
	*/
	Repo(const std::string& file_name) : file_name{ file_name }
	{
		load_file();
	};

	/*
	Returns refference to vector from repo
	*/
	std::vector<Song>& get_all();

	/*
	Returns number of songs with given rank
	in: rank - int between 0 and 10
	out: int
	*/
	int get_rank_count(const int& rank);

	/*
	Return number of songs with given artist
	int: artist - std::string
	out - int
	*/
	int get_artist_count(const std::string& artist);

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
	Adds a song to repo
	If exists, throws exception
	In: s - Song
	*/
	void add(Song s);
	~Repo();
};