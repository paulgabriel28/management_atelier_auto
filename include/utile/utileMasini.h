#pragma once

#include <string>
#include <ctime>
#include <algorithm>

#include "../enum.h"
#include "../Masini/Masina.h"
#include "../utile/functions.h"

#include "../Masini/Masina.h"
#include "../Masini/Autobuz.h"
#include "../Masini/Camion.h"
#include "../Masini/Standard.h"

using namespace std;

unsigned int getVechime(const unsigned int &);

typeMasini stringToTypeMasina(const string &);

Masina* citesteMasina();