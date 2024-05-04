#include "../../include/data/files.h"

void citesteAngajatiJSON(Angajat **&vec, unsigned int &dim) {
    fstream file("data/Angajati.json", ios::in);

    if (!file.is_open()) {
        sendError("Nu s-a putut deschide fisierul JSON pentru citire.");
        return;
    }

    json json;
    file >> json;

    dim = json.size();
    vec = new Angajat*[dim];

    // NOTE: Seteaza ID-ul la 0
    Angajat::setAllID(0);

    unsigned int index = 0;
    for(auto it = json.begin(); it != json.end(); it++) {
        typeAngajat type = stringToTypeAngajat((*it)["type"]);
        
        string nume = (*it)["nume"];
        string prenume = (*it)["prenume"];
        string dataNastere[3] = {(*it)["dataNastere"]["zi"], (*it)["dataNastere"]["luna"], (*it)["dataNastere"]["an"]};
        string dataAngajare[3] = {(*it)["dataAngajare"]["zi"], (*it)["dataAngajare"]["luna"], (*it)["dataAngajare"]["an"]};
        long long unixOcupat[5] = {(*it)["unixOcupat"]["masini"]["1"], (*it)["unixOcupat"]["masini"]["2"], (*it)["unixOcupat"]["masini"]["3"], (*it)["unixOcupat"]["autobuz"], (*it)["unixOcupat"]["camion"]};

        switch (type) {
            case DIRECTOR: {
                vec[index] = new Director(nume, prenume, dataNastere, dataAngajare, unixOcupat);
                break;
            }

            case MECANIC: {
                vec[index] = new Mecanic(nume, prenume, dataNastere, dataAngajare, unixOcupat);
                break;
            }

            case ASISTENT: {
                vec[index] = new Asistent(nume, prenume, dataNastere, dataAngajare, unixOcupat);
                break;
            }
            
            default:
                break;
        }

        index++;
    }

    file.close();
}

void salveazaAngajatiToJson(Angajat **&vec, unsigned int &dim) {
    json json;

    for(unsigned int i = 0; i < dim; i++) {
        json[to_string(i)]["type"] = getTypeAngajat(vec[i]);
        json[to_string(i)]["id"] = vec[i]->getIdAngajat();
        
        json[to_string(i)]["nume"] = vec[i]->getNume();
        json[to_string(i)]["prenume"] = vec[i]->getPrenume();
        
        json[to_string(i)]["dataNastere"]["zi"] = vec[i]->getDataNastere()[0];
        json[to_string(i)]["dataNastere"]["luna"] = vec[i]->getDataNastere()[1];
        json[to_string(i)]["dataNastere"]["an"] = vec[i]->getDataNastere()[2];
        
        json[to_string(i)]["dataAngajare"]["zi"] = vec[i]->getDataAngajare()[0];
        json[to_string(i)]["dataAngajare"]["luna"] = vec[i]->getDataAngajare()[1];
        json[to_string(i)]["dataAngajare"]["an"] = vec[i]->getDataAngajare()[2];

        json[to_string(i)]["unixOcupat"]["masini"]["1"] = vec[i]->getUnixIntrariAtelier(0);
        json[to_string(i)]["unixOcupat"]["masini"]["2"] = vec[i]->getUnixIntrariAtelier(1);
        json[to_string(i)]["unixOcupat"]["masini"]["3"] = vec[i]->getUnixIntrariAtelier(2);
        json[to_string(i)]["unixOcupat"]["autobuz"] = vec[i]->getUnixIntrariAtelier(3);
        json[to_string(i)]["unixOcupat"]["camion"] = vec[i]->getUnixIntrariAtelier(4);
    }

    fstream file("data/Angajati.json", ios::out);

    if (!file.is_open()) {
        sendError("Nu s-a putut deschide fisierul JSON pentru scriere.");
        return;
    }

    file << setw(4) << json << ::setfill(' ');

    file.close();
}