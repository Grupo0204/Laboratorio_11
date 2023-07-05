#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numeros;
    int numero;
    char opcion;

    do {
        cout << "Ingrese un numero entero: ";
        cin >> numero;

        numeros.push_back(numero);

        cout << "¿Desea ingresar otro numero? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
    
    int suma = 0;
    for (int num : numeros) {
        suma += num;
    }

    int maximo = *max_element(numeros.begin(), numeros.end());
    int minimo = *min_element(numeros.begin(), numeros.end());

    sort(numeros.begin(), numeros.end());

    numeros.erase(remove_if(numeros.begin(), numeros.end(), [](int num) {
        return num % 2 == 0;
    }), numeros.end());

    cout << "Suma de los numeros: " << suma << endl;
    cout << "Numero maximo: " << maximo << endl;
    cout << "Numero minimo: " << minimo << endl;
    cout << "Contenido final del contenedor: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
