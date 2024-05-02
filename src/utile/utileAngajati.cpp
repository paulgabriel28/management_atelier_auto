#include "../include/utile/utileAngajati.h"

using namespace std;

atributeAngajati angajatiGetParametru(const string &type) {
    string lowerType = type;
    transform(lowerType.begin(), lowerType.end(), lowerType.begin(), [](unsigned char c) { return tolower(c); });

    if (lowerType == "nume") return NUME;
    if (lowerType == "prenume") return PRENUME;
    if (lowerType == "datanastere") return dataNASTERE;
    if (lowerType == "dataangajare") return dataANGAJARE;
    return atributNULL;
}

typeAngajat stringToTypeAngajat(const string &type) {
    string lowerType = type;
    transform(lowerType.begin(), lowerType.end(), lowerType.begin(), [](unsigned char c) { return tolower(c); });

    if (lowerType == "director") return DIRECTOR;
    if (lowerType == "mecanic") return MECANIC;
    if (lowerType == "asistent") return ASISTENT;
    return ANGAJAT;
}

// MARK: isMajor
bool isMajor(const string *data) {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    int ziCurenta = now->tm_mday;
    int lunaCurenta = now->tm_mon + 1;
    int anCurent = now->tm_yday + 1900;

    int date[3];
    stringstream(data[ZIUA]) >> date[ZIUA];
    stringstream(data[LUNA]) >> date[LUNA];
    stringstream(data[AN]) >> date[AN];

    int varsta = max(anCurent - date[AN], 0);
    if(lunaCurenta < date[1] || (lunaCurenta == date[1] && ziCurenta < date[0])) {
        varsta--;
    }

    return varsta >= 18;
}

// MARK: isPresent
bool isPresent(const string *data) {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    int ziCurenta = now->tm_mday;
    int lunaCurenta = now->tm_mon + 1;
    int anCurent = now->tm_year + 1900;

    int date[3];
    stringstream(data[ZIUA]) >> date[ZIUA];
    stringstream(data[LUNA]) >> date[LUNA];
    stringstream(data[AN]) >> date[AN];

    if (date[AN] > anCurent) {
        return false;
    } else if (date[AN] == anCurent && date[LUNA] > lunaCurenta) {
        return false;
    } else if (date[AN] == anCurent && date[LUNA] == lunaCurenta && date[ZIUA] > ziCurenta) {
        return false;
    }

    return true;
}

void citesteAngajat(string &nume, string &prenume, string *dataNastere, string *dataAngajare) {
    sendSeparator();
    sendID();
    do {
        sendQuestion("-> Nume: ");
        cin >> nume;

        if(nume.size() > 30) {
            sendError("Numele este pera lung, introdu un nou nume!");
        }

    } while (nume.size() > 30);
    

    do {
        sendQuestion("-> Prenume: ");
        cin >> prenume;

        if(prenume.size() > 30) {
            sendError("Prenumele este prea lung, introdu din nou prenumele!");
        }

    } while(prenume.size() > 30);
    

    do {
        sendQuestion("-> Data de nastere [format: zz ll aa | ex: 28 07 2004]: ");
        for(int i = 0; i < 3; i++) {
            cin >> dataNastere[i];
        }

        if(!isMajor(dataNastere)) {
            sendError("Angajatul nu poate fi minor, introdu din nou data de nastere: ");
        }
    } while(!isMajor(dataNastere));

    do {
        for(int i = 0; i < 3; i++) {
            cin >> dataNastere[i];
        }
        cout << "-> Data de angajare [formt: zz ll aa | ]: ";

        if(!isPresent(dataNastere)) {
            sendError("Data de angajare nu poate fi din viitor, introdu din nou data de nastere");
        }
    } while(!isPresent(dataAngajare));
}
