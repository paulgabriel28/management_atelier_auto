#include "../../include/Masini/Autobuz.h"

Autobuz::Autobuz() {
    numarLocuri = 0;
    discount = 0.10;
}

Autobuz::Autobuz(const double &nrKm, const unsigned int &an, const bool &disel, const unsigned int &nrLoc)
                : Masina(nrKm, an, disel), numarLocuri(nrLoc) {
    discount = 0.10;
}