#ifndef _PIN
#define _PIN

// NOTE: Sistem PIN [2021]

#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <ctime>
#include <chrono>
#include <fstream>

#include "../data/files.h"
#include "../utile/functions.h"

using namespace std;
using namespace chrono;


unsigned int hasing(const string);
int login(const string);

#endif