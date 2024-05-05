#include "../../include/Masini/Camion.h"

Camion::Camion() {
    tonaj = 0;
    discount = 0.15;
}

Camion::Camion(const double &nrKm, const unsigned int &an, const bool &disel, const unsigned &id, const double &tona)
                : Masina(nrKm, an, disel, id), tonaj(tona) {
    discount = 0.15;
}

double Camion::getTonaj() const {
    return tonaj;
}