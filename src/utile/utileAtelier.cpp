#include "../../include/utile/utileAtelier.h"

int zileRamaseUnix(const long long &unixTimestamp) {
    time_t unixTime = time_t(unixTimestamp);

    time_t timpulCurent = time(nullptr);
    int diferentaSecunde = difftime(timpulCurent, unixTime);

    int zile = diferentaSecunde / (24 * 3600);

    return zile;
}

typeMasini stringToTypeMasina(const string &type) {
    string lowerType = type;
    transform(lowerType.begin(), lowerType.end(), lowerType.begin(), [](unsigned char c) { return tolower(c); });

    if (lowerType == "masina") return MASINA;
    if (lowerType == "standard") return STANDARD;
    if (lowerType == "autobuz") return AUTOBUZ;
    if (lowerType == "camion") return CAMION;
    return tipNULL;
}
