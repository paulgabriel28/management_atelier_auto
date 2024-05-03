#include "../../include/Angajati/Director.h"

Director::Director() {
    coeficientSalariu = 2;
}

Director::Director(const string &nume, const string &prenume, const string *dataNastere, const string *dataAngajare, const long long *unixOcupat) 
                    : Angajat(nume, prenume, dataNastere, dataAngajare, unixOcupat) {
    coeficientSalariu = 2;
}

void Director::afisareAngajat() const {
    Angajat::afisareAngajat();
    cout << "Coeficient Salariat: " << coeficientSalariu << endl;
}

void Director::editAngajat() {
    Angajat::editAngajat();
    coeficientSalariu = 2;
}