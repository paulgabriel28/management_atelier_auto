#include <fstream>
#include <nlohmann/json.hpp>
#include <string>
#include <typeinfo>
#include <iomanip>

#include <vector>
#include <utility> // pair

#include "../Angajati/Angajat.h"
#include "../Angajati/Director.h"
#include "../Angajati/Asistent.h"
#include "../Angajati/Mecanic.h"

#include "../utile/utileAngajati.h"
#include "../utile/utileMasini.h"

#include "../enum.h"

using namespace std;
using json = nlohmann::json;

void citesteAngajatiJSON(Angajat **&, unsigned int &);
void salveazaAngajatiToJson(Angajat **&, unsigned int &);

void intrareInAtelier(const Angajat *, const Masina *, const long long &, const bool &, const bool &, const unsigned short int &);
json citesteIntrariAtelier();