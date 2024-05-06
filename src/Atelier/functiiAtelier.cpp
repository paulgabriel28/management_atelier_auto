#include "../../include/Atelier/functiiAtelier.h"

vectorMasiniPoz getLocLiber(Angajat *const *vec, const unsigned int &preferintaAngajat, const typeMasini &tipMasina) {
    switch (tipMasina)
    {
        case tipSTANDARD: {
            if(vec[preferintaAngajat]->getUnixIntrariAtelier((int)MASINA1) == 0) {
                return MASINA1;
            }
            else if(vec[preferintaAngajat]->getUnixIntrariAtelier((int)MASINA2) == 0) {
                return MASINA2;
            }
            else if(vec[preferintaAngajat]->getUnixIntrariAtelier((int)MASINA3) == 0) {
                return MASINA3;
            }
            break;
        }

        case tipAUTOBUZ: {
            if(vec[preferintaAngajat]->getUnixIntrariAtelier((int)AUTOBUZ) == 0) {
                return AUTOBUZ;
            }
            break;
        }

        case tipCAMION: {
            if(vec[preferintaAngajat]->getUnixIntrariAtelier((int)CAMION) == 0) {
                return CAMION;
            }
            break;
        }
        
        default:
            break;
    }

    return vectorNULL;  
}

