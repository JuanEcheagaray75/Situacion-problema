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
    // Los comentarios con código tienen la implementación para que veas como está trabajando el algoritmo

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
        // El new regresa un pointer, pero también se crea el objeto con las propiedades dadas
        arrVideos[cantidad] = new Pelicula(row[0], row[1], stoi(row[2]), row[3], stod(row[4]), stoi(row[5]));
        /* 
        cout << "ID: " << row[0] << "\n";
        cout << "Titulo: " << row[1] << "\n";
        cout << "Duracion: " << row[2] << "\n";
        cout << "Genero: " << row[3] << "\n";
        cout << "Calificacion: " << row[4] << "\n";
        cout << "Oscares: " << row[5] << "\n";

        cout << "Dentro del objeto:" << arrPtrPeliculas[cantidad]->str() << "\n"; */
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