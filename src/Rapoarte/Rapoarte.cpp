#include "../../include/Rapoarte/Rapoarte.h"

bool unixInDateString(const long long &unix, const string *data) {
    time_t unixTime = unix;
    struct tm *time = localtime(&unixTime);

    if(time->tm_mday == stoi(data[ZIUA]) && time->tm_mon == stoi(data[LUNA]) - 1 && time->tm_year + 1900 == stoi(data[AN])) {
        return true;
    }

    return false;
}

void comenxiMaxZi(const string *data) {
    json intrariAtelier = citesteIntrariAtelier();

    Angajat **angajati = nullptr;
    unsigned int dim = 0;
    citesteAngajatiJSON(angajati, dim);
    
    if(intrariAtelier.empty()) {
        sendError("Nu exista intrari in atelier.");
        return;
    }

    struct {
        unsigned int nrComenzi = 0;
        unsigned int nrComenziAsteptare = 0;
    } vecAngajati[dim];

    for(size_t i = 0; i < intrariAtelier.size(); i++) {
        if(unixInDateString(intrariAtelier[i]["dataIntrareUnix"], data)) {
            if(intrariAtelier[i]["inAsteptare"]) {
                vecAngajati[(int)intrariAtelier[i]["idAngajat"]].nrComenziAsteptare++;
                cout <<"barosan\n";
            } else {
                vecAngajati[(int)intrariAtelier[i]["idAngajat"]].nrComenzi++;
            }            
        }
    }

    int pozMax = 0;

    for(unsigned int i = 0; i < dim; i++) {
        if(vecAngajati[i].nrComenzi == 0) {
            continue;
        }

        if(vecAngajati[i].nrComenzi > vecAngajati[pozMax].nrComenzi) {
            pozMax = i;
        }
        else if(vecAngajati[i].nrComenzi == vecAngajati[pozMax].nrComenzi) {
            if(vecAngajati[i].nrComenziAsteptare > vecAngajati[pozMax].nrComenziAsteptare) {
                pozMax = i;
            }
        }
    }

    if(vecAngajati[pozMax].nrComenzi == 0) {
        sendError("Nu exista comenzi in aceasta zi.");
        return;
    }

    sendInfo("Angajatul cu cele mai multe comenzi in ziua respectiva este:");
    angajati[pozMax]->afisareAngajat();
    delete [] angajati;
}

