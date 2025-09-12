#include <iostream>
#include "Alumno.h"

Alumno::Alumno(){};
Alumno::Alumno(int id, string nombre, string apellido, string carrera, string fechaIngreso) {
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->carrera = carrera;
    this->fechaIngreso = fechaIngreso;
    this->headInscripcion = nullptr;
}

int Alumno::getId() { return id; }
string Alumno::getNombre() { return nombre; }
string Alumno::getApellido() { return apellido; }
string Alumno::getCarrera() { return carrera; }
string Alumno::getFechaIngreso() { return fechaIngreso; }


Alumno::RefCurso::RefCurso(Curso *curso) {
    this->curso = curso;
    this->siguiente = nullptr;
}

Curso* Alumno::RefCurso::getCurso() {return this->curso;}
Alumno::RefCurso* Alumno::RefCurso::getSiguiente() {return this->siguiente;}
void Alumno::RefCurso::setSiguiente(RefCurso* curso) {  this->siguiente = siguiente;}


bool Alumno::inscribirCurso(Curso* curso) {
    RefCurso* nuevoCurso = new RefCurso(curso);
    if (headInscripcion==nullptr) {
        headInscripcion=nuevoCurso;
        return true;
    }
    RefCurso* aux = headInscripcion;

    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }
    aux->setSiguiente(nuevoCurso);
    return true;
}

bool Alumno::eliminarCurso(Curso* curso) {
    if (headInscripcion == nullptr) {
        cout << "La lista esta vacia" << endl;
        return false;
    }

    RefCurso* aux = headInscripcion;
    RefCurso* anterior = nullptr;
    while (aux!= nullptr) {
        if (aux->getCurso()==curso) {
            if (anterior == nullptr) {
                headInscripcion = aux->getSiguiente();
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
void Alumno::imprimirCursos() {
    if (headInscripcion==nullptr) {
        cout << "El alumno no esta en ningun curso" << endl;
        return;
    }

    cout << "El alumno: " << getNombre() << " " << getApellido() << " Esta inscrito en los siguientes cursos: " << endl;

    RefCurso* aux = headInscripcion;
    while (aux!= nullptr) {
        cout << aux->getCurso()->getNombre() << endl;
        aux = aux->getSiguiente();
        }
}

Curso* Alumno::tieneCurso(int codigo) {
    Curso* cursoSelec = nullptr;
    RefCurso* aux = headInscripcion;
    while (aux != nullptr) {
        if (aux->getCurso()->getCodigo()==codigo) {
            cursoSelec = aux->getCurso();
            return cursoSelec;
        }
        aux = aux->getSiguiente();
    }
    return cursoSelec;
}