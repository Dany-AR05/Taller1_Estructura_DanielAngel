#ifndef TALLER1_ESTRUCTURA_DANIELANGEL_NOTA_H
#define TALLER1_ESTRUCTURA_DANIELANGEL_NOTA_H
#include "Alumno.h"

class Alumno;

class Nota {
private:
    Alumno* alumno;
    float nota;
    Nota* siguiente;

public:
    Nota(Alumno* alumno, float nota);

    Alumno* getAlumno();
    float getNota();
    Nota* getSiguiente();
    void setSiguiente(Nota* siguiente);
};
#endif