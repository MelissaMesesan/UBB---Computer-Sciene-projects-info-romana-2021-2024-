#include "service.h"


std::vector<Song>& Service::get_all()
{
	return repo.get_all();
	/*std::vector<Song>v = this->repo.get_all();
	sort(v.begin(), v.end(), [](Song& p1, Song& p2) {
		return p1.get_artist() < p2.get_artist();
		});
	return v;*/
}

void Service::add(const int& id, const std::string& title, const std::string& artist, const std::string& genre)
{
	if (id < 1)
		throw std::exception("Id invalid");
	if (title.size() == 0)
		throw std::exception("Titlu vid");
	if (artist.size() == 0)
		throw std::exception("Artist vid");
	if (genre != std::string("pop") && genre != std::string("rock") && genre != std::string("folk") && genre != std::string("disco"))
		throw std::exception("Gen invalid!");

	repo.add(Song(id, title, artist, genre));
}

void Service::del(const int& id)
{
	repo.del(id);
}

int Service::how_many_genre(const std::string& genre)
{
	int total = 0;
	for (auto& i : repo.get_all())
		if (i.get_genre() == genre)
			total++;
	return total;
}

int Service::get_nr_artist(std::string artist)
{
	return repo.get_nr_artist(artist);
}

int Service::get_nr_genre(std::string genre)
{
	return repo.get_nr_genre(genre);
}

/*std::vector<Song> Service::filter(std::string artist) {
	std::vector<Song>filtered;
	std:: vector<Song>& v = get_all();
	std::copy_if(v.begin(), v.end(), back_inserter(filtered), [=](const Product& p) {
		return p.getPrice() <= price;
		});
	return filtered;

}
*/
Service::~Service()
{
}