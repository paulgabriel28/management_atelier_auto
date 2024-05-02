#include "../../include/Masini/Standard.h"
#include "../../include/utile/utileMasini.h"

Standard::Standard(const double &nrKm, const unsigned int &an, const bool &disel, const typeTransmisie &type)
                : Masina(nrKm, an, disel), transmisie(type) {}

double Standard::getPolita(const bool &discount) const {
    double politaAsigurare = double(getVechime(anFabricare) * 100 + ((isDisel == 1) ? 500 : 0) + ((numarKm > 200000) ? 500 : 0));

    if(discount) {
        return politaAsigurare - (politaAsigurare * 0.05);
    }
    return politaAsigurare;
}