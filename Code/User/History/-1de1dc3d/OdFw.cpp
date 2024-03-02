#include <iostream>
#include <stdint.h>
#include "Estudiante.h"
#include "Asignatura.h"
#include "Inscripcion.h"

#define NUMAXEST 5
#define NUMAXASIG 5
#define NUMAXINS 5

using namespace std;

int mostrarMenu() {
    int opcion = 0;

    cout << "seleccione la accion a realizar: " << endl;
    cout << "1. Agregar estudiante" << endl;
    cout << "2. Agregar asignatura" << endl;
    cout << "3. Hacer inscripciones" << endl;
    cout << "4. Mostrar lista de estudiantes" << endl;
    cout << "5. Mostrar lista de asignaturas" << endl;
    cout << "6. Mostrar lista de inscripciones" << endl;
    cout << "7. Ver detalles de la inscripcion" << endl;
    cout << "8. Salir" << endl;

    cin >> opcion;
    return opcion;
}

Estudiante buscarEstudiante(Estudiante listaEstudiantes[], int contadorEstudiantes, int codigoEstudiante) {
    Estudiante estudiante;

    for(int i = 0; i < contadorEstudiantes; i++) {
        if(listaEstudiantes[i].getCodigo() == codigoEstudiante) {
            estudiante = listaEstudiantes[i];
        }
    }

    return estudiante;
}

Asignatura buscarMateria(Asignatura listaAsignaturas[], int contadorAsignatura, int codigoMateria) {
    Asignatura asignatura;

    for(int i = 0; i < contadorAsignatura; i++) {
        if(listaAsignaturas[i].getCodigo() == codigoMateria) {
            asignatura = listaAsignaturas[i];
        }
    }

    return asignatura;
}

Inscripcion buscarInscripcion(Inscripcion listaInscripciones[], int contadorInscripcion, int idInscripcion) {
    Inscripcion inscripcion;

    for(int i = 0; i < contadorInscripcion; i++) {
        if(listaInscripciones[i].getIdInscripcion() == idInscripcion) {
            inscripcion = listaInscripciones[i];
        }
    }

    return inscripcion;
}

Estudiante agregarEstudiante() {
    int codigo;
    string nombre, apellido;
    cout << "digite el codigo del estudiante: " << endl;
    cin >> codigo;

    cout << "digite el nombre del estudiante: " << endl;
    cin >> nombre;

    cout << "digite el apellido del estudiante: " << endl;
    cin >> apellido;

    Estudiante estudiante(codigo, nombre, apellido);
    return estudiante;
}

Asignatura agregarAsignatura() {
    int codigo;
    string nombre;
    cout << "digite el codigo de la asignatura" << endl;
    cin >> codigo;

    cout << "digite el nombre de la asignatura" << endl;
    cin >> nombre;

    Asignatura asignatura(codigo, nombre);
    return asignatura;
}

Inscripcion agregarInscripcion(Estudiante listaEstudiantes[], int contadorEstudiantes, Asignatura listaAsignaturas[], int contadorAsignatura) {
    int codigoEstudiante, idInscripcion, codigoMateria;
    string cicloAcademico;
    Estudiante estudiante;
    Asignatura materia;

    cout << "digite el codigo del estudiante a inscribir" << endl;
    cin >> codigoEstudiante;

    estudiante = buscarEstudiante(listaEstudiantes, contadorEstudiantes, codigoEstudiante);

    if(estudiante.getCodigo() != 0) {
        cout << "digite el Id de la inscripcion" << endl;
        cin >> idInscripcion;
        cout << "digite el ciclo academico" << endl;
        cin >> cicloAcademico;
    } else {
        cout << "estudiante no encontrado";
    }

    Inscripcion inscripcion(idInscripcion, estudiante, cicloAcademico);

    int opcion = 1;
    do {
        cout << "digite el codigo de la materia a inscribir: " << endl;
        cin >> codigoMateria;

        materia = buscarMateria(listaAsignaturas, contadorAsignatura, codigoMateria);

        if(materia.getCodigo() != 0) {
            inscripcion.agregarAsignatura(materia);
            cout << "la materia se inscribio exitosamente" << endl;
        } else {
            cout << "materia no encontrada..." << endl;
        }

        cout << "�desea agregar otra materia?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cin >> opcion;

    } while(opcion == 1);

    return inscripcion;
}

void mostrarListaEstudiantes(Estudiante listaEstudiantes[], int contadorEstudiantes) {
    if(contadorEstudiantes != 0) {
        cout << "Codigo\tNombre\tApellido" << endl;
        for(int i = 0; i < contadorEstudiantes; i++) {
            cout << listaEstudiantes[i].getCodigo() << "\t";
            cout << listaEstudiantes[i].getNombre() << "\t";
            cout << listaEstudiantes[i].getApellido() << "\n";
        }
    } else {
        cout << "lista de estudiantes vacia" << endl;
    }
}

