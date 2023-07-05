#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct Evento {
	string nombre;
	string fecha;
    vector<string> asistentes;
};
map<string, Evento> eventos;
void agregarEvento() {
	Evento nuevoEvento;
	cout << "Ingrese el nombre del evento: ";
	cin.ignore();
	getline(cin, nuevoEvento.nombre);
	cout << "Ingrese la fecha del evento: ";
	getline(cin, nuevoEvento.fecha);
    eventos[nuevoEvento.nombre] = nuevoEvento;
	cout << "Evento agregado correctamente." << endl;
}
void agregarAsistente() {
	string nombreEvento;
	cout << "Ingrese el nombre del evento al que desea agregar asistentes: ";
	cin.ignore();
	getline(cin, nombreEvento);
	if (eventos.count(nombreEvento) > 0) {
    	string asistente;
    	cout << "Ingrese el nombre del asistente (Ingrese '0' para finalizar): ";
    	getline(cin, asistente);
    	while (asistente != "0") {
            eventos[nombreEvento].asistentes.push_back(asistente);
        	cout << "Asistente agregado correctamente. Ingrese otro nombre (Ingrese '0' para finalizar): ";
            getline(cin, asistente);
    	}
    	cout << "Asistentes agregados al evento correctamente." << endl;
	} else {
        cout << "No se encontró un evento con ese nombre." << endl;
	}
}
void mostrarAsistentes() {
	string nombreEvento;
	cout << "Ingrese el nombre del evento para mostrar la lista de asistentes: ";
	cin.ignore();
	getline(cin, nombreEvento);
	if (eventos.count(nombreEvento) > 0) {
        vector<string> asistentes = eventos[nombreEvento].asistentes;
        sort(asistentes.begin(), asistentes.end());
    	cout << "Lista de asistentes del evento \"" << nombreEvento << "\":" << endl;
    	for (const auto& asistente : asistentes) {
        	cout << asistente << endl;
    	}
	} else {
    	cout << "No se encontró un evento con ese nombre." << endl;
	}
}
void buscarEventosPorFecha() {
	string fecha;
	cout << "Ingrese la fecha para buscar eventos: ";
	cin.ignore();
	getline(cin, fecha);
	cout << "Eventos encontrados en la fecha " << fecha << ":" << endl;
	for (const auto& evento : eventos) {
    	if (evento.second.fecha == fecha) {
        	cout << evento.second.nombre << endl;
    	}
	}
}
int main() {
	char opcion;
	do {
    	cout << "-------------------------" << endl;
    	cout << "Menu de opciones:" << endl;
    	cout << "1. Agregar evento" << endl;
    	cout << "2. Agregar asistentes a un evento" << endl;
    	cout << "3. Mostrar lista de asistentes de un evento" << endl;
    	cout << "4. Buscar eventos por fecha" << endl;
    	cout << "5. Salir" << endl;
    	cout << "Ingrese su opcion: ";
    	cin >> opcion;
    	switch (opcion) {
        	case '1':
                agregarEvento();
            	break;
        	case '2':
      	      agregarAsistente();
            	break;
        	case '3':
                mostrarAsistentes();
            	break;
        	case '4':
                buscarEventosPorFecha();
            	break;
        	case '5':
            	cout << "Saliendo del programa." << endl;
            	break;
        	default:
            	cout << "Opción inválida." << endl;
            	break;
    	}
	} while (opcion != '5');
	return 0;
}
