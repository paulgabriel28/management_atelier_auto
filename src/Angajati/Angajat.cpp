#include "../../include/Angajati/Angajat.h"
#include "../../include/utile/functions.h"
#include "../../include/utile/utileAngajati.h"
#include "../../include/enum.h"

#include "../../include/Angajati/Director.h"
#include "../../include/Angajati/Mecanic.h"
#include "../../include/Angajati/Asistent.h"

unsigned int Angajat::ID = 0;

// MARK: - Constructori
Angajat::Angajat() {
    idAngajat = ID++;
    nume = "";
    prenume = "";
    coeficientSalariu = 0;
    for (int i = 0; i < 3; i++) {
        dataNastere[i] = "";
        dataAngajare[i] = "";
    }
    for (int i = 0; i < 5; i++) {
        unixOcupat[i] = 0;
    }
    masiniInAsteptare = nullptr;
    nrMasiniInAsteptare = 0;
}

Angajat::Angajat(const string &nume, const string &prenume, const string *dataNastere, const string *dataAngajare, const long long *unixOcupat) {
    idAngajat = ID++;
    this->nume = nume;
    this->prenume = prenume;
    for (int i = 0; i < 3; i++) {
        this->dataNastere[i] = dataNastere[i];
        this->dataAngajare[i] = dataAngajare[i];
    }
    for (int i = 0; i < 5; i++) {
        this->unixOcupat[i] = unixOcupat[i];
    }
    coeficientSalariu = 0;

    masiniInAsteptare = nullptr;
    nrMasiniInAsteptare = 0;
}

Angajat::Angajat(const Angajat &a) {
    masiniInAsteptare = nullptr;
    *this = a;
}

Angajat& Angajat::operator=(const Angajat &a) {
    if(this != &a) {
        idAngajat = a.idAngajat;
        nume = a.nume;
        prenume = a.prenume;
        for (int i = 0; i < 3; i++) {
            dataNastere[i] = a.dataNastere[i];
            dataAngajare[i] = a.dataAngajare[i];
        }
        for (int i = 0; i < 5; i++) {
            unixOcupat[i] = a.unixOcupat[i];
        }
        coeficientSalariu = a.coeficientSalariu;
        nrMasiniInAsteptare = a.nrMasiniInAsteptare;
        
        delete [] masiniInAsteptare;
        masiniInAsteptare = new masinaInAsteptare[nrMasiniInAsteptare];
        for (int i = 0; i < nrMasiniInAsteptare; i++) {
            masiniInAsteptare[i] = a.masiniInAsteptare[i];
        }
    }
    return *this;

}

// MARK: - Destructor
Angajat::~Angajat() {
    ID--;

    delete[] masiniInAsteptare;
    masiniInAsteptare = nullptr;
    nrMasiniInAsteptare = 0;
}

unsigned int Angajat::getID() {
    return ID;
}

void Angajat::setAllID(const unsigned int &id) {
    ID = id;
}

unsigned int Angajat::getIdAngajat() const {
    return idAngajat;
}

// MARK: - Afisare
void Angajat::afisareAngajat() const {
    sendAngajatID(this);
    cout << "Nume: " << nume << " | ";
    cout << "Prenume: " << prenume << endl;
    cout << "Data Nastere: " << dataNastere[0] << "/" << dataNastere[1] << "/" << dataNastere[2] << endl;
    cout << "Data Angajare: " << dataAngajare[0] << "/" << dataAngajare[1] << "/" << dataAngajare[2] << endl;
    cout << "Locuri in atelier: " << endl;
    cout << "\tMasini: ";
    for (int i = 0; i < 3; i++) {
        cout << ((unixOcupat[i] != 0) ? to_string(unixOcupat[i]) : "liber") << ((i == 2) ? " " : " | ");
    }
    cout << endl;
    cout << "\tAutobuz: " << ((unixOcupat[3] != 0) ? to_string(unixOcupat[3]) : "liber") << endl;
    cout << "\tCamion: " << ((unixOcupat[4] != 0) ? to_string(unixOcupat[4]) : "liber") << endl;
}

