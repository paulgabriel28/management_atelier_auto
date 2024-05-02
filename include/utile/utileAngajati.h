#pragma once

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <string>

#include <algorithm>
#include <ctime>
#include <sstream>

#include "../enum.h"

#include "functions.h"

using namespace std;

atributeAngajati angajatiGetParametru(const string &);

typeAngajat stringToTypeAngajat(const string &);

bool isMajor(const string *);

bool isPresent(const string *);

void citesteAngajat(string &, string &, string *, string *);

double calculSalariu(const double &an, const double &coeficient);