void top3maxPolita() {
    json intrariAtelier = citesteIntrariAtelier();

    struct {
        unsigned int poz = 0;
        unsigned int sumaPolitaMax = 0;
    } vecAngajati[3]; // 0 - max, 1 - 2nd max, 2 - 3rd max

    for(size_t i = 0; i < intrariAtelier.size(); i++) {
        if(intrariAtelier[i]["inAsteptare"]) {
            continue;
        }
        
        double numarKm = intrariAtelier[i]["masina"]["numarKm"];
        unsigned int anFabricare = intrariAtelier[i]["masina"]["anFabricare"];
        bool isDisel = intrariAtelier[i]["masina"]["isDisel"];
        unsigned int idAngajat = intrariAtelier[i]["idAngajat"];
        typeMasini tip = stringToTypeMasina(intrariAtelier[i]["masina"]["tip"]);

        Masina *masina = nullptr;
        switch(tip) {
            case tipSTANDARD: {
                masina = new Standard(numarKm, anFabricare, isDisel, idAngajat, (intrariAtelier[i]["masina"]["transmisie"] == 0 ? MANUAL : AUTOMAT));
                break;
            }

            case tipAUTOBUZ: {
                masina = new Autobuz(numarKm, anFabricare, isDisel, idAngajat, intrariAtelier[i]["masina"]["nrLocuri"]);
                break;
            }

            case tipCAMION: {
                masina = new Camion(numarKm, anFabricare, isDisel, idAngajat, intrariAtelier[i]["masina"]["tonaj"]);
                break;
            }

            default: {
                break;
            }
        }
    
        if(masina->getPolita() > vecAngajati[0].sumaPolitaMax) {
            vecAngajati[2] = vecAngajati[1];
            vecAngajati[1] = vecAngajati[0];

            vecAngajati[0].sumaPolitaMax = masina->getPolita();
            vecAngajati[0].poz = idAngajat;
        } else if(masina->getPolita() > vecAngajati[1].sumaPolitaMax) {
            vecAngajati[2] = vecAngajati[1];

            vecAngajati[1].sumaPolitaMax = masina->getPolita();
            vecAngajati[1].poz = idAngajat;
        } else if(masina->getPolita() > vecAngajati[2].sumaPolitaMax) {
            vecAngajati[2].sumaPolitaMax = masina->getPolita();
            vecAngajati[2].poz = idAngajat;
        }
    }

    Angajat **angajati = nullptr;
    unsigned int dim = 0;
    citesteAngajatiJSON(angajati, dim);

    sendInfo("Top 3 angajati cu cea mai mare valoare a politelor de asigurare:");
    if(vecAngajati[0].sumaPolitaMax == 0) {
        sendError("Nu exista angajati cu polita de asigurare.");
        return;
    }
    for(unsigned int i = 0; i < 3; i++) {
        sendInfo("Locul " + to_string(i + 1) + ": [ID: " + to_string(vecAngajati[i].poz) + "] - " + angajati[vecAngajati[i].poz]->getNume() + " " + angajati[vecAngajati[i].poz]->getPrenume());
    }

    delete [] angajati;
}

bool isVechi5Ani(const unsigned int &anFabricare) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    if(ltm->tm_year - anFabricare > 5) {
        return true;
    }

    return false;
}

void top3maxAutobuze() {
    json intrariAtelier = citesteIntrariAtelier();

    Angajat **angajati = nullptr;
    unsigned int dim = 0;
    citesteAngajatiJSON(angajati, dim);

    struct {
        unsigned int nrAutobuze = 0;
    } vecAngajati[dim];

    for(size_t i = 0; i < intrariAtelier.size(); i++) {
        if(intrariAtelier[i]["inAsteptare"]) {
            continue;
        }

        if(intrariAtelier[i]["masina"]["tip"] != "Autobuz") {
            continue;
        }

        unsigned int idAngajat = intrariAtelier[i]["idAngajat"];
        if(!isVechi5Ani(intrariAtelier[i]["masina"]["anFabricare"])) {
            continue;
        }
        vecAngajati[idAngajat].nrAutobuze++;
    }

    int pozMax[3] = {0};
    for(unsigned int i = 0; i < dim; i++) {
        if(vecAngajati[i].nrAutobuze == 0) {
            continue;
        }

        if(vecAngajati[i].nrAutobuze > vecAngajati[pozMax[0]].nrAutobuze) {
            pozMax[2] = pozMax[1];
            pozMax[1] = pozMax[0];
            pozMax[0] = i;
        } else if(vecAngajati[i].nrAutobuze > vecAngajati[pozMax[1]].nrAutobuze) {
            pozMax[2] = pozMax[1];
            pozMax[1] = i;
        } else if(vecAngajati[i].nrAutobuze > vecAngajati[pozMax[2]].nrAutobuze) {
            pozMax[2] = i;
        }
    }

    if(vecAngajati[pozMax[0]].nrAutobuze == 0) {
        sendError("Nu exista date care sa corespunda cerintelor.");
        delete [] angajati;
        return;
    }
    for(unsigned int i = 0; i < 3; i++) {
        sendInfo("Locul " + to_string(i + 1) + ": [ID: " + to_string(pozMax[i]) + "]" + angajati[pozMax[i]]->getNume() + " " + angajati[pozMax[i]]->getPrenume());
    }

    delete [] angajati;
}

