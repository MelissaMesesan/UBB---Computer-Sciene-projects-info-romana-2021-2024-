#include <iostream>
#include <vector>
 
using namespace std;

template <typename T>
class Geanta {
private:
    string nume;
    vector<T> continut;
public:
    Geanta(string n): nume { n }{};

    Geanta<T> operator+ (T cont) {
        continut.push_back(cont);
        return this;
    }


};

void calatorie() {
    Geanta<string> ganta{ "Ion" };//creaza geanta pentru Ion
    ganta = ganta + string{ "haine" }; //adauga obiect in ganta
    ganta + string{ "pahar" };
    for (auto o : ganta) {//itereaza obiectele din geanta
        cout << o << "\n";
    }
}

int main()
{
    calatorie();
}