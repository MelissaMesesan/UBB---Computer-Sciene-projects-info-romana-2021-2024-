#include "disciplina_repo.h"
#include<iostream>
#include<sstream>
#include <string.h>
#include <cstring>
#include <assert.h>

using std::ostream;
using std::stringstream;

void Agency_Repo::store(const Offer& of)
{
    /*if(exist(of)){
        throw Agency_Repo_Exception("Offer already exists!");
    }*/
    all.push_back(of);

}

/*bool Agency_Repo::exist(const Offer& of)const{
    try{
        find((of.getName()), of.getDestination(), of.getType());
        return true;
    }
    catch(Agency_Repo_Exception&){
        return false;
    }
}*/

const Offer& Agency_Repo::find(string name, string teacher, string type) const {
    for (const auto& of : all)
        if (of.getName() == name && of.getTeacher() == teacher && of.getType() == type) return of;}

//throw Agency_Repo_Exception("there is no offer with name"+name+"destination"+destination+"type"+type);

const vector<Offer>& Agency_Repo::getAll() const noexcept {
    return all;
}

/*ostream& operator<<(ostream& out, const Agency_Repo_Exception& ex){
    out<<ex.msg;
    return out;
}*/


void testRepo() {
    Agency_Repo repo;
    repo.store(Offer({ "a", "a", "a", 5 }));
    assert(repo.getAll().size() == 1);
    assert(repo.find("a", "a", "a").getName() == "a");

    repo.store(Offer({ "b", "b", "b", 5 }));
    assert(repo.getAll().size() == 2);

    auto p = repo.find("a", "a", "a");
    assert(p.getName() == "a");
    assert(p.getTeacher() == "a");


}




