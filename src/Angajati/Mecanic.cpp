#include "../../include/Angajati/Mecanic.h"

Mecanic::Mecanic() {
    coeficientSalariu = 1.5;
}

Mecanic::Mecanic(const string &nume, const string &prenume, const string *dataNastere, const string *dataAngajare, const long long *unixOcupat) 
                    : Angajat(nume, prenume, dataNastere, dataAngajare, unixOcupat) {
    coeficientSalariu = 1.5;
}

void Mecanic::afisareAngajat() const {
    Angajat::afisareAngajat();
    cout << "- Coeficient Salariat: " << coeficientSalariu << endl;
}

void Mecanic::editAngajat() {
    Angajat::editAngajat();
    coeficientSalariu = 2;
}