// MARK: - Getters
string Angajat::getNume() {
    return nume;
}

string Angajat::getPrenume() {
    return prenume;
}

string *Angajat::getDataAngajare() {
    return dataAngajare;
}

string *Angajat::getDataNastere() {
    return dataNastere;
}

void Angajat::editAngajat()
{
    unsigned int modify = 0;

    do
    {
        sendInfo("Urmeaza sa il modifici pe user-ul: ");
        afisareAngajat();

        sendInfo("Ce doresti sa modifici?");
        sendInfo("Parametrii pentru modificare: nume, prenume, data_nastere, data_angajare: ");
        string type;
        cin >> type;
        atributeAngajati typeParam = angajatiGetParametru(type);

        switch (typeParam)
        {
            case NUME:
            {
                sendSeparator();
                citesteValoare("Numele nou");
                string newNume;
                do
                {
                    cin >> newNume;
                    if (newNume.empty())
                    {
                        sendError("Numele introdus nu este valid, introdu un nou nume: ");
                        citesteValoare("Introdu numele");
                    }
                } while (newNume.empty());
                nume = newNume;
                sendSuccess("Numele a fost setat cu succes!");
                break;
            }

            case PRENUME:
            {
                sendSeparator();
                citesteValoare("Prenumele nou");
                string newPrenuem;
                do
                {
                    cin >> newPrenuem;
                    if (newPrenuem.empty())
                    {
                        sendError("Prenumele introdus nu este valid, introdu un nou prenume: ");
                        cout << "- Introdu prenumele: ";
                    }
                } while (newPrenuem.empty());
                prenume = newPrenuem;
                sendSuccess("Prenumele a fost setat cu succes!");
                break;
            }

            case dataNASTERE:
            {
                sendSeparator();
                citesteValoare("Introdu data [ format: zi luna an (ex: 28 07 2004)]");
                string newData[3];
                do
                {
                    for (int i = 0; i < 3; i++)
                    {
                        cin >> newData[i];

                        if (newData[i].empty())
                        {
                            sendError("Nu poti lasa acest parametru gol!");
                            i--;
                        }
                    }

                    if (!isMajor(newData))
                    {
                        sendError("Data este introdusa gresit, angajatul nu poate sa fie minor!");
                    }
                } while (newData[ZIUA].empty() && newData[LUNA].empty() && newData[AN].empty() && !isMajor(newData));

                for (int i = 0; i < 3; i++)
                {
                    dataNastere[i] = newData[i];
                }
                sendSuccess("Data de nastere a fost setata cu succes");
                break;
            }

            case dataANGAJARE:
            {
                sendSeparator();
                citesteValoare("Introdu data [ format: zi luna an (ex: 28 07 2004)]");
                string newData[3];
                do
                {
                    for (int i = 0; i < 3; i++)
                    {
                        cin >> newData[i];

                        if (newData[i].empty())
                        {
                            sendError("Nu poti lasa acest parametru gol!");
                            i--;
                        }
                    }

                    if (!isPresent(newData))
                    {
                        sendError("Data este introdusa gresit, data nu poate fi din viitor!");
                    }
                } while (newData[ZIUA].empty() && newData[LUNA].empty() && newData[AN].empty() && !isPresent(newData));

                for (int i = 0; i < 3; i++)
                {
                    dataAngajare[i] = newData[i];
                }
                sendSuccess("Data de angajare a fost setata cu succes");
                break;
            }

            default:
                break;
        }

        sendInfo("Doresti sa mai faci o modificare?\n Y - Da\tN - Nu\n");
        citesteValoare("Raspuns");
        char q;
        cin >> q;
        modify = (tolower(q) == 'y') ? 1 : 0;
    } while (modify);
}

double Angajat::getSalariu() const {
    return calculSalariu(double(stoi(dataAngajare[2])), coeficientSalariu);
}

