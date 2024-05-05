#include "../../include/Masini/Masina.h"

unsigned int Masina::ID = 0;

// MARK: - Constructori
Masina::Masina() {
    Masina::ID++;
}

Masina::Masina(const double &nrKm, const unsigned int &an, const bool &disel)
                : numarKm(nrKm), anFabricare(an), isDisel(disel) {
    Masina::ID++;
}

Masina::~Masina() {
    Masina::ID--;
}

unsigned int Masina::getID() {
    return ID;
}

unsigned int Masina::getAnFabricare() const {
    return anFabricare;
}

double Masina::getNumarKm() const {
    return numarKm;
}

double Masina::getPolita() const {
    double politaAsigurare = double(getVechime() * 100 + ((isDisel == 1) ? 500 : 0) + ((numarKm > 200000) ? 500 : 0));

    if(discount) {
        return politaAsigurare - (politaAsigurare * discount);
    }
    return politaAsigurare;
}

unsigned int Masina::getVechime() const {
    time_t timpPrezent = time(nullptr);
    tm* structTmPrezent = localtime(&timpPrezent);
    unsigned int anPrezent = structTmPrezent->tm_year + 1900;

    return anPrezent - anFabricare;
}
