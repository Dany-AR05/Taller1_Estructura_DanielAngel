#include "Curso.h"

Curso::Curso(){};
Curso::Curso(int codigo, string nombre, int cantidadMax, string carrera, string profesor) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->cantidadMax = cantidadMax;
    this->carrera = carrera;
    this->profesor = profesor;
};

int Curso::getCodigo(){return codigo;};
string Curso::getNombre(){return nombre;};
int Curso::getCantidadMax(){return cantidadMax;};
string Curso::getCarrera(){return carrera;};
string Curso::getProfesor() {return profesor;};
void Curso::setCantidadMax(int cantidadMax){ this->cantidadMax = cantidadMax;};
