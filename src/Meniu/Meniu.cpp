#include "../../include/Meniu/Meniu.h"

void sendMeniuOption(const unsigned int &option, const string &message) {
    cout << "\033[38;2;0;0;255m" << option << "\t-\t\033[0m" << message << endl;
}

void meniuPrincipal() {
    clearChat();
    sendInfo("Meniu principal");
    cout << "1\t-\tAtelier\n";
    cout << "2\t-\tAdmin\n";
    cout << "0\t-\tInchide Program\n";
    sendQuestion("Alege optiunea dorita!");
}

void meniuAdminAngajati() {
    clearChat();
    sendInfo("Meniu angajati");
    sendMeniuOption(1, "Adauga angajat");
    sendMeniuOption(2, "Sterge angajat [ID]");
    sendMeniuOption(3, "Editare angajat [ID]");
    sendMeniuOption(4, "Afisare angajat");
    sendMeniuOption(5, "Afisare toti angajatii");
    sendMeniuOption(0, "Inapoi");
    sendQuestion("Alege optiunea dorita!");
}

void meniuAdminMasini() {
    clearChat();
    sendInfo("Meniu masini");
    sendMeniuOption(1, "Adauga masina");
    sendMeniuOption(2, "Sterge masina [ID]");
    sendMeniuOption(3, "Editare masina [ID]");
    sendMeniuOption(4, "Afisare masina");
    sendMeniuOption(5, "Afisare toate masinile");
    sendMeniuOption(0, "Inapoi");
    sendQuestion("Alege optiunea dorita!");
}

void meniuSetari() {
    clearChat();

}

void meniuAdmin() {
    clearChat();
    sendInfo("Meniu admin");
    sendMeniuOption(1, "Angajati");
    sendMeniuOption(2, "Masini");
    sendMeniuOption(3, "Setari");
    sendMeniuOption(0, "Inapoi");
    sendQuestion("Alege optiunea dorita!");
}

void meniuAtelier() {
    clearChat();

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
    } else if(meniu == MENIU_ADMIN_MASINI) {
        if(option <= 5) {
            return true;
        }
    } else if(meniu == MENIU_SETARI) {
        if(option <= 3) {
            return true;
        }
    } else if(meniu == MENIU_ADMIN) {
        if(option <= 3) {
            return true;
        }
    }
    return false;
}

void Meniu(const MeniuOptions &meniu) {
    switch (meniu)
    {
        case MENIU_NULL: {
            
            break;
        }
        case MENIU_PRINCIPAL: {
            unsigned int option;
            do {
                meniuPrincipal();
                cout << "\tOptiune:"; cin >> option;

                if(correctOption(option, MENIU_PRINCIPAL)) {
                    switch (option)
                    {
                        case 1: {
                            meniuAtelier();
                            Meniu(MENIU_ATELIER);
                            break;
                        }

                        case 2: {
                            meniuAdmin();
                            Meniu(MENIU_ADMIN);
                            break;
                        }

                        case 0: {
                            // TODO: Inchide program
                            break;
                        }

                        default:
                            break;
                    }
                } else {
                    sendError("Optiunea aleasa nu este corecta!");
                }
            } while (!correctOption(option, MENIU_PRINCIPAL));
            break;
        }

        case MENIU_ADMIN_ANGAJATI: {
            unsigned int option;
            do {
                meniuAdminAngajati();
                cout << "\tOptiune:"; cin >> option;

                if(correctOption(option, MENIU_ADMIN_ANGAJATI)) {
                    switch (option)
                    {
                        case 1: {
                            Angajat **vec = nullptr;
                            unsigned int dim = 0;
                            citesteAngajatiJSON(vec, dim);
                            break;
                        }

                        case 2: {
                            break;
                        }

                        case 3: {
                            break;
                        }

                        case 4: {
                            break;
                        }

                        case 5: {
                            break;
                        }

                        case 0: {
                            break;
                        }

                        default:
                            break;
                    }
                } else {
                    sendError("Optiunea aleasa nu este corecta!");
                }
            } while (!correctOption(option, MENIU_ADMIN_ANGAJATI));
            break;
        }

        default:
            break;
    }
}