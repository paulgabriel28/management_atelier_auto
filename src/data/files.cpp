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

        switch (type)
        {
            case DIRECTOR: {
                vec[stoi(i)] = new Director(nume, prenume, dataNastere, dataAngajare);
                break;
            }

            case MECANIC: {
                vec[stoi(i)] = new Mecanic(nume, prenume, dataNastere, dataAngajare);
            }

            case ASISTENT: {
                vec[stoi(i)] = new Asistent(nume, prenume, dataNastere, dataAngajare);
            }
            
            default:
                break;
        }
    }
}