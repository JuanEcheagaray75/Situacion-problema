#include "Video.hpp"

Video::Video()
{
    id = "000";
    titulo = "___";
    duracion = 0;
    genero = "XXX";
    calificacionPromedio = 0;
}

Video::~Video()
{
}

Video::Video(string _id, string _titulo, string _genero, int _duracion, double _calificacionPromedio)
{
    id = _id;
    titulo = _titulo;
    genero = _genero;
    duracion = fabs(_duracion);
    calificacionPromedio = fabs(_calificacionPromedio);
}

void Video::setId(string _id)
{
    id = _id;
}

void Video::setTitulo(string _titulo)
{
    titulo = _titulo;
}

void Video::setGenero(string _genero)
{
    genero = _genero;
}

void Video::setDuracion(int _duracion)
{
    duracion = fabs(_duracion);
}

void Video::setCalificacion(double _calificacionPromedio)
{
    calificacionPromedio = fabs(_calificacionPromedio);
}

string Video::getId()
{
    return id;
}

string Video::getTitulo()
{
    return titulo;
}

string Video::getGenero()
{
    return genero;
}

int Video::getDuracion()
{
    return duracion;
}

double Video::getCalificacion()
{
    return calificacionPromedio;
}

string Video::str()
{
    string ret_val;
    ret_val = id + "," + titulo + "," + to_string(duracion) + "," + genero + "," +
              to_string(calificacionPromedio);
    return ret_val;
}