#include "../../include/Masini/Standard.h"

Standard::Standard(const double &nrKm, const unsigned int &an, const bool &disel, const unsigned int &id, const typeTransmisie &type)
                : Masina(nrKm, an, disel, id), transmisie(type) {
    discount = 0.05;
}

Standard::Standard() {
    discount = 0.05;
    transmisie = transmisieNULL;
}

typeTransmisie Standard::getTransmisie() const {
    return transmisie;
}

double Standard::getPolita() {
    double politaAsigurare = double(Masina::getVechime() * 100 + ((isDisel == 1) ? 500 : 0) + ((numarKm > 200000) ? 500 : 0));

    if(discount) {
        return politaAsigurare - (politaAsigurare * discount);
    }
    return politaAsigurare;
}