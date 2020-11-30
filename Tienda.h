// Clase hecha en equipo
#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h> 


using namespace std;
#ifndef TIENDA_C
#define TIENDA_C

class Tienda {
private:
	string nombre;
	string ubicacion;
	string tipo;
public:
	Tienda() {
		nombre = "Sin especificar";
		ubicacion = "Sin especificar";
		tipo = "Sin especificar";
	}
	void ExtraTienda(string nombre, string ubicacion, string tipo) {
		this->nombre = nombre;
		this->ubicacion = ubicacion;
		this->tipo = tipo;
	}
	void crear_tienda() {
		cout << "Nombre de la tienda (por favor solo use una palabra): "; cin >> nombre;
		cout << "Donde esta su tienda? (Solo el pais): "; cin >> ubicacion;
		cout << "De que tipo son sus productos? (Solo una palabra): "; cin >> tipo;
	}
	void contactar_tienda() {
		    int num;
			srand(time(NULL));
			num = rand() % 10 + 2;
			cout << "Le ha mandado una solicitud de contacto a " + nombre + ". Como estan en " + ubicacion + ",le tomara " + to_string(num) + " dias en contestar" << endl;
	}
	void reportar_plagio() {
		cout << "Gracias por reportar a " + nombre + "\nVeremos como lo resolvemos. Disculpe las incomodidades." << endl;

	}
	void editar_tienda() {
		cout << "Que nombre quiere ponerle? (por favor solo use una palabra): "; cin >> nombre;
		cout << "Que ubicacion quiere cambiar? (Solo el pais): "; cin >> ubicacion;
		cout << "De que tipo son sus productos ahora? (Solo una palabra): "; cin >> tipo;
	}
	string getNombre() { return nombre; }
	string getUbicacion() { return ubicacion; }
	string getTipo() { return tipo; }
};


#endif