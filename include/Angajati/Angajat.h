#pragma once

#include <string>
#include <iostream> 

#include "../enum.h"

using namespace std;

struct masinaInAsteptare {
    typeMasini tip;
    long long unixIntrare;
};

class Angajat {
    protected:
        static unsigned int ID;
        unsigned int idAngajat;
        string nume;
        string prenume;
        string dataNastere[3] = {""};
        string dataAngajare[3] = {""};
        double coeficientSalariu;

        unsigned int nrMasiniInAsteptare = 0;
        masinaInAsteptare *masiniInAsteptare = nullptr;
        long long unixOcupat[5] = {0};
    
    public:
        Angajat();
        Angajat(const string &, const string &, const string *, const string *, const long long *, const unsigned int &, masinaInAsteptare *);
        virtual ~Angajat();

        static unsigned int getID();
        static void setAllID(const unsigned int &);
        unsigned int getIdAngajat() const;

        Angajat(const Angajat &);
        Angajat& operator=(const Angajat &);

        virtual void afisareAngajat() const;
        virtual void editAngajat();
        double getSalariu() const;
        
        friend void adaugareAngajat(Angajat **&, unsigned int &);
        friend void stergereAngajat(Angajat **&, unsigned int &);

        string getNume();
        string getPrenume();
        string *getDataAngajare();
        string *getDataNastere();

        void setUnixIntrariAtelier(const unsigned int &, const int &);
        auto getUnixIntrariAtelier(const unsigned int &poz) const -> long long;

};