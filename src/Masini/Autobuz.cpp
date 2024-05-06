#include "../../include/Masini/Autobuz.h"

Autobuz::Autobuz() {
    numarLocuri = 0;
    discount = 0.10;
}

Autobuz::Autobuz(const double &nrKm, const unsigned int &an, const bool &disel, const unsigned int &id, const unsigned int &nrLoc)
                : Masina(nrKm, an, disel, id), numarLocuri(nrLoc) {
    discount = 0.10;
}

unsigned int Autobuz::getNumarLocuri() const {
    return numarLocuri;
}

double Autobuz::getPolita() {
    double politaAsigurare = double(Masina::getVechime() * 200 + ((isDisel == 1) ? 1000 : 0) + ((numarKm > 200000) ? 1000 : (numarKm > 100000) ? 500 : 0));
    
    if(discount) {
        return politaAsigurare - (politaAsigurare * discount);
    }
    return politaAsigurare;
}