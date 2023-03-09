#pragma once
#include "disciplina.h"

#include <vector>
#include <string>
#include <ostream>

using std::vector;
using std::string;
using std::ostream;

class Agency_Repo {

    vector<Offer> all;

    bool exist(const Offer& o) const;

public:

    Agency_Repo() = default;

    Agency_Repo(const Agency_Repo& ot) = delete;

    void store(const Offer& o);

    const Offer& find(string name, string teacher, string type) const;

    const vector<Offer>& getAll() const noexcept;

};

class Agency_Repo_Exception {

    string msg;
public:

    Agency_Repo_Exception(string m) :msg{ m } {}

    friend ostream& operator<<(ostream& out, const Agency_Repo_Exception& ex);

};

ostream& operator<<(ostream& out, const Agency_Repo_Exception& ex);
void testRepo();
