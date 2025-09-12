#ifndef TALLER1_ESTRUCTURA_DANIELANGEL_ALUMNO_H
#define TALLER1_ESTRUCTURA_DANIELANGEL_ALUMNO_H
#include <string>
#include "Curso.h"
using namespace std;

class Alumno {
private:
    int id;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;

    class RefCurso {
    private:
        Curso* curso;
        RefCurso* siguiente;

    public:
        RefCurso(Curso* curso);

        Curso* getCurso();
        RefCurso* getSiguiente();
        void setSiguiente(RefCurso* curso);
    };

    RefCurso* headInscripcion;

public:
    Alumno();
    Alumno(int id, string nombre, string apellido, string carrera, string fechaIngreso);
    int getId();
    string getNombre();
    string getApellido();
    string getCarrera();
    string getFechaIngreso();

    bool inscribirCurso(Curso* curso);
    bool eliminarCurso(Curso* curso);
    void imprimirCursos();
};


#endif