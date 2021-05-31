#include "Serie.hpp"

Serie::Serie()
{
    cantidad_episodios = 0;
    calificacionPromedio = -1;
}

Serie::~Serie()
{
}

Serie::Serie(string _id, string _titulo, int _duracion, string _genero, double _calificacion, int _cantidad_episodios)
{
    id = _id;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacionPromedio = _calificacion;
    cantidad_episodios = _cantidad_episodios;
}

void Serie::setEpisodio(int _index, Episodio _episodio)
{
    if (abs(_index) >= 0 && abs(_index) <= cantidad_episodios)
    {
        episodios[abs(_index)] = _episodio;
    }
    else
    {
        cout << "Captura un indice valido \n";
    }
}

void Serie::setCantidad(int _cantidad_episodios)
{
    cantidad_episodios = abs(_cantidad_episodios);
}

int Serie::getCantidad()
{
    return cantidad_episodios;
}

Episodio Serie::getEpisodio(int _index)
{
    if (abs(_index) >= 0 && abs(_index <= cantidad_episodios))
    {
        return episodios[abs(_index)];
    }
    else
    {
        return episodios[0];
    }
}

string Serie::str()
{
    string ret_val;
    ret_val = "S" + Video::str() + "," + to_string(cantidad_episodios) + "\n";
    for (int i = 0; i < cantidad_episodios; i++)
    {
        ret_val += to_string(i) + ':' + episodios[i].str() + "\n";
    }
    // ret_val += "\n";
    return ret_val;
}

void Serie::calculaCalPromedio()
{
    double prom = 0;
    if (cantidad_episodios > 0)
    {
        for (int i = 0; i < cantidad_episodios; i++)
        {
            prom += episodios[i].getCalificacion();
        }
        prom /= cantidad_episodios;
        calificacionPromedio = prom;
    }
    else
    {
        calificacionPromedio = -1;
    }
}