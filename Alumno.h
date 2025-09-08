#ifndef TALLER1_ESTRUCTURA_DANIELANGEL_ALUMNO_H
#define TALLER1_ESTRUCTURA_DANIELANGEL_ALUMNO_H
#include <string>
using namespace std;

class Alumno {
private:
    int id;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;

public:
    Alumno(int id, string nombre, string apellido, string carrera, string fechaIngreso);
    int getId();
    string getNombre();
    string getApellido();
    string getCarrera();
    string getFechaIngreso();
};
#endif