#ifndef _AUTOBUZ
#define _AUTOBUZ

#include "Masina.h"

class Autobuz final: public Masina {
    unsigned int numarLocuri;

    public:
        Autobuz();
        Autobuz(const double &, const unsigned int &, const bool &, const unsigned int &, const unsigned int &);

        unsigned int getNumarLocuri() const;
        double getPolita() override;
};

#endif