// MARK: - Adaugare
void adaugareAngajat(Angajat **&vec, unsigned int &dim)
{
    bool done = 0;
    typeAngajat type;
    string typeString;
    
    sendInfo("Introdu tipul angajatului:\n\t Director \t | \t Mecanic \t | \t Asistent");
    citesteValoare("Tipul dorit");
    do {
        cin >> typeString;
        type = stringToTypeAngajat(typeString);
        
        if(typeString != "cancel") {
            if(type != parametruNULLtype) {
                done = 1;
            }
            else {
                clearChat();
                sendError("Parametrul introdus nu este valid, parametrii disponibli sunt:\n\t Director \t | \t Mecanic \t | \t Asistent");
                sendInfo("Daca vrei sa anulezi modificarea, introdu '-1'");
                citesteValoare("Tipul dorit");
            }
        }
        else if(typeString == "cancel") {
            done = 1;
            sendInfo("Ai anulat adaugarea unui angajat!");
        }

    } while(!done);

    if(typeString != "cancel") {
        Angajat **copyVec = new Angajat*[dim];
        for (unsigned int i = 0; i < dim; i++) {
            copyVec[i] = vec[i];
        }

        delete[] vec;
        vec = nullptr;
        dim++;

        vec = new Angajat *[dim];
        for (unsigned int i = 0; i < dim - 1; i++) {
            vec[i] = copyVec[i];
        }
        
        string nume, prenume, dataNastere[3], dataAngajare[3];
        citesteAngajat(nume, prenume, dataNastere, dataAngajare);

        long long unixOcupat[5] = {0};

        switch (type) { 
            case DIRECTOR: {
                vec[dim - 1] = new Director(nume, prenume, dataNastere, dataAngajare, unixOcupat);
                break;
            }

            case MECANIC: {
                vec[dim - 1] = new Mecanic(nume, prenume, dataNastere, dataAngajare, unixOcupat);
                break;
            }

            case ASISTENT: {
                vec[dim - 1] = new Asistent(nume, prenume, dataNastere, dataAngajare, unixOcupat);
                break;
            }

            default:
                break;
        }

        sortVectorAngajatiByID(vec, dim);
        sendSuccess("Angajatul a fost adaugat cu succes: ");
        vec[dim - 1]->afisareAngajat();
    }
}

void stergereAngajat(Angajat **&vec, unsigned int &dim) {

    sendInfo("Introdu ID-ul angajatului pe care doresti sa il stergi!");
    bool exista = 0;
    string deleteID;

    do {
        citesteValoare("ID");
        cin >> deleteID;
        
        if(deleteID != "cancel") {
            for(unsigned int i = 0; i < dim; i++) {
                if(vec[i]->getIdAngajat() == (unsigned int)stoi(deleteID)) {
                    exista = 1;
                }
            }
        } 
        else if(deleteID == "cancel") {
            exista = 1;
        }

        if(!exista) {
            sendError("ID-ul introdus nu exista in lista cu angajati, introdu un nou ID!");
            sendInfo("Daca doresti sa anulezi modificarea, scrie 'cancel'!");
        }

    } while(!exista);


    if(deleteID == "cancel") {
        sendInfo("Ai anulat stergerea unui membru!");
    }
    else {
        Angajat **copyVec = new Angajat*[dim];
        copyVectorAngajat(copyVec, vec, dim);
        
        delete [] vec;
        vec = nullptr;

        vec = new Angajat*[dim - 1];
        int j = 0;
        for(unsigned int i = 0; i < dim; i++) {
            if(copyVec[i]->getIdAngajat() != (unsigned int)stoi(deleteID)) {
                vec[j++] = copyVec[i];
            }
        }
        
        dim --;
        Angajat::ID--;
        sendSuccess("Angajatul a fost sters cu succes!");
    }
}

// MARK: UnixLocuri
void Angajat::setUnixIntrariAtelier(const unsigned int &poz, const int &val) {
    unixOcupat[poz] = val;
}

auto Angajat::getUnixIntrariAtelier(const unsigned int &poz) const -> long long{
    return unixOcupat[poz];
}