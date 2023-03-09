/*#include "validator.h"
#include <assert.h>
#include <sstream>
#include <ostream>

void OfferValidator::validate(const Offer& of) {
    vector<string> msgs;
    if (of.getPrice() < 0) msgs.push_back("invalid price!");
    if (of.getType().size() == 0) msgs.push_back("invalid type!");
    if (of.getDestination().size()==0)msgs.push_back("invalid destination!");
    if (of.getName().size() == 0) msgs.push_back("invalid name!");
    if (msgs.size() > 0) {
        throw ValidateException(msgs);
    }
}

ostream& operator<<(ostream& out, const ValidateException& ex) {
    for (const auto& msg : ex.msgs) {
        out << msg<<" ";
    }
    return out;
}

/*void testValidator() {
    OfferValidator v;
    Offer of{"","","", -1};
    try {
        v.validate(of);
    }
    catch (const ValidateException & ex) {
        std::stringstream sout;
        sout << ex;
        auto mesaj = sout.str();
        assert(mesaj.find("invalid") >= 0);
        //assert(mesaj.find("vid") >= 0);
    }

}*/