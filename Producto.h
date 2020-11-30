// Clase hecha en equipo
#pragma once
#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Precio.h"



using namespace std;

#ifndef PRODUCTO_C
#define PRODUCTO_C
class Producto {
private:
	string nombre;
	string tipo;
	string direccion_de_envio;
	int preciotemp1;
	int preciotemp2;
	int desctemp1;
	Precio precio;

public:
	void crear_producto() {
		cout << "Nombre del producto: "; cin >> nombre;
		cout << "Precio: "; cin >> preciotemp1;
		cout << "Quiere ponerle algun descuento? (Si no solo digite 0): "; cin >> desctemp1;
		cout << "\tQue tipo de producto es? le recomendamos elegir uno de esta lista" << endl;
		cout << "\t1)Viveres/comida" << endl;
		cout << "\t2)Ropa/calzado" << endl;
		cout << "\t3)Electricos" << endl;
		cout << "\t4)Misalaneos" << endl;
		cout << "Escriba una opcion de la lista o su propio tipo (solo una palabra): "; cin >> tipo;
		precio.calcular_descuento(preciotemp1, desctemp1);
		preciotemp1 = precio.get_precio_real();
		desctemp1 = precio.get_porcentaje();
	}
	Producto() {
		nombre = "Sin especificar";
		tipo = "Sin especificar";

	}
	Producto(string name, string type) : nombre{ name }, tipo{ type } {

	}

	void editar_producto() {

		cout << "Que nombre quiere ponerle?: "; cin >> nombre;
		cout << "Que tipo le quiere poner?: "; cin >> tipo;
		cout << "Que precio quiere cambiarle?: "; cin >> preciotemp1;
		cout << "Quiere cambiarle el descuento? (Si no solo coloque 0): "; cin >> desctemp1;
		precio.calcular_descuento(preciotemp1, desctemp1);
		preciotemp1 = precio.get_precio_real();
		desctemp1 = precio.get_porcentaje();

	}
	void enviar_producto() {
		int num;
		srand(time(NULL));
		num = rand() % 10 + 2;
		cout << "A que pais quiere enviar este producto?: "; cin >> direccion_de_envio;
		cout << "\nPerfecto!! Viendo que quiere enviarlo a " + direccion_de_envio + ". Tomara un total de " + to_string(num) + " dias en llegar";
		cout << "\n Recuerde dar por agotado el producto si es que no tiene mas!!";
	}

	void agotar_producto() {
		nombre = nombre + " (Agotado, pronto se revastesera)";
		cout << "Su producto ya esta dado de alta como agotado, puede checarlo en la lista de sus productos";
	}

	string getNombre() { return nombre; }
	string getTipo() { return tipo; }
	int getPrecioSinDescuento() {
		return precio.get_precio_sin_descuento();
	}
	int getPorcentajeDescuento() {
		return precio.get_porcentaje();

	}
	int getPrecioReal() {
		return precio.get_precio_real();
	}
	

};




#endif