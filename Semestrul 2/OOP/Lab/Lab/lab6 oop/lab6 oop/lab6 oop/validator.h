#pragma once
#include <string>
#include "disciplina.h"
#include <vector>
#include <sstream>
#include <ostream>

using std::vector;
using std::string;
using std::ostream;

class ValidateException {

    vector<string> msgs;

public:

    ValidateException(const vector<string>& errors) :msgs{ errors } {}

    friend ostream& operator<<(ostream& out, const ValidateException& ex);
};

ostream& operator<<(ostream& out, const ValidateException& ex);

class OfferValidator {
public:

    void validate(const Offer& p);

};

void testValidator();