#include "main.h"

int main() {
    Angajat **vec = nullptr;
    int dim = 3;
    vec = new Angajat*[dim];

    vec[0] = new Asistent();
    vec[1] = new Mecanic();
    vec[2] = new Director();


    // Dealocarea memoriei
    for(int i = 0; i < dim; i++) {
        delete vec[i];
    }
    delete[] vec;

    return 0;
}