#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    deque<char> caracteres;
    string cadena;

    cout << "Ingrese una cadena de caracteres: ";
    cin >> cadena;

    for (char c : cadena) {
        caracteres.push_back(c);
    }

    cout << "Caracteres en el contenedor: ";
    for (auto it = caracteres.begin(); it != caracteres.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = caracteres.begin(); it != caracteres.end(); ++it) {
        if (*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u') {
            *it = '*';
        }
    }

    cout << "Caracteres en orden inverso: ";
    for (auto rit = caracteres.rbegin(); rit != caracteres.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}
