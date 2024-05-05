#pragma once

#include "Angajat.h"
#include <string>
#include <iostream>

using namespace  std;

class Asistent final: virtual public Angajat {
    public:
        Asistent();
        Asistent(const string &, const string &, const string *, const string *, const long long *, const unsigned int &, masinaInAsteptare *);

        void afisareAngajat() const;
        void editAngajat();
};