#include "Curso.h"
#include <iostream>

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
Nota *Curso::getHeadNotas() {return this->headNotas;}


bool Curso::registrarNota(Alumno* alumno, float nota) {
    if (nota<1.0 || nota>7.0) {
        cout << "Nota invalido" << endl;
        return false;
    }

    Nota* notaNueva = new Nota(alumno, nota);

    if (headNotas==nullptr) {
        headNotas=notaNueva;
        return true;
    }

    Nota* aux = headNotas;
    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }
    aux->setSiguiente(notaNueva);
    return true;
}

float Curso::promedioNotas(Alumno* alumno) {
    float promedio = 0;
    int contador= 0;

    if (headNotas==nullptr) {
        cout << "El alumno no tiene notas registradas" << endl;
        return 0.0;
    }

    Nota* aux = headNotas;
    while (aux!= nullptr) {
        if (aux->getAlumno() == alumno) {
            promedio = promedio + aux->getNota();
            contador++;
        }
        aux = aux->getSiguiente();
    }
    if (contador==0) {
        cout << "El alumno no tiene notas registradas" << endl;
        return 0.0;
    }
    return promedio / contador;
}
