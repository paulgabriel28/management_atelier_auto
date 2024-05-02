#include "main.h"

int main() {
    fstream file("data.json", ios::in);

    if (!file.is_open()) {
        std::cerr << "Nu s-a putut deschide fisierul JSON.\n";
        return 1;
    }

    json j;
    file >> j;

    cout << j.dump(4) << '\n';

    for(string i = "1"; j.contains(i); i = to_string(stoi(i) + 1)) {
        cout << j[i]["name"] << '\n';
        cout << j[i]["age"] << '\n';
        cout << endl;
    }

    file.close();
    return 0;
}