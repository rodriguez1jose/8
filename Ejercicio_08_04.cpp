// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creacion: 24/11/2023

// Fecha modificación: 27/11/2023

// Numero de ejericio: 4 

// Problema planteado: Codifique un programa que cree un fichero para contener los datos relativos a los artículos de un almacén.
// Para cada artículo habrá de guardar la siguiente información:.........

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

void crearArchivoArticulos();
void ordenarPorCodigo();
void mostrarInventario();
void mezclarFicheros();

int main() {
    crearArchivoArticulos();
    ordenarPorCodigo();
    mostrarInventario();
    mezclarFicheros();

    return 0;
}

void crearArchivoArticulos() {
    ofstream archivoArticulos(archivo, ios::binary | ios::app);

    if (!archivoArticulos.good()) {
        cout << "Error al abrir el archivo de articulos.\n";
        return;
    }

    cout << "Ingrese los datos de los articulos. Para finalizar, ingrese el codigo 0.\n";
    Articulo articulo;

    do {
        cout << "Codigo del articulo (0 para salir): ";
        cin >> articulo.codigo;
        if (articulo.codigo != 0) {
            cin.ignore();
            cout << "Nombre del articulo: ";
            getline(cin, articulo.nombre);
            cout << "Existencias actuales: ";
            cin >> articulo.existencias;
            cout << "Precio: ";
            cin >> articulo.precio;
            archivoArticulos.write(reinterpret_cast<char*>(&articulo), sizeof(Articulo));
        }
    } while (articulo.codigo != 0);
    archivoArticulos.close();
}

void ordenarPorCodigo() {
    ifstream archivoLectura(archivo, ios::binary);
    if (!archivoLectura.good()) {
        cout << "Error al abrir el archivo.\n";
        return;
    }
    Articulo articulos[100];
    int totalArticulos = 0;
    while (archivoLectura.read(reinterpret_cast<char*>(&articulos[totalArticulos]), sizeof(Articulo))) {
        totalArticulos++;
    }
    archivoLectura.close();
    for (int i = 0; i < totalArticulos - 1; i++) {
        for (int j = i + 1; j < totalArticulos; j++) {
            if (articulos[i].codigo > articulos[j].codigo) {
                swap(articulos[i], articulos[j]);
            }
        }
    }
    ofstream archivoEscritura(archivo, ios::binary);

    for (int i = 0; i < totalArticulos; i++) {
        archivoEscritura.write(reinterpret_cast<char*>(&articulos[i]), sizeof(Articulo));
    }
    archivoEscritura.close();
}
void mostrarInventario() {
    ifstream archivoLectura(archivo, ios::binary);
    if (!archivoLectura.good()) {
        cout << "Error al abrir el archivo.\n";
        return;
    }
    cout << "\nInventario ordenado por codigo:\n";
    cout << "--------------------------------\n";
    cout << "Código\tNombre\tExistencias\tPrecio\n";
    Articulo articulo;
    while (archivoLectura.read(reinterpret_cast<char*>(&articulo), sizeof(Articulo))) {
        cout << articulo.codigo << "\t" << articulo.nombre << "\t" << articulo.existencias << "\t\t" << articulo.precio << "\n";
    }
    archivoLectura.close();
}
void mezclarFicheros() {
    ifstream archivoLectura1(archivo, ios::binary);
    ifstream archivoLectura2(archivo, ios::binary);
    ofstream archivoEscritura("mezcla.txt");
    if (!archivoLectura1.good() || !archivoLectura2.good() || !archivoEscritura.good()) {
        cout << "Error al abrir uno de los archivos.\n";
        return;
    }
    Articulo articulo1, articulo2;
    archivoLectura1.read(reinterpret_cast<char*>(&articulo1), sizeof(Articulo));
    archivoLectura2.read(reinterpret_cast<char*>(&articulo2), sizeof(Articulo));

    while (!archivoLectura1.eof() && !archivoLectura2.eof()) {
        if (articulo1.codigo < articulo2.codigo) {
            archivoEscritura << articulo1.codigo << "\t" << articulo1.nombre << "\t" << articulo1.existencias << "\t" << articulo1.precio << "\n";
            archivoLectura1.read(reinterpret_cast<char*>(&articulo1), sizeof(Articulo));
        } else {
            archivoEscritura << articulo2.codigo << "\t" << articulo2.nombre << "\t" << articulo2.existencias << "\t" << articulo2.precio << "\n";
            archivoLectura2.read(reinterpret_cast<char*>(&articulo2), sizeof(Articulo));
        }
    }
    while (!archivoLectura1.eof()) {
        archivoEscritura << articulo1.codigo << "\t" << articulo1.nombre << "\t" << articulo1.existencias << "\t" << articulo1.precio << "\n";
        archivoLectura1.read(reinterpret_cast<char*>(&articulo1), sizeof(Articulo));
    }
    while (!archivoLectura2.eof()) {
        archivoEscritura << articulo2.codigo << "\t" << articulo2.nombre << "\t" << articulo2.existencias << "\t" << articulo2.precio << "\n";
        archivoLectura2.read(reinterpret_cast<char*>(&articulo2), sizeof(Articulo));
    }
    archivoLectura1.close();
    archivoLectura2.close();
    archivoEscritura.close();
    cout <<"Mezcla de ficheros realizada con exito. Resultado en 'mezcla.txt'.\n";
}

