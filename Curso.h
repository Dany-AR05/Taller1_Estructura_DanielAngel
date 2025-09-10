#ifndef TALLER1_ESTRUCTURA_DANIELANGEL_CURSO_H
#define TALLER1_ESTRUCTURA_DANIELANGEL_CURSO_H
#include <string>
using namespace std;


class Curso {
private:
    int codigo;
    string nombre;
    int cantidadMax;
    string carrera;
    string profesor;

public:
    Curso();
    Curso(int codigo, string nombre, int cantidadMax, string carrera, string profesor);

    int getCodigo();
    string getNombre();
    int getCantidadMax();
    string getCarrera();
    string getProfesor();
};

#endif