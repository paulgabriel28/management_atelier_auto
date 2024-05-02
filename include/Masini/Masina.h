#pragma once

#include <string>
using namespace std;

class Masina {
    protected:
        static unsigned int ID;
        double numarKm;
        unsigned int anFabricare;
        bool isDisel;
    
    public:
        inline Masina();
        inline Masina(const double &, const unsigned int &, const bool &);
        inline virtual ~Masina();

        inline static unsigned int getID();
        double virtual getPolita(const bool & = 0) const = 0;
        inline unsigned int getAnFabricare() const;
        inline double getNumarKm() const;
};