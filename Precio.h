// Clase hecha por Juan Pablo Castañeda Individualmente
#include <string>
#include <iostream>
#include "Producto.h"

using namespace std;

#ifndef PRECIO_C
#define PRECIO_C

class Precio {
private:
	float porcentaje_descuento;
	float precio_sin_descuento;
	float precio_con_descuento;
	float precio_real;
public:
	Precio() {
		porcentaje_descuento = 0;
		precio_sin_descuento = 0;
		precio_con_descuento = 0.0;
		precio_real = 0;
	}
	Precio(float prize, float discount) : precio_sin_descuento{ prize }, porcentaje_descuento{ discount }, precio_con_descuento{}, precio_real{}{

	}
	void calcular_descuento(float pr, float dis) {
		precio_sin_descuento = pr;
		porcentaje_descuento = dis;
		precio_con_descuento = (pr * (dis * (.01)));
		precio_real = precio_sin_descuento - precio_con_descuento;

	}
	void editar_descuento(int po) {
		porcentaje_descuento = po;
	}
	void quitar_descuento() {
		porcentaje_descuento = 0;
	}
	float get_precio_descuento() { return precio_con_descuento; }
	float get_precio_sin_descuento() { return precio_sin_descuento; }
	float get_precio_real() { return precio_real; }
	float get_porcentaje() { return porcentaje_descuento; }

};

#endif