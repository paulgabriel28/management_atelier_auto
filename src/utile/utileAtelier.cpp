#include "../../include/utile/utileAtelier.h"

long long UnixToZile(const long long &unixTimestamp) {
    time_t unixTime = time_t(unixTimestamp);

    time_t timpulCurent = time_t(getCurrentTime());
    int diferentaSecunde = difftime(timpulCurent, unixTime);

    int zile = diferentaSecunde / (24 * 3600);

    return zile;
}

long long ZileToUnix(const int &nrDays) {
    time_t currentTime = time_t(getCurrentTime());
    time_t timeUnix = currentTime + nrDays * 24 * 3600;
    return (long long)timeUnix;
}