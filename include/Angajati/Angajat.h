#pragma once

#include <string>
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
        Angajat();
        Angajat(const string &, const string &, const string *, const string *);
        virtual ~Angajat();

        static unsigned int getID();
        unsigned int getIdAngajat() const;

        virtual void afisareAngajat() const;
        virtual void editAngajat();
        virtual double getSalariu() const;
        
        friend void adaugareAngajat(Angajat **&, unsigned int &, const Angajat *);
        friend void stergereAngajat(Angajat **&, unsigned int &, const unsigned int &);

        void setUnixIntrariAtelier(const unsigned int &, const int &);
        auto getUnixIntrariAtelier() const -> int;
};