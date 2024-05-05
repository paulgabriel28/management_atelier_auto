#include "../../include/utile/utileAtelier.h"

long long ZileToUnix(const long long &unixTimestamp) {
    time_t unixTime = time_t(unixTimestamp);

    time_t timpulCurent = time(nullptr);
    int diferentaSecunde = difftime(timpulCurent, unixTime);

    int zile = diferentaSecunde / (24 * 3600);

    return zile;
}

long long UnixToZile(const long long &nrDays) {
    time_t currentTime = time(nullptr);
    time_t timeUnix = currentTime + nrDays * 24 * 3600;
    return (long long)timeUnix;
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
