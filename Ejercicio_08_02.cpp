// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creacion: 25/11/2023

// Fecha modificación: 27/11/2023

// Numero de ejericio: 2

// Problema planteado: Escriba un programa que cree un fichero de texto llamado "PERSONAS.BIN" en el que se guarde la información de un número indeterminado de personas.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Persona {
    string nombre;
    int edad;
    char sexo;
    string fechaNacimiento;
};

const char* archivo = "PERSONAS.BIN";

void crearArchivoPersonas();
void procesarCandidatos();
bool esAceptable(const Persona& candidato);
void mostrarAceptados();

int main() {
    crearArchivoPersonas();
    procesarCandidatos();
    mostrarAceptados();

    return 0;
}

void crearArchivoPersonas() {
    ofstream archivoPersonas(archivo, ios::binary | ios::app);

    if (!archivoPersonas.good()) {
        cout << "Error al abrir el archivo de personas.\n";
        return;
    }
    cout <<"Ingrese la informacion de las personas.\n";
    Persona persona;
    do {
        cout << "Nombre (ingrese un espacio para finalizar): ";
        getline(cin, persona.nombre);
        if (persona.nombre != " ") {
            cout <<"Edad: ";
            cin >> persona.edad;
            cout <<"Sexo (M/F): ";
            cin >> persona.sexo;
            cout<<"Fecha de Nacimiento (dd/mm/yyyy): ";
            cin>>persona.fechaNacimiento;
            archivoPersonas.write(reinterpret_cast<char*>(&persona), sizeof(Persona));
            cin.ignore();
        }
    } while (persona.nombre != " ");
    archivoPersonas.close();
}
void procesarCandidatos() {
    ifstream archivoPersonas(archivo, ios::binary);
    if (!archivoPersonas.good()) {
        cout << "Error al abrir el archivo de personas.\n";
        return;
    }
    ofstream archivoAceptados("ACEPTADOS.DAT", ios::binary);
    if (!archivoAceptados.good()) {
        cout << "Error al abrir el archivo de aceptados.\n";
        archivoPersonas.close();
        return;
    }
    Persona candidato;
    while (archivoPersonas.read(reinterpret_cast<char*>(&candidato), sizeof(Persona))) {
        if (esAceptable(candidato)) {
            archivoAceptados.write(reinterpret_cast<char*>(&candidato), sizeof(Persona));
        }
    }
    archivoPersonas.close();
    archivoAceptados.close();
}

bool esAceptable(const Persona& candidato) {
    return candidato.sexo != 'M' && candidato.fechaNacimiento.substr(3, 7) == "06/2023";
}

void mostrarAceptados() {
    ifstream archivoAceptados("ACEPTADOS.DAT", ios::binary);
    if (!archivoAceptados.good()) {
        cout << "Error al abrir el archivo de aceptados.\n";
        return;
    }
    cout << "\nCandidatos Aceptados:\n";
    Persona aceptado;
    while (archivoAceptados.read(reinterpret_cast<char*>(&aceptado), sizeof(Persona))) {
        cout<<"Nombre: "<<aceptado.nombre<<", Edad: "<< aceptado.edad<<", Sexo: "<<aceptado.sexo <<", Fecha de Nacimiento: "<<aceptado.fechaNacimiento<<endl;
    }
    archivoAceptados.close();
}

