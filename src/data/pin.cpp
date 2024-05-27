#include "../../include/data/pin.h"

// MARK: current_time
const char *current_time()
{
    auto now = system_clock::now();
    time_t currentTime = system_clock::to_time_t(now);
    const char *rawTimeString = ctime(&currentTime);
    size_t length = strlen(rawTimeString);
    char *timeString = new char[length];
    strcpy(timeString, rawTimeString);
    timeString[length - 1] = '\0';

    return timeString;
}

// MARK: hashing
unsigned int hashing(const string a)
{
    int32_t hash = 538;
    int c;
    
    for(unsigned int i = 0; i < a.size(); i++) {
        c = a[i];
        hash = ((hash << 5u) + hash) + c;
    }
    
    return hash;
}

// MARK: loginpinAdmin
int login(const string pass)
{
    json settings = getSettings();
    string pinAdmin = settings["pinAdmin"];
    
    unsigned int passHash = hashing(pass);

    string passHashStr = to_string(passHash);
    
    if (pinAdmin == passHashStr) 
        return 1;
    
    return 0;
}