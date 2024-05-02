#pragma once

#include <string>
#include <iostream> 
using namespace std;

class Angajat {
    protected:
        static unsigned int ID;
        unsigned int idAngajat;
        string nume;
        string prenume;
        string dataNastere[3] = {""};
        string dataAngajare[3] = {""};
        double coeficientSalariu;

        int unixOcupat[5] = {0};
    
    public:
        inline Angajat();
        inline Angajat(const string &, const string &, const string *, const string *);
        inline virtual ~Angajat();

        static unsigned int getID();
        unsigned int getIdAngajat() const;

        virtual void afisareAngajat() const;
        virtual void editAngajat();
        virtual double getSalariu() const;
        
        friend void adaugareAngajat(Angajat **&, unsigned int &);
        friend void stergereAngajat(Angajat **&, unsigned int &);

        void setUnixIntrariAtelier(const unsigned int &, const int &);
        auto getUnixIntrariAtelier(const unsigned int &poz) const -> long long;
};