#include "../../include/utile/functions.h"

using namespace std;

void sendError(const string &mesaj) {
    cout << "\033[38;2;255;0;0m[x]: \033[0m" << mesaj << endl;
}

void sendInfo(const string &info) {
    cout << "\n\033[38;2;0;0;255m[!] \033[0m" << info << endl;
}

void sendQuestion(const string &question) {
    cout << "\n\033[38;2;255;255;0m(?) \033[0m" << question << endl;
}

void sendSeparator() {
    cout << "\n\033[38;2;0;0;128m----------\033[0m\n";
}

void sendSuccess(const string &message) {
    cout << "\n\033[38;2;0;128;0m[✓] \033[0m" << message;
}

void sendAngajatID(const Angajat *a) {
    cout << "\n033[38;2;0;0;255m[!]\033[0m Angajat ID: " << a->getIdAngajat() << endl;
}

void sendID() {
    cout << "\n033[38;2;0;0;255m[!]\033[0m Angajat ID: " << Angajat::getID() << endl;
}

template <typename Tvec, typename Tdim>
void copyVectorPointer(const Tvec **copyVec, const Tvec **vec, const Tdim &dim) {
    if(copyVec != nullptr) {
        delete [] copyVec;
        copyVec = NULL;
    }

    copyVec = new Tvec*[dim];    
    for(int i = 0; i < dim; i++) {
        copyVec[i] = vec[i];
    }
}

long long getCurrentTime(){
    auto currentTime = chrono::system_clock::now().time_since_epoch();
    auto currentTimeSeconds = chrono::duration_cast<chrono::seconds>(currentTime).count();
    return currentTimeSeconds += 7200; // UTC+2 (Bucuresti)
}
