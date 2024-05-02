#include "../include/utile/functions.h"


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
void sortVectorByID(Tvec **vec, Tdim dim) {
    for(int i = 0; i < dim - 1; i++) {
        for(int j = i + 1; j < dim; j++) {
            if(vec[i]->getID() > vec[j]->getID()) {
                Tvec* temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
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

double calculSalariu(const double &an, const double &coeficient) {
    if(an) {
        return an * coeficient * 1000;
    }
    return coeficient * 1000;
}

auto getCurrentTime(){
    auto currentTime = chrono::system_clock::now().time_since_epoch();
    auto currentTimeSeconds = chrono::duration_cast<chrono::seconds>(currentTime).count();
    return currentTimeSeconds += 7200; // UTC+2 (Bucuresti)
}
