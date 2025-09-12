#include <iostream>
#include "Alumno.h"
#include "Curso.h"
using namespace std;

class  NodoAlumno {
private:
    Alumno alumno;
    NodoAlumno* siguiente;

public:
    NodoAlumno(Alumno alumno) {
        this->alumno = alumno;
        this->siguiente = nullptr;
    }

    Alumno& getAlumno() { return this->alumno; }
    void setAlumno(Alumno alumno){ this->alumno = alumno; }
    NodoAlumno* getSiguiente(){ return this->siguiente; }
    void setSiguiente(NodoAlumno* siguiente){ this->siguiente = siguiente; }
};

class NodoCurso {
private:
    Curso curso;
    NodoCurso* siguiente;

public:
    NodoCurso(Curso curso) {
        this->curso = curso;
        this->siguiente = nullptr;
    }

    Curso& getCurso(){ return this->curso; }
    void setCurso(Curso curso){ this->curso = curso; }
    NodoCurso* getSiguiente(){ return this->siguiente; }
    void setSiguiente(NodoCurso* siguiente){ this->siguiente = siguiente; }
};

bool addAlumno(NodoAlumno*& head);
void buscarAlumno(NodoAlumno* head);
bool esString(string buscador);
bool eliminarAlumno(NodoAlumno*& head);
bool addCurso(NodoCurso*& head);
void buscarCurso(NodoCurso* head);
bool eliminarCurso(NodoCurso*& head);
bool inscripcionCurso(NodoCurso*& headCurso, NodoAlumno*& headAlumno);
bool eliminarInscripcion(NodoCurso*& headCurso, NodoAlumno*& headAlumno);
void imprimirAlumnosCarrera(NodoAlumno*& head);
void imprimirCursosAlumno(NodoAlumno*& head);
void registrarNota(NodoAlumno*& head);


int main() {
    NodoAlumno* headAlumno = nullptr;
    NodoCurso* headCurso = nullptr;

    int opcion = 10;
    int opcion2 = 10;
    while (opcion!=0) {
        cout << "1.- manejo de alumnos" << endl;
        cout << "2.- manejo de cursos" << endl;
        cout << "3.- manejo de inscripciones" << endl;
        cout << "4.- manejo de notas" << endl;
        cout << "5.- consultas y reportes" << endl;
        cout << "0.- Salir" << endl;
        cout << "Seleccione una opcion : ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "---Bienvenido al manejo de alumnos---" << endl;
                cout << "1.- Add alumno" << endl;
                cout << "2.- Buscar alumno" << endl;
                cout << "3.- Eliminar alumno" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {
                        if (addAlumno(headAlumno)) {
                            cout << "Alumno Guardado Correctamente" << endl;
                        } else {
                            cout << "Alumno No Guardado" << endl;
                        }
                        break;
                    }
                    case 2: {
                        buscarAlumno(headAlumno);
                        break;
                    }
                    case 3: {
                        if (eliminarAlumno(headAlumno)) {
                            cout << "Alumno Eliminado Correctamente" << endl;
                        } else {
                            cout << "Alumno no eliminado" << endl;
                        }
                        break;
                    }
                }
                break;
            }
            case 2: {
                cout << "---Bienvenido al manejo de cursos---" << endl;
                cout << "1.- Crear curso" << endl;
                cout << "2.- Buscar curso" << endl;
                cout << "3.- Eliminar curso" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {
                        if (addCurso(headCurso)) {
                            cout << "Curso Guardado Correctamente" << endl;
                        } else {
                            cout << "Curso No Guardado" << endl;
                        }
                        break;
                    }
                    case 2: {
                        buscarCurso(headCurso);
                        break;

                    }
                    case 3: {
                        if (eliminarCurso(headCurso)) {
                            cout << "Curso Eliminado Correctamente" << endl;
                        } else {
                            cout << "Curso no eliminado" << endl;
                        }
                        break;

                    }
                }
                break;
            }

            case 3: {
                cout << "---Bienvenido al manejo de inscripciones---" << endl;
                cout << "1.- Inscribir un alumno a un curso" << endl;
                cout << "2.- Eliminar un alumno de un curso" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {
                        if (inscripcionCurso(headCurso, headAlumno)) {
                            cout << "Inscripcion Correctamente" << endl;
                        } else {
                            cout << "Inscripcion Incorrecta" << endl;
                        }
                        break;

                    }
                    case 2: {
                        if (eliminarInscripcion(headCurso, headAlumno)) {
                            cout << "Inscripcion Eliminado Correctamente" << endl;
                        } else {
                            cout << "Inscripcion no eliminado" << endl;
                        }
                        break;
                    }
                }
                break;
            }

            case 4: {
                cout << "---Bienvenido al manejo de notas---" << endl;
                cout << "1.- Registrar notas" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {
                        registrarNota(headAlumno);
                        break;
                    }
                }
                break;
            }

            case 5: {
                cout << "---Bienvenido a consultas y reportes---" << endl;
                cout << "1.- Obtener todos los alumnos de una carrera" << endl;
                cout << "2.- Obtener todos los cursos en los que un alumno esta inscrito" << endl;
                cout << "3.- Calcular el promedio de notas de un alumno" << endl;
                cout << "4.- Calcular el promedio general de notas de un alumno" << endl;
                cout << "Seleccione una opcion : ";
                cin >> opcion2;

                switch (opcion2) {
                    case 1: {
                        imprimirAlumnosCarrera(headAlumno);
                        break;
                    }
                    case 2: {
                        imprimirCursosAlumno(headAlumno);
                        break;

                    }
                    case 3: {
                        break;

                    }
                    case 4: {
                        break;

                    }
                }
                break;
            }
        }
    }
}

