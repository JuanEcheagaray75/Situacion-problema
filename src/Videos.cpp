#include "Videos.hpp"

Videos::Videos()
{
    cantidad = 0;
    for (int i = 0; i < MAX_VIDEOS; i++)
    {
        arrVideos[i] = nullptr;
    }
}

Videos::~Videos()
{
}

void Videos::leerArchivo()
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
        stringstream s(line);
        int iRow = 0;

        while (getline(s, word, ','))
        {
            row[iRow++] = word;
        }
        arrVideos[cantidad] = new Pelicula(row[0], row[1], stoi(row[2]), row[3], stod(row[4]), stoi(row[5]));
        cantidad++;
    }
    fin.close();
}

void Videos::reporteDuracion(int _duracion)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (arrVideos[i]->getDuracion() == _duracion)
        {
            cout << arrVideos[i]->str() << "\n";
        }
    }
}

void Videos::reporteVideos()
{
    double prom = 0;
    for (int i = 0; i < cantidad; i++)
    {
        cout << arrVideos[i]->str() << "\n";
        prom += arrVideos[i]->getCalificacion();
    }
    if (cantidad > 0)
    {
        prom /= cantidad;
        cout << "Calificacion Promedio =" << prom << "\n";
    }
}