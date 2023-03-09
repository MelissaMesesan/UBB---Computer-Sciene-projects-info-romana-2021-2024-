#pragma once

#include "Song.h"
#include "Repo.h"
#include <assert.h>
#include "Service.h"

void test_song()
{
	Song song{ 1,"Umbrela","Rihana",4 };

	assert(song.get_id() == 1);
	assert(song.get_artist() == std::string("Rihana"));
	assert(song.get_title() == std::string("Umbrela"));
	assert(song.get_rank() == 4);
	assert(song == 1);
	assert(song == Song(1, "fafa", "gaga", 4));

	song.set_rank(7);
	song.set_title("Vai");
	assert(song.get_rank() == 7);
	assert(song.get_title() == std::string("Vai"));
}

void test_repo()
{
	Repo repo{ "test.txt" };

	assert(repo.get_all().size() == 5);
	assert(repo.get_artist_count("Miley Cyrus") == 1);
	assert(repo.get_rank_count(1) == 1);

	repo.update(1, "Vai", 1);
	assert(repo.get_rank_count(1) == 2);
	repo.update(1, "Umbrela", 5);

	try
	{
		repo.del(1);
	}
	catch (std::exception& e)
	{
		assert(true);
	}
}

void test_service()
{
	Repo repo{ "test.txt" };
	Service service{ repo };

	assert(service.get_all().size() == 5);
	service.update(1, "Vai", 1);
	assert(service.get_rank_count(1) == 2);
	service.update(1, "Umbrela", 5);

	try
	{
		service.update(1, "", 0);
	}
	catch (std::exception& e)
	{
		assert(true);
	}

	service.del(5);
	assert(service.get_all().size() == 4);
	service.add(5, "Baby", "Justin BIeber", 1);
}

void test_all()
{
	test_song();
	test_repo();
	test_service();
}
