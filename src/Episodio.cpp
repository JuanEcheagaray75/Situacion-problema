#include "Episodio.hpp"

Episodio::Episodio()
{
    titulo = "Episodio base";
    temporada = 0;
    calificacion = 0;
}

Episodio::~Episodio()
{
}

Episodio::Episodio(string _titulo, int _temporada, double _calificacion)
{
    titulo = _titulo;
    temporada = abs(_temporada);
    calificacion = abs(_calificacion);
}

void Episodio::setTitulo(string _titulo)
{
    titulo = _titulo;
}

void Episodio::setTemporada(int _temporada)
{
    temporada = abs(_temporada);
}

void Episodio::setCalificacion(double _calificacion)
{
    calificacion = abs(_calificacion);
}

string Episodio::getTitulo()
{
    return titulo;
}

int Episodio::getTemporada()
{
    return temporada;
}

double Episodio::getCalificacion()
{
    return calificacion;
}

string Episodio::str()
{
    string ret_val;
    ret_val = "E" + titulo + "," + to_string(temporada) + "," + to_string(calificacion);
    return ret_val;
}