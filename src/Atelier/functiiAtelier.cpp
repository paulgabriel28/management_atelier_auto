#include "../../include/Atelier/functiiAtelier.h"

// lucram pe zile
short nouaMasinaInAtelier() {
    Angajat **vec = nullptr;
    unsigned int nrAngajati = 0;
    unsigned int preferintaAngajat = 0;

    typeMasini tipMasina = tipNULL;
    unsigned int pozMasina = vectorNULL;
    
    citesteAngajatiJSON(vec, nrAngajati);

    sendInfo("Introduceti tipul masinii: ");
}