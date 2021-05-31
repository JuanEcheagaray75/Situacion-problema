#include "Series.hpp"

Series::Series()
{
    cantidad = 0;
    for (int i = 0; i < MAX_SERIES; i++)
    {
        arrPtrSeries[i] = nullptr;
    }
}

Series::~Series()
{
}

void Series::setPtrSerie(int index, Serie *_ptrSerie)
{
    arrPtrSeries[abs(index)] = _ptrSerie;
}

void Series::setCantidadSeries(int _cantidad)
{
    cantidad = abs(_cantidad);
}

Serie *Series::getPtrSerie(string _id)
{
    Serie* retPtr;
    for (int i = 0; i < cantidad; i++)
    {
        if (_id == arrPtrSeries[i]->getId())
        {
            retPtr = arrPtrSeries[i];
        }
    }
    return retPtr;
}

int Series::getCantidadSeries()
{
    return cantidad;
}

void Series::reporteTodasLasSeries()
{
    double prom = 0;
    for (int i = 0; i < cantidad; i++)
    {
        cout << arrPtrSeries[i]->str() << "\n";
        prom += arrPtrSeries[i]->getCalificacion();
    }
    prom /= cantidad;
    cout << "Promedio Series:" << prom;
}

void Series::reporteConCalificacion(double _calificacion)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (arrPtrSeries[i]->getCalificacion() == _calificacion)
        {
            cout << arrPtrSeries[i]->str() << "\n";
        }
    }
}

void Series::reporteGenero(string _genero)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (arrPtrSeries[i]->getGenero() == _genero)
        {
            cout << arrPtrSeries[i]->str() << "\n";
        }
    }
}

void Series::calcularCalificacionSeries()
{
    for (int i = 0; i < cantidad; i++)
    {
        arrPtrSeries[i]->calculaCalPromedio();
    }
}
void Series::leerArchivo()
{
    string linea, dato, row[6];
    int iRow, iS, cantidadEpisodios;
    fstream lectura;
    Episodio *episodio;

    lectura.open("Serie2021.csv", ios::in);
    cantidad = 0;
    while (getline(lectura, linea))
    {
        stringstream registro(linea);
        iRow = 0;
        while (getline(registro, dato, ','))
        {
            row[iRow++] = dato;
        }
        arrPtrSeries[cantidad] = new Serie(row[0], row[1], stoi(row[2]), row[3], stod(row[4]), 0);
        cantidad++;
    }
    lectura.close();

    lectura.open("Episodio2021.csv", ios::in);
    while (getline(lectura, linea))
    {
        stringstream registro(linea);
        iRow = 0;

        while (getline(registro, dato, ','))
        {
            row[iRow++] = dato;
        }
        iS = stoi(row[0]) - 500;
        episodio = new Episodio(row[1], stoi(row[2]), stod(row[3]));
        cantidadEpisodios = arrPtrSeries[iS]->getCantidad();
        if (cantidadEpisodios < 5)
        {
            arrPtrSeries[iS]->setEpisodio(cantidadEpisodios, *(episodio));
            arrPtrSeries[iS]->setCantidad(++cantidadEpisodios);
        }
    }
    lectura.close();
}