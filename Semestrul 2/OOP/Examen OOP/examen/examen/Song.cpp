#include "Song.h"

int Song::get_id()
{
	return id;
}

std::string Song::get_title()
{
	return title;
}

std::string Song::get_artist()
{
	return artist;
}

std::string Song::get_genre()
{
	return genre;
}

bool Song::operator==(const int& id)
{
	return this->id == id;
}

bool Song::operator==(const Song& s)
{
	return this->id == s.id;
}


Song::~Song()
{
}