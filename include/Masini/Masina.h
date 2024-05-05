#pragma once
#include <string>
#include "../utile/utileMasini.h"

using namespace std;

class Masina {
    protected:
        static unsigned int ID;
        double numarKm;
        unsigned int anFabricare;
        bool isDisel;
        double discount = 0;
    
    public:
        Masina();
        Masina(const double &, const unsigned int &, const bool &);
        virtual ~Masina();

        static unsigned int getID();
        double virtual getPolita() const;
        unsigned int getAnFabricare() const;
        double getNumarKm() const;
};