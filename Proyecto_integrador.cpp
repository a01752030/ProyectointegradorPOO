//Trabajo Realizado por Juan Pablo Castañeda Serrano y Salvador Arreola Tena

#include "Calculadora.h"
#include "Precio.h"
#include "Producto.h"
#include "Tienda.h"
#include "Usuario.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

void menu(Usuario& usuario, Tienda& tienda) {
	int opcion;
	cout << "\n\tPuede hacer las siguientes opciones. Usuario: "+usuario.getNombre()+" "+usuario.getApellido() << endl;
	cout << "1) Colocar productos a vender" << endl;
	cout << "2) Ver o editar mis productos" << endl;
	cout << "3) Opciones de tienda" << endl;
	cout << "4) Calculadora de mis productos" << endl;
	cout << "5) Gestionar cuenta" << endl;
	cout << "6) Salir" << endl;
	cout << "Recuerde que tiene su pais puesto como " + usuario.getPais() + " y su tienda como " + tienda.getUbicacion();
	
}

void verTiendas(vector<Tienda>& tiendas) {
	for (int i = 0; i < tiendas.size(); i++) {
		cout << "\nTienda: " << to_string(i + 1) << endl;
		cout << "\tNombre: " << tiendas[i].getNombre() << endl;
		cout << "\tUbicacion: " << tiendas[i].getUbicacion() << endl;
		cout << "\tTipo: " << tiendas[i].getTipo() << endl;
	}
}



