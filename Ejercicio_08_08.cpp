// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creacion: 26/11/2023

// Fecha modificación: 27/11/2023

// Numero de ejericio: 8

// Problema planteado: Escribir un programa que genere a partir de un fichero de entrada que contiene una tabla de
// números reales otro fichero de salida <nombre>.BIN grabado en formato binario. 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

void generarArchivoBinario(const string& nombreArchivo);
void leerArchivoTexto(const string& nombreArchivo);
void generarArchivoBinarioDesdeTexto(const string& nombreArchivoTexto, const string& nombreArchivoBinario);

int main() {
    const string nombreArchivoTexto = "entrada.txt";
    const string nombreArchivoBinario = "salida.bin";
    generarArchivoBinarioDesdeTexto(nombreArchivoTexto, nombreArchivoBinario);
    leerArchivoTexto(nombreArchivoTexto);
    return 0;
}
void generarArchivoBinario(const string& nombreArchivo) {
    ofstream archivoBinario(nombreArchivo, ios::binary);
    if (!archivoBinario.good()) {
        cout << "Error al abrir el archivo binario para escritura.\n";
        return;
    }
    vector<double> numeros = {1.23, 3.45, 12.5, 4.8, 3.9, 0.83};
    for (const double& numero : numeros) {
        archivoBinario.write(reinterpret_cast<const char*>(&numero), sizeof(double));
    }
    archivoBinario.close();
}

void leerArchivoTexto(const string& nombreArchivo) {
    ifstream archivoTexto(nombreArchivo);
    if (!archivoTexto.good()) {
        cout << "Error al abrir el archivo de texto\n";
        return;
    }
    double numero;
    cout << "\nContenido del archivo de texto:\n";
    while (archivoTexto >> numero) {
        cout << fixed << setprecision(2) << numero << " ";
    }
    cout << "\n";
    archivoTexto.close();
}

void generarArchivoBinarioDesdeTexto(const string& nombreArchivoTexto, const string& nombreArchivoBinario) {
    ifstream archivoTexto(nombreArchivoTexto);
    if (!archivoTexto.good()) {
        cout << "Error al abrir el archivo de texto\n";
        return;
    }
    ofstream archivoBinario(nombreArchivoBinario, ios::binary);
    if (!archivoBinario.good()) {
        cout << "Error al abrir el archivo binario para escritura\n";
        archivoTexto.close();
        return;
    }
    double numero;
    while (archivoTexto >> numero) {
        archivoBinario.write(reinterpret_cast<const char*>(&numero), sizeof(double));
    }
    cout << "Generacion de archivo binario desde texto exitosa. Resultado en '" << nombreArchivoBinario << "'\n";
    archivoTexto.close();
    archivoBinario.close();
}

