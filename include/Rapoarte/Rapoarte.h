#ifndef _RAPOARTE
#define _RAPOARTE

#include <string>
#include <iomanip>
#include <nlohmann/json.hpp>

#include "../Angajati/Angajat.h"
#include "../data/files.h"
#include "../enum.h"

using namespace std;

bool unixInDateString(const long long &, const string *);

void comenxiMaxZi(const string *);

void top3maxPolita();

void top3maxAutobuze();

void top3CereriSpeciale();

void afisareBacsis();

#endif