#ifndef PELICULAS_H
#define PELICULAS_H
#pragma once
using namespace std;
#include <fstream>
#include <iostream>
#include "Pelicula.hpp"

// No puede quedar dentro de la definición de la clase
const int MAX_PEL = 50;

class Peliculas : public Pelicula
{
private:
	int cantidad;
	Pelicula *arrPtrPeliculas[MAX_PEL];

public:
	// Constructores y destructor
	Peliculas();
	~Peliculas();

	// Métodos de acceso
	Pelicula *getPtrPelicula(string _id);
	int getCantidadPeliculas();

	// Métodos de modificación
	void setPtrPelicula(Pelicula *_peliptr, int _index);
	void setCantidadPeliculas(int _cantidad);

	// Métodos de despliegue
	void reporteTodasLasPeliculas();
	void reporteConCalificacion(double _calificacion);
	void reporteGenero(string _genero);

	// Lectura de archivos
	void leerArchivo();
};
#endif