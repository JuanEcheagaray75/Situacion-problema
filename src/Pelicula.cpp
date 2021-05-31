#include "Pelicula.hpp"  
	
Pelicula::Pelicula()
{
	oscares = 0;
}
	
Pelicula::~Pelicula()
{
	
}

Pelicula::Pelicula(string _id, string _titulo, int _duracion, string _genero, double _calificacionPromedio, int _oscares)
{
    id = _id;
    titulo = _titulo;
    genero = _genero;
    duracion = abs(_duracion);
    calificacionPromedio = abs(_calificacionPromedio);
    oscares = abs(_oscares);
}

void Pelicula::setOscares(int _oscares)
{
    oscares = abs(_oscares);
}

int Pelicula::getOscares()
{
    return oscares;
}

string Pelicula::str()
{
    string ret_val;
    ret_val = "P" + Video::str() + "," + to_string(oscares);
    return ret_val;
}