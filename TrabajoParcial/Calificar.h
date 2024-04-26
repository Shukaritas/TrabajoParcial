#pragma once

class CCalificar
{
private:
	string curso;
	float nota;
	float num_exam;

public:
	CCalificar(string curso, int nota, int num_exam) : curso(curso), nota(nota), num_exam(num_exam)
	{
	}

	~CCalificar()
	{
	}

	float getNota() { return nota; }
	string getCurso() { return curso; }
	float getNumExam() { return num_exam; }
};