void mostrarListaMaterias(Asignatura listaMateria[], int contadorMateria) {
    if(contadorMateria != 0) {
        cout << "Codigo\tNombre\t" << endl;
        for(int i = 0; i < contadorMateria; i++) {
            cout << listaMateria[i].getCodigo() << "\t";
            cout << listaMateria[i].getNomAsignatura() << "\n";
        }
    } else {
        cout << "lista de materias vacia vacia" << endl;
    }
}

void mostrarListaInscripcion(Inscripcion listaInscripcion[], int contadorInscripcion) {
    if(contadorInscripcion != 0) {
        cout << "Id\tCodigo estudiante\tCiclo" << endl;
        for(int i = 0; i < contadorInscripcion; i++) {
            cout << listaInscripcion[i].getIdInscripcion() << "\t";
            cout << listaInscripcion[i].getEstudiante().getCodigo() << "\t";
            cout << listaInscripcion[i].getCicloAcademico() << "\n";
        }
    } else {
        cout << "lista de inscripciones vacias" << endl;
    }
}

void mostrarDetallesInscripcion(Inscripcion listaInscripciones[], int contadorInscripciones, int idInscripcion) {
    Inscripcion inscripcion = buscarInscripcion(listaInscripciones, contadorInscripciones, idInscripcion);

    if(inscripcion.getIdInscripcion() != 0) {
        cout << "estudiante: " << inscripcion.getEstudiante().getNombre() << " " << inscripcion.getEstudiante().getApellido() << endl;
        cout << "ciclo academico: " << inscripcion.getCicloAcademico() << endl;

        if(inscripcion.getContAsig() != 0) {
            cout << "lista de materias: " << endl;
            cout << "Codigo\tNombre\t" << endl;
            Asignatura *listaMaterias = inscripcion.getMateriasInscritas();
            for(int i = 0; i < inscripcion.getContAsig(); i++) {
                cout << listaMaterias[i].getCodigo() << "\t";
                cout << listaMaterias[i].getNomAsignatura() << "\n";
            }
        } else {
            cout << "no hay materias inscritas";
        }
    } else {
        cout << "inscripcion no encontrada";
    }


}

int main()
{
    int opcion, contadorEstudiantes = 0, contadorAsignaturas = 0, contadorInscripciones = 0;
    Estudiante listaEstudiantes[NUMAXEST];
    Asignatura listaAsignaturas[NUMAXASIG];
    Inscripcion listaDeInscripciones[NUMAXINS];

    do {
        system("cls");

        opcion = mostrarMenu();
        switch(opcion) {
            case 1:
                if(contadorEstudiantes < NUMAXEST) {
                    listaEstudiantes[contadorEstudiantes] = agregarEstudiante();
                    contadorEstudiantes++;
                    cout << "estudiante agregado exitosamente";
                } else {
                    cout << "la lista de estudiantes esta llena" << endl;
                }

                break;

            case 2:
                if(contadorAsignaturas < NUMAXASIG) {
                    listaAsignaturas[contadorAsignaturas] = agregarAsignatura();
                    contadorAsignaturas++;
                    cout << "asignatura agregada exitosamente";
                } else {
                    cout << "la lista de asignaturas esta llena" << endl;
                }
                break;

            case 3:
                if(contadorInscripciones < NUMAXINS) {
                    Inscripcion inscripcion = agregarInscripcion(listaEstudiantes, contadorEstudiantes, listaAsignaturas, contadorAsignaturas);

                    if(inscripcion.getIdInscripcion() != 0) {
                        listaDeInscripciones[contadorInscripciones] = inscripcion;
                        contadorInscripciones++;
                        cout << "la incripcion se realizo con exito";
                    } else {
                        cout << "ocurrio un error durante la inscripcion";
                    }
                }

                break;
            case 4:
                mostrarListaEstudiantes(listaEstudiantes, contadorEstudiantes);
                break;
            case 5:
                mostrarListaMaterias(listaAsignaturas, contadorAsignaturas);
                break;
            case 6:
                mostrarListaInscripcion(listaDeInscripciones, contadorInscripciones);
                break;
            case 7:
                int idInscripcion;
                cout << "digite el Id de la inscripcion a consultar: " << endl;
                cin >> idInscripcion;
                mostrarDetallesInscripcion(listaDeInscripciones, contadorInscripciones, idInscripcion);
                break;
            case 8:
                break;
            default:
                cout << "opcion invalida";
                break;
        }

        system("pause");

    } while(opcion != 8);
    return 0;
}
