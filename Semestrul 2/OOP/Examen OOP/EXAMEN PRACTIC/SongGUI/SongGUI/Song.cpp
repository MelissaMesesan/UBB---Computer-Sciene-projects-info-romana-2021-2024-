#include "Song.h"


Song::~Song()
{
}

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

int Song::get_rank()
{
	return rank;
}

void Song::set_title(const std::string& title)
{
	this->title = title;
}

void Song::set_rank(const int& rank)
{
	this->rank = rank;
}

bool Song::operator==(const int& i)
{
	return this->id == i;
}

bool Song::operator==(Song& s)
{
	return this->id == s.get_id();
}