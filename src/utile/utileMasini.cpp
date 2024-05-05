#include "../../include/utile/utileMasini.h"

typeMasini stringToTypeMasina(const string &type) {
    string lowerType = type;
    transform(lowerType.begin(), lowerType.end(), lowerType.begin(), [](unsigned char c) { return tolower(c); });

    if (lowerType == "masina") return tipMASINA;
    if (lowerType == "standard") return tipSTANDARD;
    if (lowerType == "autobuz") return tipAUTOBUZ;
    if (lowerType == "camion") return tipCAMION;
    return tipNULL;
}

Masina* citesteMasina() {
    Masina *masina = nullptr;
    sendSeparator();

    string tip;
    do {
        citesteValoare("Introdu tipul masinii: ");
        cin >> tip;
        if(stringToTypeMasina(tip) == tipNULL) {
            sendError("Tipul masinii introdus nu este corect!");
            sendInfo("Tipuri de masini dispinibile:\n\t standard \t|\t autobuz \t|\t camion");
        }
    } while(stringToTypeMasina(tip) == tipNULL);

    double numarKm;
    citesteValoare("Introdu numarul de kilometri: ");
    cin >> numarKm;

    unsigned int anFabricare;
    citesteValoare("Introdu anul de fabricare: ");
    cin >> anFabricare;

    bool isDisel;
    citesteValoare("Masina este diesel? (1 - da, 0 - nu): ");
    do {
        cin >> isDisel;
        if(isDisel != 0 && isDisel != 1) {
            sendError("Valoarea introdusa nu este corecta!");
            sendInfo("Masina este diesel? (1 - da, 0 - nu): ");
        }
    } while(isDisel != 0 && isDisel != 1);
    
    switch (stringToTypeMasina(tip))
    {
        case tipSTANDARD: {
            bool transmisie;
            citesteValoare("Masina are transmisie automata? (1 - da, 0 - nu): ");
            do {
                cin >> transmisie;
                if(transmisie != 0 && transmisie != 1) {
                    sendError("Valoarea introdusa nu este corecta!");
                    sendInfo("Masina are transmisie automata? (1 - da, 0 - nu): ");
                }
            } while(transmisie != 0 && transmisie != 1);
            masina = new Standard(numarKm, anFabricare, isDisel, (transmisie == 1 ? AUTOMAT : MANUAL));
            break;
        }
        
        case tipAUTOBUZ: {
            unsigned int numarLocuri = 0;
            citesteValoare("Introdu numarul de locuri: ");
            cin >> numarLocuri;
            masina = new Autobuz(numarKm, anFabricare, isDisel, numarLocuri);
            break;
        }

        case tipCAMION: {
            double tonaj = 0;
            citesteValoare("Introdu tonajul: ");
            cin >> tonaj;
            masina = new Camion(numarKm, anFabricare, isDisel, tonaj);
            break;
        }
        
        default:
            break;
    }
    
    return masina;
}

string getTypeMasina(const Masina* masina) {
    if (dynamic_cast<const Standard*>(masina)) {
        return "standard";
    } else if (dynamic_cast<const Autobuz*>(masina)) {
        return "autobuz";
    } else if (dynamic_cast<const Camion*>(masina)) {
        return "camion";
    } else if (dynamic_cast<const Masina*>(masina)) {
        return "masina";
    }
    return "necunoscut";
}