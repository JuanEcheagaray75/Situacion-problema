#ifndef PELICULA_H
#define PELICULA_H
#pragma once
#include "Video.hpp"

class Pelicula : public Video
{
private:
	int oscares;

public:
	// Constructores y destructor
	Pelicula();
	~Pelicula();
	Pelicula(string _id, string _titulo, int _duracion, string _genero, double _calificacionPromedio, int _oscares);

	// Métodos de modificación
	void setOscares(int _oscares);

	// Métodos de acceso
	int getOscares();

	// Métodos extra
	string str();
};
#endif