#include "disciplina.h"

bool cmpName(const Offer& o1, const Offer& o2) {
    return o1.getName() < o2.getName();
}

bool cmpTeacher(const Offer& o1, const Offer& o2) {
    return o1.getTeacher() < o2.getTeacher();
}

/*bool cmpType(const Offer& o1, const Offer& o2){
    return o1.getType()<o2.getType();
}

bool cmpPrice(const Offer& o1, const Offer& o2){
    return o1.getPrice()<o2.getPrice();
}*/

