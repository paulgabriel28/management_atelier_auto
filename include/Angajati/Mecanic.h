#pragma once

#include "Angajat.h"
#include <string>

using namespace  std;

class Mecanic final: virtual public Angajat {
    public:
        Mecanic();
        Mecanic(const string &, const string &, const string *, const string *);

        void afisareAngajat() const;
        void editAngajat();
        double getSalariu() const;
};