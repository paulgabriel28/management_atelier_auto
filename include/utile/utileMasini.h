#include <ctime>

unsigned int getVechime(const unsigned int &an) {
    time_t timpPrezent = time(nullptr);
    tm* structTmPrezent = localtime(&timpPrezent);
    unsigned int anPrezent = structTmPrezent->tm_year + 1900;

    return anPrezent - an;
}