#include "../../include/data/files.h"

void citesteAngajatiJSON(Angajat **&vec, unsigned int &dim) {
    ifstream file("../../data/Angajati.json");

    nlohmann::json json;
    file >> json;

    dim = json.size();
    vec = new Angajat*[dim];

    // NOTE: Seteaza ID-ul la 0
    Angajat::setAllID(0);

    for(string i = "0"; i <= to_string(dim); i = to_string(stoi(i) + 1)) {
        typeAngajat type = stringToTypeAngajat(json[i]["type"]);
        
        string nume = json[i]["nume"];
        string prenume = json[i]["prenume"];
        string dataNastere[3] = {json[i]["dataNastere"]["zi"], json[i]["dataNastere"]["luna"], json[i]["dataNastere"]["an"]};
        string dataAngajare[3] = {json[i]["dataAngajare"]["zi"], json[i]["dataAngajare"]["luna"], json[i]["dataAngajare"]["an"]};
        long long unixOcupat[5] = {json[i]["unixOcupat"]["masini"]["1"], json[i]["unixOcupat"]["masini"]["2"], json[i]["unixOcupat"]["masini"]["3"], json[i]["unixOcupat"]["autobuz"], json[i]["unixOcupat"]["camion"]};

        switch (type)
        {
            case DIRECTOR: {
                vec[stoi(i)] = new Director(nume, prenume, dataNastere, dataAngajare, unixOcupat);
                break;
            }

            case MECANIC: {
                vec[stoi(i)] = new Mecanic(nume, prenume, dataNastere, dataAngajare, unixOcupat);
            }

            case ASISTENT: {
                vec[stoi(i)] = new Asistent(nume, prenume, dataNastere, dataAngajare, unixOcupat);
            }
            
            default:
                break;
        }
    }
}

void salveazaAngajatitoJson(Angajat **&vec, unsigned int &dim) {
    nlohmann::json json;

    for(unsigned int i = 0; i < dim; i++) {
        json[to_string(i)]["type"] = typeid(*vec[i]).name();
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

    ofstream file("../../data/Angajati.json");
    file << json;
}