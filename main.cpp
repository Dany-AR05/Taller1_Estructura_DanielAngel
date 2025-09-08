#include <iostream>
#include "alumno.h"
using namespace std;

class  NodoAlumno {
private:
    Alumno alumno;
    NodoAlumno* siguiente;

public:
    /*NodoAlumno(Alumno alumno, NodoAlumno* siguiente) {
        this->alumno = alumno;
        this->siguiente = siguiente;
    }*/

    Alumno getAlumno() { return this->alumno; }
    void setAlumno(Alumno alumno){ this->alumno = alumno; }
    NodoAlumno* getSiguiente(){ return this->siguiente; }
    void setSiguiente(NodoAlumno* siguiente){ this->siguiente = siguiente; }
};

int main() {
    Alumno* listaAlumnos = nullptr;

    int opcion = 10;
    int opcion2 = 10;
    while (opcion!=0) {
        cout << "1.- manejo de alumnos" << endl;
        cout << "2.- manejo de cursos" << endl;
        cout << "3.- manejo de inscripciones" << endl;
        cout << "4.- manejo de notas" << endl;
        cout << "5.- consultas y reportes" << endl;
        cout << "0.- Salir" << endl;
        cout << "Seleccione una opcion : ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "---Bienvenido al manejo de alumnos---" << endl;
                cout << "1.- Añadir alumno" << endl;
                cout << "2.- Buscar alumno" << endl;
                cout << "3.- Eliminar alumno" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {

                    }
                    case 2: {

                    }
                    case 3: {

                    }
                }
            }

            case 2: {
                cout << "---Bienvenido al manejo de cursos---" << endl;
                cout << "1.- Crear curso" << endl;
                cout << "2.- Buscar curso" << endl;
                cout << "3.- Eliminar curso" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {

                    }
                    case 2: {

                    }
                    case 3: {

                    }
                }
            }

            case 3: {
                cout << "---Bienvenido al manejo de inscripciones---" << endl;
                cout << "1.- Inscribir un alumno a un curso" << endl;
                cout << "2.- Eliminar un alumno de un curso" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {

                    }
                    case 2: {

                    }
                }
            }

            case 4: {
                cout << "---Bienvenido al manejo de notas---" << endl;
                cout << "1.- Registrar notas" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {

                    }
                }
            }

            case 5: {
                cout << "---Bienvenido a consultas y reportes---" << endl;
                cout << "1.- Obtener todos los alumnos de una carrera" << endl;
                cout << "2.- Obtener todos los cursos en los que un alumno esta inscrito" << endl;
                cout << "3.- Calcular el promedio de notas de un alumno" << endl;
                cout << "4.- Calcular el promedio general de notas de un alumno" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {

                    }
                    case 2: {

                    }
                    case 3: {

                    }
                    case 4: {

                    }
                }
            }
        }
    }
}

bool añadirAlumno() {
    int id;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;
    cout << "Ingrese id : ";
    cin >> id;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese apellido: ";
    cin >> apellido;
    cout << "Ingrese carrera: ";
    cin >> carrera;
    cout << "Ingrese fecha de ingreso: ";
    cin >> fechaIngreso;
    //Alumno alumno = new Alumno(id, nombre, apellido, carrera, fechaIngreso);

    return true;

}
