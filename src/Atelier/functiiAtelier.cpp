#include "../../include/Atelier/functiiAtelier.h"

// NOTE: cand se apeleaza atelier din meniu, sa se verifice daca e deschis
short nouaMasinaInAtelier() {
    Angajat **vec = nullptr;
    unsigned int nrAngajati = 0;

    typeMasini tipMasina = tipNULL;
    
    citesteAngajatiJSON(vec, nrAngajati);

    sendInfo("Urmeaza sa adaugi o masina noua in atelier!");
    sendInfo("Pentru a continua, este nevoie de tipul masinii\nTipuri de masini dispinibile:\n\t standard \t|\t autobuz \t|\t camion");
    
    string tipMasinaString;
    do {
        citesteValoare("Introdu tipul masinii: ");
        cin >> tipMasinaString;
        tipMasina = stringToTypeMasina(tipMasinaString);

        if(tipMasina == tipNULL) {
            sendError("Tipul masinii introdus nu este corect!");
            sendInfo("Tipuri de masini dispinibile:\n\t standard \t|\t autobuz \t|\t camion");
        }
    } while(tipMasina == tipNULL);
    
    clearChat();
    sendSuccess("Tipul masinii a fost setat cu succes!");

    char preferinta;
    int preferintaAngajat = -2;
    sendQuestion("Doresti ca masina sa fie adaugata la un anumit angajat?");
    sendInfo("Y - Da \t|\t N - Nu");

    do {
        cin >> preferinta;
        if(preferinta == 'Y' || preferinta == 'y') {
            clearChat();
            sendInfo("Alege angajatul la care vrei sa fie adaugata masina:");
            for(unsigned int i = 0; i < nrAngajati; i++) {
                cout << "\t" << vec[i]->getIdAngajat() << " -> " << vec[i]->getNume() << " " << vec[i]->getPrenume() << endl;
            }

            do {
                citesteValoare("Introdu ID-ul angajatului: ");
                cin >> preferintaAngajat;
                if(preferintaAngajat >= (int)nrAngajati) {
                    sendError("Angajatul ales nu exista!");
                }
            } while(!(existaIdAngajat(vec, nrAngajati, preferintaAngajat)));

        } else if(preferinta == 'N' || preferinta == 'n') {
            preferintaAngajat = -1;

        } else {
            sendError("Optiunea aleasa nu este corecta!");
        }
    } while(preferintaAngajat == -2);

    if(preferintaAngajat == -1) {
        sendInfo("Masina va fi adaugata in atelier!");
    } else {
        sendInfo("Masina va fi adaugata la angajatul ales!");
    }
    
    return 0;
}