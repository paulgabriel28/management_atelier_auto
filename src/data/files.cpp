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
        unsigned int nrMasiniInAsteptare = (*it)["nrMasiniInAsteptare"];
        masinaInAsteptare *masiniInAsteptare = new masinaInAsteptare[nrMasiniInAsteptare];
        for (unsigned int i = 0; i < nrMasiniInAsteptare; ++i) {
            masiniInAsteptare[i].tip = (*it)["masiniInAsteptare"][i]["tip"];
            masiniInAsteptare[i].unixIntrare = (*it)["masiniInAsteptare"][i]["unixIntrare"];
        }

        switch (type) {
            case DIRECTOR: {
                vec[index] = new Director(nume, prenume, dataNastere, dataAngajare, unixOcupat, nrMasiniInAsteptare, masiniInAsteptare);
                break;
            }

            case MECANIC: {
                vec[index] = new Mecanic(nume, prenume, dataNastere, dataAngajare, unixOcupat, nrMasiniInAsteptare, masiniInAsteptare);
                break;
            }

            case ASISTENT: {
                vec[index] = new Asistent(nume, prenume, dataNastere, dataAngajare, unixOcupat, nrMasiniInAsteptare, masiniInAsteptare);
                break;
            }
            
            default:
                break;
        }

        delete [] masiniInAsteptare;
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

        json[to_string(i)]["nrMasiniInAsteptare"] = vec[i]->getNrMasiniInAsteptare();
        json[to_string(i)]["masiniInAsteptare"] = json::array();
        for (unsigned int j = 0; j < vec[i]->getNrMasiniInAsteptare(); ++j) {
            json[to_string(i)]["masiniInAsteptare"][j]["tip"] = vec[i]->getMasiniInAsteptare()[j].tip;
            json[to_string(i)]["masiniInAsteptare"][j]["unixIntrare"] = vec[i]->getMasiniInAsteptare()[j].unixIntrare;
        }
    }

    fstream file("data/Angajati.json", ios::out);

    if (!file.is_open()) {
        sendError("Nu s-a putut deschide fisierul JSON pentru scriere.");
        return;
    }

    file << json.dump(4);

    file.close();
}

void intrareInAtelier(const Angajat *angajat, const Masina *masina, const long long &iesireService, const bool &cerereSpeciala, const bool &inAsteptare, const unsigned short int &bacsis) {
    fstream file("data/intrariAtelier.json", ios::in | ios::out);

    if (!file.is_open()) {
        sendError("Nu s-a putut deschide fisierul JSON pentru citire/scriere.");
        return;
    }

    json dateExistent;
    file >> dateExistent;

    json json;
    json["idAngajat"] = angajat->getIdAngajat();
    json["dataIntrareUnix"] = getCurrentTime();
    json["dataIesireUnix"] = iesireService;
    json["cerereSpeciala"] = cerereSpeciala;
    json["inAsteptare"] = inAsteptare;
    json["bacsis"] = bacsis;

    json["masina"]["tip"] = getTypeMasina(masina);
    json["masina"]["numarKm"] = masina->getNumarKm();
    json["masina"]["anFabricare"] = masina->getAnFabricare();
    json["masina"]["isDisel"] = masina->getIsDisel();
    json["masina"]["discount"] = masina->getDiscount();

    unsigned int numarLocuri = 0;
    double tonaj = 0.0;
    typeTransmisie transmisie = transmisieNULL;

    switch (stringToTypeMasina(getTypeMasina(masina)))
    {
        case tipSTANDARD: {
            transmisie = dynamic_cast<const Standard*>(masina)->getTransmisie();
            break;
        }

        case tipAUTOBUZ: {
            numarLocuri = dynamic_cast<const Autobuz*>(masina)->getNumarLocuri();
            break;
        }

        case tipCAMION: {
            tonaj = dynamic_cast<const Camion*>(masina)->getTonaj();
            break;
        }

        default:
            break;
    }

    json["masina"]["numarLocuri"] = numarLocuri;
    json["masina"]["tonaj"] = tonaj;
    json["masina"]["transmisie"] = (transmisie == transmisieNULL ? -1 : (transmisie == AUTOMAT ? 1 : 0));

    
    dateExistent.push_back(json);
    file.seekp(0);
    file << dateExistent.dump(4);

    file.close();
}

json citesteIntrariAtelier() {
    fstream file("data/intrariAtelier.json", ios::in);
    
    if (!file.is_open()) {
        sendError("Nu s-a putut deschide fisierul JSON pentru citire.");
        return json();
    }
    
    json dateExistent;
    file >> dateExistent;
    file.close();
    
    return dateExistent;
}