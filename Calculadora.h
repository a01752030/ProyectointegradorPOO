// Clase hecha por Salvador Arreola Tena
#ifndef CALCULADORA_C
#define CALCULADORA_C

#include <string>
#include "Producto.h"
#include <vector>
using namespace std;
#include <iostream>

class Calculadora {
private:
    int total;
    int total_descuentos;
    int diferencia_con_totales;
 

public:
    Calculadora() {
        total = 0;
        total_descuentos = 0;
        diferencia_con_totales = 0;
    }
    void calcular_total(vector<Producto>& productos) {
        for (int i = 0; i < productos.size(); i++) {

            total += productos[i].getPrecioSinDescuento();
        }
    }

    void calcular_total_descuentos(vector<Producto>& productos) {
        for (int i = 0; i < productos.size(); i++) {
            total_descuentos += productos[i].getPrecioReal();
        }
    }
    void diferenciar() {
        diferencia_con_totales = total - total_descuentos;
    }
    int getTotal() { return total; }
    int getTotalDescuentos() { return total_descuentos; }
    int getDiferencia() { return diferencia_con_totales; }
};

#endif
