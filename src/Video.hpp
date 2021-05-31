#ifndef VIDEO_H
#define VIDEO_H
#pragma once
#include <sstream>
#include <cmath>
using namespace std;

class Video
{
protected:
	string id;
	string titulo;
	string genero;
	int duracion;
	double calificacionPromedio;

public:
	// Constructores y destructor
	Video();
	Video(string _id, string _titulo, string _genero, int _duracion, double _calificacionPromedio);
	~Video();

	// Métodos de modificación
	void setId(string _id);
	void setTitulo(string _titulo);
	void setGenero(string _genero);
	void setDuracion(int _duracion);
	void setCalificacion(double _calificacionPromedio);

	// Métodos de acceso
	string getId();
	string getTitulo();
	string getGenero();
	int getDuracion();
	double getCalificacion();

	// Métodos extra
	string str();
};
#endif
