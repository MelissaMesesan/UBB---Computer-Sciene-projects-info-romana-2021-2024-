#include "disciplina_service.h"
#include <functional>
#include <algorithm>
#include <assert.h>

vector <Offer> Agency::generalSort(bool (*smaller)(const Offer&, const Offer&)) {
    vector <Offer> v{ (repo.getAll()) };
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = i + 1; j < v.size(); j++) {
            if (!smaller(v[i], v[j])) {
                Offer aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }

        }
    }
    return v;
}


void Agency::addOffer(const string& name, const string& teacher, const string& type, int hour) {
    Offer off{ name, teacher, type, hour };
    //val.validate(off);
    repo.store(off);
}


vector <Offer> Agency::sortByName() {
    auto copyAll = repo.getAll();
    std::sort(copyAll.begin(), copyAll.end(), cmpName);
    return copyAll;
}





vector <Offer> Agency::sortByTeacher() {
    auto copyAll = repo.getAll();
    std::sort(copyAll.begin(), copyAll.end(), cmpTeacher);
    return copyAll;
}





vector <Offer> Agency::sortByTypeHour() {
    return generalSort([](const Offer& of1, const Offer& of2) {
        if (of1.getType() == of2.getType()) {
            return of1.getHour() < of2.getHour();
        }
        return of1.getType() < of2.getType();

        });
}



vector <Offer> Agency::filter(function<bool(const Offer&)> fct) {
    vector<Offer> rez;
    for (const auto& of : repo.getAll()) {
        if (fct(of)) {
            rez.push_back(of);
        }
    }
    return rez;
}


vector <Offer> Agency::filterHour(int hour) {
    return filter([hour](const Offer& of) {
        return of.getHour() == hour;
        });
}

vector <Offer> Agency::filterTeacher(string teacher) {
    return filter([teacher](const Offer& of) {
        return of.getTeacher() == teacher;
        });
}

void testAddFilterSort() {
    Agency_Repo repo;
    OfferValidator val;
    Agency str{ repo,val };
    str.addOffer("a", "a", "a", 10);
    assert(str.getAll().size() == 1);
    str.addOffer("h", "h", "h", 1);
    //str.addOffer("a", "a", "a", 10);
    str.addOffer("g", "g", "t", 20000);
    assert(str.filterTeacher("a").size() == 1);
    assert(str.filterHour(1).size() == 1);
    str.addOffer("z", "z", "g", 100);
    str.addOffer("b", "x", "a", 120);
    str.addOffer("c", "f", "j", 14500);
    auto firstP = str.sortByName()[0];
    assert(firstP.getName() == "a");
    firstP = str.sortByTeacher()[0];
    assert(firstP.getName() == "a");
    firstP = str.sortByTypeHour()[0];
    assert(firstP.getName() == "a");


}