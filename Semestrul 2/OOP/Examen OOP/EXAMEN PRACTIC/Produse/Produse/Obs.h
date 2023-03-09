#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Observer {
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};
class Observable {
	vector<Observer*> obs;
public:
	virtual void attach(Observer* ob) {
		obs.push_back(ob);
	}
	virtual void detach(Observer* ob) {
		obs.erase(find_if(obs.begin(), obs.end(), [&](const Observer* o) {return o == ob; }));
	}
	virtual ~Observable() {}
protected:
	void notify() {
		for (auto ob : obs)
			ob->update();
	}
};
