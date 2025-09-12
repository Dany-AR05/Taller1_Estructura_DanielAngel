#ifndef TALLER1_ESTRUCTURA_DANIELANGEL_CURSO_H
#define TALLER1_ESTRUCTURA_DANIELANGEL_CURSO_H
#include <string>
#include "Nota.h"
#include "Alumno.h"

class Nota;
class Alumno;

using namespace std;

class Curso {
private:
    int codigo;
    string nombre;
    int cantidadMax;
    string carrera;
    string profesor;
    Nota* headNotas;

public:
    Curso();
    Curso(int codigo, string nombre, int cantidadMax, string carrera, string profesor);

    int getCodigo();
    string getNombre();
    int getCantidadMax();
    string getCarrera();
    string getProfesor();
    void setCantidadMax(int cantidadMax);
    bool registrarNota(Alumno* alumno, float nota);
};
#endif