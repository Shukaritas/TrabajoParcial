#pragma once

class CPadre : CPersona
{
private:
	string tipoApoderado;

public:
	CPadre(string& nombre, string& apellido, string& codigo, string& tipoApoderado) :
		CPersona(nombre, apellido, codigo), 
		tipoApoderado(tipoApoderado)
	{

	}
	~CPadre(){}
	string getNombre() { return this->nombre; }
	string getApellido() { return this->apellido; }
	string getCodigo() { return this->codigo; }
	string getTipo() { return this->tipoApoderado; }
};