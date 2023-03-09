#include "Observable.h"

#include <algorithm>

void Observable::add_observer(Observer* obs)
{
	std::vector<Observer*>::iterator it = find(observers.begin(), observers.end(), obs);
	if (it == observers.end())
		observers.push_back(obs);
}

void Observable::del_observer(Observer* obs)
{
	std::vector<Observer*>::iterator it = find(observers.begin(), observers.end(), obs);
	if (it != observers.end())
		observers.erase(it);
}

void Observable::notify_observers()
{
	for (auto& i : observers)
		i->update_me();
}