void top3CereriSpeciale() {
    json json = citesteIntrariAtelier();

    Angajat **angajati = nullptr;
    unsigned int dim = 0;
    citesteAngajatiJSON(angajati, dim);

    unsigned int vecAngajati[dim] = {0};

    for(size_t i = 0; i < json.size(); i++) {
        if(json[i]["cerereSpeciala"]) {
            vecAngajati[(int)json[i]["idAngajat"]]++;
        }
    }

    int pozMax[3] = {0};
    for(unsigned int i = 0; i < dim; i++) {
        if(vecAngajati[i] == 0) {
            continue;
        }

        if(vecAngajati[i] > vecAngajati[pozMax[0]]) {
            pozMax[2] = pozMax[1];
            pozMax[1] = pozMax[0];
            pozMax[0] = i;
        } else if(vecAngajati[i] > vecAngajati[pozMax[1]]) {
            pozMax[2] = pozMax[1];
            pozMax[1] = i;
        } else if(vecAngajati[i] > vecAngajati[pozMax[2]]) {
            pozMax[2] = i;
        }
    }

    sendInfo("Top 3 angajati care au cele mai multe cereri speciale:");
    
    if(vecAngajati[pozMax[0]] == 0) {
        sendError("Nu exista date care sa corespunda cerintelor.");
        delete [] angajati;
        return;
    }
    for(unsigned int i = 0; i < 3; i++) {
        if(vecAngajati[pozMax[i]] == 0) {
            continue;
        }
        sendInfo("Locul " + to_string(i + 1) + ": [ID: " + to_string(pozMax[i]) + "] " + angajati[pozMax[i]]->getNume() + " " + angajati[pozMax[i]]->getPrenume());
    }
}

void afisareBacsis() {
    json intrariAtelier = citesteIntrariAtelier();

    Angajat **angajati = nullptr;
    unsigned int dim = 0;
    citesteAngajatiJSON(angajati, dim);

    struct {
        unsigned int idAngajat;
        double bacsis = 0;
    } vecAngajati[dim];

    bool exist = false;

    for(size_t i = 0; i < intrariAtelier.size(); i++) {
        if(intrariAtelier[i]["inAsteptare"]) {
            continue;
        }

        double numarKm = intrariAtelier[i]["masina"]["numarKm"];
        unsigned int anFabricare = intrariAtelier[i]["masina"]["anFabricare"];
        bool isDisel = intrariAtelier[i]["masina"]["isDisel"];
        unsigned int idAngajat = intrariAtelier[i]["idAngajat"];
        typeMasini tip = stringToTypeMasina(intrariAtelier[i]["masina"]["tip"]);

        Masina *masina = nullptr;
        switch(tip) {
            case tipSTANDARD: {
                masina = new Standard(numarKm, anFabricare, isDisel, idAngajat, (intrariAtelier[i]["masina"]["transmisie"] == false ? MANUAL : AUTOMAT));
                break;
            }

            case tipAUTOBUZ: {
                masina = new Autobuz(numarKm, anFabricare, isDisel, idAngajat, intrariAtelier[i]["masina"]["nrLocuri"]);
                break;
            }

            case tipCAMION: {
                masina = new Camion(numarKm, anFabricare, isDisel, idAngajat, intrariAtelier[i]["masina"]["tonaj"]);
                break;
            }

            default: {
                break;
            }
        }
    
        double bacsis = masina->getPolita() * 0.01;
        vecAngajati[idAngajat].bacsis += bacsis;
        exist = true;
    }

    if(exist == false) {
        sendError("Nu exista bacsisuri de afisat.");
    }
    else {
        for(unsigned int i = 0; i < dim; i++) {
            if(vecAngajati[i].bacsis == 0) {
                continue;
            }
            sendInfo("Angajatul " + angajati[i]->getNume() + " " + angajati[i]->getPrenume() + " are un bacsis de " + to_string(vecAngajati[i].bacsis) + " lei.");
        }

        delete [] angajati;
    }
}