#pragma once
#include<string>
#include<iostream>

using std::string;
using std::cout;

class Offer {
    std::string name;
    std::string teacher;
    std::string type;
    int hour;
public:
    Offer(const string n, const string d, const string t, int p) :name{ n }, teacher{ d }, type{ t }, hour{ p } {}

    Offer(const Offer& ot) :name{ ot.name }, teacher{ ot.teacher }, type{ ot.type }, hour{ ot.hour } {
        //cout << "!!!!!!!!!!!!!!!!!!!!\n";
    }
    string getName()const {
        return name;
    }
    string getTeacher()const {
        return teacher;
    }
    string getType()const {
        return type;
    }
    int getHour()const noexcept {
        return hour;
    }
};

bool cmpName(const Offer& o1, const Offer& o2);
bool cmpTeacher(const Offer& o1, const Offer& o2);
bool cmpType(const Offer& o1, const Offer& o2);
bool cmpHour(const Offer& o1, const Offer& o2);
