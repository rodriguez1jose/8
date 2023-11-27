// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creacion: 24/11/2023

// Fecha modificación: 27/11/2023

// Numero de ejericio: 6

// Problema planteado: Escriba un programa que tome como entrada el fichero del ejercicio 4 y una condición sobre el campo Precio. La condición podrá ser:......

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Articulo {
    int codigo;
    string nombre;
    int existencias;
    double precio;
};
const char* archivo = "almacen.txt";
const char* archivoSalida = "salida.dat";
void filtrarPorPrecio(double precioLimite);
void mostrarArchivoSalida();

int main() {
    double precioLimite;
    cout << "Ingrese el precio lImite: ";
    cin >> precioLimite;
    filtrarPorPrecio(precioLimite);
    mostrarArchivoSalida();
    return 0;
}

void filtrarPorPrecio(double precioLimite) {
    ifstream archivoLectura(archivo, ios::binary);
    ofstream archivoSalida(archivoSalida, ios::binary);
    if (!archivoLectura.good() || !archivoSalida.good()) {
        cout << "Error al abrir uno de los archivos.\n";
        return;
    }
    Articulo articulo;
    while (archivoLectura.read(reinterpret_cast<char*>(&articulo), sizeof(Articulo))) {
        if (articulo.precio <= precioLimite) {
            archivoSalida.write(reinterpret_cast<char*>(&articulo), sizeof(Articulo));
        }
    }

    archivoLectura.close();
    archivoSalida.close();
    cout << "Filtrado por precio realizado con exito. Resultado en 'salida.dat'\n";
}
void mostrarArchivoSalida() {
    ifstream archivoSalida(archivoSalida, ios::binary);
    if (!archivoSalida.good()) {
        cout << "Error al abrir el archivo de salida\n";
        return;
    }
    cout << "\nArticulos filtrados por precio:\n";
    cout << "--------------------------------\n";
    cout << "Codigo\tNombre\tExistencias\tPrecio\n";
    Articulo articulo;
    while (archivoSalida.read(reinterpret_cast<char*>(&articulo), sizeof(Articulo))) {
        cout << articulo.codigo << "\t" << articulo.nombre << "\t" << articulo.existencias << "\t" << articulo.precio << "\n";
    }
    archivoSalida.close();
}

