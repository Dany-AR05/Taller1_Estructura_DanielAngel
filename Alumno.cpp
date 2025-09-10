#include "Alumno.h"

Alumno::Alumno(){};
Alumno::Alumno(int id, string nombre, string apellido, string carrera, string fechaIngreso) {
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->carrera = carrera;
    this->fechaIngreso = fechaIngreso;
}

int Alumno::getId() { return id; }
string Alumno::getNombre() { return nombre; }
string Alumno::getApellido() { return apellido; }
string Alumno::getCarrera() { return carrera; }
string Alumno::getFechaIngreso() { return fechaIngreso; }