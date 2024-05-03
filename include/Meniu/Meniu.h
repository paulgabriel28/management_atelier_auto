#pragma once

#include "../utile/functions.h"

#include <iostream>
using namespace std;

enum MeniuOptions {
    MENIU_NULL = -1,
    MENIU_PRINCIPAL = 0,
    MENIU_ADMIN_ANGAJATI,
    MENIU_ADMIN_MASINI,
    MENIU_SETARI,
    MENIU_ADMIN,
    MENIU_ATELIER
};

void sendMeniuOption(const unsigned int &, const string &);

void meniuPrincipal();

void meniuAdminAngajati();
void meniuAdminMasini();

void meniuSetari();
void meniuAdmin();

void meniuAtelier();

bool correctOption(const unsigned int &, const MeniuOptions &);

void Meniu(const MeniuOptions &);