bool addAlumno(NodoAlumno*& head) {
    string idString;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;
    cout << "Ingrese id : ";
    cin >> idString;
    if (esString(idString)) {
        cout << "Error id tiene que ser un numero" << endl;
        return false;
    }
    int id = stoi(idString);
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese apellido: ";
    cin >> apellido;
    cout << "Ingrese carrera: ";
    cin >> carrera;
    cout << "Ingrese fecha de ingreso: ";
    cin >> fechaIngreso;

    Alumno alumno(id, nombre, apellido, carrera, fechaIngreso);
    NodoAlumno* nuevoAlumno = new NodoAlumno(alumno);
    if (head==nullptr) {
        head=nuevoAlumno;
        return true;
    }

    NodoAlumno* aux = head;
    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }
    aux->setSiguiente(nuevoAlumno);
    return true;

}

void buscarAlumno(NodoAlumno* head) {
    string buscador;
    cout << "Ingrese un id o nombre: ";
    cin >> buscador;
    NodoAlumno* aux = head;
    cout << "Alumnos encontrados: " << endl;
    while (aux != nullptr) {
        if (esString(buscador)) {
            if (aux->getAlumno().getNombre()==buscador) {
                cout << aux->getAlumno().getId();
                cout << "---";
                cout << aux->getAlumno().getNombre();
                cout << "---";
                cout << aux->getAlumno().getApellido();
                cout << "---";
                cout << aux->getAlumno().getCarrera();
                cout << "---";
                cout << aux->getAlumno().getFechaIngreso() << endl;
            }
        } else {
            int buscadorId = stoi(buscador);
            if (aux->getAlumno().getId()==buscadorId) {
                cout << aux->getAlumno().getId();
                cout << "---";
                cout << aux->getAlumno().getNombre();
                cout << "---";
                cout << aux->getAlumno().getApellido();
                cout << "---";
                cout << aux->getAlumno().getCarrera();
                cout << "---";
                cout << aux->getAlumno().getFechaIngreso() << endl;
            }
        }
        aux = aux->getSiguiente();
    }
}

bool esString(string buscador) {
    for (char letra : buscador) {
        if (!isdigit(letra)) {
            return true;;
        }
    }
    return false;
}

