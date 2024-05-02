#include "../../include/Masini/Masina.h"

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