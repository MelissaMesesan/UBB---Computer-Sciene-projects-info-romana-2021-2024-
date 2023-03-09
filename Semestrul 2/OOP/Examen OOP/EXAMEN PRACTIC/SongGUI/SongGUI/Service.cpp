#include "Service.h"


std::vector<Song>& Service::get_all()
{
	return repo.get_all();
}

void Service::update(const int& id, const std::string& title, const int& rank)
{
	if (title.size() == 0)
		throw std::exception("Titlul nu poate sa fie vid");
	repo.update(id, title, rank);
}

void Service::del(const int& id)
{
	repo.del(id);
}

int Service::get_rank_count(const int& rank)
{
	return repo.get_rank_count(rank);
}

void Service::add(const int& id, const std::string& title, const std::string& artist, const int& rank)
{
	repo.add(Song{ id,title,artist,rank });
}

Service::~Service()
{
}