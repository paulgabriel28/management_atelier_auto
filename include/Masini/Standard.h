#pragma once

#include "Masina.h"
#include "../enum.h"

class Standard final: public Masina {
    typeTransmisie transmisie;
    
    public:
        Standard();
        Standard(const double &, const unsigned int &, const bool &, const unsigned int &, const typeTransmisie &);

        typeTransmisie getTransmisie() const;
        double getPolita() override;
};