#pragma once

#include "Masina.h"

enum typeTransmisie {
    transmisieNULL = -1,
    MANUAL = 0,
    AUTOMAT
};

class Standard final: public Masina {
    typeTransmisie transmisie;
    
    public:
        inline Standard(const double &, const unsigned int &, const bool &, const typeTransmisie &);

        inline double getPolita(const bool & = 0) const;
};