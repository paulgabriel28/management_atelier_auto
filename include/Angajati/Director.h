#ifndef _DIRECTOR
#define _DIRECTOR

#include "Angajat.h"
#include <string>
#include <iostream>

using namespace  std;

class Director final: virtual public Angajat {
    public:
        Director();
        Director(const string &, const string &, const string *, const string *, const long long *, const unsigned int &, masinaInAsteptare *);

        void afisareAngajat() const;
        void editAngajat();
};

#endif