vector<Producto>& altaProducto(vector<Producto>& productos) {
	Producto producto;
	producto.crear_producto();
	productos.push_back(producto);
	return productos;
}



	void verProductos(vector<Producto> & productos) {
		for (int i = 0; i < productos.size(); i++) {
			cout << "\nProducto " << to_string(i + 1) << endl;
			cout << "\tNombre: " << productos[i].getNombre() << endl;
			cout << "\tTipo: " << productos[i].getTipo() << endl;
			cout << "\tPrecio sin descuento: " << productos[i].getPrecioSinDescuento() << endl;
			cout << "\tDescuento: " << productos[i].getPorcentajeDescuento() << "%" << endl;
			cout << "\t Precio final: " << productos[i].getPrecioReal() << endl;
		}

	}
	void calculadora(vector<Producto>& productos) {
		Calculadora calc;
		calc.calcular_total(productos);
		calc.calcular_total_descuentos(productos);
		calc.diferenciar();
		cout << "\nEl total de todos sus precios de sus productos es: " << calc.getTotal() << endl;
		cout << "El total de todos sus precios incluyendo los descuentos es:" << calc.getTotalDescuentos() << endl;
		cout << "La diferencia entre los 2 anteriores es: " << calc.getDiferencia() << endl;
	}
	void main() {

		vector<Producto> inventario;
		vector <Tienda> mochila;
		inventario.reserve(5);
		mochila.reserve(5);

		int opcion_de_menu = 0;
		cout << "Antes de iniciar su navegacion necesita crear una cuenta, por favor denos sus datos" << endl;
		Usuario usu;
		usu.crear_cuenta();
		cout << "\tGracias por crear su cuenta!" << endl;
		cout << "Ahora necesita crear una tienda" << endl;
		Tienda tien_usu;
		tien_usu.crear_tienda();
		mochila.push_back(tien_usu);
		Tienda tien1;
		Tienda tien2;
		Tienda tien3;
		tien1.ExtraTienda("Wall Mart", "E.E.U.U", "Comida/Viveres");
		mochila.push_back(tien1);
		tien2.ExtraTienda("Mos Easley", "Tatooine", "Electronicos");
		mochila.push_back(tien2);
		tien3.ExtraTienda("Coppel", "Mexico", "Misalaneos");
		mochila.push_back(tien3);
		mochila.push_back(tien_usu);
		cout << "\tAhora que tienes una tienda, es hora de poner tu primer producto a la venta" << endl;
		Producto produ1;
		Precio precio1;
		produ1.crear_producto();
		inventario.push_back(produ1);
		cout << "Felicidades, ya esta listo para administrar su tienda y checar otras!!";
		while (opcion_de_menu != 6) {
			menu(usu, mochila[0]);
			cout << "\nSeleccione el numero de la opcion que desee: "; cin >> opcion_de_menu;
			switch (opcion_de_menu) {
			case 1: {
				inventario = altaProducto(inventario);
				break;
			}
			case 2: {
				int opcion_mini;
				int num_produc;

				verProductos(inventario);
				cout << "Puede: " << endl;
				cout << "1) Editar un producto" << endl;
				cout << "2) Enviar un producto" << endl;
				cout << "3) Dar un producto por agotado" << endl;
				cout << "4) Volver al menu principal" << endl;
				cout << "Seleccione una opcion: "; cin >> opcion_mini;

				if (opcion_mini == 1) {
					cout << "Cual desea editar? (Digite el numero del producto): "; cin >> num_produc;
					inventario[num_produc - 1].editar_producto();
					cout << "Gracias por usar el editor de productos!!";
					break;
				}
				if (opcion_mini == 2) {
					int num_produc;
					cout << "Cual desea enviar? (Digite el numero del producto): "; cin >> num_produc;
					inventario[num_produc - 1].enviar_producto();
					break;
				}
				if (opcion_mini == 3) {
					int opci;
					cout << "Cual desea dar por agotado? (Digite el numero del producto): "; cin >> opci;
					inventario[opci - 1].agotar_producto();
					break;
				}
				if (opcion_mini == 4) {
					break;
				}
			}
			case 3: {
				int opcion_minimini;
				cout << "\tQuiere: " << endl;
				cout << "\t1) Ver otras tiendas" << endl;
				cout << "\t2) Editar mi tienda" << endl;
				cout << "Seleccione una opcion: "; cin >> opcion_minimini;
				if (opcion_minimini == 1) {
					int opcion_miniminimni;
					cout << "RECUERDE QUE SI VE SU TIENDA 2 VECES EN ESTA LISTA, ESTA SUFRIENDO DE PLAGIO Y DEBE REPORTALO" << endl;
					verTiendas(mochila);
					cout << "\nPuede:" << endl;
					cout << "1) Reportar plagio" << endl;
					cout << "2) Contactar alguna tienda" << endl;
					cout << "3) Volver al menu principal" << endl;
					cout << "Seleccione una opcion: "; cin >> opcion_miniminimni;
					if (opcion_miniminimni == 1) {
						int plagio;
						cout << "A que tienda desea repotar? (Coloque su numero de tienda): "; cin >> plagio;
						mochila[plagio - 1].reportar_plagio();
						break;
					}
					if (opcion_miniminimni == 2) {
						int contacto;
						cout << "A que tienda desea contactar? (Coloque su numero de tienda): "; cin >> contacto;
						mochila[contacto - 1].contactar_tienda();
						break;
					}
					if (opcion_miniminimni == 3) {
						break;
					}

				}
				if (opcion_minimini == 2) {
					mochila[0].editar_tienda();
					cout << "Aunque haya cambiado su nombre, puede que alguien le este haciendo plagio con los datos de su antigua tienda." << endl;
					cout << "Favor de reportar si encuentra algo en la lista de tiendas que se vea sospechoso." << endl;
					break;
				}
			}
			case 4: {
				int principio;
				cout << "\n\tAqui esta la lista del calculo de sus precios" << endl;
				calculadora(inventario);
				cout << "\nDigite cualquier numero para volver al menu principal"; cin >> principio;
				break;
			}
			case 5: {
				int pequenopcion;
				cout << "\nQue quieres hacer con tu cuenta?" << endl;
				cout << "1) Editar cuenta" << endl;
				cout << "2) Borrar cuenta" << endl;
				cout << "Selecciona una opcion: "; cin >> pequenopcion;
				if (pequenopcion == 1) {
					usu.editar_cuenta();
				}
				if (pequenopcion == 2) {
					usu.borrar_cuenta();
				}
			}
			}

		}
		cout << "Gracias por su visita!!";
		}
	