#pragma once

#include <string>

class Song
{
private:
	int id;
	std::string title;
	std::string artist;
	int rank;
public:
	Song(const int& id, const std::string& title, const std::string& artist, const int& rank) :
		id{ id }, title{ title }, artist{ artist }, rank{ rank } {};

	/*
	Getter for id
	Out: int
	*/
	int get_id();

	/*
	Getter for title
	out: std::string
	*/
	std::string get_title();

	/*
	Getter for artist
	out: std::string
	*/
	std::string get_artist();

	/*
	Getter for rank
	out: int
	*/
	int get_rank();

	/*
	Sets title
	in: title - std::string
	*/
	void set_title(const std::string& title);

	/*
	Sets rank
	in: rank -int
	*/
	void set_rank(const int& rank);

	/*
	Song equals to it's id
	*/
	bool operator==(const int& i);

	/*
	Song equals to a song with same id
	*/
	bool operator==(Song& s);

	~Song();
};
