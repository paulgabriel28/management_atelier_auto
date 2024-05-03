#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

#include "../Angajati/Angajat.h"
#include "../Angajati/Director.h"
#include "../Angajati/Asistent.h"
#include "../Angajati/Mecanic.h"

#include "../utile/utileAngajati.h"

#include "../enum.h"


using namespace std;

void citesteAngajatiJSON(Angajat **&, unsigned int &);