#pragma once

#include "Masina.h"

class Camion final: public Masina {
    double tonaj;

    public:
        inline Camion();
        inline Camion(const double &, const unsigned int &, const bool &, const double &);
};