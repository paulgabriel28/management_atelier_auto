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
void sendSuccess(const string &);
void citesteValoare(const string &);

void sendSeparator();

void sendAngajatID(const Angajat *a);

void sendID();

double calculSalariu(const double &, const double &);

void clearChat();

void elibereazaMemorie(Angajat **&, const unsigned int &);