#include "../include/Angajati/Angajat.h"
#include "../include/utile/functions.h"
#include "../include/utile/utileAngajati.h"
#include "../include/enum.h"

#include <iostream>
using namespace std;

// MARK: - Constructori
Angajat::Angajat() {
    idAngajat = ID++;
    nume = "";
    prenume = "";
    coeficientSalariu = 0;
}

Angajat::Angajat(const string &nume, const string &prenume, const string *dataNastere, const string *dataAngajare) {
    idAngajat = ID++;
    this->nume = nume;
    this->prenume = prenume;
    for (int i = 0; i < 3; i++) {
        this->dataNastere[i] = dataNastere[i];
        this->dataAngajare[i] = dataAngajare[i];
    }
    coeficientSalariu = 0;
}

// MARK: - Destructor
Angajat::~Angajat() {
    ID--;
}

unsigned int Angajat::getID() {
    return ID;
}

unsigned int Angajat::getIdAngajat() const {
    return idAngajat;
}

// MARK: - Afisare
void Angajat::afisareAngajat() const {
    sendAngajatID(this);
    cout << "Nume: " << nume << endl;
    cout << "Prenume: " << prenume << endl;
    cout << "Data Nastere: " << dataNastere[0] << "/" << dataNastere[1] << "/" << dataNastere[2] << endl;
    cout << "Data Angajare: " << dataAngajare[0] << "/" << dataAngajare[1] << "/" << dataAngajare[2] << endl;
    cout << "Coeficient Salariu: " << coeficientSalariu << endl;
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
            sendQuestion("Care este numele nou?");
            cout << "- Introdu numele: ";
            string newNume;
            do
            {
                cin >> newNume;
                if (newNume.empty())
                {
                    sendError("Numele introdus nu este valid, introdu un nou nume: ");
                    cout << "- Introdu numele: ";
                }
            } while (!newNume.empty());
            nume = newNume;
            sendSuccess("Numele a fost setat cu succes!");
            break;
        }

        case PRENUME:
        {
            sendSeparator();
            sendQuestion("Care este prenumele nou?");
            cout << "- Introdu prenumele: ";
            string newPrenuem;
            do
            {
                cin >> newPrenuem;
                if (newPrenuem.empty())
                {
                    sendError("Prenumele introdus nu este valid, introdu un nou prenume: ");
                    cout << "- Introdu prenumele: ";
                }
            } while (!newPrenuem.empty());
            prenume = newPrenuem;
            sendSuccess("Prenumele a fost setat cu succes!");
            break;
        }

        case dataNASTERE:
        {
            sendSeparator();
            sendQuestion("Care este noua data de nastere?");
            cout << "- Introdu data [ format: zi luna an (ex: 28 07 2004)]: ";
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
            } while (!newData[ZIUA].empty() && !newData[LUNA].empty() && !newData[AN].empty() && !isMajor(newData));

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
            sendQuestion("Care este noua data de angajare?");
            cout << "- Introdu data [ format: zi luna an (ex: 28 07 2004)]: ";
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
            } while (!newData[ZIUA].empty() && !newData[LUNA].empty() && !newData[AN].empty() && !isPresent(newData));

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

        sendInfo("Doresti sa mai faci o modificare?\n Y - Da\tN - Nu\n-> Raspuns: ");
        char q;
        cin >> q;
        modify = (tolower(q) == 'y') ? 1 : 0;
    } while (modify);
}