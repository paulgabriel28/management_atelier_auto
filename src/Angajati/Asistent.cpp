#include "../../include/Angajati/Asistent.h"
#include "../../include/utile/functions.h"

Asistent::Asistent() {
    coeficientSalariu = 1;
}

Asistent::Asistent(const string &nume, const string &prenume, const string *dataNastere, const string *dataAngajare, const long long *unixOcupat, const unsigned int &nrAsteptare, masinaInAsteptare *masiniAsteptare) 
                    : Angajat(nume, prenume, dataNastere, dataAngajare, unixOcupat, nrAsteptare, masiniAsteptare) {
    coeficientSalariu = 1;
}

void Asistent::afisareAngajat() const {
    Angajat::afisareAngajat();
    cout << "- Coeficient Salariat: " << coeficientSalariu << endl;
}

void Asistent::editAngajat() {
    Angajat::editAngajat();
    coeficientSalariu = 2;
}