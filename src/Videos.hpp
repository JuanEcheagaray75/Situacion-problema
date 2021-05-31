#ifndef VIDEOS_H
#define VIDEOS_H
#pragma once
#include "Video.hpp"
#include "Pelicula.hpp"
#include <fstream>
#include <iostream>
const int MAX_VIDEOS = 100;

class Videos
{
private:
	Video *arrVideos[MAX_VIDEOS];
	int cantidad;

public:
	// Constructores y destructor
	Videos();
	~Videos();

	// Métodos extra
	void leerArchivo();
	void reporteDuracion(int _duracion);
	void reporteVideos(); // Este método debe de reportar el promedio
};
#endif