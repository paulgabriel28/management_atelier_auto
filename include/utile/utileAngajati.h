#ifndef _UTILE_ANGAJATI
#define _UTILE_ANGAJATI

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <string>

#include <algorithm>
#include <ctime>
#include <sstream>

#include "../enum.h"
#include "functions.h"

#include "../Angajati/Angajat.h"
#include "../Angajati/Asistent.h"
#include "../Angajati/Mecanic.h"
#include "../Angajati/Director.h"

#include <nlohmann/json.hpp>

using namespace std;

atributeAngajati angajatiGetParametru(const string &);

typeAngajat stringToTypeAngajat(const string &);

bool isMajor(const string *);

bool isPresent(const string *);

void citesteAngajat(string &, string &, string *, string *);

double calculSalariu(const double &an, const double &coeficient);

void sortVectorAngajatiByID(Angajat **, const unsigned int &);

string getTypeAngajat(const Angajat *);

void copyVectorAngajat(Angajat **&, Angajat **, const unsigned int &);

bool existaIdAngajat(Angajat *const *, const unsigned int &, const int &);

#endif