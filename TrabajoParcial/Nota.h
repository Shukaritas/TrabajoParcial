#pragma once

#include "Calificar.h"

class CNota
{
private:

public:
	CNota()
	{

	}

	~CNota()
	{

	}

	Lista<CCalificar*>* asignarNotas(string curso, Lista<string>* arrCursos, Lista<int>* arrCursosExamenes)
	{
		Lista<CCalificar*>* arrCalificaciones = new Lista<CCalificar*>();

		for (size_t i = 0; i < arrCursos->longitud(); i++)
		{
			if (curso == arrCursos->obtenerPos(i))
			{
				for (size_t j = 0; j < arrCursosExamenes->obtenerPos(i); j++)
				{
					int nota;
					cout << "INGRESE NOTA " << j;
					cin >> nota;

					if (nota > 20)
					{
						nota = 20;
					}
					else if(nota < 0)
					{
						nota = 0;
					}

					cout << "[D] Curso " << arrCursos->obtenerPos(i) << endl;
					cout << "[D] Nota " << nota << endl;
					cout << "[D] Max Exam " << arrCursosExamenes->obtenerPos(i) << endl;

					arrCalificaciones->agregaPos(new CCalificar(arrCursos->obtenerPos(i), nota, arrCursosExamenes->obtenerPos(i)), j);
				}
			}
		}

		return arrCalificaciones;
	}

	float obtenerPromedio(string curso, Lista<CCalificar*>* arrCalificar)
	{
		if (arrCalificar->longitud() <= 0)
			return 0;

		float sum = 0.0f;
		float prom = 0;

		for (size_t i = 0; i < arrCalificar->longitud(); i++)
		{
			if (arrCalificar->obtenerPos(i)->getCurso() == curso)
			{
				sum += arrCalificar->obtenerPos(i)->getNota();
				prom = arrCalificar->obtenerPos(i)->getNumExam();
			}
		}

		return sum / prom;
	}
};
