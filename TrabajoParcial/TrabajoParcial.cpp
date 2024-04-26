#include <iostream>

using namespace std;

#include "Lista.h"
#include "Persona.h"
#include "Parentezco.h"
#include "Profesor.h"
#include "Curso.h"

Lista<CParentezco*>* arrParentezco = new Lista<CParentezco*>();
Lista<CProfesor*>* arrProfesor = new Lista<CProfesor*>();
CCurso* pCursos = new CCurso();

void ingresarAlumno(int iPos)
{
	string nom_pa, ape_pa, cod_pa, tip_pa;
	string nom_al, ape_al, cod_al; 
	int grad_al;

	cout << "\n";
	cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
	cout << "     REGISTRAR DATOS DE ALUMNO       " << endl;
	cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;

	cout << endl;

	cout << "Ingresar el nombre padre: "; cin >> nom_pa;
	cout << "Ingresar el apellido padre: "; cin >> ape_pa;
	cout << "Ingresar codigo padre: "; cin >> cod_pa;
	cout << "Ingresar tipo padre: "; cin >> tip_pa;

	cout << "Ingresar el nombre alumno: "; cin >> nom_al;
	cout << "Ingresar el apellido alumno: "; cin >> ape_al;
	cout << "Ingresar codigo alumno: "; cin >> cod_al;
	cout << "Ingresar grado alumno: "; cin >> grad_al;

	CPadre* pPadre = new CPadre(nom_pa, ape_pa, cod_pa, tip_pa);
	CAlumno* pAlumno = new CAlumno(nom_al, ape_al, cod_al, grad_al);
	pCursos->asignarCursoAlumno(pAlumno, grad_al);

	CParentezco* pParentezco = new CParentezco(pAlumno, pPadre);
	arrParentezco->agregaPos(pParentezco, iPos);
}

void ingresarProfesor(int iPos)
{
	string nom, ape, cod;
	int ele;
	cout << "\n";
	cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
	cout << "     REGISTRAR DATOS DE PROFESOR       " << endl;
	cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;

	cout << endl;

	cout << "Ingresar el nombre profesor: "; cin >> nom;
	cout << "Ingresar el apellido profesor: "; cin >> ape;
	cout << "Ingresar codigo profesor: "; cin >> cod;

	CProfesor* pProfesor = new CProfesor(nom, ape, cod);
	pCursos->asignarCursoProfesor(pProfesor);
	cout << "\n";
	cout << " -------------------------------------" << endl;
	cout << "|<1> Calificar Alumno                 |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "|<2> Citar Tutor                      |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Elegir: ";
	cin >> ele;

	switch(ele) 
	{
		case 1:
		{
			int indices_al = 0;

			Lista<CAlumno*>* arrAlumnos = pCursos->obtenerCursos(pProfesor, arrParentezco);

			for (size_t i = 0; i < arrAlumnos->longitud(); i++)
			{
				CAlumno* pAlumno = arrAlumnos->obtenerPos(i);

				cout << "ALUMNO: " << i + 1 << endl;
				cout << "NOMBRE DEL ALUMNO: " << pAlumno->getNombre() << endl;
				cout << "APELLIDO DEL ALUMNO: " << pAlumno->getApellido() << endl;
				cout << "CODIGO DE ALUMNO: " << pAlumno->getCodigo() << endl;
				cout << "GRADO DEL ALUMNO: " << pAlumno->getGrado() << endl;
				cout << endl;
			}

			//do
			//{
				cout << "Elige el alumno a calificar" << endl;
				cin >> indices_al;

				cout << arrAlumnos->longitud() << endl;
				cout << indices_al << endl;

				if (indices_al < 0 || indices_al > arrAlumnos->longitud())
				{
					cout << "Alumno invalido, ingrese un alumno valido" << endl;
					break;
				}

				CAlumno* pAlumno = arrAlumnos->obtenerPos(indices_al-1);

				//Borras arrAlumnos->obtenerPos(indices_al-1)
				
				Lista<CCalificar*>* pCalificacion = pCursos->asignarNotas(pProfesor->getCursos(), pAlumno->getCursos(), pAlumno->getCursosExamenes() );
				pAlumno->setCalificacion(pCalificacion);

			//} while (arrAlumnos->longitud() > 0);

			break;
		}
	}
	arrProfesor->agregaPos(pProfesor, iPos);
}

