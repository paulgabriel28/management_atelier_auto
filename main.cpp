#include "main.h"

int main() {
    // MARK: Start
    // NOTE: Securitate pe PIN [8 cifre] [criptat (sistemul din 2021)]

    sendSuccess("Programul a pornit cu succes!");

    // NOTE: Sistem PIN [2021]
    string pin;
    citesteValoare("Introduceti PIN-ul");

    do {
        cin >> pin;
        if(pin != "exit") {
            if (login(pin) == 1) {
                sendSuccess("PIN-ul este corect!");
                Meniu(MENIU_PRINCIPAL);
            } else {
                sendError("PIN-ul este incorect!");
            }
        sendInfo("Daca doresti sa iesi din program, tasteaza exit");
        citesteValoare("Introduceti PIN-ul / [sau exit]");
        }
    } while (pin != "exit");
    
    sendSuccess("Programul a fost inchis cu succes!");
    return 0;
}