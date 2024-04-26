#pragma once

class CProfesor : CPersona
{
private:
	string curso;
public:
	CProfesor(string& nombre, string& apellido, string& codigo) :
		CPersona(nombre, apellido, codigo)
	{

	}

	~CProfesor()
	{

	}

	string getCursos() { return this->curso; }
	string getNombre() { return this->nombre; }
	string getApellido() { return this->apellido; }
	string getCodigo() { return this->codigo; }
	void setCurso(string dummy) { this->curso = dummy; }

	void listarProfesor() 
	{
		cout << "NOMBRE PROFESOR: "<< this->getNombre() <<endl;
		cout << "APELLIDO PROFESOR: " << this->getApellido() << endl;
		cout << "CODIGO PROFESOR: " << this->getCodigo() << endl;
		cout << "AREA: " << this->getCursos() << endl;
	}
};