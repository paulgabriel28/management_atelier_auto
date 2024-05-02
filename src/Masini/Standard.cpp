#include "../../include/Masini/Standard.h"

Standard::Standard(const double &nrKm, const unsigned int &an, const bool &disel, const typeTransmisie &type)
                : Masina(nrKm, an, disel), transmisie(type) {
    discount = 0.05;
}

Standard::Standard() {
    discount = 0.05;
    transmisie = transmisieNULL;
}