#include "../../include/Angajati/Mecanic.h"

Mecanic::Mecanic() {
    coeficientSalariu = 1.5;
}

Mecanic::Mecanic(const string &nume, const string &prenume, const string *dataNastere, const string *dataAngajare) 
                    : Angajat(nume, prenume, dataNastere, dataAngajare) {
    coeficientSalariu = 1.5;
}

void Mecanic::afisareAngajat() const {
    Angajat::afisareAngajat();
    cout << "\n\t- Coeficient Salariat: " << coeficientSalariu << endl;
}

void Mecanic::editAngajat() {
    Angajat::editAngajat();
    coeficientSalariu = 2;
}