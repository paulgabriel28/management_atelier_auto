#pragma once

#include "Angajat.h"
#include <string>

using namespace  std;

class Director final: virtual public Angajat {
    public:
        Director();
        Director(const string &, const string &, const string *, const string *);

        void afisareAngajat() const;
        void editAngajat();
        double getSalariu() const;
};