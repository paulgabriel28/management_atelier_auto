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

// MARK: isMajor
bool isMajor(const string *);

// MARK: isPresent
bool isPresent(const string *);

void citesteAngajat(string &, string &, string *, string *);