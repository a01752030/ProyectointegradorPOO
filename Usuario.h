// Clase hecha en equipo
#include <string>
#include <iostream>
using namespace std;

	
#ifndef USUARIO_C
#define USUARIO_C

class Usuario {
private:
	string nombre;
	string apellido;
	string pais;
public:
	void crear_cuenta() {
		cout << "1er nombre: "; cin >> nombre;
		cout << "1er apellido: "; cin >> apellido;
		cout << "Pais de recidencia: "; cin >> pais;
	}
	void borrar_cuenta() {
		nombre = "Borrado";
		apellido = "Borrado";
		pais = "Borrado";
		cout << "Su cuenta ha sido borrada, ahora sus datos estarán en 'borrado'";
	}
	void editar_cuenta() {
		cout << "A que nombre quieres cambiarle: "; cin >> nombre;
		cout << "A que apellido quiere cambiarte: "; cin >> apellido;
		cout << "A que pais quieres cambiarte: "; cin >> pais;
	}
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	string getPais() { return pais; }

};//Clase usuario

#endif