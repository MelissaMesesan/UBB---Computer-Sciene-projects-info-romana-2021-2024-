#include "Repo.h"

#include <fstream>

void Repo::load_file()
{
	std::ifstream f;
	f.open(file_name);
	if (!f.is_open())
		throw std::exception("Fisierul nu s-a putut deschide");

	int id;
	std::string artist, genre, title;
	map_genre.clear();
	map_artist.clear();
	while (f >> id)
	{
		f.get();
		std::getline(f, title);
		std::getline(f, artist);
		std::getline(f, genre);
		songs.push_back(Song{ id,title,artist,genre });

		map_genre[genre] ++;
		map_artist[artist] ++;
	}
	f.close();
}

void Repo::save_file()
{
	std::ofstream o(file_name);
	if (!o.is_open())
		throw std::exception("Fisireul nu s-a putut deschide");

	map_genre.clear();
	map_artist.clear();
	for (auto& i : songs)
	{
		o << i.get_id() << '\n';
		o << i.get_title() << '\n';
		o << i.get_artist() << '\n';
		o << i.get_genre() << '\n';
		map_genre[i.get_genre()] ++;
		map_artist[i.get_artist()] ++;
	}
	o.close();
}

void Repo::add(Song s)
{
	std::vector<Song>::iterator it = find(songs.begin(), songs.end(), s);
	if (it != songs.end())
		throw std::exception("Melodia exista deja in repo!");
	songs.push_back(s);
	save_file();
}

void Repo::del(int id)
{
	std::vector<Song>::iterator it = find(songs.begin(), songs.end(), id);
	if (it == songs.end())
		throw std::exception("Melodia nu exista in repo!");
	songs.erase(it);
	save_file();
}

std::vector<Song>& Repo::get_all()
{
	return songs;
}

int Repo::get_nr_artist(std::string artist)
{
	return map_artist[artist];
}

int Repo::get_nr_genre(std::string genre)
{
	return map_genre[genre];
}

Repo::~Repo()
{
}