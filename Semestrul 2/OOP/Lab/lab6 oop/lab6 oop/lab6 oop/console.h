#pragma once
#include "disciplina_service.h"
#include "disciplina.h"
class Console {

    Agency& str;

    void adaugaUI();

    void display(const vector<Offer>& offers);

public:

    Console(Agency& str) :str{ str } {}

    Console(const Console& ot) = delete;

    void start();
};