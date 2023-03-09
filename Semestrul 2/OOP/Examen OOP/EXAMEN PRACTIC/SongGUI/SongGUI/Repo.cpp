#include "Repo.h"

void Repo::load_file()
{
	std::ifstream f;
	f.open(file_name);
	if (!f.is_open())
		throw std::exception("File cannot be opened to read");

	int id;
	std::string title;
	std::string artist;
	int rank;
	while (f >> id)
	{
		f.get();
		std::getline(f, title);
		std::getline(f, artist);
		f >> rank;

		rank_count[rank] ++;
		artist_count[artist] ++;

		songs.push_back(Song{ id,title,artist,rank });
	}
	f.close();
	sort(songs.begin(), songs.end(), [](Song& s1, Song& s2) {
		return s1.get_rank() > s2.get_rank();
		}
	);

}

void Repo::save_file()
{
	std::ofstream o;
	o.open(file_name);
	if (!o.is_open())
		throw std::exception("Cannot open file to write data");

	for (auto& i : songs)
	{
		o << i.get_id() << '\n';
		o << i.get_title() << '\n';
		o << i.get_artist() << '\n';
		o << i.get_rank() << '\n';
	}

	o.close();
}

std::vector<Song>& Repo::get_all()
{
	return songs;
}

int Repo::get_rank_count(const int& rank)
{
	return rank_count[rank];
}

int Repo::get_artist_count(const std::string& artist)
{
	return artist_count[artist];
}

void Repo::update(const int& id, const std::string& title, const int& rank)
{
	std::vector<Song>::iterator it = find(songs.begin(), songs.end(), id);

	if (it != songs.end())
	{
		rank_count[it->get_rank()] --;
		rank_count[rank] ++;

		it->set_title(title);
		it->set_rank(rank);
	}
	sort(songs.begin(), songs.end(), [](Song& s1, Song& s2) {
		return s1.get_rank() > s2.get_rank();
		}
	);
	save_file();

}

void Repo::del(const int& id)
{
	std::vector<Song>::iterator it = find(songs.begin(), songs.end(), id);

	if (artist_count[it->get_artist()] == 1)
		throw std::exception("Este ultima lui melodie :(");

	artist_count[it->get_artist()] --;
	rank_count[it->get_rank()] --;
	songs.erase(it);
	save_file();
}

void Repo::add(Song s)
{
	std::vector<Song>::iterator it = find(songs.begin(), songs.end(), s.get_id());

	if (it != songs.end())
		throw std::exception("Song alreadty exists in repo");

	songs.push_back(s);
	save_file();
}

Repo::~Repo()
{
}