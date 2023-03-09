#pragma once

#include "observer.h"
#include <vector>

class Observable
{
private:
	std::vector<Observer*> v;
public:
	void add_observer(Observer* obs)
	{
		v.push_back(obs);
	}

	void update_all()
	{
		for (auto& i : v)
			i->update_me();
	}
};