#pragma once

#include "Observer.h"
#include <vector>

class Observable
{
private:
	std::vector<Observer*> observers;
public:
	void add_observer(Observer* obs);
	void del_observer(Observer* obs);
	void notify_observers();
};

