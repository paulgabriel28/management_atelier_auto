#pragma once

#include "Masina.h"

class Camion final: public Masina {
    double tonaj;

    public:
        Camion();
        Camion(const double &, const unsigned int &, const bool &, const double &);

        double getTonaj() const;
};