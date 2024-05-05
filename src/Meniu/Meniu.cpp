#include "../../include/Meniu/Meniu.h"

void sendMeniuOption(const unsigned int &option, const string &message) {
    cout << "\033[38;2;0;0;255m" << option << "\t-\t\033[0m" << message << endl;
}

void meniuPrincipal() {
    sendInfo("Meniu principal");
    sendMeniuOption(1, "Atelier");
    sendMeniuOption(2, "Admin");
    sendMeniuOption(0, "Inchide Program");
    sendQuestion("Alege optiunea dorita!");
}

void meniuAdmin() {
    sendInfo("Meniu admin");
    sendMeniuOption(1, "Angajati");
    sendMeniuOption(2, "Setari");
    sendMeniuOption(0, "Inapoi - Meniu principal");
    sendQuestion("Alege optiunea dorita!");
}

void meniuAdminAngajati() {
    sendInfo("Meniu angajati [ admin ]");
    sendMeniuOption(1, "Adauga angajat");
    sendMeniuOption(2, "Sterge angajat [ID]");
    sendMeniuOption(3, "Editare angajat [ID]");
    sendMeniuOption(4, "Afisare angajat [ID]");
    sendMeniuOption(5, "Afisare toti angajatii");
    sendMeniuOption(0, "Inapoi - Meniu admin");
    sendQuestion("Alege optiunea dorita!");
}

void meniuSetari() {
    sendMeniuOption(1, "Schimba parola");
    sendMeniuOption(2, "Sterge baza de date");
    sendMeniuOption(0, "Inapoi - Meniu admin");
    sendQuestion("Alege optiunea dorita!");
}


void meniuAtelier() {
    sendInfo("Meniu atelier");
    sendMeniuOption(1, "Adauga masina in atelier");
    sendMeniuOption(2, "Vezi angajatul cu cele mai multe comenzi intr-o zi");
    sendMeniuOption(3, "Top 3 angajati cu cea mai mare valoare a politelor de asigurare");
    sendMeniuOption(4, "Top 3 angajati care au reparat cele mai multe autobuze noi");
    sendMeniuOption(5, "Top 3 cei mai solicitiati angajati");
    sendMeniuOption(6, "Bacsisul fiecarui angajat");
    sendMeniuOption(0, "Inapoi - Meniu principal");
    sendQuestion("Alege optiunea dorita!");
}

bool correctOption(const unsigned int &option, const MeniuOptions &meniu) {
    if (meniu == MENIU_PRINCIPAL) {
        if(option <= 2) {
            return true;
        }
    } else if(meniu == MENIU_ADMIN_ANGAJATI) {
        if(option <= 5) {
            return true;
        }
    } else if(meniu == MENIU_SETARI) {
        if(option <= 3) {
            return true;
        }
    } else if(meniu == MENIU_ADMIN) {
        if(option <= 2) {
            return true;
        }
    } else if(meniu == MENIU_ATELIER) {
        if(option <= 6) {
            return true;
        }
    }
    return false;
}

