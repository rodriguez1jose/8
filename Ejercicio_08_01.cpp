// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creacion: 24/11/2023

// Fecha modificación: 27/11/2023

// Numero de ejericio: 1

// Problema planteado: Escribir un programa con la opción de encriptar y de desencriptar un fichero de texto. La encriptación consiste en que dado un fichero de texto de entrada genere otro fichero de lalida de extensión <nombre>.COD donde el texto estará codificado (encriptado).

#include<iostream>
#include <fstream>
#include <string>

using namespace std;

void encriptarArchivo(const string& nombreArchivo);
void desencriptarArchivo(const string& nombreArchivo);

int main() {
    cout<<"Ingrese el nombre del archivo (incluyendo la extencion): ";
    string nombreArchivo;
    getline(cin, nombreArchivo);
    int opcion;
    cout << "Seleccione una opcion:\n";
    cout << "1.Encriptar\n";
    cout << "2.Desencriptar\n";
    cout <<"Opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            encriptarArchivo(nombreArchivo);
            break;
        case 2:
            desencriptarArchivo(nombreArchivo);
            break;
        default:
            cout<<"Opcion no valida.\n";
    }

    return 0;
}

void encriptarArchivo(const string& nombreArchivo) {
    ifstream archivoEntrada(nombreArchivo);

    if (!archivoEntrada.open()) {
        cout << "Error al abrir el archivo de entrada.\n";
        return;
    }
    string nombreArchivoSalida = nombreArchivo + ".COD";
    ofstream archivoSalida(nombreArchivoSalida);

    if (!archivoSalida.open()) {
        cout << "Error al abrir el archivo de salida.\n";
        archivoEntrada.close();
        return;
    }
    char letra;
    while (archivoEntrada.get(letra)) {
        letra += 3;
        archivoSalida.put(letra);
    }
    cout<<"Encriptacion exitosa. Archivo encriptado: " << nombreArchivoSalida << "\n";
    archivoEntrada.close();
    archivoSalida.close();
}

void desencriptarArchivo(const string& nombreArchivo) {
    ifstream archivoEntrada(nombreArchivo);

    if (!archivoEntrada.open()) {
        cout << "Error al abrir el archivo de entrada.\n";
        return;
    }
    string nombreArchivoSalida = nombreArchivo.substr(0, nombreArchivo.size() - 4);
    ofstream archivoSalida(nombreArchivoSalida);

    if (!archivoSalida.open()) {
        cout << "Error al abrir el archivo de salida.\n";
        archivoEntrada.close();
        return;
    }
    char letra;
    while (archivoEntrada.get(letra)) {
        letra -= 3;
        archivoSalida.put(letra);
    }
    cout << "Desencriptacion exitosa. Archivo desencriptado: " << nombreArchivoSalida << "\n";
    archivoEntrada.close();
    archivoSalida.close();
}

