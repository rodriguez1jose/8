// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creacion: 25/11/2023

// Fecha modificación: 27/11/2023

// Numero de ejericio: 7

// Problema planteado: Escriba un programa que tenga como entrada un fichero que contenga un texto y dé como resultado una estadística del número de palabras.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int contarPalabras(const string& texto);

int main() {
    ifstream archivoEntrada("texto.txt");
    if (!archivoEntrada.good()) {
        cout << "Error al abrir el archivo de entrada.\n";
        return 1;
    }
    stringstream buffer;
    buffer << archivoEntrada.rdbuf();
    string texto = buffer.str();
    archivoEntrada.close();
    int numeroPalabras = contarPalabras(texto);
    cout << "Numero de palabras en el archivo: " << numeroPalabras << endl;
    return 0;
}
int contarPalabras(const string& texto) {
    istringstream iss(texto);
    int contador = 0;
    string palabra;
    while (iss >> palabra) {
        contador++;
    }
    return contador;
}

