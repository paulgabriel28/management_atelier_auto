#include "../include/Angajati/Asistent.h"
#include "../include/utile/functions.h"

Asistent::Asistent() {
    coeficientSalariu = 1;
}

Asistent::Asistent(const string &nume, const string &prenume, const string *dataNastere, const string *dataAngajare) 
                    : Angajat(nume, prenume, dataNastere, dataAngajare) {
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

double Asistent::getSalariu() const {
    return calculSalariu(double(stoi(dataAngajare[2])), coeficientSalariu);
}