void Meniu(const MeniuOptions &meniu) {
    clearChat();
    switch (meniu)
    {
        case MENIU_NULL: {
            return;
        }

        case INCHIDE_MENIU: {
            clearChat();
            sendInfo("Ai iesit din meniu!");
            return;
        }

        case NOUA_OPTIUNE: {
            sendInfo("Actiunea a fost efectuata cu succes!");
            sendInfo("Doresti sa faci o noua actiune?");
            sendQuestion("1 - Da \t|\t 0 - Nu");
            unsigned int option = -1;
            do {
                cin >> option;
                if(option != 0 && option != 1) {
                    sendError("Optiunea aleasa nu este corecta!");
                    sendQuestion("1 - Da \t|\t 0 - Nu");
                }
            } while(option != 0 && option != 1);

            if(option == 1) {
                Meniu(MENIU_PRINCIPAL);
            } 
            else if(option == 0) {
                Meniu(INCHIDE_MENIU);
            }

            break;
        }

        case MENIU_PRINCIPAL: {
            unsigned int option;
            do {
                meniuPrincipal();
                citesteValoare("Optiune"); 
                cin >> option;

                if(correctOption(option, MENIU_PRINCIPAL)) {
                    switch (option)
                    {
                        case 1: {
                            Meniu(MENIU_ATELIER);
                            break;
                        }

                        case 2: {
                            Meniu(MENIU_ADMIN);
                            break;
                        }

                        case 0: {
                            clearChat();
                            sendInfo("Programul se inchide...");
                            break;
                        }

                        default:
                            break;
                    }
                } else {
                    clearChat();
                    sendError("Optiunea aleasa nu este corecta!");
                }
            } while (!correctOption(option, MENIU_PRINCIPAL));
            break;
        }

        case MENIU_ADMIN: {
            unsigned int option;
            do {
                meniuAdmin();
                citesteValoare("Optiune"); 
                cin >> option;

                if(correctOption(option, MENIU_ADMIN)) {
                    switch (option)
                    {
                        case 1: {
                            Meniu(MENIU_ADMIN_ANGAJATI);
                            break;
                        }

                        case 2: {
                            Meniu(MENIU_SETARI);
                            break;
                        }

                        case 0: {
                            Meniu(MENIU_PRINCIPAL);
                            break;
                        }

                        default:
                            break;
                    }
                } else {
                    clearChat();
                    sendError("Optiunea aleasa nu este corecta!");
                }
            } while (!correctOption(option, MENIU_ADMIN));

            break;
        }

        case MENIU_ADMIN_ANGAJATI: {
            unsigned int option;
            do {
                meniuAdminAngajati();
                citesteValoare("Optiune"); 
                cin >> option;

                if(correctOption(option, MENIU_ADMIN_ANGAJATI)) {
                    Angajat **vec = nullptr;
                    unsigned int dim = 0;
                    citesteAngajatiJSON(vec, dim);

                    switch (option)
                    {
                        case 1: {
                            adaugareAngajat(vec, dim);
                            salveazaAngajatiToJson(vec, dim);
                            Meniu(NOUA_OPTIUNE);
                            break;
                        }

                        case 2: {
                            stergereAngajat(vec, dim);
                            salveazaAngajatiToJson(vec, dim);
                            Meniu(NOUA_OPTIUNE);

                            break;
                        }

                        case 3: {                            
                            unsigned int id;
                            sendInfo("Introdu ID-ul angajatului pe care vrei sa il editezi:");
                            for(unsigned int i = 0; i < dim; i++) {
                                cout << "\t" << vec[i]->getIdAngajat() << " -> " << vec[i]->getNume() << " " << vec[i]->getPrenume() << endl;
                            }
                            cout << "\tID: "; cin >> id;
                            vec[id]->editAngajat();

                            salveazaAngajatiToJson(vec, dim);

                            Meniu(NOUA_OPTIUNE);
                            break;
                        }

                        case 4: {
                            unsigned int id;
                            sendInfo("Introdu ID-ul angajatului pe care vrei sa il afisezi:");
                            cout << "\tID:"; cin >> id;
                            vec[id]->afisareAngajat();

                            Meniu(NOUA_OPTIUNE);
                            break;
                        }

                        case 5: {                            
                            if(dim == 0) {
                                sendError("Nu exista angajati in baza de date!");
                                break;
                            }

                            for(unsigned int i = 0; i < dim; i++) {
                                vec[i]->afisareAngajat();
                            }
                            break;

                            Meniu(NOUA_OPTIUNE);
                        }

                        case 0: {
                            Meniu(MENIU_ADMIN);
                            break;
                        }

                        default:
                            break;
                    }
                
                elibereazaMemorie(vec, dim);
                } else {
                    clearChat();
                    sendError("Optiunea aleasa nu este corecta!");
                }
            } while (!correctOption(option, MENIU_ADMIN_ANGAJATI));
            break;
        }

        case MENIU_ATELIER: {
            unsigned int option;
            do {
                clearChat();
                meniuAtelier();
                citesteValoare("Optiune");
                cin >> option;

                switch (option)
                {
                    case 1: {
                        nouaMasinaInAtelier();
                        Meniu(NOUA_OPTIUNE);
                        break;
                    }

                    case 0: {
                        Meniu(MENIU_PRINCIPAL);
                        break;
                    }
                    
                    default:
                        break;
                }
            } while(!correctOption(option, MENIU_ATELIER));
        }

        default:
            break;
    }
}