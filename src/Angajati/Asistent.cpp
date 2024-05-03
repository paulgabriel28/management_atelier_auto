#include "../../include/Angajati/Asistent.h"
#include "../../include/utile/functions.h"

Asistent::Asistent() {
    coeficientSalariu = 1;
}

Asistent::Asistent(const string &nume, const string &prenume, const string *dataNastere, const string *dataAngajare, const long long *unixOcupat) 
                    : Angajat(nume, prenume, dataNastere, dataAngajare, unixOcupat) {
    coeficientSalariu = 1;
}

void Asistent::afisareAngajat() const {
    Angajat::afisareAngajat();
    cout << "\n\t- Coeficient Salariat: " << coeficientSalariu << endl;
}

void Asistent::editAngajat() {
    Angajat::editAngajat();
    coeficientSalariu = 2;
}