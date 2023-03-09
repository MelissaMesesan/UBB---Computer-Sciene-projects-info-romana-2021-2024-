//#include <iostream>
#include "validator.h"
#include "disciplina_service.h"
#include "disciplina_repo.h"
#include "disciplina.h"
#include "console.h"



int main()
{
    testAddFilterSort();
    testRepo();
    Agency_Repo repo;
    OfferValidator val;
    Agency str{ repo, val };
    str.addOffer("OOP", "Czibula", "IR", 12);
    str.addOffer("Geometrie", "Blaga", "IE", 3);
    str.addOffer("SDA", "Czibula", "IE", 10);
    str.addOffer("OS", "Boian", "IR", 4);

    Console ui{ str };
    ui.start();
}