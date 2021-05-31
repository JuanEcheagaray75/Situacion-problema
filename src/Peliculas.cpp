#include "Peliculas.hpp"

Peliculas::Peliculas()
{
    cantidad = 0;
    for (int i = 0; i < MAX_PEL; i++)
    {
        arrPtrPeliculas[i] = nullptr;
    }
}

Peliculas::~Peliculas()
{
}

// Métodos de acceso
int Peliculas::getCantidadPeliculas()
{
    return cantidad;
}

Pelicula *Peliculas::getPtrPelicula(string _id)
{
    Pelicula *testptr;
    for (int i = 0; i < cantidad; i++)
    {
        if (arrPtrPeliculas[i]->getId() == _id)
        {
            testptr = arrPtrPeliculas[i];
            break;
        }
    }
    return testptr;
}

// Métodos de modificación
void Peliculas::setCantidadPeliculas(int _cantidad)
{
    cantidad = _cantidad;
}

void Peliculas::setPtrPelicula(Pelicula *_peliptr, int _index)
{
    if (abs(_index) <= cantidad)
    {
        arrPtrPeliculas[_index] = _peliptr;
    }
}

// Métodos extra
void Peliculas::leerArchivo()
{
    // Declaración de variables
    fstream fin;
    string row[6];
    string line, word;
    fin.open("Pelicula.csv", ios::in);

    // Lectura de archivo
    cantidad = 0;
    while (getline(fin, line))
    {
        // Este código lee una linea del archivo csv, la separa y lo almacena en s
        // cout << cantidad << line << "\n";
        stringstream s(line);
        int iRow = 0;

        while (getline(s, word, ','))
        {
            row[iRow++] = word;
        }

        // Modificación del arreglo de películas
        arrPtrPeliculas[cantidad] = new Pelicula(row[0], row[1], stoi(row[2]), row[3], stod(row[4]), stoi(row[5]));
        cantidad++;
    }
    fin.close();
}

void Peliculas::reporteTodasLasPeliculas()
{
    for (int i = 0; i < cantidad; i++)
    {
        cout << arrPtrPeliculas[i]->str() << "\n";
    }
}

void Peliculas::reporteConCalificacion(double _calificacion)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (arrPtrPeliculas[i]->getCalificacion() == _calificacion)
        {
            cout << arrPtrPeliculas[i]->str() << "\n";
        }
    }
}

void Peliculas::reporteGenero(string _genero)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (arrPtrPeliculas[i]->getGenero() == _genero)
        {
            cout << arrPtrPeliculas[i]->str() << "\n";
        }
    }
}