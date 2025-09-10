#include <iostream>
#include "Alumno.h"
using namespace std;

class  NodoAlumno {
private:
    Alumno alumno;
    NodoAlumno* siguiente;

public:
    NodoAlumno(Alumno alumno) {
        this->alumno = alumno;
        this->siguiente = nullptr;
    }

    Alumno getAlumno() { return this->alumno; }
    void setAlumno(Alumno alumno){ this->alumno = alumno; }
    NodoAlumno* getSiguiente(){ return this->siguiente; }
    void setSiguiente(NodoAlumno* siguiente){ this->siguiente = siguiente; }
};

bool addAlumno(NodoAlumno*& head);
void buscarAlumno(NodoAlumno* head);
bool esString(string buscador);
bool eliminarAlumno(NodoAlumno*& head);


int main() {
    NodoAlumno* head = nullptr;

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
                cout << "1.- Add alumno" << endl;
                cout << "2.- Buscar alumno" << endl;
                cout << "3.- Eliminar alumno" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {
                        if (addAlumno(head)) {
                            cout << "Alumno Guardado Correctamente" << endl;
                        } else {
                            cout << "Alumno No Guardado" << endl;
                        }
                        break;
                    }
                    case 2: {
                        buscarAlumno(head);
                        break;

                    }
                    case 3: {
                        if (eliminarAlumno(head)) {
                            cout << "Alumno Eliminado Correctamente" << endl;
                        } else {
                            cout << "Alumno no eliminado" << endl;
                        }
                        break;

                    }
                }
                break;
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
                        break;

                    }
                    case 2: {
                        break;

                    }
                    case 3: {
                        break;

                    }
                }
                break;
            }

            case 3: {
                cout << "---Bienvenido al manejo de inscripciones---" << endl;
                cout << "1.- Inscribir un alumno a un curso" << endl;
                cout << "2.- Eliminar un alumno de un curso" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {
                        break;

                    }
                    case 2: {
                        break;

                    }
                }
                break;
            }

            case 4: {
                cout << "---Bienvenido al manejo de notas---" << endl;
                cout << "1.- Registrar notas" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {
                        break;

                    }
                }
                break;
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
                        break;

                    }
                    case 2: {
                        break;

                    }
                    case 3: {
                        break;

                    }
                    case 4: {
                        break;

                    }
                }
                break;
            }
        }
    }
}

bool addAlumno(NodoAlumno*& head) {
    string idString;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;
    cout << "Ingrese id : ";
    cin >> idString;
    if (esString(idString)) {
        cout << "Error id tiene que ser un numero" << endl;
        return false;
    }
    int id = stoi(idString);
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese apellido: ";
    cin >> apellido;
    cout << "Ingrese carrera: ";
    cin >> carrera;
    cout << "Ingrese fecha de ingreso: ";
    cin >> fechaIngreso;
    Alumno alumno(id, nombre, apellido, carrera, fechaIngreso);
    NodoAlumno* nuevoAlumno = new NodoAlumno(alumno);
    if (head==nullptr) {
        head=nuevoAlumno;
        return true;
    }

    NodoAlumno* aux = head;
    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }
    aux->setSiguiente(nuevoAlumno);
    return true;

}

void buscarAlumno(NodoAlumno* head) {
    string buscador;
    cout << "Ingrese un id o nombre: ";
    cin >> buscador;
    NodoAlumno* aux = head;
    while (aux != nullptr) {
        if (esString(buscador)) {
            if (aux->getAlumno().getNombre()==buscador) {
                cout << "Alumnos encontrados: " << endl;
                cout << aux->getAlumno().getId();
                cout << "---";
                cout << aux->getAlumno().getNombre();
                cout << "---";
                cout << aux->getAlumno().getApellido();
                cout << "---";
                cout << aux->getAlumno().getCarrera();
                cout << "---";
                cout << aux->getAlumno().getFechaIngreso() << endl;
            }
        } else {
            int buscadorId = stoi(buscador);
            if (aux->getAlumno().getId()==buscadorId) {
                cout << "Alumno encontrado: " << endl;
                cout << aux->getAlumno().getId();
                cout << "---";
                cout << aux->getAlumno().getNombre();
                cout << "---";
                cout << aux->getAlumno().getApellido();
                cout << "---";
                cout << aux->getAlumno().getCarrera();
                cout << "---";
                cout << aux->getAlumno().getFechaIngreso() << endl;
            }
        }
        aux = aux->getSiguiente();
    }
}

bool esString(string buscador) {
    for (char letra : buscador) {
        if (!isdigit(letra)) {
            return true;;
        }
    }
    return false;
}

bool eliminarAlumno(NodoAlumno*& head) {
    if (head == nullptr) {
        cout << "La lista esta vacia" << endl;
        return false;
    }

    string idString;
    cout << "Ingrese un id: ";
    cin >> idString;
    if (esString(idString)) {
        cout << "Error id tiene que ser un numero" << endl;
        return false;
    }
    int id = stoi(idString);

    NodoAlumno* aux = head;
    NodoAlumno* anterior = nullptr;
    while (aux!= nullptr) {
        if (aux->getAlumno().getId()==id) {
            if (anterior == nullptr) {
                head = aux->getSiguiente();
            } else {
                anterior->setSiguiente(aux->getSiguiente());
            }
            delete aux;
            return true;
        }
        anterior = aux;
        aux = aux->getSiguiente();
    }
    return false;
}