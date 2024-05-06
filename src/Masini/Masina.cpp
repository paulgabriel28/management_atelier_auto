#include "../../include/Masini/Masina.h"

unsigned int Masina::ID = 0;

// MARK: - Constructori
Masina::Masina() {
    Masina::ID++;
}

Masina::Masina(const double &nrKm, const unsigned int &an, const bool &disel, const unsigned int &angajat)
                : numarKm(nrKm), anFabricare(an), isDisel(disel),idAngajat(angajat) {
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

unsigned int Masina::getVechime() const {
    time_t timpPrezent = time(nullptr);
    tm* structTmPrezent = localtime(&timpPrezent);
    unsigned int anPrezent = structTmPrezent->tm_year + 1900;

    return anPrezent - anFabricare;
}

bool Masina::getIsDisel() const {
    return isDisel;
}

double Masina::getDiscount() const {
    return discount;
}