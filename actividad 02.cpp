#include <iostream>
#include <list>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    list<string> palabras;
    string palabra;
    char opcion;

    do {
        cout << "Ingrese una palabra: ";
        cin >> palabra;

        palabras.push_back(palabra);

        cout << "¿Desea ingresar otra palabra? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    palabras.sort();

    string palabraBuscada;
    cout << "Ingrese la palabra que desea buscar: ";
    cin >> palabraBuscada;
    int cantidad = count(palabras.begin(), palabras.end(), palabraBuscada);
    
    transform(palabras.begin(), palabras.end(), palabras.begin(), [](string& palabra) {
        for (char& c : palabra) {
            c = toupper(c);
        }
        return palabra;
    });

    cout << "Lista resultante:" << endl;
    for (const string& p : palabras) {
        cout << p << endl;
    }

    cout << "La palabra '" << palabraBuscada << "' aparece " << cantidad << " veces en la lista." << endl;

    return 0;
}
