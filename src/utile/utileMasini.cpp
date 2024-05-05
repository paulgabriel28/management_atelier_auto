#include "../../include/utile/utileMasini.h"

unsigned int getVechime(const unsigned int &an) {
    time_t timpPrezent = time(nullptr);
    tm* structTmPrezent = localtime(&timpPrezent);
    unsigned int anPrezent = structTmPrezent->tm_year + 1900;

    return anPrezent - an;
}

typeMasini stringToTypeMasina(const string &type) {
    string lowerType = type;
    transform(lowerType.begin(), lowerType.end(), lowerType.begin(), [](unsigned char c) { return tolower(c); });

    if (lowerType == "masina") return tipMASINA;
    if (lowerType == "standard") return tipSTANDARD;
    if (lowerType == "autobuz") return tipAUTOBUZ;
    if (lowerType == "camion") return tipCAMION;
    return tipNULL;
}
