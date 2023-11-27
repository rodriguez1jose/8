// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creacion: 24/11/2023

// Fecha modificación: 27/11/2023

// Numero de ejericio: 5

// Problema planteado: Escriba un programa que dados dos ficheros generados por el programa anterior y ordenados genere un tercer fichero que sea el resultado de mezclar de formar ordenada los dos primeros. 

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const char* archivo1 = "archivo1.txt";
const char* archivo2 = "archivo2.txt";
const char* archivoSalida = "resultado.txt";

void generarArchivos();
void mezclarArchivos();

int main() {
    generarArchivos();
    mezclarArchivos();

    return 0;
}

void generarArchivos() {
    ofstream archivo1(archivo1);
    ofstream archivo2(archivo2);

    if (!archivo1.good() || !archivo2.good()) {
        cout << "Error al abrir los archivos para escritura.\n";
        return;
    }
    cout << "Generando contenido para archivos...\n";
    for (int i = 1; i <= 10; ++i) {
        archivo1 << i << "\n";
    }
    for (int i = 11; i <= 20; ++i) {
        archivo2 << i << "\n";
    }
    cout << "Contenido generado y guardado en archivos.\n";
    archivo1.close();
    archivo2.close();
}

void mezclarArchivos() {
    ifstream archivo1(archivo1);
    ifstream archivo2(archivo2);
    ofstream archivoSalida(archivoSalida);
    if (!archivo1.good() || !archivo2.good() || !archivoSalida.good()) {
        cout << "Error al abrir los archivos para lectura o escritura.\n";
        return;
    }
    cout << "Mezclando contenido de archivos...\n";
    string lineaArchivo1, lineaArchivo2;
    getline(archivo1, lineaArchivo1);
    getline(archivo2, lineaArchivo2);
    while (!archivo1.eof() || !archivo2.eof()) {
        if (!lineaArchivo1.empty() && !lineaArchivo2.empty()) {
            int valorArchivo1 = stoi(lineaArchivo1);
            int valorArchivo2 = stoi(lineaArchivo2);
            if (valorArchivo1 < valorArchivo2) {
                archivoSalida << lineaArchivo1 << "\n";
                getline(archivo1, lineaArchivo1);
            } else {
                archivoSalida << lineaArchivo2 << "\n";
                getline(archivo2, lineaArchivo2);
            }
        } else if (!lineaArchivo1.empty()) {
            archivoSalida << lineaArchivo1 << "\n";
            getline(archivo1, lineaArchivo1);
        } else if (!lineaArchivo2.empty()) {
            archivoSalida << lineaArchivo2 << "\n";
            getline(archivo2, lineaArchivo2);
        }
    }
    cout << "Contenido mezclado y guardado en '" << archivoSalida << "'.\n";
    archivo1.close();
    archivo2.close();
    archivoSalida.close();
}

