#pragma once

#include <string>

class Song
{
private:
	int id;
	std::string title, artist, genre;
public:
	/*
		constructor clasa Song
	*/
	Song(const int& id, const std::string& title, const std::string& artist, const std::string& genre) :
		id{ id }, title{ title }, artist{ artist }, genre{ genre } {};

	/*
		get int id
		out: int id
	*/
	int get_id();

	/*
		get string titlu
		out: string titlu
	*/
	std::string get_title();

	/*
		get string artist
		out: string artist
	*/
	std::string get_artist();

	/*
		get string gen
		out: string gen
	*/
	std::string get_genre();

	/*
		suprascrie operator == pt id
	*/
	bool operator==(const int&);
	/*
		suprascrie operator == pt cantece
	*/
	bool operator==(const Song&);

	/*
		destructor
	*/
	~Song();
};
