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

#include "../enum.h"

using namespace std;
using json = nlohmann::json;

void citesteAngajatiJSON(Angajat **&, unsigned int &);

void salveazaAngajatitoJson(Angajat **&, unsigned int &);