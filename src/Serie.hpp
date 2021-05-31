#ifndef SERIE_H
#define SERIE_H
#pragma once
#include <iostream>
#include "Video.hpp"
#include "Episodio.hpp"
using namespace std;

class Serie : public Video
{
private:
	int cantidad_episodios;
	Episodio episodios[5];

public:
	// Constructores y destructor
	Serie();
	Serie(string _id, string _titulo, int _duracion, string _genero, double _calificacion, int _cantidad);
	~Serie();

	// Métodos de acceso
	void setEpisodio(int _index, Episodio _episodio);
	void setCantidad(int _cantidad_episodios);

	// Métodos de modificación
	Episodio getEpisodio(int _index);
	int getCantidad();

	// Métodos extra
	string str();
	void calculaCalPromedio();
};
#endif