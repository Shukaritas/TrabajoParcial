#pragma once

#include "Alumno.h"
#include "Padre.h"

class CParentezco
{
private:
	CAlumno* pAlumno;
	CPadre* pPadre;

public:
	CParentezco(CAlumno* pAlumno, CPadre* pPadre)
	{
		this->pAlumno = pAlumno;
		this->pPadre = pPadre;
	}

	~CParentezco()
	{
		delete this->pAlumno;
		delete this->pPadre;
	}

	CPadre* getPadre() { return this->pPadre; }
	CAlumno* getAlumno() { return this->pAlumno; }	
	
	void setPadre(CPadre* dummy) { this->pPadre = dummy; }
	void setAlumno(CAlumno* dummy) { this->pAlumno = dummy; }

	void listar() 
	{
		cout << "TIPO DE APODERADO: " << pPadre->getTipo() << endl;
		cout << "NOMBRE DE " << pPadre->getTipo() << ": " << pPadre->getNombre() << endl;
		cout << "APELLIDO DE " << pPadre->getTipo() << ": " << pPadre->getApellido() << endl;
		cout << "CODIGO DE " << pPadre->getTipo() << ": " << pPadre->getCodigo() << endl;
		cout << "NOMBRE ALUMNO: " << pAlumno->getNombre() << endl;
		cout << "APELLIDO ALUMNO: " << pAlumno->getApellido() << endl;
		cout << "CODIGO ALUMNO: " << pAlumno->getCodigo() << endl;
		cout << "GRADO ALUMNO: " << pAlumno->getGrado() << endl;
		cout << "CURSOS: " << endl;
	}
};