short nouaMasinaInAtelier() {
    Angajat **vec = nullptr;
    unsigned int nrAngajati = 0;

    typeMasini tipMasina = tipNULL;
    citesteAngajatiJSON(vec, nrAngajati);

    sendInfo("Urmeaza sa adaugi o masina noua in atelier!");
    sendInfo("Pentru a continua, este nevoie de tipul masinii\nTipuri de masini dispinibile:\n\t standard \t|\t autobuz \t|\t camion");
    
    string tip;
    do {
        citesteValoare("Introdu tipul masinii");
        cin >> tip;
        tipMasina = stringToTypeMasina(tip);
        if(stringToTypeMasina(tip) == tipNULL) {
            sendError("Tipul masinii introdus nu este corect!");
            sendInfo("Tipuri de masini dispinibile:\n\t standard \t|\t autobuz \t|\t camion");
        }
    } while(stringToTypeMasina(tip) == tipNULL);


    Masina *masina = citesteMasina(tip);
    cout << masina->getPolita() << endl;

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
                citesteValoare("Introdu ID-ul angajatului");
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
    
    if(preferintaAngajat != -1) {
        vectorMasiniPoz loc = getLocLiber(vec, preferintaAngajat, tipMasina);
        if(loc != vectorNULL) {
            int zile = 0;
            citesteValoare("Introdu numarul de zile pana cand masina va fi scoasa din atelier");
            cin >> zile;
            long long timeUnix = ZileToUnix(zile);
            vec[preferintaAngajat]->setUnixIntrariAtelier((int)loc, timeUnix);
            
            double bacsis = masina->getPolita() * 0.01;
            intrareInAtelier(vec[preferintaAngajat], masina, timeUnix, true, false, bacsis);
            sendSuccess("Masina a fost adaugata cu succes la angajatul ales!");
            salveazaAngajatiToJson(vec, nrAngajati);
            return 1;
        }
        else if(loc == vectorNULL) {
            sendError("Angajatul ales nu are locuri disponibile pentru masina de tipul ales!");
            sendInfo("Doresti ca sistemul sa aleaga un angajat, sau doresti sa ramai in lsita de asteptare pentru angajatul ales!\n\t1 - Alege un angajat automat \t|\t 2 - Ramai in lista de asteptare pentru angajatul ales");
            citesteValoare("Introdu optiunea");
            unsigned short int dorinta = 0;
            do {
                cin >> dorinta;
                if(dorinta > 2) {
                    clearChat();
                    sendError("Optiunea aleasa nu este corecta!\n\t1 - Alege un angajat automat \t|\t 2 - Ramai in lista de asteptare pentru angajatul ales \t|\t 0 - Nu adauga masina");
                    citesteValoare("Introdu optiunea");
                }
            } while(dorinta > 2);

            if(dorinta == 1) {
                for(unsigned int i = 0; i < nrAngajati; i++) {
                    vectorMasiniPoz loc = getLocLiber(vec, i, tipMasina);
                    if(loc != vectorNULL) {
                        int zile = 0;
                        citesteValoare("Introdu numarul de zile pana cand masina va fi scoasa din atelier");
                        cin >> zile;
                        long long timeUnix = ZileToUnix(zile);
                        vec[i]->setUnixIntrariAtelier((int)loc, timeUnix);
                        sendSuccess("Masina a fost adaugata cu succes la angajatul cu ID-ul " + i);
                        preferintaAngajat = 0;

                        double bacsis = masina->getPolita() * 0.01;
                        intrareInAtelier(vec[preferintaAngajat], masina, timeUnix, true, false, bacsis);
                        salveazaAngajatiToJson(vec, nrAngajati);
                        return 1;
                    }
                }
            }
            else if(dorinta == 2) {
                vec[preferintaAngajat]->addMasiniInAsteptare(tipMasina, getCurrentTime());
                double bacsis = masina->getPolita() * 0.01;
                intrareInAtelier(vec[preferintaAngajat], masina, 0, true, true, bacsis);

                sendInfo("Ai fost adaugat in lista de asteptare pentru angajatul ales!");
                salveazaAngajatiToJson(vec, nrAngajati);
                return 1;
            }
            else if(dorinta == 0) {
                sendInfo("Ai parasit atelierul, iar masina nu a fost salvata in atelier!");
                return 0;
            }
        }
    }
    else if (preferintaAngajat == -1){
        sendInfo("Vei fi repartizat la un angajat disponibil!");

        unsigned int incercariAngajati = 0;
        for(unsigned int i = 0; i < nrAngajati; i++) {
            vectorMasiniPoz loc = getLocLiber(vec, i, tipMasina);
            if(loc != vectorNULL) {
                int zile = 0;
                citesteValoare("Introdu numarul de zile pana cand masina va fi scoasa din atelier");
                cin >> zile;
                long long timeUnix = ZileToUnix(zile);
                vec[i]->setUnixIntrariAtelier((int)loc, timeUnix);
                sendInfo("Masina a fost adaugata cu succes la angajatul cu ID-ul " + to_string(i) + " si va fi scoasa din atelier in " + to_string(zile) + " zile");
                double bacsis = masina->getPolita() * 0.01;
                intrareInAtelier(vec[preferintaAngajat], masina, timeUnix, false, false, bacsis);

                sendSuccess("Masina a fost adaugata cu succes la angajatul cu ID-ul " + i);
                salveazaAngajatiToJson(vec, nrAngajati);
                return 1;
            }
            else {
                incercariAngajati++;
            }
        }

        if(incercariAngajati == nrAngajati - 1) {
            clearChat();
            sendError("Niciun angajat nu are locuri disponibile pentru masina de tipul ales!");
            sendInfo("Doresti sa ramai in lista de asteptare pentru angajatii disponibili?");
            sendInfo("Y - Da \t|\t N - Nu");
            char dorinta;
            do {
                cin >> dorinta;
                if(dorinta == 'Y' || dorinta == 'y') {
                    for(unsigned int i = 0; i < nrAngajati; i++) {
                        for(typeMasini tip = tipSTANDARD; i <= tipCAMION; i = typeMasini(i + 1)) {
                            if(getLocLiber(vec, i, tip) != vectorNULL) {
                                preferintaAngajat = i;
                                break;
                            }
                        }
                    }
                    
                    intrareInAtelier(vec[preferintaAngajat], masina, 0, false, true, 0);
                    sendInfo("Ti-am cautat cel mai liber angajat, acesta va lua masina in curand!");
                    salveazaAngajatiToJson(vec, nrAngajati);
                    return 1;
                }
                else if(dorinta == 'N' || dorinta == 'n') {
                    sendInfo("Nu s-a adaugat nicio masina!");
                    return 0;
                }
                else {
                    sendError("Optiunea aleasa nu este corecta!");
                }
            } while(dorinta != 'Y' && dorinta != 'y' && dorinta != 'N' && dorinta != 'n');
        }
    }
    return 0;
}