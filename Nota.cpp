#include "Nota.h"

Nota::Nota(Alumno* alumno, float nota) {
    this->alumno = alumno;
    this->nota = nota;
    this->siguiente = nullptr;
}

Alumno* Nota::getAlumno() { return this->alumno;}
float Nota::getNota() { return this->nota;}
Nota* Nota::getSiguiente() { return this->siguiente;}
void Nota::setSiguiente(Nota* siguiente) { this->siguiente = siguiente;}