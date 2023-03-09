#pragma once

#include "disciplina.h"
#include "disciplina_repo.h"
#include <string>
#include <vector>

#include <functional>
#include "validator.h"

using std::vector;
using std::function;

class Agency {

    Agency_Repo& repo;

    OfferValidator& val;

    vector <Offer> generalSort(bool (*smaller)(const Offer&, const Offer&));

    vector <Offer> filter(function <bool(const Offer&)> fct);

public:

    Agency(Agency_Repo& repo, OfferValidator& val) :repo{ repo }, val{ val }{}

    Agency(const Agency& ot) = delete;

    const vector<Offer>& getAll() noexcept {
        return repo.getAll();
    }

    void addOffer(const string& name, const string& teacher, const string& type, int hour);

    vector <Offer> sortByName();

    vector <Offer> sortByTeacher();

    vector <Offer> sortByTypeHour();

    vector <Offer> filterTeacher(string teacher);

    vector <Offer> filterHour(int hour);

};
void testAddFilterSort();