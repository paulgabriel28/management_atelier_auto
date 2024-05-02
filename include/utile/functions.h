#pragma once

#include "../Angajati/Angajat.h"
#include <iostream>
#include <chrono>
#include <string>
#include <cstdlib>
using namespace std;

void sendError(const string &);

void sendInfo(const string &);

void sendQuestion(const string &);

void sendSeparator();

void sendSuccess(const string &);

void sendAngajatID(const Angajat *a);

void sendID();

template <typename Tvec, typename Tdim>
void copyVectorPointer(const Tvec **, const Tvec **, const Tdim &);

double calculSalariu(const double &, const double &);

void clearChat();