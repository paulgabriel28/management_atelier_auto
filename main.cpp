#include "main.h"

int main()
{
    cout << "Hello World!" << endl;
    string nume = "Popescu";
    string prenume = "Gabriel";
    string datanastere[3] = {"28", "07", "2004"};
    string dataangajare[3] = {"01", "01", "2024"};
    Angajat *a = new Director(nume, prenume, datanastere, dataangajare);
    clearChat();
    a->afisareAngajat();

    cin.get();
    return 0;
}