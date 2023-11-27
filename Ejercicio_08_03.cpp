// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creacion: 25/11/2023

// Fecha modificación: 27/11/2023

// Numero de ejericio: 3

// Problema planteado: Amplíe el programa anterior que procesa clientes de una agencia matrimonial para que tome
//los datos de todos los candidatos a estudiar del fichero PERSONAS.DAT del ejercicio anterior,
//lea el cliente del teclado y finalmente genere como resultado un listado por pantalla con los
// nombres de los candidatos aceptados y un fichero llamado ACEPTADOS.DAT

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
const char* archivoAceptados= "ACEPTADOS.DAT";
void mostrarCandidatos();

int main() {
    mostrarCandidatos();

    return 0;
}
void mostrarCandidatos() {
    ifstream archivoAceptados(NOMBRE_ARCHIVO_ACEPTADOS, ios::binary);
    if (!archivoAceptados.good()) {
        cout<<"Error al abrir el archivo de aceptados.\n";
        return;
    }

    cout<<"\nListado de Candidatos Aceptados:\n";
    Persona aceptado;
    while (archivoAceptados.read(reinterpret_cast<char*>(&aceptado), sizeof(Persona))) {
        cout<<"Nombre: "<<aceptado.nombre<<", Edad: "<<aceptado.edad<<", Sexo: "<<aceptado.sexo<<", Fecha de Nacimiento: "<<aceptado.fechaNacimiento<<endl;
    }
    archivoAceptados.close();
}