int menu(){
	cout << "\n";
	cout << " -------------------------------------" << endl;
	cout << "|                MENU                 |" << endl;
	cout << " -------------------------------------" << endl;
	cout << "|<1> Gestionar Alumno                 |" << endl;
	cout << " -------------------------------------" << endl;
	cout << "|<2> Gestionar Profesor               |" << endl;
	cout << " -------------------------------------" << endl;
	cout << "|<3> Gestion General                  |" << endl;
	cout << " -------------------------------------" << endl;
	cout << "|<4> Salir                            |" << endl;
	cout << " -------------------------------------" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	do
	{
		cin >> opcion;
		if (opcion < 0 || opcion>4)
			cout << "Ingrese una opcion valida... ";
	} while (opcion < 0 || opcion>4);

	return opcion;
}
int main()
{
	int nalumnos = 0, nprofesores = 0;
	while (true) {
		int opc = menu();
		switch (opc) {
			int oc1, oc2,oc3;
		case 1:
			cout << "\n";
			cout << " -------------------------------------" << endl;
			cout << "|               ALUMNO                |" << endl;
			cout << " -------------------------------------" << endl;
			cout << "|<1> Registrar Alumno                 |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "|<2> Administrar Pendientes           |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "Elegir: ";
			cin >> oc1;
			switch (oc1) {
			case 1:
				ingresarAlumno(nalumnos);
				nalumnos++;
				break;
			case 2:
				break;
			}
			break;
		case 2:
			cout << "\n";
			cout << " -------------------------------------" << endl;
			cout << "|              PROFESOR               |" << endl;
			cout << " -------------------------------------" << endl;
			cout << "|<1> Registrar Profesor               |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "|<2> Administrar Pendientes           |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "Elegir: ";
			cin >> oc2;
			switch (oc2) {
			case 1:
				ingresarProfesor(nprofesores);
				nprofesores++;
				break;
			case 2:
				break;
			}
			break;
		case 3:
			cout << "\n";
			cout << " -------------------------------------" << endl;
			cout << "|           ADMINISTRACION            |" << endl;
			cout << " -------------------------------------" << endl;
			cout << "|<1> Listar Alumnos                   |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "|<2> Borrar Alumno                    |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "|<3> Ordenar Alumnos (Promedio)       |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "|<4> Listar Profesores                |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "|<5> Borrar Profesor                  |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "|<6> Ordenar Profesores (Alfabeto)    |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "Elegir: ";
			cin >> oc3;
			switch (oc3) {
			case 1:
				for (int i = 0; i < arrParentezco->longitud(); i++) {
					cout << endl;
					cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
					cout << "      LISTA DE ALUMNOS        " << endl;
					cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
					cout << "\nALUMNO: " << i + 1 << endl;
					arrParentezco->obtenerPos(i)->listar();

					for (size_t j = 0; j < arrParentezco->obtenerPos(i)->getAlumno()->getCursos()->longitud(); j++)
					{
						cout << "\t -" << arrParentezco->obtenerPos(i)->getAlumno()->getCursos()->obtenerPos(j) << " | Promedio: " << pCursos->obtenerPromedio(arrParentezco->obtenerPos(i)->getAlumno()->getCursos()->obtenerPos(j), arrParentezco->obtenerPos(i)->getAlumno()->getCalificacion()) << endl;
					}
				}
				if (arrParentezco->longitud() == 0) 
				{
					cout << endl;
					cout << "No hay alumnos ingresados";
					cout << endl;
				}
			case 2:
				break;
			case 3:
				break;
			case 4:
				for (int i = 0; i < arrProfesor->longitud(); i++) {
					cout << endl;
					cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
					cout << "      LISTA DE PROFFESORES        " << endl;
					cout << " "; cout << "- - - - - - - - - - - - - - - - - - - " << endl;
					cout << "\nProfesor: " << i + 1 << endl;
					arrProfesor->obtenerPos(i)->listarProfesor();
				}
				if (arrProfesor->longitud() == 0) {
					cout << endl;
					cout << "No hay profesores ingresados";
					cout << endl;
				}
			}
			break;
		case 4:
			return false;
			break;
		}
	}
}