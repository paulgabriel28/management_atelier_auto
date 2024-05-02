#pragma once

#include "Masina.h"
#include "../enum.h"

class Standard final: public Masina {
    typeTransmisie transmisie;
    
    public:
        inline Standard();
        inline Standard(const double &, const unsigned int &, const bool &, const typeTransmisie &);
};