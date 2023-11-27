// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creacion: 26/11/2023

// Fecha modificación: 27/11/2023

// Numero de ejericio: 9

// Problema planteado: Dado una tabla grabada en un fichero en formato binario <nombre>.BIN hallar la suma
// horizontal y vertical y grabar la tabla y los resultados en otro fichero de texto o binario según se
// introduzca por pantalla. 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

void sumarHorizontalYVertical(const string& nombreArchivoTexto, const string& nombreArchivoSalida);
void mostrarArchivoSalida(const string& nombreArchivo);

int main() {
    const string nombreArchivoTexto = "entrada.txt";
    const string nombreArchivoSalida = "salida.txt";

    sumarHorizontalYVertical(nombreArchivoTexto, nombreArchivoSalida);
    mostrarArchivoSalida(nombreArchivoSalida);

    return 0;
}

void sumarHorizontalYVertical(const string& nombreArchivoTexto, const string& nombreArchivoSalida) {
    ifstream archivoTexto(nombreArchivoTexto);

    if (!archivoTexto.good()) {
        cout << "Error al abrir el archivo de texto.\n";
        return;
    }
    ofstream archivoSalida(nombreArchivoSalida);
    if (!archivoSalida.good()) {
        cout << "Error al abrir el archivo de salida.\n";
        archivoTexto.close();
        return;
    }
    vector<vector<double>> tabla;
    double numero;
    while (archivoTexto >> numero) {
        tabla.push_back({numero});
    }
    archivoTexto.close();
    for (const auto& fila : tabla) {
        double sumaHorizontal = 0;
        for (double valor : fila) {
            sumaHorizontal += valor;
        }
        fila.push_back(sumaHorizontal);
    }
    for (size_t i = 0; i < tabla[0].size(); ++i) {
        double sumaVertical = 0;
        for (size_t j = 0; j < tabla.size(); ++j) {
            sumaVertical += tabla[j][i];
        }
        tabla[0].push_back(sumaVertical);
    }
    for (const auto& fila : tabla) {
        for (double valor : fila) {
            archivoSalida << fixed << setprecision(2) << valor << "\t";
        }
        archivoSalida << "\n";
    }
    archivoSalida.close();
    cout << "Suma horizontal y vertical realizada con exito. Resultado en '" << nombreArchivoSalida << "'.\n";
}
void mostrarArchivoSalida(const string& nombreArchivo) {
    ifstream archivoSalida(nombreArchivo);
    if (!archivoSalida.good()) {
        cout << "Error al abrir el archivo de salida\n";
        return;
    }
    cout << "\nContenido del archivo de salida:\n";
    string linea;
    while (getline(archivoSalida, linea)) {
        cout << linea << "\n";
    }
    archivoSalida.close();
}

