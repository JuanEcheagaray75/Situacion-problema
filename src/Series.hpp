#ifndef SERIES_H
#define SERIES_H
#pragma once
#include "Serie.hpp"
#include <fstream>
#include <iostream>

const int MAX_SERIES = 50;

class Series : public Serie
{
private:
	int cantidad;
	Serie *arrPtrSeries[MAX_SERIES];

public:
	// Constructores y destructor
	Series();
	~Series();

	// Métodos de modificación
	void setPtrSerie(int index, Serie *_ptrSerie);
	void setCantidadSeries(int _cantidad);

	// Métodos de acceso
	Serie *getPtrSerie(string _id);
	int getCantidadSeries();

	// Métodos extra
	void reporteTodasLasSeries();
	void reporteConCalificacion(double _calificacion);
	void reporteGenero(string _genero);
	void calcularCalificacionSeries();
	void leerArchivo();
};
#endif