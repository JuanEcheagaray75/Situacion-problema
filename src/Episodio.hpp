#ifndef EPISODIO_H
#define EPISODIO_H
#pragma once
#include <sstream>
using namespace std;

class Episodio
{
private:
	string titulo;
	int temporada;
	double calificacion;

public:
	// Constructores y destructor
	Episodio();
	~Episodio();
	Episodio(string _titulo, int _temporada, double _calificacion);

	// Métodos de modificación
	void setTitulo(string _titulo);
	void setTemporada(int _temporada);
	void setCalificacion(double _calificacion);

	// Métodos de acceso
	string getTitulo();
	int getTemporada();
	double getCalificacion();

	// Métodos extra
	string str();
};
#endif