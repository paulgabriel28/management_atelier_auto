#include "../../include/Masini/Camion.h"

Camion::Camion() {
    tonaj = 0;
    discount = 0.15;
}

Camion::Camion(const double &nrKm, const unsigned int &an, const bool &disel, const double &tona)
                : Masina(nrKm, an, disel), tonaj(tona) {}