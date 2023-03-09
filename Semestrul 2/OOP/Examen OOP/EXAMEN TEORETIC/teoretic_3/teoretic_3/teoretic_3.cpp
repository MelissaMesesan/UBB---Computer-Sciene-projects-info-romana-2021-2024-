
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Smoothy {
private:
    int pret;
public:
    Smoothy(int p) : pret{ p }{};
    virtual int getPret() {
        return pret;
    };
    virtual string descriere() = 0;

    virtual ~Smoothy(){}

};

class BasicSmoothy: public Smoothy {
private:
    string nume;
public:
    BasicSmoothy(string n, int pret) : nume{ n }, Smoothy{ pret } {};
    string descriere() override {
        return nume;
    }
};

class DecoratorSmoothy : public Smoothy {
private:
    Smoothy* smoothy;
public:
    DecoratorSmoothy(Smoothy* s) : smoothy{ s }, Smoothy{ s->getPret() }{};
    string descriere() override {
        return smoothy->descriere();
    }
};

class SmoothyCuFrisca : public DecoratorSmoothy {
public:
    SmoothyCuFrisca(Smoothy* s) : DecoratorSmoothy{ s } {};
    int getPret() override {
        return DecoratorSmoothy::getPret() + 2;
    }
    string descriere() override {
        return DecoratorSmoothy::descriere() + " " + "cu frisca";
    }
};

class SmoothyCuUmbreluta : public DecoratorSmoothy {
public:
    SmoothyCuUmbreluta(Smoothy* s) : DecoratorSmoothy{ s } {};
    int getPret() override {
        return DecoratorSmoothy::getPret() + 3;
    }
    string descriere() override {
        return DecoratorSmoothy::descriere() + " " + "cu umbreluta";
    }
};

vector<Smoothy*> getSmoothys() {
    vector<Smoothy*> s;
    Smoothy* skfu = new SmoothyCuUmbreluta{ new SmoothyCuFrisca{new BasicSmoothy{"kivi", 10}} };
    Smoothy* scf = new SmoothyCuFrisca{ new BasicSmoothy{"capsuni", 15} };
    Smoothy* sk = new BasicSmoothy{ "kivi", 10 };
    s.push_back(skfu);
    s.push_back(scf);
    s.push_back(sk);
    return s;
}

int main()
{
    /*
    Smoothy* s = new BasicSmoothy{ "kivi", 10};
    Smoothy* sf = new SmoothyCuFrisca{ s };
    Smoothy* sfu = new SmoothyCuUmbreluta{ sf };
    cout << s->getPret() << endl;
    cout << s->descriere() << endl;
    cout << sf->getPret() << endl;
    cout << sf->descriere() << endl;
    cout << sfu->getPret() << endl;
    cout << sfu->descriere() << endl;
    */

    vector<Smoothy*> smoothys = getSmoothys();
    sort(smoothys.begin(), smoothys.end(), [](const auto& st, const auto& dr) {
        return st->descriere() < dr->descriere();
    });

    for (auto sm : smoothys) {
        cout << sm->getPret() << endl;
        cout << sm->descriere() << endl;
    }
    _CrtDumpMemoryLeaks();
}