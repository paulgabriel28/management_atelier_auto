#pragma once

#include "Angajat.h"
#include <string>
#include <iostream>

using namespace  std;

class Mecanic final: virtual public Angajat {
    public:
        Mecanic();
        Mecanic(const string &, const string &, const string *, const string *, const long long *);

        void afisareAngajat() const;
        void editAngajat();
};