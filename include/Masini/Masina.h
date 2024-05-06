#pragma once
#include <string>
#include <ctime>

using namespace std;

class Masina {
    protected:
        static unsigned int ID;
        double numarKm;
        unsigned int anFabricare;
        bool isDisel;
        double discount = 0;
        unsigned int idAngajat = 0;
    
    public:
        Masina();
        Masina(const double &, const unsigned int &, const bool &, const unsigned int &);
        virtual ~Masina();

        unsigned int getVechime() const;

        static unsigned int getID();
        double virtual getPolita() const = 0;
        unsigned int getAnFabricare() const;
        double getNumarKm() const;
        bool getIsDisel() const;
        double getDiscount() const;
};