bool eliminarAlumno(NodoAlumno*& head) {
    if (head == nullptr) {
        cout << "La lista esta vacia" << endl;
        return false;
    }

    string idString;
    cout << "Ingrese un id: ";
    cin >> idString;
    if (esString(idString)) {
        cout << "Error id tiene que ser un numero" << endl;
        return false;
    }
    int id = stoi(idString);

    NodoAlumno* aux = head;
    NodoAlumno* anterior = nullptr;
    while (aux!= nullptr) {
        if (aux->getAlumno().getId()==id) {
            if (anterior == nullptr) {
                head = aux->getSiguiente();
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

bool addCurso(NodoCurso*& head) {
    string codigoString;
    string nombre;
    string cantidadMaxString;
    string carrera;
    string profesor;
    cout << "Ingrese codigo : ";
    cin >> codigoString;
    if (esString(codigoString)) {
        cout << "Error codigo tiene que ser un numero" << endl;
        return false;
    }
    int codigo = stoi(codigoString);
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese cantidad maxima de estudiantes: ";
    cin >> cantidadMaxString;
    if (esString(cantidadMaxString)) {
        cout << "Error codigo tiene que ser un numero" << endl;
        return false;
    }
    int cantidadMax = stoi(cantidadMaxString);
    cout << "Ingrese carrera: ";
    cin >> carrera;
    cout << "Ingrese nombre del profesor: ";
    cin >> profesor;
    Curso curso(codigo, nombre, cantidadMax, carrera, profesor);

    NodoCurso* nuevoCurso = new NodoCurso(curso);

    if (head==nullptr) {
        head=nuevoCurso;
        return true;
    }

    NodoCurso* aux = head;
    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }
    aux->setSiguiente(nuevoCurso);
    return true;
}

void buscarCurso(NodoCurso* head) {
    string buscador;
    cout << "Ingrese un codigo o nombre: ";
    cin >> buscador;
    NodoCurso* aux = head;
    cout << "Cursos encontrados: " << endl;
    while (aux != nullptr) {
        if (esString(buscador)) {
            if (aux->getCurso().getNombre()==buscador) {
                cout << aux->getCurso().getCodigo();
                cout << "---";
                cout << aux->getCurso().getNombre();
                cout << "---";
                cout << aux->getCurso().getCantidadMax();
                cout << "---";
                cout << aux->getCurso().getCarrera();
                cout << "---";
                cout << aux->getCurso().getProfesor() << endl;
            }
        } else {
            int buscadorId = stoi(buscador);
            if (aux->getCurso().getCodigo()==buscadorId) {
                cout << aux->getCurso().getCodigo();
                cout << "---";
                cout << aux->getCurso().getNombre();
                cout << "---";
                cout << aux->getCurso().getCantidadMax();
                cout << "---";
                cout << aux->getCurso().getCarrera();
                cout << "---";
                cout << aux->getCurso().getProfesor() << endl;
            }
        }
        aux = aux->getSiguiente();
    }
}

bool eliminarCurso(NodoCurso*& head) {
    if (head == nullptr) {
        cout << "La lista esta vacia" << endl;
        return false;
    }

    string codigoString;
    cout << "Ingrese un codigo: ";
    cin >> codigoString;
    if (esString(codigoString)) {
        cout << "Error codigo tiene que ser un numero" << endl;
        return false;
    }
    int codigo = stoi(codigoString);

    NodoCurso* aux = head;
    NodoCurso* anterior = nullptr;
    while (aux!= nullptr) {
        if (aux->getCurso().getCodigo()==codigo) {
            if (anterior == nullptr) {
                head = aux->getSiguiente();
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

Alumno* existeAlumno(NodoAlumno* aux, int id) {
    Alumno* alumnoSelec = nullptr;
    while (aux != nullptr) {
        if (aux->getAlumno().getId()==id) {
            alumnoSelec = &aux->getAlumno();
            return alumnoSelec;
        }
        aux = aux->getSiguiente();
    }
    return alumnoSelec;
}

Curso* existeCurso(NodoCurso* aux, int codigo) {
    Curso* cursoSelec = nullptr;
    while (aux != nullptr) {
        if (aux->getCurso().getCodigo()==codigo) {
            cursoSelec = &aux->getCurso();
            return cursoSelec;
        }
        aux = aux->getSiguiente();
    }
    return cursoSelec;
}

bool inscripcionCurso(NodoCurso*& headCurso, NodoAlumno*& headAlumno) {
    string idString;
    cout << "Ingrese el id de la persona: ";
    cin >> idString;
    if (esString(idString)) {
        cout << "Error codigo tiene que ser un numero" << endl;
        return false;
    }
    int id = stoi(idString);
    string codigoString;
    cout << "Ingrese un codigo de el curso: ";
    cin >> codigoString;
    if (esString(codigoString)) {
        cout << "Error codigo tiene que ser un numero" << endl;
        return false;
    }
    int codigo = stoi(codigoString);

    Alumno* alumnoSelec = existeAlumno(headAlumno, id);
    Curso* cursoSelec = existeCurso(headCurso, codigo);


    if (alumnoSelec==nullptr || cursoSelec==nullptr) {
        return false;
    }

    if (cursoSelec->getCantidadMax()>=1 && cursoSelec->getCarrera()==alumnoSelec->getCarrera()) {
        if (alumnoSelec->inscribirCurso(cursoSelec)) {
            cursoSelec->setCantidadMax(cursoSelec->getCantidadMax()-1);
            return true;
        } else {
            return false;
        }
    }
}

bool eliminarInscripcion(NodoCurso*& headCurso, NodoAlumno*& headAlumno) {
    string idString;
    cout << "Ingrese el id de la persona: ";
    cin >> idString;
    if (esString(idString)) {
        cout << "Error codigo tiene que ser un numero" << endl;
        return false;
    }
    int id = stoi(idString);
    string codigoString;
    cout << "Ingrese un codigo de el curso: ";
    cin >> codigoString;
    if (esString(codigoString)) {
        cout << "Error codigo tiene que ser un numero" << endl;
        return false;
    }
    int codigo = stoi(codigoString);

    Alumno* alumnoSelec = existeAlumno(headAlumno, id);
    Curso* cursoSelec = existeCurso(headCurso, codigo);

    if (alumnoSelec==nullptr || cursoSelec==nullptr) {
        return false;
    }

    if (alumnoSelec->eliminarCurso(cursoSelec)) {
        cursoSelec->setCantidadMax(cursoSelec->getCantidadMax()+1);
        return true;
    } else {
        return false;
    }
}

void imprimirAlumnosCarrera(NodoAlumno*& head) {
    string carrera;
    cout << "Ingrese nombre de la carrera: ";
    cin >> carrera;

    NodoAlumno* aux= head;
    bool existe = false;
    while (aux != nullptr) {
        if (aux->getAlumno().getCarrera()==carrera) {
            cout << "Alumno: " << aux->getAlumno().getNombre() << " " <<aux->getAlumno().getApellido() << "Inscrito en la carrera" << endl;
            existe = true;
        }
        aux = aux->getSiguiente();
    }
    if (!existe) {
        cout << "No existe ningun alumno en la carrera" << endl;
    }
}

void imprimirCursosAlumno(NodoAlumno*& head) {
    string idString;
    cout << "Ingrese el id de la persona: ";
    cin >> idString;
    if (esString(idString)) {
        cout << "Error id que ser un numero" << endl;
        return;
    }
    int id = stoi(idString);

    Alumno* alumnoSelec = existeAlumno(head, id);

    if (alumnoSelec==nullptr) {
        cout << "No existe ningun alumno con esa id" << endl;
        return;
    }
    alumnoSelec->imprimirCursos();
}

void registrarNota(NodoAlumno*& head) {
    string idString;
    cout << "Ingrese el id de la persona: ";
    cin >> idString;
    if (esString(idString)) {
        cout << "Error id tiene que ser un numero" << endl;
        return;
    }
    int id = stoi(idString);
    string codigoString;
    cout << "Ingrese el codigo de el curso: ";
    cin >> codigoString;
    if (esString(codigoString)) {
        cout << "Error codigo tiene que ser un numero" << endl;
        return;
    }
    int codigo = stoi(codigoString);
    Alumno* alumnoSelec = existeAlumno(head, id);
    if (alumnoSelec==nullptr) {
        return;
    }
    Curso* cursoSelec = alumnoSelec->tieneCurso(codigo);
    if (cursoSelec==nullptr) {
        return;
    }

    float nota;
    char opcion = 's';
    while (opcion == 's') {
        cout << "Ingrese la nota de el curso: ";
        cin >> nota;
        if (cursoSelec->registrarNota(alumnoSelec, nota)) {
            cout << "Nota registrada correctamente" << endl;
        } else {
            cout << "Nota no registrada" << endl;
        }
        cout << "Quiere seguir ingresando notas? (s/n): ";
        cin >> opcion;
    }
}

